#pragma once
#include "Object.h"

class Circle :public Object
{
public:
	float radius;
	Circle();
	Circle(float x, float y, float radius, float mass, float velocity);
	~Circle();
	float GetRadius();
	float GetWidth();
	float GetHeight();
	void Render();
	void Update(float frameTime);
	void Move(float x, float y);
};

