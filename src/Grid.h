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

	class Grid {
	public:
		explicit Grid(int width, int height) 
			: m_Width(width)
			, m_Height(height)
			, m_Data(static_cast<size_t>(width) * static_cast<size_t>(height), ECellType::Empty)
		{
			assert(width > 0 && "Grid width must be > 0");
			assert(height > 0 && "Grid height must be > 0");
		}

		int Width() const noexcept { return m_Width; }
		int Height() const noexcept { return m_Height; }

		ECellType& At(int x, int y) {
			assert(InBounds(x, y));
			return m_Data[Index(x, y)];
		}
		const ECellType& At(int x, int y) const {
			assert(InBounds(x, y));
			return m_Data[Index(x, y)];
		}

		ECellType& AtUnchecked(int x, int y) {
			return m_Data[Index(x, y)];
		}
		const ECellType& AtUnchecked(int x, int y) const {
			return m_Data[Index(x, y)];
		}

		ECellType* Data() noexcept { return m_Data.data(); }
		const ECellType* Data() const noexcept { return m_Data.data(); }

		bool InBounds(int x, int y) const noexcept {
			return (x >= 0) && (x < m_Width) && (y >= 0) && (y < m_Height);
		}

	private:
		size_t Index(int x, int y) const noexcept {
			return static_cast<size_t>(y) * static_cast<size_t>(m_Width) + static_cast<size_t>(x);
		}

	private:
		int m_Width;
		int m_Height;
		std::vector<ECellType> m_Data;
	};
}