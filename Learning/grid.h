#pragma once
#include <memory>
#include <iostream>
#include "ship.h"

#define WANT_CHEATS 1

class Grid
{

public:

	size_t m_num_ships;
	const int m_width;
	const int m_height;
	const char SHIP_CHAR;

	Grid(int width, int height, char ship_char);

	Grid(Grid& other) = delete;

	void print(const bool reveal_ships) const;

	void print() const;

	void set_char_at(int x, int y, char c);

	bool handle_fire(int x, int y);

	bool all_ships_sunk();

	char& get_at(int x, int y) const;

	char& operator()(int x, int y) const
	{
		return get_at(x, y);
	}

	bool within_bounds(int x, int y) const;

private:
	char* m_tiles;
	Ship* m_ships[];

	void _place_ships();
};