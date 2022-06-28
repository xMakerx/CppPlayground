#include "grid.h"

Grid::Grid(int width, int height, char ship_char) :
	m_width(width), m_height(height), SHIP_CHAR(ship_char)
{
	// Width * Height
	m_tiles = new char[width * height];
	memset(m_tiles, 'O', (size_t)(width * height));
	_place_ships();
}

void Grid::print(const bool reveal_ships) const
{
	for (int y = 0; y < m_height; y++)
	{
		for (int x = 0; x < m_width; x++)
		{
			char c = get_at(x, y);

			if (c == SHIP_CHAR && !reveal_ships)
			{
				c = 'O';
			}

			std::cout << c;

			if ((x + 1) != m_width)
				std::cout << " ";
		}

		std::cout << std::endl;
	}
}

void Grid::print() const
{
	print((WANT_CHEATS == 1));
}

void Grid::set_char_at(int x, int y, char c)
{
	m_tiles[x + (y * m_height)] = c;
}

bool Grid::handle_fire(int x, int y)
{
	for (int i = 0; i < m_num_ships; i++)
	{
		Ship* ship = m_ships[i];

		if (ship->is_part_of(x, y))
		{
			ship->try_hit(x, y);
			set_char_at(x, y, 'X');
			return true;
		}
	}

	return false;
}

bool Grid::all_ships_sunk()
{
	bool all_sunk = m_ships[0]->is_sunk();

	for (int i = 1; i < m_num_ships; i++)
	{
		bool sunk = m_ships[i]->is_sunk();
		all_sunk = all_sunk && sunk;
	}

	return all_sunk;
}

char& Grid::get_at(int x, int y) const
{
	return m_tiles[x + (y * m_height)];
}

bool Grid::within_bounds(int x, int y) const
{
	return (x > -1 && x < m_width&& y > -1 && y < m_height);
}

void Grid::_place_ships() 
{

	// Can spawn between 1 and 4 ships
	int num_ships = rand() % 4 + 1;

	m_ships[num_ships];
	m_num_ships = num_ships;

	for (int i = 0; i < num_ships; i++)
	{
		int x = rand() % m_width;
		int y = rand() % m_height;

		int h = m_width - x;
		int v = m_height - y;

		int size = rand() % std::max(h, v) + 1;

		bool horizontal = (x + size) < m_width;

		if (WANT_CHEATS == 1)
			std::cout << "Ship: " << x << ", " << y << ", size: " << size << ", hor: " << horizontal << std::endl;

		m_ships[i] = new Ship(x, y, size, horizontal);

		for (int j = 0; j < size; j++)
		{
			set_char_at(x, y, SHIP_CHAR);
			x += (horizontal) ? 1 : 0;
			y += (horizontal) ? 0 : 1;
		}

	}

}
