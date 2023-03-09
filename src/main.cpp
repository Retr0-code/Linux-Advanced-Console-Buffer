#include <cmath>
#include <unistd.h>
#include <iostream>
#include "Screen.hpp"

#define WIDTH		80
#define HEIGHT		40
#define RADIUS		10
#define RATIO		0.6
#define SCREEN_W	110

int main()
{
	Screen screen(WIDTH, HEIGHT);
	screen.Clear();
	screen.Fill('@');

	for (uint32_t x = 0; x <= 10; x++)
	{
		screen.GetTile(x + 40, std::sqrt(RADIUS * RADIUS - x * x) * RATIO + 10)->SetChar(' ');
		screen.GetTile(x + 40, -std::sqrt(RADIUS * RADIUS - x * x) * RATIO + 10)->SetChar(' ');
		screen.GetTile(-x + 40, std::sqrt(RADIUS * RADIUS - x * x) * RATIO + 10)->SetChar(' ');
		screen.GetTile(-x + 40, -std::sqrt(RADIUS * RADIUS - x * x) * RATIO + 10)->SetChar(' ');
	}
	
	while (true)
	{
		for (uint32_t x = 0; x <= SCREEN_W - WIDTH; x++)
		{
			screen.SetOrigin(x, 0);
			usleep(100000 / 30.f);
		}

		usleep(100000);

		for (uint32_t x = SCREEN_W - WIDTH; x >= 1; x--)
		{
			screen.SetOrigin(x, 0);
			usleep(100000 / 30.f);
		}
	}

	std::cin.get();
	return 0;
}
