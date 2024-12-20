#include <iostream>
#include <iomanip> 
#include "structure.h"

using namespace std;

int karma = 0;

void game_points(int karma_points)
{
    char symbol = '-';

    karma += karma_points;
    cout << setw(83) << setfill(symbol) << symbol << endl;
    cout << "\t *Итоги дня*\n";
    cout << "Ваша карма: " << karma << " xp\n";
}

void game_points_result()
{
    int karma_limit = 71;

    char symbol = '#';
    cout << "##Итоги" << setw(75) << setfill(symbol) << symbol << endl;
    cout << "Дин, дон! Мэр, пришло время выборов. Наши подсчеты говорят, что вы:\n";
    if (karma >= karma_limit)
    {
        cout << "Вы отличный мэр, так держать!\n";
    }
    else if (karma == karma_limit / 2)
    {
        cout << "О вас точно не напишут в учебниках.\n";
    }
    else
    {
        cout << "К сожалению, жители городка не хотят вас больше видеть на посту мэра :(\n";
    }
}