#pragma once

namespace WGPrep
{
	class Grid;

	struct FRaycastResults {
		bool IsVisible = false;
		int HitX = -1;
		int HitY = -1;
		// Debug
		int Steps = 0;
	};

	FRaycastResults LineOfSight(
		Grid& grid,
		int x0, int y0,
		int x1, int y1,
		bool updateGrid);
}

