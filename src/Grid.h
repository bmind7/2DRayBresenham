#pragma once
#include <vector>
#include <cstdint>
#include <cassert>
#include <cstddef>

namespace WGPrep {
	enum class ECellType : uint8_t
	{
		Empty = 0,
		Wall = 1,
		Enemy = 2,
		Ray = 3
	};

	// Data-oriented: Pure data structure
	struct Grid {
		int Width;
		int Height;
		std::vector<ECellType> Data;
	};

	// Data-oriented: Free functions for operations
	inline Grid CreateGrid(int width, int height) {
		assert(width > 0 && "Grid width must be > 0");
		assert(height > 0 && "Grid height must be > 0");

		Grid grid;
		grid.Width = width;
		grid.Height = height;
		grid.Data.resize(static_cast<size_t>(width) * static_cast<size_t>(height), ECellType::Empty);
		return grid;
	}

	inline size_t GridIndex(const Grid& grid, int x, int y) noexcept {
		return static_cast<size_t>(y) * static_cast<size_t>(grid.Width) + static_cast<size_t>(x);
	}

	inline bool GridInBounds(const Grid& grid, int x, int y) noexcept {
		return (x >= 0) && (x < grid.Width) && (y >= 0) && (y < grid.Height);
	}

	inline ECellType& GridAt(Grid& grid, int x, int y) {
		assert(GridInBounds(grid, x, y));
		return grid.Data[GridIndex(grid, x, y)];
	}

	inline const ECellType& GridAt(const Grid& grid, int x, int y) {
		assert(GridInBounds(grid, x, y));
		return grid.Data[GridIndex(grid, x, y)];
	}

	inline ECellType& GridAtUnchecked(Grid& grid, int x, int y) {
		return grid.Data[GridIndex(grid, x, y)];
	}

	inline const ECellType& GridAtUnchecked(const Grid& grid, int x, int y) {
		return grid.Data[GridIndex(grid, x, y)];
	}
}