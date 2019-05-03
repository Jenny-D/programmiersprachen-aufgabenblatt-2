#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "vec2.hpp"
#include "color.hpp"

class Rectangle {
public:	Vec2 min_;
		Vec2 max_;
		Color color;
		Rectangle();
		Rectangle(Vec2 const& min_, Vec2 const& max_);
		Rectangle(Vec2 const& min_, Vec2 const& max_, Color color);
		float circumference();
};

#endif