#ifndef GAME_OF_LIFE_HPP
#define GAME_OF_LIFE_HPP
#include "array2d.hpp"
#include <random>
#include <string>
#include <windows.h>
#include <conio.h>
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

namespace data_structures
{

	class GameOfLife
	{
	public:
		~GameOfLife() = default;
		GameOfLife();
		void Print();
		void UpDate();
		bool getState(int row, int column);
		void iterate(int iterations);
		void SetPauseTime();
		char playAgain();

	private:
		Array2D<bool> board_;
		Array2D<bool> next_board_;
		//char cell_;
		int pause_time_{ 0 };

	};

	GameOfLife::GameOfLife()
	{
		board_ = Array2D<bool>(30, 30);
		next_board_ = Array2D<bool>(30, 30);
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(0, 1);


		for (auto i = 0; i < 30; ++i)
		{
			for (auto j = 0; j < 30; ++j)
			{
				if (dis(gen) == 1)
				{
					board_[i][j] = true;
					next_board_[i][j] = true;
				}
				else
				{
					board_[i][j] = false;
					next_board_[i][j] = false;
				}
			}
		}
	}

	inline void GameOfLife::Print()
	{
		for (auto i = 0; i < 30; ++i)
		{
			for (auto j = 0; j < 30; ++j)
			{
				if (board_[i][j] == true)
				{
					cout << 'X' << ' ';
				}
				else
				{
					cout << '.' << ' ';
				}
			}
			cout << endl;
		}
	}


	inline bool GameOfLife::getState(int row, int column)
	{
		int neighbors = 0;

		for (auto i = row - 1; i <= row + 1; i++)
		{
			for (auto j = column - 1; j <= column + 1; j++)
			{
				if (i == row && j == column)
				{
					continue;
				}

				if (i > -1 && i < 30 && j > -1 && j < 30)
				{
					if (board_[i][j] == true)
					{
						neighbors++;
					}
				}
			}
		}

		if (board_[row][column])
		{
			if (neighbors < 2 || neighbors > 3)
				return false;
			if (neighbors == 3 || neighbors == 2)
				return true;
		}

		if (board_[row][column] == false)
		{
			if (neighbors < 3 || neighbors > 3)
				return false;
			if (neighbors == 3)
				return true;
		}

	}

	inline void GameOfLife::UpDate()
	{
		auto debug = 0;

		int stag_count = 15;
		do
		{
			int now = 0;
			int previous = 0;
			for (auto i = 0; i < 30; i++)
			{
				for (auto j = 0; j < 30; j++)
				{
					next_board_[i][j] = getState(i, j);
				}
			}

			for (auto i = 0; i < 30; i++)
			{
				for (auto j = 0; j < 30; j++)
				{
					if (board_[i][j] == true)
					{
						previous++;
					}
				}
			}
			board_ = next_board_;

			for (auto i = 0; i < 30; i++)
			{
				for (auto j = 0; j < 30; j++)
				{
					if (board_[i][j] == true)
					{
						now++;
					}
				}
			}

			if (now - previous == 0)
			{
				stag_count--;
			}
			debug++;
			cout << "Generation " << debug << " " << endl;
			Print();
			cout << " ";

			if (_kbhit() != 0)
			{
				const char key = std::cin.get();
				if (key == 'x')
				{
					break;
				}
			}

		} while (stag_count > 0);
	}

	inline void GameOfLife::iterate(int iterations)
	{
		// couldnt figure out how to 
	}

	inline void GameOfLife::SetPauseTime()
	{
		cout << "\n\nWelcome to the Game of Life Implementation!: \n\n";
		cout << "\nIf you wish to end the Game of Life early, press 'x' then enter. \n\n";
		int user_time;
		cout << "Enter the Desired Pause Time (milliseconds) in between generations (0 - 5000): ";
		cin >> user_time;

		if (user_time < 0 || user_time > 5000)
			throw AdtException("WRONG!");

		pause_time_ = user_time;

	}

}
#endif
