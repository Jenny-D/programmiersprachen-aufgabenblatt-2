#include "circle.hpp"

Circle::Circle() :
	r(0.0f),
	center(0.0f, 0.0f) {}

Circle::Circle(float radius_, Vec2 const& center_) :
	radius_(radius_),
	center_(center_) {}

float Circle::circumference() {
	return radius_ * M_PI * 2;
}