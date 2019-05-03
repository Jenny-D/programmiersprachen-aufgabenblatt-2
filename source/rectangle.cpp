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

//2.9
float Rectangle::circumference() {
	float umfang = 2 * (max_.x - min_.x) + 2 * (max_.y - min_.y);
	return umfang;
}

//2.11
void Rectangle::draw(Window const& window, Color const& color_) const {
	window.draw_line(min_.x, min_.y, max_.x, min_.y, color_.r, color_.g, color_.b);
	window.draw_line(max_.x, min_.y, max_.x, max_.y, color_.r, color_.g, color_.b);
	window.draw_line(max_.x, max_.y, min_.x, max_.y, color_.r, color_.g, color_.b);
	window.draw_line(min_.x, max_.y, min_.x, min_.y, color_.r, color_.g, color_.b);
}

//2.12
void Rectangle::draw(Window const& window, Color const& color_, float thickness) const {
	window.draw_line(min_.x, min_.y, max_.x, min_.y, color_.r, color_.g, color_.b, thickness);
	window.draw_line(max_.x, min_.y, max_.x, max_.y, color_.r, color_.g, color_.b, thickness);
	window.draw_line(max_.x, max_.y, min_.x, max_.y, color_.r, color_.g, color_.b, thickness);
	window.draw_line(min_.x, max_.y, min_.x, min_.y, color_.r, color_.g, color_.b, thickness);
}

//2.13
bool Rectangle::is_inside(Vec2 const& mouse_pos) {
	bool inside = false;
	// wenn mouse_pos < min_ oder > max_, dann ist es nicht im Rechteck
	// -> testen, ob mouse_pos >= min_ und <= max_
	if (mouse_pos.x >= min_.x && mouse_pos.x <= max_.x && mouse_pos.y >= min_.y && mouse_pos.y <= max_.y){
		inside = true;
	}
	return inside;
}