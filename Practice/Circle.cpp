#include "Circle.h"
#include "VideoDriver.h"
#include <iostream>
Circle::Circle() {

}

Circle::Circle(float x, float y, float radius, float velocity, float mass) {
	type = "CIRCLE";
	time = 0;
	this->xPos = x;
	this->yPos = y;
	this->radius = radius;
	this->velocity = velocity;
	this->mass  = mass;
}


Circle::~Circle()
{
}

float Circle::GetWidth() {
	return 0;

}
float Circle::GetHeight() {
	return 0;
}

void Circle::Render() {
	VideoDriver::GetInstance() -> DrawCircle(this->xPos, this->yPos, this->radius);
}

float Circle::GetRadius() {
	return radius;
}

void Circle::Move(float x, float y) {
	this->xPos = x;
	this->yPos = y;
}

void Circle::Update(float deltaTime) {
	if (this->xPos < radius) {
		this->xPos = radius;
	}
	if (this->yPos < radius) {
		this->yPos = radius;
	}
	if (this->xPos + radius - 1 >= SCREEN_W) {
		this->xPos = SCREEN_W - radius;
	}
	if (this->yPos + radius - 1 >= SCREEN_H) {
		this->yPos = SCREEN_H - radius;
	}
	time += deltaTime;
	velocity += G*time;
	yPos += deltaTime * velocity;
}
