#include "mat2.hpp"
#include "vec2.hpp"
#include <cmath>

//2.5
Mat2& Mat2::operator*=(Mat2 const& m) {
	float x1 = e_00 * m.e_00 + e_01 * m.e_10;
	float x2 = e_00 * m.e_01 + e_01 * m.e_11;
	float y1 = e_10 * m.e_00 + e_11 * m.e_10;
	float y2 = e_10 * m.e_01 + e_11 * m.e_11;
	e_00 = x1;
	e_01 = x2;
	e_10 = y1;
	e_11 = y2;
	return *this;
}

Mat2 operator*(Mat2 const& m1, Mat2 const& m2) {
	Mat2 m3;

	m3.e_00 = m1.e_00 * m2.e_00 + m1.e_01 * m2.e_10; 
	m3.e_01 = m1.e_00 * m2.e_01 + m1.e_01 * m2.e_11;
	m3.e_10 = m1.e_10 * m2.e_00 + m1.e_11 * m2.e_10;
	m3.e_11 = m1.e_10 * m2.e_01 + m1.e_11 * m2.e_11;
	return m3;
}