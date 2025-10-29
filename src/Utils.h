#pragma once
#include <vector>
#include <random>
#include <algorithm>
#include "Grid.h"

namespace WGPrep
{
	inline void RandomPlacement(Grid& grid, ECellType cType, int quantity)
	{
		static std::mt19937 gen{ 12345u };

		// Gather all empty cell indices by iterating Data directly
		std::vector<size_t> emptyCellIndices;
		emptyCellIndices.reserve(grid.Data.size());

		const size_t dataSize = grid.Data.size();

		for (size_t i = 0; i < dataSize; ++i)
		{
			if (grid.Data[i] == ECellType::Empty)
			{
				emptyCellIndices.push_back(i);
			}
		}

		std::shuffle(emptyCellIndices.begin(), emptyCellIndices.end(), gen);

		// Place cells (limited by available empty cells)
		const int cellsToPlace = std::min(quantity, static_cast<int>(emptyCellIndices.size()));

		for (int i = 0; i < cellsToPlace; ++i)
		{
			grid.Data[emptyCellIndices[i]] = cType;
		}
	}
}
