#ifndef __TILE_H__
#define __TILE_H__

// #include "stdafx.hpp"

#include <string>
#include "Screen.hpp"

class Screen;

class Tile
{
private:
	char _tile;
	std::string _fg_color;
	std::string _bg_color;
	Screen* _screen;

public:
	// Tile();
	Tile(Screen* screen);

	void SetChar(char tile);

	char GetChar();

	void Update();
};

#endif
