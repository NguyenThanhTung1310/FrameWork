#include "Object.h"
#include <iostream>


Object::Object()
{
}


Object::~Object()
{

}
void Object::setPosition(float x, float y) {
	this->xPos = x;
	this->yPos = y;
}
void Object::Render(){}
void Object::Update(float frameTime){}
void Object::Move(float x, float y){}
