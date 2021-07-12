#pragma once
#include "Object.h"
#include "Rectangle.h"
#include "Circle.h"
#include <vector>
using namespace std;
class CollisionManager : public Object
{
public:
	CollisionManager();
	~CollisionManager();

	float GetWidth();
	float GetHeight();
	float GetRadius();
	void Render();
	void Update(float deltaTime);
	void Move(float, float);

	void checkAllCollision(vector<Object*> listObj);
	bool rectToRect(Object* rect1, Object* rect2);
	bool rectToCircle(Object* rect, Object* circle);
	bool rectToPlane(Object* rect);
	bool circleToCircle(Object* circle1, Object* circle2);
	bool circleToPlane(Object* circle);
	bool checkOverlap(int R, int Xc, int Yc, int X1, int Y1, int X2, int Y2);

	

};