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


