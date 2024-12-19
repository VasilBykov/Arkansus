#include <iostream>
#include <cstdio>
#include "structure.h"

using namespace std;

void events_1931()
{
    setlocale(LC_CTYPE, "Russian");

    srand((unsigned)time(NULL));
    int incident = rand() % 2 + 1;
    int choice;

    int karma_points;
    /* Это обязательная переменная! Ее значение (от -3 до 3),
    должно быть указано после каждого case! Она занимается
    начисление очков за каждое выбранное действие игроком.*/

    int enemy_max_damage;
    int enemy_protection;
    int enemy_health;

    // Пример события #1:
    if (incident == 1)
    {
        cout << "Рабочий Майкл: Мэр, в баре «Устрица Джо» поднимают цену на выпивку! Решите этот вопрос!" << endl;
        cout << "1 - Конечно, я пришлю ребят и они накостылять Джо." << endl;
        cout << "2 - Иди отсюда, пьянь!" << endl;
        cout << "3 - Достать револьвер и выстрелить в жалобщика." << endl;

        cout << "-> "; cin >> choice; // Пожалуйста, при вводе значений в переменную, соблюдайте такой стиль.

        switch (choice)
        {
        case 1:
        {
            cout << "Рабочий Майкл: Спасибо вам, мэр! Мы добудем для вас больше угля! Слава меру!" << endl;
            karma_points = 3; // Начисляем 3 очка за выбор.
            game_points(karma_points); // Передаем 3 очка в функцию по расчету очков.
            break;
        }
        case 2:
        {
            int possible_fight = rand() % 10; //В данном варианте ответа, есть две развилки с различными событиями.
            if (possible_fight < 6)
            {
                cout << "Рабочий Майкл: Ах ты гнида! Иди сюда, мерзавец!" << endl;
                cout << "На вас напали!" << endl;

                enemy_max_damage = 13;
                enemy_protection = 21;
                enemy_health = 100;
                fight(enemy_max_damage, enemy_protection, enemy_health); // Передача выполнения функции "Драка"

                break;
            }
            else
            {
                cout << "Рабочий Майкл: Я понял вас... Уже ухожу.";
                karma_points = 1;
                game_points(karma_points);
                break;
            }
        }
        default:
        {
            cout << "Вы убили жалобщика." << endl;
            karma_points = -3;
            game_points(karma_points);
            break;
        }

        }
    }

    if (incident == 2)
    {
        cout << "Шериф: Мэр, в центре города корова застряла в фонтане. Люди паникуют!" << endl;
        cout << "1 - Приказать шерифу вызвать пожарных." << endl;
        cout << "2 - Объявить корову символом города." << endl;
        cout << "3 - Притвориться, что ничего не слышали, и закрыть дверь." << endl;

        cout << "-> "; cin >> choice;

        switch (choice)
        {

        case 1:
        {
            cout << "Пожарные спасли корову, но сломали фонтан. Теперь жители требуют новый." << endl;
            karma_points = 2;
            game_points(karma_points);
            break;
        }

        case 2:
        {
            cout << "Вы объявили корову символом города. Её теперь кормят лучше, чем вас." << endl;
            karma_points = 1;
            game_points(karma_points);
            break;
        }

        default:
        {
            cout << "Вы закрыли дверь, но корова так и осталась в фонтане." << endl;
            karma_points = -2;
            game_points(karma_points);
            break;
        }

        }
    }
}