#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"

class Rectangle {
public:	Rectangle();
		Rectangle(Vec2 const& min_, Vec2 const& max_);
		Rectangle(Vec2 const& min_, Vec2 const& max_, Color const& color_);
		float circumference() const;
		void draw(Window const& window, Color const& color_) const;
		void draw(Window const& window, Color const& color_, float thickness) const;
		bool is_inside(Vec2 const& mouse_pos) const;

private: Vec2 min_;
		 Vec2 max_;
		 Color color_;
};

#endif