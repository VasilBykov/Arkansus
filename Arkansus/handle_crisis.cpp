#include <iostream>
#include <cstdlib>
#include <ctime>
#include "structure.h"

using namespace std;

void handle_crisis()
{
    int public_discontent = 50; // ������� ������������ ���������.
    int time_remaining = 60; // ����� �� ������������ � �������.

    cout << "�� ������ ���������� � ��������. ������� ������������ ���������: " << public_discontent << endl;

    while (time_remaining > 0 && public_discontent > 0)
    {
        cout << "�������� �������: " << time_remaining << " �����.\n";
        cout << "1 - �������� ������� � ��������." << endl;
        cout << "2 - ��������� ���������� ���������� ��������." << endl;
        cout << "3 - ������������ ��������." << endl;

        cout << "-> ";
        int action;
        cin >> action;

        switch (action)
        {
        case 1: // �������� ������� � ��������
        {
            if (rand() % 2 == 0)
            {
                public_discontent -= 20; // �����.
                cout << "������� ������ �������, ������ ��������! ������� ������������: " << public_discontent << endl;
            }
            else
            {
                public_discontent += 10; // �������.
                cout << "������� �� �������, ������ ����������. ������� ������������: " << public_discontent << endl;
            }
            break;
        }
        case 2: // ��������� ���������� ���������� ��������
        {
            if (rand() % 2 == 0)
            {
                public_discontent -= 15; // �����.
                cout << "���������� ��������� ���� ���������, � ������ ��������! ������� ������������: " << public_discontent << endl;
            }
            else
            {
                public_discontent += 5; // �������.
                cout << "�� ������� ��������� ���������. ������� ������������: " << public_discontent << endl;
            }
            break;
        }
        case 3: // ������������ ��������
        {
            public_discontent += 25; // ������������� �������� � ����� ������������.
            cout << "�� ��������������� ��������, � ������������ ������� ��������! ������� ������������: " << public_discontent << endl;
            break;
        }
        default:
            cout << "�������� ��������. �� �������� �����!\n";
            break;
        }

        time_remaining -= 10; // ��������� ����� �� ������������.

        if (public_discontent <= 0)
        {
            cout << "�� ������� ���������� � ��������, � ������ ��������! ������� ������������: " << public_discontent << endl;
            int karma_points = 3;
            game_points(karma_points);
            return;
        }
    }

    cout << "������ �� ������� ���������, � ������������ ������� �������� ����������� �������. �� ��������� �������.\n";
    int karma_points = -5;
    game_points(karma_points);
}