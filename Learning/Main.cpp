
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <ctime>
#include "ship.h"
#include "grid.h"


// Memory Address
// &var

// Pointer:
// type*
// ex: double*

// Dereference pointer (get data pointer is pointing to)
// *type
// ex: *double

bool running = true;

void _clear_console()
{
#if defined _WIN32
    system("cls");
#endif
}


int main()
{

    std::srand(time(NULL));

    Grid* grid = new Grid(5, 5, 'S');

    std::cout << "Ships: " << grid->m_num_ships << std::endl;

    while (!grid->all_ships_sunk())
    {

        grid->print();

        int x = 0, y = 0;
        std::cout << "Ship X: ";
        std::cin >> x;
        std::cout << "Ship Y: ";
        std::cin >> y;

        if (grid->within_bounds(x, y))
        {

            _clear_console();

            if (grid->handle_fire(x, y))
            {
                std::cout << "You hit something! Nice job!\n";
            }
            else
            {
                std::cout << "Hmmm....\n";
            }

            continue;
        }

        std::cout << "Invalid input!\n";
        break;

    }

    if (grid->all_ships_sunk())
        std::cout << "You win! Yay!!!";

    std::cin.get();

    return 0;
}