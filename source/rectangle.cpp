#include "rectangle.hpp"

Rectangle::Rectangle() :
	min_{ 0.0f, 0.0f },
	max_{ 0.0f, 0.0f },
	color{0.0f, 0.0f, 0.0f} {}

Rectangle::Rectangle(Vec2 const& min_, Vec2 const& max_):
	min_(min_),
	max_(max_) {}

Rectangle::Rectangle(Vec2 const& min_, Vec2 const& max_, Color color) :
	min_(min_),
	max_(max_),
	color(color) {}

float Rectangle::circumference() {
	float umfang = 2 * (max_.x - min_.x) + 2 * (max_.y - min_.y);
	return umfang;
}