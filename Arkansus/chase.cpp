#include <iostream>
#include <cstdlib>
#include <ctime>
#include "structure.h"

using namespace std;

void chase()
{
    int distance = 100; // ���������� �� �������.
    int player_speed = 10; // �������� ������.
    int enemy_speed = rand() % 8 + 5; // �������� ������� (���������).

    cout << "�� ������ ������ �� ��������. ����������: " << distance << " ������.\n";

    while (distance > 0)
    {
        cout << "1 - ����������\n";
        cout << "2 - ���������� ��������� ����\n";
        cout << "3 - �������� �������������� ����\n";

        cout << "-> ";
        int action;
        cin >> action;

        switch (action)
        {
        case 1: // ����������.
            player_speed += rand() % 5 + 1; // ��������� ��������� ��������.
            cout << "�� ����������! ���� ��������: " << player_speed << " �/�.\n";
            break;

        case 2: // ��������� ����.
            if (rand() % 2 == 0)
            {
                distance -= 20; // ������� ��������� ����������.
                cout << "�� ����� �������� ����! ���������� ����������: " << distance << " ������.\n";
            }
            else
            {
                cout << "���� �������� �������. �� �������� �����.\n";
            }
            break;

        case 3: // �������� �������������� ����.
            enemy_speed -= 2; // ��������� �������� �������.
            cout << "������� ����������� ����� ���������. �������� ������� ��������� �� " << enemy_speed << " �/�.\n";
            break;

        default:
            cout << "�������� ��������. �� �������� �����!\n";
            break;
        }

        // ���������� ���������� �������.
        int random_event = rand() % 4; // ��������� ���������� �������.
        switch (random_event)
        {
        case 0: // ����������� �� ����.
            cout << "�� ���������� �� ����������� � �����������!\n";
            player_speed -= rand() % 3 + 1; // ��������� �������� ������.
            if (player_speed < 0) player_speed = 0; // �������� �� ����� ���� �������������.
            break;

        case 1: // ������� �������.
            cout << "������ ������� ������ � ���������!\n";
            enemy_speed += rand() % 3 + 1; // ����������� �������� �������.
            break;

        case 2: // ������ �����.
            cout << "������ ����� � ��� �������� ���������.\n";
            enemy_speed -= rand() % 3 + 1; // ��������� �������� �������.
            if (enemy_speed < 0) enemy_speed = 0; // �������� �� ����� ���� �������������.
            break;

        case 3: // ����������� �����.
            cout << "�� ����� �������������� �������� ���� � ��������� ����������!\n";
            distance -= 15; // ��������� ����������.
            break;

        default:
            break;
        }

        // ���������� ����������.
        distance -= player_speed - enemy_speed;

        if (distance <= 0)
        {
            cout << "�� ������� �������! ������!\n";
            int karma_points = 3;
            game_points(karma_points);
            return;
        }

        if (player_speed <= enemy_speed)
        {
            cout << "������ ����������� �����. ���������� ����������: " << distance << " ������.\n";
        }
    }

    cout << "������ �������. �� ��������� �������.\n";
    int karma_points = -3;
    game_points(karma_points);
}