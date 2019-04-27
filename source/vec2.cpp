#include "vec2.hpp"
#include <iostream>
#include <cmath>

//2.2
Vec2::Vec2() :
	x(0.0f),
	y(0.0f) {}

Vec2::Vec2(float x, float y) :
	x(x),
	y(y) {}

//2.3
Vec2& Vec2::operator +=(Vec2 const& v) {
		x += v.x;
		y += v.y;
		return *this;
}

Vec2& Vec2::operator -=(Vec2 const& v) {
		x -= v.x;
		y -= v.y;
		return *this;
}

Vec2& Vec2::operator *=(float s) {
		x *= s;
		y *= s;
		return *this;
}

Vec2& Vec2::operator /=(float s) {
	if (s == 0.0f) {
		std::cout << "Die Divison durch 0 ist nicht definiert!\n";
		return *this;
	}
	else {
		x /= s;
		y /= s;
		return *this;
	}
}