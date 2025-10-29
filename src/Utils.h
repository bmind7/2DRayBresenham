#pragma once
#include <vector>
#include <random>
#include <algorithm>
#include <cstring>
#include "Grid.h"

namespace WGPrep
{
    inline void RandomPlacement(Grid& grid, ECellType cType, int quantity)
    {
        if (quantity <= 0) return;

        const size_t n = grid.Data.size();

        // Collect indices of empty cells in one linear pass
        std::vector<size_t> empties;
        empties.reserve(n);

        const ECellType* read = grid.Data.data(); // pointer from Grid::Data()
        for (size_t i = 0; i < n; ++i)
            if (read[i] == ECellType::Empty)
                empties.push_back(i);

        if (empties.empty()) return;
        if (static_cast<size_t>(quantity) > empties.size())
            quantity = static_cast<int>(empties.size());

        static std::mt19937 gen{ 12345u };
        std::shuffle(empties.begin(), empties.end(), gen);

        // Scatter writes (not vectorizable, but fine for small counts)
        ECellType* write = grid.Data.data();
        for (int i = 0; i < quantity; ++i)
            write[empties[static_cast<size_t>(i)]] = cType;
    }
}
