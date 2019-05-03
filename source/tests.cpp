#define CATCH_CONFIG_RUNNER
#define _USE_MATH_DEFINES
#include <catch.hpp>
#include "vec2.hpp"
#include "mat2.hpp"
#include "color.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

//2.2
TEST_CASE("testing_initialization", "[testing_initialization]")
{
	Vec2 a;
	Vec2 b{ 5.1f, -9.3f };

	REQUIRE(0.0f == Approx(a.x));
	REQUIRE(0.0f == Approx(a.y));
	REQUIRE(5.1f == Approx(b.x));
	REQUIRE(-9.3f == Approx(b.y));
}

//2.3
TEST_CASE("testing_Vecoperator+=", "[testing_Vecoperator+=]")
{
	Vec2 a{ 0.0f, -2.0f };
	Vec2 b{ 3.3f, 6.6f };
	Vec2 c{ 5.7f, 7.3f };

	a += b;
	REQUIRE(a.x == Approx(3.3f));
	REQUIRE(a.y == Approx(4.6f));

	b += c;
	REQUIRE(b.x == Approx(9.0f));
	REQUIRE(b.y == Approx(13.9f));

	c += a;
	REQUIRE(c.x == Approx(5.7f));
	REQUIRE(c.y == Approx(5.3f));
}

TEST_CASE("testing_Vecoperator-=", "[testing_Vecoperator-=]")
{
	Vec2 a{ 0.0f, -2.0f };
	Vec2 b{ 3.3f, 6.6f };
	Vec2 c{ 5.7f, 7.3f };

	a -= b;
	REQUIRE(a.x == Approx(-3.3f));
	REQUIRE(a.y == Approx(-8.6f));

	b -= c;
	REQUIRE(b.x == Approx(-2.4f));
	REQUIRE(b.y == Approx(-0.7f));

	c -= a;
	REQUIRE(c.x == Approx(5.7f));
	REQUIRE(c.y == Approx(9.3f));
}

TEST_CASE("testing_Vecoperator*=", "[testing_Vecoperator*=]")
{
	Vec2 a{ 5.0f, 4.0f };
	float s1(3.0f);
	float s2(0.0f);
	float s3(-2.0f);

	a *= s1;
	REQUIRE(a.x == Approx(15.0f));
	REQUIRE(a.y == Approx(12.0f));

	a *= s2;
	REQUIRE(a.x == Approx(0.0f));
	REQUIRE(a.y == Approx(0.0f));

	a *= s3;
	REQUIRE(a.x == Approx(-10.0f));
	REQUIRE(a.y == Approx(-8.0f));
}

TEST_CASE("testing_Vecoperator/=", "[testing_Vecoperator/=]")
{
	Vec2 a{ 4.0f, 7.0f };
	float s1(0.0f);
	float s2(2.0f);
	float s3(-2.0f);

	a /= s1;
	REQUIRE("Die Division durch 0 ist nicht definiert.\n");

	a /= s2;
	REQUIRE(a.x == Approx(2.0f));
	REQUIRE(a.y == Approx(3.5f));

	a /= s3;
	REQUIRE(a.x == Approx(-2.0f));
	REQUIRE(a.y == Approx(-3.5f));
}

//2.4
TEST_CASE("testing_Vecoperator+", "[testing_Vecoperator+]")
{
	Vec2 a;
	Vec2 u{ 0.0f, -2.0f };
	Vec2 v{ 3.3f, 6.6f };
	Vec2 w{ 5.7f, 7.3f };

	u + v;
	REQUIRE(a.x == Approx(3.3f));
	REQUIRE(a.y == Approx(4.6f));

	v + w;
	REQUIRE(a.x == Approx(9.0f));
	REQUIRE(a.y == Approx(13.9f));

	w + u;
	REQUIRE(a.x == Approx(5.7f));
	REQUIRE(a.y == Approx(5.3f));
}

TEST_CASE("testing_Vecoperator-", "[testing_Vecoperator-]")
{
	Vec2 a;
	Vec2 u{ 0.0f, -2.0f };
	Vec2 v{ 3.3f, 6.6f };
	Vec2 w{ 5.7f, 7.3f };

	u - v;
	REQUIRE(a.x == Approx(-3.3f));
	REQUIRE(a.y == Approx(-8.6f));

	v - w;
	REQUIRE(a.x == Approx(-2.4f));
	REQUIRE(a.y == Approx(-0.7f));

	w - u;
	REQUIRE(a.x == Approx(5.7f));
	REQUIRE(a.y == Approx(9.3f));
}

