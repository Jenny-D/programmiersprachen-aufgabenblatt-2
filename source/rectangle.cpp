#include "rectangle.hpp"

Rectangle::Rectangle() :
	min_(0.0f, 0.0f),
	max_(0.0f, 0.0f) {}

Rectangle::Rectangle(Vec2 const& min_, Vec2 const& max_) :
	min_(min_),
	max_(max_) {}