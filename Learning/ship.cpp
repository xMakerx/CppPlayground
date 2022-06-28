#include <memory>
#include "ship.h"

Ship::Ship(int x, int y,
	int size, bool horizontal) : m_x(x), m_y(y),
	m_size(size), m_horizontal(horizontal)
{
	m_sunk = new bool[size];
	for (int i = 0; i < size; i++)
	{
		m_sunk[i] = false;
	}
}

bool Ship::try_hit(int x, int y)
{
	for (int i = 0; i < m_size; i++)
	{
		int c_x = m_x + (m_horizontal ? i : 0);
		int c_y = m_y + (m_horizontal ? 0 : i);

		if (x == c_x && y == c_y)
		{
			m_sunk[i] = true;
			return true;
		}
	}

	return false;
}

bool Ship::is_part_of(int x, int y)
{
	if (x == m_x && y == m_y)
		return true;

	for (int i = 0; i < m_size; i++)
	{
		int c_x = m_x + (m_horizontal ? i : 0);
		int c_y = m_y + (m_horizontal ? 0 : i);

		if (x == c_x && y == c_y)
			return true;
	}

	return false;
}

bool Ship::is_sunk()
{
	bool sunk = m_sunk[0] == true;

	for (int i = 1; i < m_size; i++)
	{
		bool b = m_sunk[i] == true;
		sunk = sunk && b;
	}

	return sunk;
}
