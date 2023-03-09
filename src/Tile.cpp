// #include "stdafx.hpp"
#include "Tile.hpp"

Tile::Tile(Screen* screen)
// Tile::Tile()
{
	_tile = '\0';
	_fg_color = "\033[37m";
	_bg_color = "\033[40m";
	_screen = screen;
	_screen->Update(this);
}

void Tile::SetChar(char tile)
{
	_tile = tile;
	_screen->Update(this);
}

char Tile::GetChar()
{
	return _tile;
}

void Tile::Update()
{
	_screen->Update(this);
}
