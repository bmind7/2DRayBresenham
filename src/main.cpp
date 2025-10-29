#include <iostream>
#include <random>
#include <algorithm>
#include "Grid.h"
#include "Ascii.h"
#include "Raycast.h"

using WGPrep::Grid;
using WGPrep::CreateGrid;
using WGPrep::GridAt;
using WGPrep::GridAtUnchecked;
using WGPrep::GridInBounds;
using WGPrep::OutputGrid;
using WGPrep::ECellType;
using WGPrep::FRaycastResults;
using WGPrep::LineOfSight;

inline void RandomPlacement(Grid& grid, ECellType cType, int quantity)
{
	static std::mt19937 gen{ 12345u };
	const int gridX = grid.Width;
	const int gridY = grid.Height;
	std::uniform_int_distribution<int> distX(0, gridX - 1);
	std::uniform_int_distribution<int> distY(0, gridY - 1);

	int placed = 0;
	int maxAttempts = std::max(quantity * 10, gridX * gridY);
	int attempts = 0;

	// TODO: refactor to avoid multiple attempts
	while (placed < quantity && attempts < maxAttempts)
	{
		++attempts;
		int x = distX(gen);
		int y = distY(gen);

		if (GridAtUnchecked(grid, x, y) != ECellType::Empty) continue;

		GridAt(grid, x, y) = cType;
		++placed;
	}
}

int main()
{
	Grid grid = CreateGrid(20, 20);

	const int wallCount = 20;
	RandomPlacement(grid, ECellType::Wall, wallCount);
	const int enemyCount = 5;
	RandomPlacement(grid, ECellType::Enemy, enemyCount);

	FRaycastResults results = LineOfSight(grid, 0, 0, 10, 7, true);

	OutputGrid(grid);

	return 0;
}
