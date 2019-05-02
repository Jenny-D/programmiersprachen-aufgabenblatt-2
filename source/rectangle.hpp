#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "vec2.hpp"

class Rectangle {
public:	Vec2 min_;
		Vec2 max_;
		Rectangle() const;
		Rectangle(Vec2 const& min_, Vec2 const& max_);
};

#endif