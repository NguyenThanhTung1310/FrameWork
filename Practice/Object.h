#pragma once
#include "videoDriver.h"
class Object
{
public:
	float xPos;
	float yPos;
	float mass;
	float velocity;
	char* type;
	bool isFall = true;
	bool isClicked = false;
	float time = 0;

	Object();
	~Object();
	float* getPosition();
	void setPosition(float x, float y);
	int getMass();
	void setMass(int mass);
	int getVelocity();
	char* getType();
	void setVelocity(int velocity);

	virtual void Render();
	virtual void Update(float frameTime);
	virtual float GetWidth() = 0;
	virtual float GetHeight() = 0;
	virtual float GetRadius() = 0;
	virtual void Move(float x, float y);
};

