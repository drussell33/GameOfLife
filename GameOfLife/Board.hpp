#ifndef BOARD_HPP
#define BOARD_HPP
#include "array2d.hpp"
#include <random>
#include <windows.h>

namespace data_structures
{
	class Board
	{
	public:
		~Board() = default;
		Board(const size_t& rows, const size_t& columns);

	private:
		Array2D<char> board_;

	};

	Board::Board(const size_t& rows, const size_t& columns)
		:board_(rows* columns)
	{
	}




}
#endif