#include <iostream>
#include "structure.h"

using namespace std;

void event_selection()
{
	int rmn = 1, rmx = 4;
	const int MAX = 25;
	int Game_Event[MAX];
	int choice;

	srand((unsigned)time(NULL));
	for (int i = 0; i < MAX; ++i)
	{
		Game_Event[i] = rand() % rmx + rmn;
		cout << Game_Event[i] << " ";
	}
	cout << "\n"; // для быстрого контроля

	for (int i = 0; i < MAX; ++i)
	{
		choice = Game_Event[i];

		switch (choice)
		{
		case 1:
			events_1931();
			break;
		case 2:
			events_1940();
			break;
		case 3:
			events_1938();
			break;
		case 4:
			events_1952();
			break;
		default:
			break;
		}
	}

	cout << "Спасибо за игру!\n";
}