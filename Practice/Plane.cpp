#include "Plane.h"

Plane::Plane() {
	type = "PLANE";
}

float Plane::GetWidth() {
	return 0;
}
float Plane::GetHeight() {
	return 0;
}
float Plane::GetRadius() {
	return 0;
}

void Plane::Render() {
	VideoDriver::GetInstance()->DrawRect(0, 0, (int)width, (int)height);
}

void Plane::Update(float deltaTime) {

}

void Plane::Move(float x, float y) {

}