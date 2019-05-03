#include "window.hpp"
#include "circle.hpp"
#include "color.hpp"

int main(int argc, char* argv[]) {

	Window win{ std::make_pair(800,800) };
	Vec2 center{ 400.0f, 400.0f };
	Circle clock(200.0f, center);
	Color clockColor{ 1.0f, 1.0f, 1.0f };


}