#include <cmath>
#include <iostream>
#include "Screen.hpp"

#define WIDTH	60
#define HEIGHT	60

int main()
{
	Screen screen(WIDTH, HEIGHT);
	screen.Clear();

	for (uint32_t x = 1; x <= 30; x++)
		screen.GetTile(x, x)->SetChar('#');
	// screen.Fill('#');
	// screen[630]->SetChar(' ');
	// screen.SetOrigin(WIDTH / 2, HEIGHT / 2);
	std::cin.get();
	return 0;
}
