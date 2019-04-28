#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}

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
	Vec2 a(0.0f, -2.0f);
	Vec2 b(3.3f, 6.6f);
	Vec2 c(5.7f, 7.3f);

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
	Vec2 a(0.0f, -2.0f);
	Vec2 b(3.3f, 6.6f);
	Vec2 c(5.7f, 7.3f);

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
	Vec2 a(5.0f, 4.0f);
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
	Vec2 a(4.0f, 7.0f);
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
	Vec2 u(0.0f, -2.0f);
	Vec2 v(3.3f, 6.6f);
	Vec2 w(5.7f, 7.3f);

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
	Vec2 u(0.0f, -2.0f);
	Vec2 v(3.3f, 6.6f);
	Vec2 w(5.7f, 7.3f);

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
	Vec2 v(5.0f, 4.0f);
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
}

TEST_CASE("testing_Vecoperator*", "[testing_Vecoperator*]")
{
	Vec2 a;
	Vec2 v(5.0f, 4.0f);
	float s1(3.0f);
	float s2(0.0f);
	float s3(-2.0f);

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
	Vec2 v(4.0f, 7.0f);
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