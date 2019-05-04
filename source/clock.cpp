#define _USE_MATH_DEFINES
#include "window.hpp"
#include "circle.hpp"
#include "color.hpp"
#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>

int main(int argc, char* argv[]) {

	Window win{ std::make_pair(800,800) };
	Vec2 center{ 400.0f, 400.0f };
	Circle clock(200.0f, center);
	Color clockColor{ 1.0f, 1.0f, 1.0f };

	while (!win.should_close()) {
		if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
			win.close();
		}

		float t = win.get_time();

		clock.draw(win, clockColor);

		Vec2 s{ (float)sin((2 * t*M_PI) / 60) * 190,(float)-cos((2 * t*M_PI) / 60) * 190 };
		Vec2 m{ (float)sin((2 * t*M_PI) / 3600) * 150,(float)-cos((2 * t*M_PI) / 3600) * 150 };
		Vec2 h{ (float)sin((2 * t*M_PI) / (43200)) * 110,(float)-cos((2 * t*M_PI) / (43200)) * 110 };

		s += center;
		m += center;
		h += center;

		win.draw_line(center.x, center.y, s.x, s.y, 0.5, 0.0, 0.5);
		win.draw_line(center.x, center.y, m.x, m.y, 0.8, 0.4, 0.2);
		win.draw_line(center.x, center.y, h.x, h.y, 0.0, 1.0, 0.0);

		win.update();
	}
	return 0;
}