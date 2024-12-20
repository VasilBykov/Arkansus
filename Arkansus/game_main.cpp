#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "structure.h"

using namespace std;

void event_selection();

int main()
{
	setlocale(LC_CTYPE, "Russian");

	int menu_selection;

	drawCity();
	cout << "1 - *Новая игра* \n";
	cout << "2 - !Выйти из игры! \n";

	do
	{
		cout << "-> "; cin >> menu_selection;
	} while (menu_selection < 1 || menu_selection > 3);

	switch (menu_selection)
	{
	case 1:
	{
		event_selection();
		break;
	}
	default:
		exit(0);
		break;
	}

	return 0;
}

void event_selection()
{
	int rmn = 1, rmx = 3;
	const int MAX = 25;
	int Game_Event[MAX];
	int choice;

	srand((unsigned)time(NULL));
	for (int i = 0; i < MAX; ++i)
	{
		Game_Event[i] = rand() % rmx + rmn;
	}

	for (int i = 0; i < MAX; ++i)
	{
		choice = Game_Event[i];

		char symbol = '-';
		cout << "--День №" << i + 1 << setw(75) << setfill(symbol) << symbol << endl;

		switch (choice)
		{
		case 1:
			events_1931();
			break;
		case 2:
			events_1940();
			break;
		case 3:
			events_1952();
			break;
		default:
			break;
		}
	}

	drawCity();
	game_points_result();

	cout << "\nСпасибо за игру!\n";
}