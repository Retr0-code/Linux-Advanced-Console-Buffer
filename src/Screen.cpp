// #include "stdafx.hpp"
#include "Screen.hpp"

Screen::Screen()
{
	_origin_x = 0;
	_origin_y = 0;

	this->SetResolution(120, 40);
}

Screen::Screen(uint32_t width, uint32_t height)
{
	_origin_x = 0;
	_origin_y = 0;

	this->SetResolution(width, height);
}

void Screen::SetResolution(uint32_t width, uint32_t height)
{
	_width = ++width;
	_height = ++height;
	_address_space = _width * _height;

	uint32_t old_size = _display.size();
	_display.resize(_address_space);

	for (uint32_t i = old_size; i < _address_space; i++)
		_display.at(i) = new Tile(this);
}

void Screen::SetOrigin(uint32_t x, uint32_t y)
{
	this->Clear();
	_origin_x = x;
	_origin_y = y;

	this->UpdateAll();
}

void Screen::Fill(char disp_char)
{
	for (uint32_t i = 0; i < _address_space; i++)
		_display[i]->SetChar(disp_char);
}

Tile* Screen::operator[](uint32_t address_offset)
{
	return _display.at(address_offset);
}

Tile* Screen::GetTile(uint32_t x, uint32_t y)
{
	return _display.at(y * _width + x);
}

void Screen::Update(Tile* tile)
{
	uint64_t offset = (reinterpret_cast<uint64_t>(tile) - reinterpret_cast<uint64_t>(_display.at(0)) - 1040) / 96;
	if (offset >= _display.size())
		offset = 0;

	std::printf("\033[%u;%uH%c",
		offset / _width + _origin_y,
		offset - (offset / _width) * _width + _origin_x,
		tile->GetChar());
}

void Screen::UpdateAll()
{
	for (auto tile : _display)
		tile->Update();
}

void Screen::Clear()
{
	std::puts("\033[2J\033[H");
}

Screen::~Screen()
{
	for (uint32_t i = 0; i < _address_space; i++)
		delete _display.at(i);

	std::puts("\033[0m");
}
