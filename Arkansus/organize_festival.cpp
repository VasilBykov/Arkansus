#include <iostream>
#include <cstdlib>
#include <ctime>
#include "structure.h"

using namespace std;

void organize_festival()
{
    int audience_happiness = 50; // Уровень счастья аудитории.
    int festival_duration = 120; // Длительность фестиваля в минутах.

    cout << "Вы начали организацию фестиваля. Уровень счастья аудитории: " << audience_happiness << endl;

    while (festival_duration > 0 && audience_happiness > 0)
    {
        cout << "Осталось времени: " << festival_duration << " минут.\n";
        cout << "1 - Пригласить популярных артистов.\n";
        cout << "2 - Организовать конкурсы и игры.\n";
        cout << "3 - Провести опрос среди зрителей.\n";

        cout << "-> ";
        int action;
        cin >> action;

        switch (action)
        {
        case 1: // Пригласить популярных артистов
        {
            if (rand() % 2 == 0)
            {
                audience_happiness += 20; // Успешно пригласили.
                cout << "Популярные артисты выступили! Уровень счастья: " << audience_happiness << endl;
            }
            else
            {
                audience_happiness -= 10; // Неудача.
                cout << "Не удалось пригласить артистов. Уровень счастья: " << audience_happiness << endl;
            }
            break;
        }
        case 2: // Организовать конкурсы и игры
        {
            if (rand() % 2 == 0)
            {
                audience_happiness += 15; // Успех.
                cout << "Конкурсы и игры прошли успешно! Уровень счастья: " << audience_happiness << endl;
            }
            else
            {
                audience_happiness -= 5; // Негативные отзывы.
                cout << "Некоторые конкурсы не понравились. Уровень счастья: " << audience_happiness << endl;
            }
            break;
        }
        case 3: // Провести опрос
        {
            if (rand() % 2 == 0)
            {
                cout << "Зрители довольны! Уровень счастья: " << audience_happiness << endl;
            }
            else
            {
                audience_happiness -= 15; // Негативные отзывы.
                cout << "Некоторые зрители недовольны. Уровень счастья: " << audience_happiness << endl;
            }
            break;
        }
        default:
            cout << "Неверное действие. Вы потеряли время!\n";
            break;
        }

        festival_duration -= 10; // Уменьшаем время фестиваля.

        if (audience_happiness <= 0)
        {
            cout << "Фестиваль провалился, и зрители разочарованы. Вы потерпели неудачу.\n";
            int karma_points = -3;
            game_points(karma_points);
            return;
        }
    }

    cout << "Фестиваль завершился успешно! Уровень счастья аудитории: " << audience_happiness << endl;
    int karma_points = 5;
    game_points(karma_points);
}