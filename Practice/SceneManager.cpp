#include "SceneManager.h"
#include <iostream>

SceneManager::SceneManager()
{
}


SceneManager::~SceneManager()
{
}

void SceneManager::Init() {
	FILE* data;
	data = fopen("data.txt", "r");
	int objectNumbered;
	char tmp[20];
	fscanf(data,"#OBJECT_NUM %d\n", &objectNumbered);
	for (int i = 0; i < objectNumbered; i++) {
		int id, velocity, a, b, c, d;
		char tmp2[20];
		Object *obj;
		fscanf(data, "#ID %d\n", &id);
		fscanf(data, "TYPE: %s\n", &tmp);
		if (!std::strcmp(tmp, "RECT")) {
			fscanf(data, "POSITION: %d, %d, %d, %d\n", &a, &b, &c, &d);
			fscanf(data, "VELOCITY: %d\n", &velocity);
			obj = new Rect((float)a, (float)b, (float)c, (float)d, (float)velocity, 1.0f);
		}
		else {
			fscanf(data, "POSITION: %d, %d, %d\n", &a, &b, &c);
			fscanf(data, "VELOCITY: %d\n", &velocity);
			obj = new Circle((float)a, (float)b, (float)c, (float)velocity,	1.0f);
		}
		AddObject(obj);
	}
	Object* plane = new Plane();
	plane->type = "PLANE";
	AddObject(plane);
}

void SceneManager::AddObject(Object *object)
{
	this->objList.push_back(object);
}

void SceneManager::Update(float deltaTime) {
	for (int i = 0; i < objList.size(); i++) {
		if (objList[i]->isFall == true) {
			objList[i]->Update(deltaTime);
		}
	}
}

void SceneManager::Render() {
	for (int i = 0; i < objList.size(); i++) {
		objList[i]->Render();
	}
}

bool SceneManager::isObjectRect(Object* rect, float x, float y) {
	if ((x > rect->xPos && x < rect->xPos + rect->GetWidth()) && (y > rect->yPos && y < rect->yPos + rect->GetHeight())) {
		return true;
	}
	return false;
}

bool SceneManager::isObjectCircle(Object* circle, float x, float y) {
	float distance = sqrt((x - circle->xPos) * (x - circle->xPos) + (y - circle->yPos) * (y - circle->yPos));
	if (distance < circle->GetRadius()) return true;
	return false;
}

void SceneManager::modObjectClicked(Object* obj, float x, float y) {
	if (strcmp(obj->type, "RECTANGLE") == 0) {
		if (isObjectRect(obj, x, y)) {
			obj->isFall = false;
			obj->velocity = 0;
			obj->time = 0;
			obj->xPos = x - obj->GetHeight() / 2;
			obj->yPos = y - obj->GetWidth() / 2;
		}
	}
	if (strcmp(obj->type, "CIRCLE") == 0) {
		if (isObjectCircle(obj, x, y)) {
			obj->isFall = false;
			obj->velocity = 0;
			obj->time = 0;
			obj->xPos = x;
			obj->yPos = y;
		}
	}
}

void SceneManager::modObjectReleased(Object* obj, float x, float y) {
	if (strcmp(obj->type, "RECTANGLE") == 0) {
		if (isObjectRect(obj, x, y)) {
			obj->isFall = true;
			obj->velocity = 0;
			obj->time = 0;
			obj->xPos = x - obj->GetHeight() / 2;
			obj->yPos = y - obj->GetWidth() / 2;
		}
	}
	if (strcmp(obj->type, "CIRCLE") == 0) {
		if (isObjectCircle(obj, x, y)) {
			obj->isFall = true;
			obj->velocity = 0;
			obj->time = 0;
		}
	}
}

void SceneManager::modObjectMove(Object* obj, float x, float y) {
	if (strcmp(obj->type, "RECTANGLE") == 0) {
		if (isObjectRect(obj, x, y)) {
			obj->isFall = false;
			obj->Move(x, y);
			obj->velocity = 0;
			obj->time = 0;
			obj->xPos = x - obj->GetHeight() / 2;
			obj->yPos = y - obj->GetWidth() / 2;
		}
	}
	if (strcmp(obj->type, "CIRCLE") == 0) {
		if (isObjectCircle(obj, x, y)) {
			obj->isFall = false;
			obj->Move(x, y);
			obj->velocity = 0;
			obj->time = 0;
		}
	}
}

void SceneManager::handlingObjectClicked(float x, float y) {
	for (int i = 0; i < objList.size(); i++) {
		modObjectClicked(objList[i], x, y);
	}
}

void SceneManager::handlingObjectReleased(float x, float y) {
	for (int i = 0; i < objList.size(); i++) {
		modObjectReleased(objList[i], x, y);
	}
}

void SceneManager::handlingObjectMove(float x, float y) {
	for (int i = 0; i < objList.size(); i++) {
		modObjectMove(objList[i], x, y);
	}
}