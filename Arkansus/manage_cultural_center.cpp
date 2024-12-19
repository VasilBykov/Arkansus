#include <iostream>
#include <cstdlib>
#include <ctime>
#include "structure.h"

using namespace std;

void manage_cultural_center()
{
    int community_engagement = 50; // Уровень вовлеченности сообщества.
    int time_remaining = 60; // Время на организацию в минутах.

    cout << "Вы должны успешно организовать открытие культурного центра. Уровень вовлеченности сообщества: " << community_engagement << endl;

    while (time_remaining > 0 && community_engagement > 0)
    {
        cout << "Осталось времени: " << time_remaining << " минут.\n";
        cout << "1 - Пригласить известных артистов для выступлений." << endl;
        cout << "2 - Организовать кулинарные мастер-классы." << endl;
        cout << "3 - Устроить вечер поэзии для жителей." << endl;

        cout << "-> ";
        int action;
        cin >> action;

        switch (action)
        {
        case 1: // Пригласить известных артистов
        {
            if (rand() % 2 == 0)
            {
                community_engagement += 20; // Успех.
                cout << "Известные артисты выступили, и жители в восторге! Уровень вовлеченности: " << community_engagement << endl;
            }
            else
            {
                community_engagement -= 5; // Неудача.
                cout << "Выступление не понравилось всем. Уровень вовлеченности: " << community_engagement << endl;
            }
            break;
        }
        case 2: // Организовать кулинарные мастер-классы
        {
            if (rand() % 2 == 0)
            {
                community_engagement += 15; // Успех.
                cout << "Кулинарные мастер-классы прошли отлично! Уровень вовлеченности: " << community_engagement << endl;
            }
            else
            {
                community_engagement -= 5; // Негативные отзывы.
                cout << "Некоторые мастер-классы не понравились. Уровень вовлеченности: " << community_engagement << endl;
            }
            break;
        }
        case 3: // Вечер поэзии
        {
            if (rand() % 2 == 0)
            {
                community_engagement += 25; // Успех.
                cout << "Вечер поэзии прошел великолепно! Уровень вовлеченности: " << community_engagement << endl;
            }
            else
            {
                community_engagement -= 10; // Неудача.
                cout << "Некоторые стихи не вызвали интереса. Уровень вовлеченности: " << community_engagement << endl;
            }
            break;
        }
        default:
        {
            cout << "Неверный выбор. Вы потеряли время на организацию. Уровень вовлеченности: " << community_engagement << endl;
            community_engagement -= 2; // Негативные последствия за неверный выбор.
            break;
        }
        }

        time_remaining -= 10; // Уменьшаем время на организацию.

        // Проверяем, достиг ли уровень вовлеченности критической отметки
        if (community_engagement <= 0)
        {
            cout << "Уровень вовлеченности сообщества упал до нуля. Открытие культурного центра не удалось." << endl;
            break;
        }
    }

    // Завершение мини-игры
    if (community_engagement > 0)
    {
        cout << "Открытие культурного центра прошло успешно! Уровень вовлеченности: " << community_engagement << endl;
        int karma_points = 5; // Положительные очки кармы за успешное открытие.
        game_points(karma_points);
    }
    else
    {
        cout << "К сожалению, открытие культурного центра не удалось. Нужно больше работы в будущем." << endl;
        int karma_points = -3; // Негативные очки кармы за неудачу.
        game_points(karma_points);
    }
}