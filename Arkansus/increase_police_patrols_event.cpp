#include <iostream>
#include "structure.h"
using namespace std;


void increase_police_patrols_event()
{
    setlocale(LC_ALL, "ru");
    cout << "Полицейский: Мы увеличили количество патрулей на улицах." << endl;
    cout << "1 - Продолжать финансирование патрулей." << endl;
    cout << "2 - Сократить финансирование." << endl;
    cout << "3 - Попросить жителей сообщать о преступлениях." << endl;

    int choice;
    cout << "-> "; cin >> choice;

    int karma_points;
    switch (choice)
    {
    case 1:
        cout << "Финансирование патрулей помогло улучшить безопасность!" << endl;
        karma_points = 3;
        break;
    case 2:
        cout << "Сокращение финансирования привело к увеличению преступности." << endl;
        karma_points = -3;
        break;
    case 3:
    {
        int community_response = rand() % 10; // Шанс позитивной реакции
        if (community_response < 5)
        {
            cout << "Жители начали активно сообщать о преступлениях!" << endl;
            karma_points = 2;
        }
        else
        {
            cout << "Жители не хотят вмешиваться в дела полиции." << endl;
            karma_points = -1;
        }
        break;
    }
    }
    game_points(karma_points);
}