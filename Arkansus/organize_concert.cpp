#include <iostream>
#include <cstdlib>
#include <ctime>
#include "structure.h"

using namespace std;

void organize_concert()
{
    int audience_happiness = 50; // ������� ������� ���������.
    int concert_duration = 60; // ������������ �������� � �������.

    cout << "�� ������ ����������� ��������. ������� ������� ���������: " << audience_happiness << endl;

    while (concert_duration > 0 && audience_happiness > 0)
    {
        cout << "�������� �������: " << concert_duration << " �����.\n";
        cout << "1 - ��������� ����� �����������.\n";
        cout << "2 - ���������� �������������� ��������.\n";
        cout << "3 - �������� ����� ����� ��������.\n";

        cout << "-> ";
        int action;
        cin >> action;

        switch (action)
        {
        case 1: // ��������� ����� �����������
        {
            concert_duration -= 10; // ��������� �����.
            audience_happiness += 10; // ����������� �������.
            cout << "�� ��������� ����� �����������! ������� �������: " << audience_happiness << endl;
            break;
        }
        case 2: // ���������� �������������� ��������
        {
            if (rand() % 2 == 0)
            {
                audience_happiness += 20; // ������� ����������.
                cout << "�������������� ������� ���������! ������� �������: " << audience_happiness << endl;
            }
            else
            {
                audience_happiness -= 10; // �������.
                cout << "�� ������� ���������� ��������. ������� �������: " << audience_happiness << endl;
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
            cout << "�������� �������� . �� �������� �����!\n";
            break;
        }

        concert_duration -= 5; // ��������� ����� ��������.

        if (audience_happiness <= 0)
        {
            cout << "��������� ������������ � �������� �������. �� ��������� �������.\n";
            int karma_points = -3;
            game_points(karma_points);
            return;
        }
    }

    cout << "������� ���������� �������! ������� ������� ���������: " << audience_happiness << endl;
    int karma_points = 2;
    game_points(karma_points);
}