TEST_CASE("testing_Vecoperator*", "[testing_Vecoperator*]")
{
	Vec2 a;
	Vec2 v{ 5.0f, 4.0f };
	float s1(3.0f);
	float s2(0.0f);
	float s3(-2.0f);

	v * s1;
	REQUIRE(a.x == Approx(15.0f));
	REQUIRE(a.y == Approx(12.0f));

	v * s2;
	REQUIRE(a.x == Approx(0.0f));
	REQUIRE(a.y == Approx(0.0f));

	v * s3;
	REQUIRE(a.x == Approx(-10.0f));
	REQUIRE(a.y == Approx(-8.0f));

	s1 * v;
	REQUIRE(a.x == Approx(15.0f));
	REQUIRE(a.y == Approx(12.0f));

	s2 * v;
	REQUIRE(a.x == Approx(0.0f));
	REQUIRE(a.y == Approx(0.0f));

	s3 * v;
	REQUIRE(a.x == Approx(-10.0f));
	REQUIRE(a.y == Approx(-8.0f));
}

TEST_CASE("testing_Vecoperator/", "[testing_Vecoperator/]")
{
	Vec2 a;
	Vec2 v{ 4.0f, 7.0f };
	float s1(0.0f);
	float s2(2.0f);
	float s3(-2.0f);

	v / s1;
	REQUIRE("Die Division durch 0 ist nicht definiert.\n");

	v / s2;
	REQUIRE(a.x == Approx(2.0f));
	REQUIRE(a.y == Approx(3.5f));

	v / s3;
	REQUIRE(a.x == Approx(-2.0f));
	REQUIRE(a.y == Approx(-3.5f));
}

//2.5
TEST_CASE("testing_Matoperator*=", "[testing_Matoperator*=]") {
	Mat2 m1{ 0.0f, 0.0f, 0.0f, 0.0f };
	Mat2 m2{ 2.0f, 2.0f, 3.0f, 5.0f };
	Mat2 m3{ 1.5f, 1.0f, 0.0f, -3.0f };

	m1 *= m2;
	REQUIRE(m1.e_00 == 0.0f);
	REQUIRE(m1.e_01 == 0.0f);
	REQUIRE(m1.e_10 == 0.0f);
	REQUIRE(m1.e_11 == 0.0f);

	m3 *= m2;
	REQUIRE(m3.e_00 == 6.0f);
	REQUIRE(m3.e_01 == 8.0f);
	REQUIRE(m3.e_10 == -9.0f);
	REQUIRE(m3.e_11 == -15.0f);
}

TEST_CASE("testing_Matoperator*", "[testing_Matoperator*]") {
	Mat2 m1{ 0.0f, 0.0f, 0.0f, 0.0f };
	Mat2 m2{ 2.0f, 2.0f, 3.0f, 5.0f };
	Mat2 m3{ 1.5f, 1.0f, 0.0f, -3.0f };

	m1 *= m2;
	REQUIRE(m1.e_00 == 0.0f);
	REQUIRE(m1.e_01 == 0.0f);
	REQUIRE(m1.e_10 == 0.0f);
	REQUIRE(m1.e_11 == 0.0f);

	m3 *= m2;
	REQUIRE(m3.e_00 == 6.0f);
	REQUIRE(m3.e_01 == 8.0f);
	REQUIRE(m3.e_10 == -9.0f);
	REQUIRE(m3.e_11 == -15.0f);
}

//2.6
TEST_CASE("testing_Det", "[testing_Det]") {
	Mat2 m1{ 0.0f, 0.0f, 0.0f, 0.0f };
	Mat2 m2{ 1.0f, 2.0f, 3.0f, 4.0f };

	REQUIRE(m1.det() == 0.0f);
	REQUIRE(m2.det() == -2.0f);
}

TEST_CASE("testing_MatVecOperator*", "[testing_MatVecOperator*]") {
	Mat2 m1{ 0.0f, 0.0f, 0.0f, 0.0f };
	Mat2 m2{ 2.0f, 2.0f, 3.0f, 5.0f };
	Mat2 m3{ 1.5f, 1.0f, 0.0f, -3.0f };
	Vec2 v1{ 0.0f, 0.5f };
	Vec2 v2{ 3.0f, 2.0f };
	Vec2 v3{ -1.0f, 5.0f };

	v1 * m2;
	REQUIRE(v1.x == 1.0f);
	REQUIRE(v1.y == 2.5f);

	m1 * v2;
	REQUIRE(v2.x == 0.0f);
	REQUIRE(v2.y == 0.0f);

	m3 * v3;
	REQUIRE(v3.x == 3.5);
	REQUIRE(v3.y == -15.0f);
}

