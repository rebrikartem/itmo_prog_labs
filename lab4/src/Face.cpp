#include "Face.h"
#include <iostream>

using namespace std;

Face::Face()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            colors[i][j] = 'N';
        }
    }
}

Face::Face(char c)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            colors[i][j] = c;
        }
    }
}

Face::Face(char col[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            colors[i][j] = col[i][j];
        }
    }
}

void Face::print()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << colors[i][j] << " ";
        }
        cout << endl;
    }
}

char Face::at(int i, int j)
{
    return colors[i][j];
}
