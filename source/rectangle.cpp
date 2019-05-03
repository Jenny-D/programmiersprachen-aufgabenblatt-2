#include "rectangle.hpp"

Rectangle::Rectangle() :
	min_{ 0.0f, 0.0f },
	max_{ 0.0f, 0.0f },
	color_{0.0f, 0.0f, 0.0f} {}

Rectangle::Rectangle(Vec2 const& min_, Vec2 const& max_):
	min_(min_),
	max_(max_) {}

Rectangle::Rectangle(Vec2 const& min_, Vec2 const& max_, Color const& color_) :
	min_(min_),
	max_(max_),
	color_(color_) {}

float Rectangle::circumference() {
	float umfang = 2 * (max_.x - min_.x) + 2 * (max_.y - min_.y);
	return umfang;
}

void Rectangle::draw(Window const& window, Color const& color_) const {
	window.draw_line(min_.x, min_.y, max_.x, min_.y, color_.r, color_.g, color_.b);
	window.draw_line(max_.x, min_.y, max_.x, max_.y, color_.r, color_.g, color_.b);
	window.draw_line(max_.x, max_.y, min_.x, max_.y, color_.r, color_.g, color_.b);
	window.draw_line(min_.x, max_.y, min_.x, min_.y, color_.r, color_.g, color_.b);
}