TEST_CASE("testing_Inv", "[testing_Inv]") {
	Mat2 m1;
	Mat2 m2{ 5.0f, 3.0f, 4.5f, 2.0f };
	Mat2 m3{ -1.0f, -4.5f, 5.0f, 0.0f };

	m1 = inverse(m2);
	REQUIRE(m1.e_00 == Approx(-0.571429f));
	REQUIRE(m1.e_01 == Approx(0.857143f));
	REQUIRE(m1.e_10 == Approx(1.28571f));
	REQUIRE(m1.e_11 == Approx(-1.42857f));

	m1 = inverse(m3);
	REQUIRE(m1.e_00 == Approx(0.0f));
	REQUIRE(m1.e_01 == Approx(0.2f));
	REQUIRE(m1.e_10 == Approx(-0.2222222f));
	REQUIRE(m1.e_11 == Approx(-0.04444f));
}

TEST_CASE("testing_Trans", "[testing_Trans]") {
	Mat2 m1;
	Mat2 m2{ 2.0f, 3.0f, 1.0f, 4.0f };
	Mat2 m3{ 7.0f, 2.0f, -6.0f, -1.0f };

	m1 = transpose(m2);
	REQUIRE(m1.e_01 == 4.0f);
	REQUIRE(m1.e_11 == 3.0f);

	m1 = transpose(m3);
	REQUIRE(m1.e_01 == -1.0f);
	REQUIRE(m1.e_11 == 2.0f);
}

TEST_CASE("testing_Rotat", "[testing_Rotat]") {
	float phi1 = 2 * M_PI;
	float phi2 = M_PI;
	Mat2 rotation;

	rotation = make_rotation_mat2(phi1);
	REQUIRE(rotation.e_00 == Approx(-0.28369f));
	REQUIRE(rotation.e_01 == Approx(-0.958916f));
	REQUIRE(rotation.e_10 == Approx(0.958916f));
	REQUIRE(rotation.e_11 == Approx(-0.28369f));

	rotation = make_rotation_mat2(phi2);
	REQUIRE(rotation.e_00 == Approx(-0.59846f));
	REQUIRE(rotation.e_01 == Approx(0.801153f));
	REQUIRE(rotation.e_10 == Approx(-0.801153f));
	REQUIRE(rotation.e_11 == Approx(-0.59846f));
}

//2.7
TEST_CASE("testing_Color", "[testing_Color]") {
	Color c;
	REQUIRE(Approx(0.5f) == c.r);
	REQUIRE(Approx(0.5f) == c.g);
	REQUIRE(Approx(0.5f) == c.b);

	Color c2{1.0f, 0.7f, 0.0f};
	REQUIRE(Approx(1.0f) == c2.r);
	REQUIRE(Approx(0.7f) == c2.g);
	REQUIRE(Approx(0.0f) == c2.b);
}

TEST_CASE("testing_CircleCircumference", "[testing_CircleCircumference]"){
	Vec2 center1{ 4.5f, 4.5f };
	Vec2 center2{ 5.5f, 5.5f };
	Circle c1(4.0f, center1);
	Circle c2(5.0f, center2);
	float u1;
	float u2;

	u1 = c1.circumference();
	REQUIRE(u1 == Approx(25.1327f));

	u2 = c2.circumference();
	REQUIRE(u2 == Approx(31.4159f));
}

/*TEST_CASE("testing_RectangleCircumference", "[testing_RectangleCircumference]") {
	Vec2 v1{ 5.0f, 5.0f };
	Vec2 v2{ 0.0f, 4.0f };
	Vec2 v3{ 3.0f, 2.0f };
	Vec2 v4{ -0.5f, 1.0f };
	Rectangle r1(v1, v2);
	Rectangle r2(v3, v4);

	float u1;
	float u2;

	u1 = r1.circumference();
	REQUIRE(u1 == 12.0f);

	u2 = r2.circumference();
	REQUIRE(u2 == 9.0f);
}*/

int main(int argc, char *argv[])
{
	return Catch::Session().run(argc, argv);
}