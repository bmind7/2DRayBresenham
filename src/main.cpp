#include <iostream>
#include <random>
#include <algorithm>
#include "Grid.h"
#include "Ascii.h"
#include "Raycast.h"
#include "Utils.h"

using WGPrep::Grid;
using WGPrep::CreateGrid;
using WGPrep::OutputGrid;
using WGPrep::ECellType;
using WGPrep::FRaycastResults;
using WGPrep::LineOfSight;
using WGPrep::RandomPlacement;

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
