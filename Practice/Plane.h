#pragma once
#include "Object.h"
#include "videoDriver.h"
class Plane : public Object {
public:
	float width = SCREEN_W;
	float height = SCREEN_H;
	Plane();
	void Render();
	void Update(float deltaTime);
	float GetWidth();
	float GetHeight();
	float GetRadius();
	void Move(float x, float y);
};