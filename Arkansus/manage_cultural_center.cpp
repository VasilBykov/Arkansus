#include <iostream>
#include <cstdlib>
#include <ctime>
#include "structure.h"

using namespace std;

void manage_cultural_center()
{
    int community_engagement = 50; // ������� ������������� ����������.
    int time_remaining = 60; // ����� �� ����������� � �������.

    cout << "�� ������ ������� ������������ �������� ����������� ������. ������� ������������� ����������: " << community_engagement << endl;

    while (time_remaining > 0 && community_engagement > 0)
    {
        cout << "�������� �������: " << time_remaining << " �����.\n";
        cout << "1 - ���������� ��������� �������� ��� �����������." << endl;
        cout << "2 - ������������ ���������� ������-������." << endl;
        cout << "3 - �������� ����� ������ ��� �������." << endl;

        cout << "-> ";
        int action;
        cin >> action;

        switch (action)
        {
        case 1: // ���������� ��������� ��������
        {
            if (rand() % 2 == 0)
            {
                community_engagement += 20; // �����.
                cout << "��������� ������� ���������, � ������ � ��������! ������� �������������: " << community_engagement << endl;
            }
            else
            {
                community_engagement -= 5; // �������.
                cout << "����������� �� ����������� ����. ������� �������������: " << community_engagement << endl;
            }
            break;
        }
        case 2: // ������������ ���������� ������-������
        {
            if (rand() % 2 == 0)
            {
                community_engagement += 15; // �����.
                cout << "���������� ������-������ ������ �������! ������� �������������: " << community_engagement << endl;
            }
            else
            {
                community_engagement -= 5; // ���������� ������.
                cout << "��������� ������-������ �� �����������. ������� �������������: " << community_engagement << endl;
            }
            break;
        }
        case 3: // ����� ������
        {
            if (rand() % 2 == 0)
            {
                community_engagement += 25; // �����.
                cout << "����� ������ ������ �����������! ������� �������������: " << community_engagement << endl;
            }
            else
            {
                community_engagement -= 10; // �������.
                cout << "��������� ����� �� ������� ��������. ������� �������������: " << community_engagement << endl;
            }
            break;
        }
        default:
        {
            cout << "�������� �����. �� �������� ����� �� �����������. ������� �������������: " << community_engagement << endl;
            community_engagement -= 2; // ���������� ����������� �� �������� �����.
            break;
        }
        }

        time_remaining -= 10; // ��������� ����� �� �����������.

        // ���������, ������ �� ������� ������������� ����������� �������
        if (community_engagement <= 0)
        {
            cout << "������� ������������� ���������� ���� �� ����. �������� ����������� ������ �� �������." << endl;
            break;
        }
    }

    // ���������� ����-����
    if (community_engagement > 0)
    {
        cout << "�������� ����������� ������ ������ �������! ������� �������������: " << community_engagement << endl;
        int karma_points = 5; // ������������� ���� ����� �� �������� ��������.
        game_points(karma_points);
    }
    else
    {
        cout << "� ���������, �������� ����������� ������ �� �������. ����� ������ ������ � �������." << endl;
        int karma_points = -3; // ���������� ���� ����� �� �������.
        game_points(karma_points);
    }
}