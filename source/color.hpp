#ifndef COLOR_HPP
#define COLOR_HPP

struct Color{
	float r = 0.5f;
	float g = 0.5f;
	float b = 0.5f;

	/*Color(float r, float g, float b) {
		if (r > 1 || r < 0 || b>1 || b < 0 || g>1 || g < 0) {
			std::cout << "Eingabe muss zwischen 0 und 1 liegen!\n";
			throw;
		}
	}*/
};

#endif