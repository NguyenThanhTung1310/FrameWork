#include "Rectangle.h"
#include "videoDriver.h"
#include <iostream>


Rect::Rect()
{
}

Rect::Rect(float x, float y, float h, float w, float v, float m) {
	type = "RECTANGLE";
	time = 0;
	this->xPos = x;
	this->yPos = y;
	this->height = h;
	this->width = w;
	this->velocity = v;
	this->mass = m;
}

float Rect::GetWidth() {
	return width;
}

float Rect::GetHeight() {
	return height;
}

float Rect::GetRadius() {
	return 0;
}

Rect::~Rect()
{
}
void Rect::Render()
{
	VideoDriver::GetInstance()->DrawRect(this->xPos, this->yPos, this->height, this->width);
}

void Rect::Update(float deltaTime)
{	
	if (this->xPos < 0) {
		this->xPos = 0;
	}
	if (this->yPos < 0) {
		this->yPos = 0;
	}
	if (this->xPos >= SCREEN_W - width) {
		this->xPos = SCREEN_W - width;
	}
	if (this->yPos >= SCREEN_H - height) {
		this->yPos = SCREEN_H - height;
	}
	time += deltaTime;
	velocity += G*time;
	yPos += deltaTime * velocity;
}

void Rect::Move(float x, float y) {
	this->xPos = x;
	this->yPos = y;
}
