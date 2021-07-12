#pragma once
#include"Object.h"
#include "Rectangle.h"
#include"Circle.h"
#include"Plane.h"
#include <vector>
#pragma warning(disable:4996)
using namespace std;
class SceneManager
{
public:
	vector<Object*> objList;
	SceneManager();
	~SceneManager();
	void Update(float frameTime);
	void Render();
	void AddObject(Object *object);
	void Init();
	void modObjectClicked(Object* obj, float x, float y);
	void modObjectReleased(Object* obj, float x, float y);
	void modObjectMove(Object* obj, float x, float y);
	bool isObjectRect(Object* rect, float x, float y);
	bool isObjectCircle(Object* circle, float x, float y);
	void handlingObjectClicked(float x, float y);
	void handlingObjectReleased(float x, float y);
	void handlingObjectMove(float x, float y);
	
};

