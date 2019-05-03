#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "vec2.hpp"
#include "color.hpp"

class Circle {
public:	float radius_;
		Vec2 center_;
		Color color;
		Circle();
		Circle(float radius_, Vec2 const& center_);
		Circle(float radius_, Vec2 const& center_, Color color);
		float circumference();
};

#endif