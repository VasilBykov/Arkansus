#include <iostream>
#include "structure.h"
using namespace std;

void peopleAreFurious()
{
    setlocale(LC_ALL, "ru");
    cout << "Толпа людей окружила вас и требует объяснений!" << endl;
    cout << "1 - Попробовать успокоить толпу и объяснить ситуацию." << endl;
    cout << "2 - Объявить о новых мерах для решения проблемы." << endl;
    cout << "3 - Убежать и спрятаться." << endl;

    int choice;
    cout << "-> "; cin >> choice;

    int karma_points;
    switch (choice)
    {
    case 1:
        cout << "Вы попытались успокоить толпу. Сначала они были агрессивны, но затем начали вас слушать." << endl;
        karma_points = 2; // Начисляем очки за попытку
        break;
    case 2:
        cout << "Вы объявили о новых мерах, и толпа стала более спокойной, но некоторые все еще недовольны." << endl;
        karma_points = 1; // Небольшое увеличение кармы
        break;
    case 3:
        cout << "Вы решили убежать, но толпа вас поймала. Это только усугубило ситуацию." << endl;
        karma_points = -3; // Уменьшаем карму
        break;
    default:
        cout << "Неверный выбор. Толпа начинает терять терпение!" << endl;
        karma_points = -2; // Штраф за неправильный выбор
        break;
    }

    game_points(karma_points); // Обновляем очки игрока
}