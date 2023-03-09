#ifndef __SCREEN_H__
#define __SCREEN_H__

#include <vector>
#include <cstdint>
#include <iostream>

#include "Tile.hpp"

class Tile;

class Screen
{
private:
	uint64_t _address_space;
	uint32_t _width, _height;
	uint32_t _origin_x, _origin_y;
	std::vector<Tile*> _display;

public:
	Screen();
	
	Screen(uint32_t width, uint32_t height);

	void SetResolution(uint32_t width, uint32_t height);

	void SetOrigin(uint32_t x, uint32_t y);

	void Fill(char bg_char);

	Tile* operator[](uint32_t address_offset);

	Tile* GetTile(uint32_t x, uint32_t y);

	void Update(Tile* tile);

	void UpdateAll();

	void Clear();

	~Screen();
};

#endif
