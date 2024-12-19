#include <iostream>
#include <cstdlib>
#include <ctime>
#include "structure.h"

using namespace std;

void organize_evacuations()
{
    int evacuation_success = 50; // Уровень успешности эвакуации.
    int time_remaining = 30; // Время на эвакуацию в минутах.

    cout << "Вы начали организацию эвакуации. Уровень успешности: " << evacuation_success << endl;

    while (time_remaining > 0 && evacuation_success > 0)
    {
        cout << "Осталось времени: " << time_remaining << " минут.\n";
        cout << "1 - Увеличить количество спасательных команд.\n";
        cout << "2 - Провести опрос среди жителей.\n";
        cout << "3 - Убедить жителей покинуть свои дома.\n";

        cout << "-> ";
        int action;
        cin >> action;

        switch (action)
        {
        case 1: // Увеличить количество спасательных команд
        {
            if (rand() % 2 == 0)
            {
                evacuation_success += 20; // Успешно увеличили.
                cout << "Вы увеличили количество спасательных команд! Уровень успешности: " << evacuation_success << endl;
            }
            else
            {
                evacuation_success -= 10; // Неудача.
                cout << "Не удалось привлечь дополнительные команды. Уровень успешности: " << evacuation_success << endl;
            }
            break;
        }
        case 2: // Провести опрос
        {
            if (rand() % 2 == 0)
            {
                cout << "Жители готовы к эвакуации! Уровень успешности: " << evacuation_success << endl;
            }
            else
            {
                evacuation_success -= 15; // Негативные отзывы.
                cout << "Некоторые жители отказываются покидать свои дома. Уровень успешности: " << evacuation_success << endl;
            }
            break;
        }
        case 3: // Убедить жителей покинуть дома
        {
            if (rand() % 2 == 0)
            {
                evacuation_success += 10; // Успех.
                cout << "Вы убедили жителей покинуть свои дома! Уровень успешности: " << evacuation_success << endl;
            }
            else
            {
                evacuation_success -= 20; // Неудача.
                cout << "Жители не хотят покидать свои дома. Уровень успешности: " << evacuation_success << endl;
            }
            break;
        }
        default:
            cout << "Неверное действие. Вы потеряли время!\n";
            break;
        }

        time_remaining -= 5; // Уменьшаем время эвакуации.

        if (evacuation_success <= 0)
        {
            cout << "Эвакуация провалилась, и многие жители остались в опасности. Вы потерпели неудачу.\n";
            int karma_points = -5;
            game_points(karma_points);
            return;
        }
    }

    cout << "Эвакуация завершена успешно! Уровень успешности: " << evacuation_success << endl;
    int karma_points = 4;
    game_points(karma_points);
}