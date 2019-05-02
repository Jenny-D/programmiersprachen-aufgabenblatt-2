#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "vec2.hpp"

class Circle {
public:	float radius_;
		Vec2 center_;
		Circle() const;
		Circle(float radius_, Vec2 const& center_);
};

#endif