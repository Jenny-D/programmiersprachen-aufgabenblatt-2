#define _USE_MATH_DEFINES
#include "circle.hpp"
#include <cmath>

Circle::Circle() :
	radius_(0.0f),
	center_{ 0.0f, 0.0f },
	color_{0.0f, 0.0f, 0.0f} {}

Circle::Circle(float radius_, Vec2 const& center_) :
	radius_(radius_),
	center_(center_) {}

Circle::Circle(float radius_, Vec2 const& center_, Color const& color_) :
	radius_(radius_),
	center_(center_),
	color_(color_) {}

//2.9
float Circle::circumference() {
	return radius_ * M_PI * 2;
}

//2.11
void Circle::draw(Window const& window, Color const& color_) const{
	for (int i = 0; i < 360; i++){
		// Grad zu Bogenmaß
		float grad1 = i * M_PI / 180.0f;
		float grad2 = (i + 1) * M_PI / 180.0f;

		window.draw_line(center_.x + (radius_*sin(grad1)), center_.y + (radius_*cos(grad1)), center_.x + (radius_*sin(grad2)), center_.y + (radius_*cos(grad2)), color_.r, color_.g, color_.b);
	}
}

//2.12
void Circle::draw(Window const& window, Color const& color_, float thickness) const {
	for (int i = 0; i < 360; i++){
		// Grad zu Bogenmaß
		float grad1 = i * M_PI / 180.0f;
		float grad2 = (i + 1) * M_PI / 180.0f;

		window.draw_line(center_.x + (radius_*sin(grad1)), center_.y + (radius_*cos(grad1)), center_.x + (radius_*sin(grad2)), center_.y + (radius_*cos(grad2)), color_.r, color_.g, color_.b, thickness);
	}
}

//2.13
bool Circle::is_inside(Vec2 const& mouse_pos) {
	bool inside = false;
	// wenn mouse_pos weiter entfernt ist vom center als der Radius, ist sie außerhalb
	float abstand = sqrt(pow((mouse_pos.x - center_.x), 2) + pow((mouse_pos.y - center_.y), 2));
	if (abstand <= radius_){
		inside = true;
	}
	return inside;
}
