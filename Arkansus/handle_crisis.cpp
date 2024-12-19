#include <iostream>
#include <cstdlib>
#include <ctime>
#include "structure.h"

using namespace std;

void handle_crisis()
{
    int public_discontent = 50; // Уровень недовольства населения.
    int time_remaining = 60; // Время на реагирование в минутах.

    cout << "Вы должны справиться с кризисом. Уровень недовольства населения: " << public_discontent << endl;

    while (time_remaining > 0 && public_discontent > 0)
    {
        cout << "Осталось времени: " << time_remaining << " минут.\n";
        cout << "1 - Провести встречу с жителями." << endl;
        cout << "2 - Увеличить количество социальных программ." << endl;
        cout << "3 - Игнорировать протесты." << endl;

        cout << "-> ";
        int action;
        cin >> action;

        switch (action)
        {
        case 1: // Провести встречу с жителями
        {
            if (rand() % 2 == 0)
            {
                public_discontent -= 20; // Успех.
                cout << "Встреча прошла успешно, жители довольны! Уровень недовольства: " << public_discontent << endl;
            }
            else
            {
                public_discontent += 10; // Неудача.
                cout << "Встреча не удалась, жители недовольны. Уровень недовольства: " << public_discontent << endl;
            }
            break;
        }
        case 2: // Увеличить количество социальных программ
        {
            if (rand() % 2 == 0)
            {
                public_discontent -= 15; // Успех.
                cout << "Социальные программы были увеличены, и жители довольны! Уровень недовольства: " << public_discontent << endl;
            }
            else
            {
                public_discontent += 5; // Неудача.
                cout << "Не удалось увеличить программы. Уровень недовольства: " << public_discontent << endl;
            }
            break;
        }
        case 3: // Игнорировать протесты
        {
            public_discontent += 25; // Игнорирование приводит к росту недовольства.
            cout << "Вы проигнорировали протесты, и недовольство жителей возросло! Уровень недовольства: " << public_discontent << endl;
            break;
        }
        default:
            cout << "Неверное действие. Вы потеряли время!\n";
            break;
        }

        time_remaining -= 10; // Уменьшаем время на реагирование.

        if (public_discontent <= 0)
        {
            cout << "Вы успешно справились с кризисом, и жители довольны! Уровень недовольства: " << public_discontent << endl;
            int karma_points = 3;
            game_points(karma_points);
            return;
        }
    }

    cout << "Кризис не удалось разрешить, и недовольство жителей достигло критической отметки. Вы потерпели неудачу.\n";
    int karma_points = -5;
    game_points(karma_points);
}