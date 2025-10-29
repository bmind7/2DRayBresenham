#include "Raycast.h"
#include "Grid.h"

namespace WGPrep
{
    FRaycastResults LineOfSight(
        Grid& grid,
        int x0, int y0,
        int x1, int y1,
        bool updateGrid)
    {
        FRaycastResults out{}; // defaults ensure safe state

        // single in-bounds validation
        if (!grid.InBounds(x0, y0) || !grid.InBounds(x1, y1))
            return out; //  input invalid, early exit

        int x = x0, y = y0;
        const int dx = std::abs(x1 - x0);
        const int dy = std::abs(y1 - y0);
        const int sx = (x1 >= x0) ? 1 : -1;
        const int sy = (y1 >= y0) ? 1 : -1;
        // error: F(x,y)=dy*(x-x0)-dx*(y-y0)
        int err = dx - dy;

        bool skipStart = true;

        while (true)
        {
            if (!skipStart && grid.At(x, y) != ECellType::Empty)
            {
                out.IsVisible = false;
                out.HitX = x;
                out.HitY = y;
                return out; //  blocked, exit
            }
            skipStart = false;

            if (x == x1 && y == y1)
            {
                out.IsVisible = true;
                return out; //  success exit
            }

            if (updateGrid && grid.At(x, y) == ECellType::Empty)
                grid.At(x, y) = ECellType::Ray;

            const int e2 = err << 1;

            if (e2 > -dy) { err -= dy; x += sx; }
            if (e2 < dx) { err += dx; y += sy; }

            ++out.Steps;
        }
    }

}