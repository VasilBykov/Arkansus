#include <iostream>
#include <cstdlib>
#include <ctime>
#include "structure.h"

using namespace std;

void events_1940()
{
    setlocale(LC_CTYPE, "Russian");

    srand((unsigned)time(NULL));
    int incident = rand() % 6 + 1; // ����� ��������� �������.
    int choice;

    int karma_points;

    // ������� #1: ����� ������������
    if (incident == 1)
    {
        cout << "������� �������! ���� �� ������� ����������� ������ �� ������� ������." << endl;
        cout << "1 - ������������ �������� ������ � �������� �������." << endl;
        cout << "2 - �������� ������� �� ������ �������." << endl;
        cout << "3 - ����� ���������� ��������� ��������." << endl;

        cout << "-> ";
        cin >> choice;

        switch (choice)
        {
        case 1: // �������� ������
        {
            cout << "������� ������������ ���������� ��������, �� ������� ������� ��������." << endl;
            karma_points = -1;
            game_points(karma_points);
            break;
        }
        case 2: // �������� �������
        {
            cout << "�� �������� ������� �� ������. ���� �� ������� ������� ���������� � ��������������� �������." << endl;
            karma_points = 2;
            game_points(karma_points);
            break;
        }
        case 3: // ������ ������� (���-�������: ������)
        {
            cout << "�� ������ ����� ���������� ��������. ���������� ������!" << endl;
            chase(); // ����� ������� ���-�������.
            break;
        }
        default:
        {
            cout << "�������� �����. ������ ������� ��� �����." << endl;
            karma_points = -2;
            game_points(karma_points);
            break;
        }
        }
    }

    // ������� #2: ����� ������������
    if (incident == 2)
    {
        cout << "� ����� ��������� ��������� ������! ��� ����� ����� ��� ������, ��� � ���������." << endl;
        cout << "1 - ������������ ����������� �������." << endl;
        cout << "2 - �������� �����-�����������." << endl;
        cout << "3 - ������������ �����." << endl;

        cout << "-> ";
        cin >> choice;

        switch (choice)
        {
        case 1: // ����������� �������
        {
            cout << "�� ������ ������������ ����������� �������!" << endl;
            organize_concert(); // ����� ������� ��� ����������� ��������.
            break;
        }
        case 2: // �����-�����������
        {
            cout << "�� �����-����������� �������� �����, � ��������� ������ ������ ������������." << endl;
            karma_points = -1;
            game_points(karma_points);
            break;
        }
        case 3: // ������������ �����
        {
            cout << "�� ��������������� �����, � ������ �����, �� ������� �����." << endl;
            karma_points = -2;
            game_points(karma_points);
            break;
        }
        default:
        {
            cout << "�������� �����. ����� ���������� ��������������." << endl;
            karma_points = 0;
            game_points(karma_points);
            break;
        }
        }
    }

    // ������� #3: ���������� � ������
    if (incident == 3)
    {
        cout << "� ������ ��������� ����������! ��� ����� ������ �����������." << endl;
        cout << "1 - ������������ ��������� �������." << endl;
        cout << "2 - ����������� �������� �����." << endl;
        cout << "3 - ������������ ��������." << endl;

        cout << "-> ";
        cin >> choice;

        switch (choice)
        {
        case 1: // ���������
        {
            cout << "�� ������������ ��������� �������. ��� ������ ����� ������!" << endl;
            karma_points = 3;
            game_points(karma_points);
            organize_evacuations(); // ����� ������� ��� ����������� ���������.
            break;
        }
        case 2: // ���������� ����
        {
            cout << "�� ���������� �������� �����, �� ��� �� ���� ����������." << endl;
            karma_points = -1;
            game_points(karma_points);
            break;
        }
        case 3: // ������������ ��������
        {
            cout << "�� ��������������� ��������, � ��� ������� � ������� �������." << endl;
            karma_points = -3;
            game_points(karma_points);
            break;
        }
        default:
        {
            cout << "�������� �����. ���������� ������������." << endl;
            karma_points = 0;
            game_points(karma_points);
            break;
        }
        }
    }

    // ������� #4: ���������� ���������
    if (incident == 4)
    {
        cout << "� ������ ����������� ���������� ���������! ��� �������� ����������� ��� �������." << endl;
        cout << "1 - ������������ ��������� �� ������� �������." << endl;
        cout << "2 - �������� ��������� � �����." << endl;
        cout << "3 - �������� ���������." << endl;

        cout << "-> ";
        cin >> choice;

        switch (choice)
        {
        case 1: // ��������� �� ������� �������
        {
            cout << "�� ������������ ��������� �� ������� �������. ��� ��������� ����� �����!" << endl;
            karma_points = 4;
            game_points(karma_points);
            organize_festival(); // ����� ������� ��� ����������� ���������.
            break;
        }
        case 2: // ��������� � �����
        {
            cout << "��������� � ����� ������ ������, �� ������ �����������." << endl;
            karma_points = 1;
            game_points(karma_points);
            break;
        }
        case 3: // �������� ���������
        {
            cout << "�� �������� ���������, � ������ ���� ������������." << endl;
            karma_points = -2;
            game_points(karma_points);
            break;
        }
        default:
        {
            cout << "�������� �����. ��������� �� ���������." << endl;
            karma_points = 0;
            game_points(karma_points);
            break;
        }
        }
    }

    // ������� #5: ������������� ������
    if (incident == 5)
    {
        cout << "� ������ ������� ������������� ������! ������� ����������� ������, � ������ ����������." << endl;
        cout << "1 - ��������� ������ ��� ��������� �������." << endl;
        cout << "2 - ��������� ������� �� ���������� ���������." << endl;
        cout << "3 - ������������ ������." << endl;

        cout << "-> ";
        cin >> choice;

        switch (choice)
        {
        case 1: // ��������� ������
        {
            cout << "�� ������ ��������� ������. ��� ������� ������������ ����� �������." << endl;
            karma_points = -4;
            game_points(karma_points);
            handle_crisis(); // ����� ������� ��� ��������� �������.
            break;
        }
        case 2: // ��������� ������� �� ���������� ���������
        {
            cout << "�� ��������� ������� �� ���������� ���������. ��� ������� � ���������." << endl;
            karma_points = -5;
            game_points(karma_points);
            handle_crisis(); // ����� ������� ��� ��������� �������.
            break;
        }
        case 3: // ������������ ������
        {
            cout << "�� ��������������� ������, � �������� ������ ����������." << endl;
            karma_points = -6;
            game_points(karma_points);
            handle_crisis(); // ����� ������� ��� ��������� �������.
            break;
        }
        default:
        {
            cout << "�������� �����. ������ ������������." << endl;
            karma_points = -2;
            game_points(karma_points);
            handle_crisis(); // ����� ������� ��� ��������� �������.
            break;
        }
        }
    }

    // ������� #6: �������� ������ ����������� ������
    if (incident == 6)
    {
        cout << "� ������ ����������� �������� ������ ����������� ������! ��� �������� ����������� ��� �������� �������� � ���������." << endl;
        cout << "1 - ������������ �������� ������� ����������." << endl;
        cout << "2 - �������� ������-������ ��� �������." << endl;
        cout << "3 - ������ ������� ����� ��� �����������." << endl;

        cout << "-> ";
        cin >> choice;

        switch (choice)
        {
        case 1: // �������� ������� ����������
        {
            cout << "�� ������������ �������� ������� ����������. ��� ��������� ����� �����������!" << endl;
            karma_points = 5;
            game_points(karma_points);
            manage_cultural_center(); // ����� ������� ��� ���������� ���������.
            break;
        }
        case 2: // ������-������
        {
            cout << "�� ������� ������-������, � ������ ���� � �������� �� ����� ������!" << endl;
            karma_points = 4;
            game_points(karma_points);
            manage_cultural_center(); // ����� ������� ��� ���������� ���������.
            break;
        }
        case 3: // �������� ��� �����������
        {
            cout << "�� ������ ������� �����, � ������ ������� ���, �� �� ��� ������." << endl;
            karma_points = 2;
            game_points(karma_points);
            manage_cultural_center(); // ����� ������� ��� ���������� ���������.
            break;
        }
        default:
        {
            cout << "�������� �����. ����� ��� ������ ��� ������ �����������." << endl;
            karma_points = 1;
            game_points(karma_points);
            manage_cultural_center(); // ����� ������� ��� ���������� ���������.
            break;
        }
        }
    }
}