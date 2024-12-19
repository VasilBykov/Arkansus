#include <iostream>
#include "structure.h"
using namespace std;

int play_durak()
{
    setlocale(LC_ALL, "ru");
    // Параметры игры
    int player_card = rand() % 36 + 1; // Игральные карты от 1 до 36
    int opponent_card = rand() % 36 + 1;

    cout << "Ваша карта: " << player_card << endl;
    cout << "Карта противника: " << opponent_card << endl;

    // Логика выигрыша
    if (player_card > opponent_card)
    {
        return 1; // Выигрыш
    }
    else
    {
        return 0; // Проигрыш
    }
}