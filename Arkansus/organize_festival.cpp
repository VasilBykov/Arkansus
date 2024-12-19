#include <iostream>
#include <cstdlib>
#include <ctime>
#include "structure.h"

using namespace std;

void organize_festival()
{
    int audience_happiness = 50; // ������� ������� ���������.
    int festival_duration = 120; // ������������ ��������� � �������.

    cout << "�� ������ ����������� ���������. ������� ������� ���������: " << audience_happiness << endl;

    while (festival_duration > 0 && audience_happiness > 0)
    {
        cout << "�������� �������: " << festival_duration << " �����.\n";
        cout << "1 - ���������� ���������� ��������.\n";
        cout << "2 - ������������ �������� � ����.\n";
        cout << "3 - �������� ����� ����� ��������.\n";

        cout << "-> ";
        int action;
        cin >> action;

        switch (action)
        {
        case 1: // ���������� ���������� ��������
        {
            if (rand() % 2 == 0)
            {
                audience_happiness += 20; // ������� ����������.
                cout << "���������� ������� ���������! ������� �������: " << audience_happiness << endl;
            }
            else
            {
                audience_happiness -= 10; // �������.
                cout << "�� ������� ���������� ��������. ������� �������: " << audience_happiness << endl;
            }
            break;
        }
        case 2: // ������������ �������� � ����
        {
            if (rand() % 2 == 0)
            {
                audience_happiness += 15; // �����.
                cout << "�������� � ���� ������ �������! ������� �������: " << audience_happiness << endl;
            }
            else
            {
                audience_happiness -= 5; // ���������� ������.
                cout << "��������� �������� �� �����������. ������� �������: " << audience_happiness << endl;
            }
            break;
        }
        case 3: // �������� �����
        {
            if (rand() % 2 == 0)
            {
                cout << "������� ��������! ������� �������: " << audience_happiness << endl;
            }
            else
            {
                audience_happiness -= 15; // ���������� ������.
                cout << "��������� ������� ����������. ������� �������: " << audience_happiness << endl;
            }
            break;
        }
        default:
            cout << "�������� ��������. �� �������� �����!\n";
            break;
        }

        festival_duration -= 10; // ��������� ����� ���������.

        if (audience_happiness <= 0)
        {
            cout << "��������� ����������, � ������� ������������. �� ��������� �������.\n";
            int karma_points = -3;
            game_points(karma_points);
            return;
        }
    }

    cout << "��������� ���������� �������! ������� ������� ���������: " << audience_happiness << endl;
    int karma_points = 5;
    game_points(karma_points);
}