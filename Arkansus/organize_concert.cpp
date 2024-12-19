#include <iostream>
#include <cstdlib>
#include <ctime>
#include "structure.h"

using namespace std;

void organize_concert()
{
    int audience_happiness = 50; // Уровень счастья аудитории.
    int concert_duration = 60; // Длительность концерта в минутах.

    cout << "Вы начали организацию концерта. Уровень счастья аудитории: " << audience_happiness << endl;

    while (concert_duration > 0 && audience_happiness > 0)
    {
        cout << "Осталось времени: " << concert_duration << " минут.\n";
        cout << "1 - Увеличить время выступления.\n";
        cout << "2 - Пригласить дополнительных артистов.\n";
        cout << "3 - Провести опрос среди зрителей.\n";

        cout << "-> ";
        int action;
        cin >> action;

        switch (action)
        {
        case 1: // Увеличить время выступления
        {
            concert_duration -= 10; // Уменьшаем время.
            audience_happiness += 10; // Увеличиваем счастье.
            cout << "Вы увеличили время выступления! Уровень счастья: " << audience_happiness << endl;
            break;
        }
        case 2: // Пригласить дополнительных артистов
        {
            if (rand() % 2 == 0)
            {
                audience_happiness += 20; // Успешно пригласили.
                cout << "Дополнительные артисты выступили! Уровень счастья: " << audience_happiness << endl;
            }
            else
            {
                audience_happiness -= 10; // Неудача.
                cout << "Не удалось пригласить артистов. Уровень счастья: " << audience_happiness << endl;
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
            cout << "Неверное действие . Вы потеряли время!\n";
            break;
        }

        concert_duration -= 5; // Уменьшаем время концерта.

        if (audience_happiness <= 0)
        {
            cout << "Аудитория разочарована и покидает концерт. Вы потерпели неудачу.\n";
            int karma_points = -3;
            game_points(karma_points);
            return;
        }
    }

    cout << "Концерт завершился успешно! Уровень счастья аудитории: " << audience_happiness << endl;
    int karma_points = 2;
    game_points(karma_points);
}