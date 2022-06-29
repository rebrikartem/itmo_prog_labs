#include "SmallCube.h"
#include "Functions.h"
#include <iostream>

using namespace std;

SmallCube::SmallCube()
{
    for (int i = 0; i < 6; i++)
    {
        colors[i] = 'N';
    }
}

SmallCube::SmallCube(const SmallCube &other)
{
    for (int i = 0; i < 6; i++)
    {
        colors[i] = other.colors[i];
    }
}

SmallCube::SmallCube(char *col)
{
    for (int i = 0; i < 6; i++)
    {
        colors[i] = col[i];
    }
}

SmallCube &SmallCube::operator=(const SmallCube &other)
{
    if (this == &other)
    {
        return *this;
    }

    for (int i = 0; i < 6; i++)
    {
        colors[i] = other.colors[i];
    }

    return *this;
}

void SmallCube::set_side(int i, char c)
{
    colors[i] = c;
}

char SmallCube::get_side(int i)
{
    return colors[i];
}

void SmallCube::print()
{
    cout << "   ";
    print_color(colors[5]);
    cout << endl;

    print_color(colors[4]);
    cout << " ";
    print_color(colors[1]);
    cout << " ";
    print_color(colors[2]);
    cout << " ";
    print_color(colors[3]);
    cout << endl;
    cout << "   ";
    print_color(colors[0]);
    cout << endl;
    // cout << colors[4] << " " << colors[1] << " " << colors[2] << " " << colors[3] << endl;
    // cout << "  " << colors[0] << endl;
}

SmallCube SmallCube::rot90(int i)
{
    if (i == 0)
    {
        char tmp = colors[4];

        colors[4] = colors[3];
        colors[3] = colors[2];
        colors[2] = colors[1];
        colors[1] = tmp;
    }
    else if (i == 1)
    {
        char tmp = colors[0];

        colors[0] = colors[2];
        colors[2] = colors[5];
        colors[5] = colors[4];
        colors[4] = tmp;
    }
    else if (i == 2)
    {
        char tmp = colors[0];

        colors[0] = colors[3];
        colors[3] = colors[5];
        colors[5] = colors[1];
        colors[1] = tmp;
    }
    else if (i == 3)
    {
        char tmp = colors[0];

        colors[0] = colors[4];
        colors[4] = colors[5];
        colors[5] = colors[2];
        colors[2] = tmp;
    }
    else if (i == 4)
    {
        char tmp = colors[0];

        colors[0] = colors[1];
        colors[1] = colors[5];
        colors[5] = colors[3];
        colors[3] = tmp;
    }
    else if (i == 5)
    {
        char tmp = colors[1];

        colors[1] = colors[2];
        colors[2] = colors[3];
        colors[3] = colors[4];
        colors[4] = tmp;
    }

    return SmallCube(colors);
}

bool operator==(const SmallCube &lhs, const SmallCube &rhs)
{
    for (int i = 0; i < 6; i++)
    {
        if (lhs.colors[i] != rhs.colors[i])
        {
            return false;
        }
    }

    return true;
}

bool operator!=(const SmallCube &lhs, const SmallCube &rhs)
{
    return !(lhs == rhs);
}