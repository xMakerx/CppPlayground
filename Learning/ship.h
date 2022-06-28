#pragma once
#include <iostream>

struct Ship
{

public:
	int m_x, m_y, m_size;
	bool m_horizontal;
	bool* m_sunk;

	Ship() : m_x(-1), m_y(-1), m_size(0), m_horizontal(false), m_sunk()
	{
		std::cout << "This is the default constructor!" << std::endl;
	}

	Ship(int x, int y, int size, bool horizontal);

	bool try_hit(int, int);

	bool is_part_of(int, int);

	bool is_sunk();

	Ship(const Ship& other) = delete;

};