#define _USE_MATH_DEFINES
#include "mat2.hpp"
#include <iostream>
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

//2.6
float Mat2::det() const {
	float det = e_00 * e_11 - e_10 * e_01;
	return det;
}

Vec2 operator*(Mat2 const& m, Vec2 const& v) {
	Vec2 v2;

	v2.x = m.e_00 * v.x + m.e_01 * v.y;
	v2.y = m.e_10 * v.x + m.e_11 * v.y;
	return v2;
}

Vec2 operator*(Vec2 const& v, Mat2 const& m) {
	std::cout << "Falsche Reihenfolge! Matrix * Vektor!\n";
	return m * v;
}

Mat2 inverse(Mat2 const& m) {
	Mat2 invM;

	invM.e_00 = m.e_11;
	invM.e_01 = m.e_01 * -1.0f;
	invM.e_10 = m.e_10 * -1.0f;
	invM.e_11 = m.e_00;

	float a = 1.0f / (invM.e_00 * invM.e_11 - invM.e_01 * invM.e_10);

	invM.e_00 *= a;
	invM.e_01 *= a;
	invM.e_10 *= a;
	invM.e_11 *= a;

	return invM;
}

Mat2 transpose(Mat2 const& m) {
	Mat2 m2;

	m2.e_01 = m.e_11;
	m2.e_11 = m.e_01;

	return m2;
}

Mat2 make_rotation_mat2(float phi) {
	float alpha = (360.0f / (2.0f * M_PI)) * phi;
	Mat2 rotation_matrix;
	rotation_matrix.e_00 = cos(alpha);
	rotation_matrix.e_01 = -sin(alpha);
	rotation_matrix.e_10 = sin(alpha);
	rotation_matrix.e_11 = cos(alpha);
	return rotation_matrix;
}