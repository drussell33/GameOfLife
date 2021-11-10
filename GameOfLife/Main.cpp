#include "array2d.hpp"
#include "Game_Of_Life.hpp"
using namespace data_structures;

int main()
{

	bool PlayAgain = true;

	while (PlayAgain)
	{
		auto newGame = GameOfLife();
		newGame.SetPauseTime();

		newGame.Print();
		newGame.UpDate();


		char ending;
		cout << "\n\nWould you like to Play Again? ( y or n )\n\n";
		cin >> ending;
		if (ending != 'y')
		{
			PlayAgain = false;
		}
	}


}