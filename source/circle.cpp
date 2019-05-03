#define _USE_MATH_DEFINES
#include "circle.hpp"
#include <cmath>

Circle::Circle() :
	radius_(0.0f),
	center_{ 0.0f, 0.0f },
	color{0.0f, 0.0f, 0.0f} {}

Circle::Circle(float radius_, Vec2 const& center_) :
	radius_(radius_),
	center_(center_) {}

Circle::Circle(float radius_, Vec2 const& center_, Color color) :
	radius_(radius_),
	center_(center_),
	color(color) {}

float Circle::circumference() {
	return radius_ * M_PI * 2;
}