#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"

class Circle {
public:	float radius_;
		Vec2 center_;
		Color color_;
		Circle();
		Circle(float radius_, Vec2 const& center_);
		Circle(float radius_, Vec2 const& center_, Color const& color_);
		float circumference();
		void draw(Window const& window, Color const& color_) const;
};

#endif