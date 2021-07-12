#pragma once
#include "Object.h"
class Rect : public Object
{
public:
	float height;
	float width;
	Rect();
	Rect(float x, float y, float h, float w, float v, float m);
	~Rect();
	float GetWidth();
	float GetHeight();
	float GetRadius();
	void Render();
	void Update(float frameTime);
	void Move(float x, float y);
};

