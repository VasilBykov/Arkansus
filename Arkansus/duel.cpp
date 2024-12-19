#include <iostream>
#include "structure.h"
using namespace std;

void duelMechanics() {
    cout << "Вы приняли вызов. Дуэль начинается!" << endl;
    int hero_health = 100, opponent_health = 100;
    while (hero_health > 0 && opponent_health > 0) {
        int action;
        cout << "Ваш ход: \n1. Выстрелить\n2. Уклониться\nВыберите действие: ";
        cin >> action;

        if (action == 1) {
            int hit = rand() % 2; // 50% шанс попасть
            if (hit) {
                int damage = rand() % 20 + 10; // Урон от 10 до 30
                opponent_health -= damage;
                cout << "Вы попали! Нанесено " << damage << " урона. Здоровье противника: " << opponent_health << endl;
            }
            else {
                cout << "Вы промахнулись!" << endl;
            }
        }
        else if (action == 2) {
            cout << "Вы пытаетесь уклониться." << endl;
            int evade = rand() % 2; // 50% шанс уклониться
            if (evade) {
                cout << "Вы успешно уклонились от выстрела противника!" << endl;
                continue;
            }
            else {
                int damage = rand() % 20 + 10; // Урон от 10 до 30
                hero_health -= damage;
                cout << "Не удалось уклониться! Противник попал, нанесено " << damage << " урона. Ваше здоровье: " << hero_health << endl;
            }
        }
        else {
            cout << "Неверный выбор, вы теряете ход!" << endl;
        }

        // Ход противника
        if (opponent_health > 0) {
            int opponent_action = rand() % 2; // 50% шанс действия
            if (opponent_action) {
                int hit = rand() % 2; // 50% шанс попасть
                if (hit) {
                    int damage = rand() % 20 + 10; // Урон от 10 до 30
                    hero_health -= damage;
                    cout << "Противник выстрелил и попал! Нанесено " << damage << " урона. Ваше здоровье: " << hero_health << endl;
                }
                else {
                    cout << "Противник промахнулся!" << endl;
                }
            }
            else {
                cout << "Противник уклоняется." << endl;
            }
        }
    }

    if (hero_health > 0) {
        cout << "Вы выиграли дуэль и сохранили своё место мэра!" << endl;
    }
    else {
        cout << "Вы проиграли дуэль. Противник занимает ваше место." << endl;
    }
}