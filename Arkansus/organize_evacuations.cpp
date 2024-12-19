#include <iostream>
#include <cstdlib>
#include <ctime>
#include "structure.h"

using namespace std;

void organize_evacuations()
{
    int evacuation_success = 50; // ������� ���������� ���������.
    int time_remaining = 30; // ����� �� ��������� � �������.

    cout << "�� ������ ����������� ���������. ������� ����������: " << evacuation_success << endl;

    while (time_remaining > 0 && evacuation_success > 0)
    {
        cout << "�������� �������: " << time_remaining << " �����.\n";
        cout << "1 - ��������� ���������� ������������ ������.\n";
        cout << "2 - �������� ����� ����� �������.\n";
        cout << "3 - ������� ������� �������� ���� ����.\n";

        cout << "-> ";
        int action;
        cin >> action;

        switch (action)
        {
        case 1: // ��������� ���������� ������������ ������
        {
            if (rand() % 2 == 0)
            {
                evacuation_success += 20; // ������� ���������.
                cout << "�� ��������� ���������� ������������ ������! ������� ����������: " << evacuation_success << endl;
            }
            else
            {
                evacuation_success -= 10; // �������.
                cout << "�� ������� �������� �������������� �������. ������� ����������: " << evacuation_success << endl;
            }
            break;
        }
        case 2: // �������� �����
        {
            if (rand() % 2 == 0)
            {
                cout << "������ ������ � ���������! ������� ����������: " << evacuation_success << endl;
            }
            else
            {
                evacuation_success -= 15; // ���������� ������.
                cout << "��������� ������ ������������ �������� ���� ����. ������� ����������: " << evacuation_success << endl;
            }
            break;
        }
        case 3: // ������� ������� �������� ����
        {
            if (rand() % 2 == 0)
            {
                evacuation_success += 10; // �����.
                cout << "�� ������� ������� �������� ���� ����! ������� ����������: " << evacuation_success << endl;
            }
            else
            {
                evacuation_success -= 20; // �������.
                cout << "������ �� ����� �������� ���� ����. ������� ����������: " << evacuation_success << endl;
            }
            break;
        }
        default:
            cout << "�������� ��������. �� �������� �����!\n";
            break;
        }

        time_remaining -= 5; // ��������� ����� ���������.

        if (evacuation_success <= 0)
        {
            cout << "��������� �����������, � ������ ������ �������� � ���������. �� ��������� �������.\n";
            int karma_points = -5;
            game_points(karma_points);
            return;
        }
    }

    cout << "��������� ��������� �������! ������� ����������: " << evacuation_success << endl;
    int karma_points = 4;
    game_points(karma_points);
}