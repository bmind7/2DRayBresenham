#pragma once
#include <iostream>
#include <cstdint>
#include "Grid.h"

namespace WGPrep
{
	inline void OutputGrid(const Grid& grid)
	{
		const int gridY = grid.Height;
		const int gridX = grid.Width;

		for (int y = 0; y < gridY; ++y)
		{
			for (int x = 0; x < gridX; ++x) 
			{
				char symbol = '?';
				switch (GridAt(grid, x, y))
				{
				case ECellType::Empty: symbol = '.'; break;
				case ECellType::Wall: symbol = '#'; break;
				case ECellType::Enemy: symbol = 'E'; break;
				case ECellType::Ray: symbol = '*'; break;
				}
				std::cout << symbol << " ";
			}
			std::cout << "\n";
		}
	}
}
