#include "CollisionManager.h"
#include <iostream>
using namespace std;
CollisionManager::CollisionManager() {

}

float CollisionManager::GetWidth() {
	return 0;
}
float CollisionManager::GetHeight() {
	return 0;
}
float CollisionManager::GetRadius() {
	return 0;
}

void CollisionManager::Render() {}
void CollisionManager::Update(float deltaTime) {}
void CollisionManager::Move(float, float) {}
CollisionManager::~CollisionManager() {

}

bool CollisionManager::rectToRect(Object* rect1, Object* rect2) {
	if ((rect2->xPos > rect1->xPos && rect2->xPos<rect1->xPos + rect1->GetWidth() && rect2->yPos>rect1->yPos && rect2->yPos < rect1->yPos + rect1->GetHeight()) == true) return true;
	if ((rect2->xPos + rect2->GetWidth() > rect1->xPos && rect2->xPos + rect2->GetWidth() < rect1->xPos + rect1->GetWidth() && rect2->yPos > rect1->yPos && rect2->yPos < rect1->yPos + rect1->GetHeight()) == true) return true;
	if ((rect2->xPos > rect1->xPos && rect2->xPos<rect1->xPos + rect1->GetWidth() && rect2->yPos + rect2->GetHeight()>rect1->yPos && rect2->yPos + rect2->GetHeight() < rect1->yPos + rect1->GetHeight()) == true) return true;
	if ((rect2->xPos + rect2->GetWidth() > rect1->xPos && rect2->xPos + rect2->GetWidth() < rect1->xPos + rect1->GetWidth() && rect2->yPos + rect2->GetHeight() > rect1->yPos && rect2->yPos + rect2->GetHeight() < rect1->yPos + rect1->GetHeight()) == true) return true;
	else return false;
}

bool CollisionManager::rectToCircle(Object* obj1, Object* obj2) {
	int R, X1, X2, Y1, Y2, Xc, Yc;
	if (obj1->type = "RECTANGLE") {
		R = obj2->GetRadius();
		Xc = obj2->xPos;
		Yc = obj2->yPos;
		X1 = obj1->xPos;
		Y1 = obj1->yPos + obj1->GetHeight();
		X2 = obj1->xPos + obj1->GetWidth();
		Y2 = obj1->yPos;
	}
	else {
		R = obj1->GetRadius();
		Xc = obj1->xPos;
		Yc = obj1->yPos;
		X1 = obj2->xPos;
		Y1 = obj2->yPos + obj2->GetHeight();
		X2 = obj2->xPos + obj2->GetWidth();
		Y2 = obj2->yPos;
	}
	int Xn = max(X1, min(Xc, X2));
	int Yn = max(Y1, min(Yc, Y2));
	int Dx = Xn - Xc, Dy = Yn - Yc;
	return (Dx * Dx + Dy * Dy) <= R * R;
}
bool CollisionManager::rectToPlane(Object* rect) {
	if (rect->GetHeight() >= rect->GetWidth()) {
		if (SCREEN_H - rect->yPos <= rect->GetHeight()) return true;
		else return false;
	}
	else {
		if (SCREEN_H - rect->yPos <= rect->GetWidth()) return true;
		else return false;
	}
}

bool CollisionManager::circleToPlane(Object* circle) {
	if ((SCREEN_H - circle->yPos) <= circle->GetRadius()) return true;
	else return false;
}

bool CollisionManager::circleToCircle(Object* circle1, Object* circle2) {
	float distance = sqrt((circle1->xPos - circle2->xPos) * (circle1->xPos - circle2->xPos) + (circle1->yPos - circle2->yPos) * (circle1->yPos - circle2->yPos));
	if (distance - 1 <= (circle1->GetRadius() + circle2->GetRadius())) return true;
	else return false;
}

void CollisionManager::checkAllCollision(vector<Object*> objList) {
	for (int i = 0; i < objList.size() - 1; i++) {
		for (int j = i + 1; j < objList.size(); j++) {
			char* obj1Type = objList[i]->type;
			char* obj2Type = objList[j]->type;
			if ((strcmp(obj1Type, "RECTANGLE") == 0 && strcmp(obj2Type, "PLANE") == 0) == 1) {
				if (rectToPlane(objList[i])) {
					objList[i]->isFall = false;
					objList[i]->yPos = SCREEN_H - objList[i]->GetHeight();
					cout << "edge collision detected" << endl;
					continue;
				}
			}
			if ((strcmp(obj1Type, "CIRCLE") == 0 && strcmp(obj2Type, "PLANE") == 0) == 1) {
				if (circleToPlane(objList[i])) {
					objList[i]->isFall = false;
					objList[i]->yPos = SCREEN_H - objList[i]->GetRadius();
					cout << "edge collision detected" << endl;
					continue;
				}
			}
			if ((strcmp(obj1Type, "RECTANGLE") == 0 && strcmp(obj2Type, "RECTANGLE") == 0) == 1) {
				if (rectToRect(objList[i],objList[j]) || rectToRect(objList[j], objList[i])) {
					objList[i]->isFall = false;
					objList[j]->isFall = false;
					cout << "object collision detected" << endl;

				}
				else {
					objList[i]->isFall = true;
					objList[j]->isFall = true;
				}
				continue;
			}
			if ((strcmp(obj1Type, "RECTANGLE") == 0 && strcmp(obj2Type, "CIRCLE") == 0) == 1) {
				if (rectToCircle(objList[i], objList[j])) {
					objList[i]->isFall = false;
					objList[j]->isFall = false;
					cout << "object collision detected" << endl;
				}
				else {
					objList[i]->isFall = true;
					objList[j]->isFall = true;
				}
			}
			if ((strcmp(obj1Type, "CIRCLE") == 0 && strcmp(obj2Type, "RECTANGLE") == 0) == 1) {
				if (rectToCircle(objList[i], objList[j])) {
					objList[i]->isFall = false;
					objList[j]->isFall = false;
					cout << "object collision detected" << endl;
				}
				else {
					objList[i]->isFall = true;
					objList[j]->isFall = true;
				}
			}
			if ((strcmp(obj1Type, "CIRCLE") == 0 && strcmp(obj2Type, "CIRCLE") == 0) == 1) {
				if (circleToCircle(objList[i], objList[j])) {
					objList[i]->isFall = false;
					objList[j]->isFall = false;
					cout << "object collision detected" << endl;
				}
				else {
					objList[i]->isFall = true;
					objList[j]->isFall = true;
				}
				continue;
			}
		}
	}
}