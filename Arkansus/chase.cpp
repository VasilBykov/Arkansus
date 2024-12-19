#include <iostream>
#include <cstdlib>
#include <ctime>
#include "structure.h"

using namespace std;

void chase()
{
    int distance = 100; // Расстояние до беглеца.
    int player_speed = 10; // Скорость игрока.
    int enemy_speed = rand() % 8 + 5; // Скорость беглеца (случайная).

    cout << "Вы начали погоню за беглецом. Расстояние: " << distance << " метров.\n";

    while (distance > 0)
    {
        cout << "1 - Ускориться\n";
        cout << "2 - Попытаться укоротить путь\n";
        cout << "3 - Привлечь дополнительные силы\n";

        cout << "-> ";
        int action;
        cin >> action;

        switch (action)
        {
        case 1: // Ускориться.
            player_speed += rand() % 5 + 1; // Добавляем случайную скорость.
            cout << "Вы ускорились! Ваша скорость: " << player_speed << " м/с.\n";
            break;

        case 2: // Укоротить путь.
            if (rand() % 2 == 0)
            {
                distance -= 20; // Успешно сократили расстояние.
                cout << "Вы нашли короткий путь! Оставшееся расстояние: " << distance << " метров.\n";
            }
            else
            {
                cout << "Путь оказался тупиком. Вы потеряли время.\n";
            }
            break;

        case 3: // Привлечь дополнительные силы.
            enemy_speed -= 2; // Уменьшаем скорость беглеца.
            cout << "Полиция блокировала часть маршрутов. Скорость беглеца снизилась до " << enemy_speed << " м/с.\n";
            break;

        default:
            cout << "Неверное действие. Вы потеряли время!\n";
            break;
        }

        // Добавление случайного события.
        int random_event = rand() % 4; // Генерация случайного события.
        switch (random_event)
        {
        case 0: // Препятствие на пути.
            cout << "Вы наткнулись на препятствие и замедлились!\n";
            player_speed -= rand() % 3 + 1; // Уменьшаем скорость игрока.
            if (player_speed < 0) player_speed = 0; // Скорость не может быть отрицательной.
            break;

        case 1: // Подмога беглеца.
            cout << "Беглец получил помощь и ускорился!\n";
            enemy_speed += rand() % 3 + 1; // Увеличиваем скорость беглеца.
            break;

        case 2: // Беглец устал.
            cout << "Беглец устал и его скорость снизилась.\n";
            enemy_speed -= rand() % 3 + 1; // Уменьшаем скорость беглеца.
            if (enemy_speed < 0) enemy_speed = 0; // Скорость не может быть отрицательной.
            break;

        case 3: // Неожиданная удача.
            cout << "Вы нашли дополнительный короткий путь и сократили расстояние!\n";
            distance -= 15; // Уменьшаем расстояние.
            break;

        default:
            break;
        }

        // Обновление расстояния.
        distance -= player_speed - enemy_speed;

        if (distance <= 0)
        {
            cout << "Вы догнали беглеца! Победа!\n";
            int karma_points = 3;
            game_points(karma_points);
            return;
        }

        if (player_speed <= enemy_speed)
        {
            cout << "Беглец увеличивает отрыв. Оставшееся расстояние: " << distance << " метров.\n";
        }
    }

    cout << "Беглец скрылся. Вы потерпели неудачу.\n";
    int karma_points = -3;
    game_points(karma_points);
}