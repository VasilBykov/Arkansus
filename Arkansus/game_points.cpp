#include <iostream>
#include "structure.h"

using namespace std;

int karma = 0;

void game_points(int karma_points)
{
    karma += karma_points;
    cout << "=*=\n";
    cout << "Ваша карма: " << karma << " xp\n";
    cout << "=*=\n";
}