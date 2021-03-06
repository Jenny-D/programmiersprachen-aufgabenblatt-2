#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"

class Circle {
public:	Circle();
		Circle(float radius_, Vec2 const& center_);
		Circle(float radius_, Vec2 const& center_, Color const& color_);
		float circumference() const;
		void draw(Window const& window, Color const& color_) const;
		void draw(Window const& window, Color const& color_, float thickness) const;
		bool is_inside(Vec2 const& mouse_pos) const;

private: float radius_;
		 Vec2 center_;
		 Color color_;
};

#endif