#include "Cube.h"
#include "Functions.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

Cube::Cube()
{
    Face whiteFace('W');
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arr[i][j][0].set_side(0, whiteFace.at(3 - i - 1, j));
        }
    }

    Face blueFace('B');
    for (int j = 0; j < 3; j++)
    {
        for (int k = 0; k < 3; k++)
        {
            arr[2][k][j].set_side(1, blueFace.at(3 - k - 1, j));
        }
    }

    Face redFace('R');
    for (int i = 0; i < 3; i++)
    {
        for (int k = 0; k < 3; k++)
        {
            arr[k][2][i].set_side(2, redFace.at(3 - k - 1, 3 - i - 1));
        }
    }

    Face greenFace('G');
    for (int j = 0; j < 3; j++)
    {
        for (int k = 0; k < 3; k++)
        {
            arr[0][k][j].set_side(3, greenFace.at(3 - k - 1, 3 - j - 1));
        }
    }

    Face orangeSide('O');
    for (int i = 0; i < 3; i++)
    {
        for (int k = 0; k < 3; k++)
        {
            arr[k][0][i].set_side(4, orangeSide.at(3 - k - 1, i));
        }
    }

    Face yellowSide('Y');
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arr[i][j][2].set_side(5, yellowSide.at(i, j));
        }
    }
}

void Cube::print()
{
    char topSide[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            topSide[i][j] = arr[i][j][2].get_side(5);
        }
    }

    char botSide[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            botSide[3 - i - 1][j] = arr[i][j][0].get_side(0);
        }
    }

    char frontSide[3][3];
    for (int j = 0; j < 3; j++)
    {
        for (int k = 0; k < 3; k++)
        {
            frontSide[3 - j - 1][k] = arr[2][k][j].get_side(1);
        }
    }

    char rightSide[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int k = 0; k < 3; k++)
        {
            rightSide[3 - i - 1][3 - k - 1] = arr[k][2][i].get_side(2);
        }
    }

    char backSide[3][3];
    for (int j = 0; j < 3; j++)
    {
        for (int k = 0; k < 3; k++)
        {
            backSide[3 - j - 1][3 - k - 1] = arr[0][k][j].get_side(3);
        }
    }

    char leftSide[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int k = 0; k < 3; k++)
        {
            leftSide[3 - i - 1][k] = arr[k][0][i].get_side(4);
        }
    }

    for (int i = 0; i < 3; i++)
    {
        cout << '\t';
        for (int j = 0; j < 3; j++)
        {
            // cout << "\033[01;38;05;226m"<< topSide[i][j] << "\033[0m ";
            // cout << "\033[01;38;05;226m"<< "\u25A0" << "\033[0m ";
            print_color(topSide[i][j]);
        }
        cout << endl;
    }

    for (int i = 0; i < 3; i++)
    {
        cout << "  ";
        for (int j = 0; j < 3; j++)
        {
            // cout << "\033[01;38;05;214m" << leftSide[i][j] << "\033[0m ";
            // cout << "\033[01;38;05;214m" << "\u25A0" << "\033[0m ";
            print_color(leftSide[i][j]);
        }
        for (int j = 0; j < 3; j++)
        {
            // cout << "\033[01;38;05;21m" << frontSide[i][j] << "\033[0m ";
            // cout << "\033[01;38;05;21m" << "\u25A0" << "\033[0m ";
            print_color(frontSide[i][j]);
        }
        for (int j = 0; j < 3; j++)
        {
            // cout << "\033[01;38;05;196m" << rightSide[i][j] << "\033[0m ";
            // cout << "\033[01;38;05;196m" << "\u25A0" << "\033[0m ";
            print_color(rightSide[i][j]);
        }
        for (int j = 0; j < 3; j++)
        {
            // cout << "\033[01;38;05;46m" << backSide[i][j] << "\033[0m ";
            // cout << "\033[01;38;05;46m" << "\u25A0" << "\033[0m ";
            print_color(backSide[i][j]);
        }
        cout << endl;
    }

    for (int i = 0; i < 3; i++)
    {
        cout << '\t';
        for (int j = 0; j < 3; j++)
        {
            // cout << "\033[01;38;05;15m" << botSide[i][j] << "\033[0m ";
            // cout << "\033[01;38;05;15m" << "\u25A0" << "\033[0m ";
            print_color(botSide[i][j]);
        }
        cout << endl;
    }
}

SmallCube &Cube::get_sc(int i, int j, int k)
{
    return arr[i][j][k];
}

bool operator==(const Cube &lhs, const Cube &rhs)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (lhs.arr[i][j][k] != rhs.arr[i][j][k])
                {
                    return false;
                }
            }
        }
    }

    return true;
}

bool operator!=(const Cube &lhs, const Cube &rhs)
{
    return !(lhs == rhs);
}

void Cube::rot90(char c)
{
    if (c == 'W')
    {
        SmallCube *firstA = &arr[0][0][0];
        SmallCube *secondA = &arr[2][0][0];
        SmallCube *thirdA = &arr[2][2][0];
        SmallCube *fourthA = &arr[0][2][0];

        SmallCube tmpA = *fourthA;
        *fourthA = thirdA->rot90(0);
        *thirdA = secondA->rot90(0);
        *secondA = firstA->rot90(0);
        *firstA = tmpA.rot90(0);

        SmallCube *firstE = &arr[0][1][0];
        SmallCube *secondE = &arr[1][0][0];
        SmallCube *thirdE = &arr[2][1][0];
        SmallCube *fourthE = &arr[1][2][0];

        SmallCube tmpE = *fourthE;
        *fourthE = thirdE->rot90(0);
        *thirdE = secondE->rot90(0);
        *secondE = firstE->rot90(0);
        *firstE = tmpE.rot90(0);
    }
    else if (c == 'B')
    {
        SmallCube *firstA = &arr[2][0][0];
        SmallCube *secondA = &arr[2][0][2];
        SmallCube *thirdA = &arr[2][2][2];
        SmallCube *fourthA = &arr[2][2][0];

        SmallCube tmpA = *fourthA;
        *fourthA = thirdA->rot90(1);
        *thirdA = secondA->rot90(1);
        *secondA = firstA->rot90(1);
        *firstA = tmpA.rot90(1);

        SmallCube *firstE = &arr[2][0][1];
        SmallCube *secondE = &arr[2][1][2];
        SmallCube *thirdE = &arr[2][2][1];
        SmallCube *fourthE = &arr[2][1][0];

        SmallCube tmpE = *fourthE;
        *fourthE = thirdE->rot90(1);
        *thirdE = secondE->rot90(1);
        *secondE = firstE->rot90(1);
        *firstE = tmpE.rot90(1);
    }
    else if (c == 'R')
    {
        SmallCube *firstA = &arr[2][2][0];
        SmallCube *secondA = &arr[2][2][2];
        SmallCube *thirdA = &arr[0][2][2];
        SmallCube *fourthA = &arr[0][2][0];

        SmallCube tmpA = *fourthA;
        *fourthA = thirdA->rot90(2);
        *thirdA = secondA->rot90(2);
        *secondA = firstA->rot90(2);
        *firstA = tmpA.rot90(2);

        SmallCube *firstE = &arr[2][2][1];
        SmallCube *secondE = &arr[1][2][2];
        SmallCube *thirdE = &arr[0][2][1];
        SmallCube *fourthE = &arr[1][2][0];

        SmallCube tmpE = *fourthE;
        *fourthE = thirdE->rot90(2);
        *thirdE = secondE->rot90(2);
        *secondE = firstE->rot90(2);
        *firstE = tmpE.rot90(2);
    }
    else if (c == 'G')
    {
        SmallCube *firstA = &arr[0][0][0];
        SmallCube *secondA = &arr[0][2][0];
        SmallCube *thirdA = &arr[0][2][2];
        SmallCube *fourthA = &arr[0][0][2];

        SmallCube tmpA = *fourthA;
        *fourthA = thirdA->rot90(3);
        *thirdA = secondA->rot90(3);
        *secondA = firstA->rot90(3);
        *firstA = tmpA.rot90(3);

        SmallCube *firstE = &arr[0][1][0];
        SmallCube *secondE = &arr[0][2][1];
        SmallCube *thirdE = &arr[0][1][2];
        SmallCube *fourthE = &arr[0][0][1];

        SmallCube tmpE = *fourthE;
        *fourthE = thirdE->rot90(3);
        *thirdE = secondE->rot90(3);
        *secondE = firstE->rot90(3);
        *firstE = tmpE.rot90(3);
    }
    else if (c == 'O')
    {
        SmallCube *firstA = &arr[0][0][0];
        SmallCube *secondA = &arr[0][0][2];
        SmallCube *thirdA = &arr[2][0][2];
        SmallCube *fourthA = &arr[2][0][0];

        SmallCube tmpA = *fourthA;
        *fourthA = thirdA->rot90(4);
        *thirdA = secondA->rot90(4);
        *secondA = firstA->rot90(4);
        *firstA = tmpA.rot90(4);

        SmallCube *firstE = &arr[0][0][1];
        SmallCube *secondE = &arr[1][0][2];
        SmallCube *thirdE = &arr[2][0][1];
        SmallCube *fourthE = &arr[1][0][0];

        SmallCube tmpE = *fourthE;
        *fourthE = thirdE->rot90(4);
        *thirdE = secondE->rot90(4);
        *secondE = firstE->rot90(4);
        *firstE = tmpE.rot90(4);
    }
    else if (c == 'Y')
    {
        SmallCube *firstA = &arr[0][0][2];
        SmallCube *secondA = &arr[0][2][2];
        SmallCube *thirdA = &arr[2][2][2];
        SmallCube *fourthA = &arr[2][0][2];

        SmallCube tmpA = *fourthA;
        *fourthA = thirdA->rot90(5);
        *thirdA = secondA->rot90(5);
        *secondA = firstA->rot90(5);
        *firstA = tmpA.rot90(5);

        SmallCube *firstE = &arr[0][1][2];
        SmallCube *secondE = &arr[1][2][2];
        SmallCube *thirdE = &arr[2][1][2];
        SmallCube *fourthE = &arr[1][0][2];

        SmallCube tmpE = *fourthE;
        *fourthE = thirdE->rot90(5);
        *thirdE = secondE->rot90(5);
        *secondE = firstE->rot90(5);
        *firstE = tmpE.rot90(5);
    }
}

void Cube::rot180(char c)
{
    this->rot90(c);
    this->rot90(c);
}

void Cube::rot270(char c)
{
    this->rot180(c);
    this->rot90(c);
}

// W = D
// B = F
// R = R
// G = B
// O = L
// Y = T

int Cube::step1(string& answer)
{
    int c = 0;
    int m = 0;

    while (c != 4)
    {
        bool tmp = true;

        // 1
        if (arr[2][1][2].get_side(2 - 1) == 'B' && arr[2][1][2].get_side(6 - 1) == 'W')
        {
            answer.append(" F2");
            this->rot180('B');
            tmp = false;
            // cout << " F2" << " ";
        }

        if (arr[1][2][2].get_side(3 - 1) == 'R' && arr[1][2][2].get_side(6 - 1) == 'W')
        {
            answer.append(" R2");
            this->rot180('R');
            tmp = false;
            // cout << " R2" << " ";
        }

        if (arr[1][0][2].get_side(5 - 1) == 'O' && arr[1][0][2].get_side(6 - 1) == 'W')
        {
            answer.append(" L2");
            this->rot180('O');
            tmp = false;
            // cout << " L2" << " ";
        }

        if (arr[0][1][2].get_side(4 - 1) == 'G' && arr[0][1][2].get_side(6 - 1) == 'W')
        {
            answer.append(" B2");
            this->rot180('G');
            tmp = false;
            // cout << " B2" << " ";
        }

        // 2
        if (arr[2][1][2].get_side(2 - 1) == 'W' && arr[2][1][2].get_side(6 - 1) == 'B')
        {
            answer.append(" T' R' F R");
            this->rot270('Y');
            this->rot270('R');
            this->rot90('B');
            this->rot90('R');
            tmp = false;
            // cout << " T' R' F R" << " ";
        }

        if (arr[1][2][2].get_side(3 - 1) == 'W' && arr[1][2][2].get_side(6 - 1) == 'R')
        {
            answer.append(" T' B' R B");
            this->rot270('Y');
            this->rot270('G');
            this->rot90('R');
            this->rot90('G');
            tmp = false;
            // cout << " T' B' R B" << " ";
        }

        if (arr[1][0][2].get_side(5 - 1) == 'W' && arr[1][0][2].get_side(6 - 1) == 'O')
        {
            answer.append(" T' F' L F");
            this->rot270('Y');
            this->rot270('B');
            this->rot90('O');
            this->rot90('B');
            tmp = false;
            // cout << " T' F' L F" << " ";
        }

        if (arr[0][1][2].get_side(4 - 1) == 'W' && arr[0][1][2].get_side(6 - 1) == 'G')
        {
            answer.append(" T' L' B L");
            this->rot270('Y');
            this->rot270('O');
            this->rot90('G');
            this->rot90('O');
            tmp = false;
            // cout << " T' L' B L" << " ";
        }

        // 3
        if (arr[2][2][1].get_side(2 - 1) == 'W')
        {
            answer.append(" F' T' F");
            this->rot270('B');
            this->rot270('Y');
            this->rot90('B');
            tmp = false;
            // cout << " F' T' F" << " ";
        }

        if (arr[0][2][1].get_side(3 - 1) == 'W')
        {
            answer.append(" R' T' R");
            this->rot270('R');
            this->rot270('Y');
            this->rot90('R');
            
            tmp = false;
            // cout << " R' T' R" << " ";
        }

        if (arr[2][0][1].get_side(5 - 1) == 'W')
        {
            answer.append(" L' T' L");
            this->rot270('O');
            this->rot270('Y');
            this->rot90('O');
            
            tmp = false;
            // cout << " L' T' L" << " ";
        }

        if (arr[0][0][1].get_side(4 - 1) == 'W')
        {
            answer.append(" B' T' B");
            this->rot270('G');
            this->rot270('Y');
            this->rot90('G');
            
            tmp = false;
            // cout << " B' T' B" << " ";
        }

        // 4
        if (arr[2][0][1].get_side(2 - 1) == 'W')
        {
            answer.append(" F T' F'");
            this->rot90('B');
            this->rot270('Y');
            this->rot270('B');
            
            tmp = false;
            // cout << " F T' F'" << " ";
        }

        if (arr[2][2][1].get_side(3 - 1) == 'W')
        {
            answer.append(" R T' R'");
            this->rot90('R');
            this->rot270('Y');
            this->rot270('R');
            
            tmp = false;
            // cout << " R T' R'" << " ";
        }

        if (arr[0][0][1].get_side(5 - 1) == 'W')
        {
            answer.append(" L T' L'");
            this->rot90('O');
            this->rot270('Y');
            this->rot270('O');
            
            tmp = false;
            // cout << " L T' L'" << " ";
        }

        if (arr[0][2][1].get_side(4 - 1) == 'W')
        {
            answer.append(" B T' B'");
            this->rot90('G');
            this->rot270('Y');
            this->rot270('G');
            
            tmp = false;
            // cout << " B T' B'" << " ";
        }

        // 5
        if (arr[2][1][0].get_side(2 - 1) == 'W')
        {
            answer.append(" F2 T' F2");
            this->rot180('B');
            this->rot270('Y');
            this->rot180('B');
            
            tmp = false;
            // cout << " F2 T' F2" << " ";
        }

        if (arr[1][2][0].get_side(3 - 1) == 'W')
        {
            answer.append(" R2 T' R2");
            this->rot180('R');
            this->rot270('Y');
            this->rot180('R');
            
            tmp = false;
            // cout << " R2 T' R2" << " ";
        }

        if (arr[1][0][0].get_side(5 - 1) == 'W')
        {
            answer.append(" L2 T' L2");
            this->rot180('O');
            this->rot270('Y');
            this->rot180('O');
            
            tmp = false;
            // cout << " L2 T' L2" << " ";
        }

        if (arr[0][1][0].get_side(4 - 1) == 'W')
        {
            answer.append(" B2 T' B2");
            this->rot180('G');
            this->rot270('Y');
            this->rot180('G');
            
            tmp = false;
            // cout << " B2 T' B2" << " ";
        }

        // 6
        if (arr[2][1][0].get_side(2 - 1) != 'B' && arr[2][1][0].get_side(1 - 1) == 'W')
        {
            answer.append(" F2 T' F2");
            this->rot180('B');
            this->rot270('Y');
            this->rot180('B');
            
            tmp = false;
            // cout << " F2 T' F2" << " ";
        }

        if (arr[1][2][0].get_side(3 - 1) != 'R' && arr[1][2][0].get_side(1 - 1) == 'W')
        {
            answer.append(" R2 T' R2");
            this->rot180('R');
            this->rot270('Y');
            this->rot180('R');
            
            tmp = false;
            // cout << " R2 T' R2" << " ";
        }

        if (arr[1][0][0].get_side(5 - 1) != 'O' && arr[1][0][0].get_side(1 - 1) == 'W')
        {
            answer.append(" L2 T' L2");
            this->rot180('O');
            this->rot270('Y');
            this->rot180('O');

            tmp = false;
            // cout << " L2 T' L2" << " ";
        }

        if (arr[0][1][0].get_side(4 - 1) != 'G' && arr[0][1][0].get_side(1 - 1) == 'W')
        {
            answer.append(" B2 T' B2");
            this->rot180('G');
            this->rot270('Y');
            this->rot180('G');
            
            tmp = false;
            // cout << " F2" << " ";
        }

        //
        if (!tmp)
        {
            c = 0;
        }
        else
        {
            answer.append(" T");
            this->rot90('Y');
            
            c++;
        }

        m++;
        if (m == 1000)
        {
            return m;
        }
    }

    return m;
}

int Cube::step2(string &answer)
{
    int c = 0;
    int m = 0;

    while (c != 4)
    {
        bool tmp = true;

        // 1
        if (arr[2][2][2].get_side(2 - 1) == 'W' && arr[2][2][2].get_side(6 - 1) == 'B' && arr[2][2][2].get_side(3 - 1) == 'R')
        {
            this->rot270('B');
            this->rot270('Y');
            this->rot90('B');
            tmp = false;

            answer.append(" F' T' F");
            // cout << "1" << endl;
        }

        if (arr[2][0][2].get_side(5 - 1) == 'W' && arr[2][0][2].get_side(2 - 1) == 'B' && arr[2][0][2].get_side(6 - 1) == 'O')
        {
            this->rot270('O');
            this->rot270('Y');
            this->rot90('O');
            tmp = false;

            answer.append(" L' T' L");
            // cout << "1" << endl;
        }

        if (arr[0][2][2].get_side(4 - 1) == 'G' && arr[0][2][2].get_side(3 - 1) == 'W' && arr[0][2][2].get_side(6 - 1) == 'R')
        {
            this->rot270('R');
            this->rot270('Y');
            this->rot90('R');
            tmp = false;

            answer.append(" R' T' R");
            // cout << "1" << endl;
        }

        if (arr[0][0][2].get_side(4 - 1) == 'W' && arr[0][0][2].get_side(6 - 1) == 'G' && arr[0][0][2].get_side(5 - 1) == 'O')
        {
            this->rot270('G');
            this->rot270('Y');
            this->rot90('G');
            tmp = false;

            answer.append(" B' T' B");
            // cout << "1" << endl;
        }

        // 2
        if (arr[2][2][2].get_side(2 - 1) == 'B' && arr[2][2][2].get_side(3 - 1) == 'W' && arr[2][2][2].get_side(6 - 1) == 'R')
        {
            this->rot90('R');
            this->rot90('Y');
            this->rot270('R');
            tmp = false;

            answer.append(" R T R'");
            // cout << "2" << endl;
        }

        if (arr[2][0][2].get_side(2 - 1) == 'W' && arr[2][0][2].get_side(6 - 1) == 'B' && arr[2][0][2].get_side(5 - 1) == 'O')
        {
            this->rot90('B');
            this->rot90('Y');
            this->rot270('B');
            tmp = false;

            answer.append(" F T F'");
            // cout << "2" << endl;
        }

        if (arr[0][2][2].get_side(4 - 1) == 'W' && arr[0][2][2].get_side(6 - 1) == 'G' && arr[0][2][2].get_side(3 - 1) == 'R')
        {
            this->rot90('G');
            this->rot90('Y');
            this->rot270('G');
            tmp = false;

            answer.append(" B T B'");
            // cout << "2" << endl;
        }

        if (arr[0][0][2].get_side(4 - 1) == 'G' && arr[0][0][2].get_side(6 - 1) == 'O' && arr[0][0][2].get_side(5 - 1) == 'W')
        {
            this->rot90('O');
            this->rot90('Y');
            this->rot270('O');
            tmp = false;

            answer.append(" L T L'");
            // cout << "2" << endl;
        }

        // 3
        if (arr[2][2][2].get_side(2 - 1) == 'R' && arr[2][2][2].get_side(3 - 1) == 'B' && arr[2][2][2].get_side(6 - 1) == 'W')
        {
            this->rot90('R');

            this->rot270('Y');

            this->rot270('R');

            this->rot180('Y');

            this->rot90('R');

            this->rot90('Y');

            this->rot270('R');
            tmp = false;

            answer.append(" R T' R' T2 R T R'");
            // cout << "3" << endl;
        }

        if (arr[2][0][2].get_side(2 - 1) == 'O' && arr[2][0][2].get_side(6 - 1) == 'W' && arr[2][0][2].get_side(5 - 1) == 'B')
        {
            this->rot90('B');

            this->rot270('Y');

            this->rot270('B');

            this->rot180('Y');

            this->rot90('B');

            this->rot90('Y');

            this->rot270('B');
            tmp = false;

            answer.append(" F T' F' T2 F T F'");
            // cout << "3" << endl;
        }

        if (arr[0][2][2].get_side(4 - 1) == 'R' && arr[0][2][2].get_side(6 - 1) == 'W' && arr[0][2][2].get_side(3 - 1) == 'G')
        {
            this->rot90('G');

            this->rot270('Y');

            this->rot270('G');

            this->rot180('Y');

            this->rot90('G');

            this->rot90('Y');

            this->rot270('G');
            tmp = false;

            answer.append(" B T' B' T2 B T B'");
            // cout << "3" << endl;
        }

        if (arr[0][0][2].get_side(4 - 1) == 'O' && arr[0][0][2].get_side(6 - 1) == 'W' && arr[0][0][2].get_side(5 - 1) == 'G')
        {
            this->rot90('O');

            this->rot270('Y');

            this->rot270('O');

            this->rot180('Y');

            this->rot90('O');

            this->rot90('Y');

            this->rot270('O');
            tmp = false;

            answer.append(" L T' L' T2 L T L'");
            // cout << "3" << endl;
        }

        // 4
        if (arr[2][2][0].get_side(2 - 1) == 'W')
        {
            this->rot270('B');
            this->rot270('Y');
            this->rot90('B');
            tmp = false;

            answer.append(" F' T' F");
            // cout << "4" << endl;
        }

        if (arr[2][0][0].get_side(5 - 1) == 'W')
        {
            this->rot270('O');
            this->rot270('Y');
            this->rot90('O');
            tmp = false;

            answer.append(" L' T' L");
            // cout << "4" << endl;
        }

        if (arr[0][2][0].get_side(3 - 1) == 'W')
        {
            this->rot270('R');
            this->rot270('Y');
            this->rot90('R');
            tmp = false;

            answer.append(" R' T' R");
            // cout << "4" << endl;
        }

        if (arr[0][0][0].get_side(4 - 1) == 'W')
        {
            this->rot270('G');
            this->rot270('Y');
            this->rot90('G');
            tmp = false;

            answer.append(" B' T' B");
            // cout << "4" << endl;
        }

        // 5
        if (arr[2][2][0].get_side(3 - 1) == 'W')
        {
            this->rot270('B');
            this->rot270('Y');
            this->rot90('B');
            tmp = false;

            answer.append(" F' T' F");
            // cout << "5" << endl;
        }

        if (arr[2][0][0].get_side(2 - 1) == 'W')
        {
            this->rot270('O');
            this->rot270('Y');
            this->rot90('O');
            tmp = false;

            answer.append(" L' T' L");
            // cout << "5" << endl;
        }

        if (arr[0][2][0].get_side(4 - 1) == 'W')
        {
            this->rot270('R');
            this->rot270('Y');
            this->rot90('R');
            tmp = false;

            answer.append(" R' T' R");
            // cout << "5" << endl;
        }

        if (arr[0][0][0].get_side(5 - 1) == 'W')
        {
            this->rot270('G');
            this->rot270('Y');
            this->rot90('G');
            tmp = false;

            answer.append(" B' T' B");
            // cout << "5" << endl;
        }

        // 6
        if ((arr[2][0][0].get_side(2 - 1) != 'B' || arr[2][0][0].get_side(5 - 1) != 'O') && arr[2][0][0].get_side(1 - 1) == 'W')
        {
            this->rot90('B');
            this->rot270('Y');
            this->rot270('B');
            tmp = false;

            answer.append(" F T' F'");
            // cout << "6" << endl;
        }

        if ((arr[2][2][0].get_side(2 - 1) != 'B' || arr[2][2][0].get_side(3 - 1) != 'R') && arr[2][2][0].get_side(1 - 1) == 'W')
        {
            this->rot90('R');
            this->rot270('Y');
            this->rot270('R');
            tmp = false;

            answer.append(" R T' R'");
            // cout << "6" << endl;
        }

        if ((arr[0][2][0].get_side(3 - 1) != 'R' || arr[0][2][0].get_side(4 - 1) != 'G') && arr[0][2][0].get_side(1 - 1) == 'W')
        {
            this->rot90('G');
            this->rot270('Y');
            this->rot270('G');
            tmp = false;

            answer.append(" B T' B'");
            // cout << "6" << endl;
        }

        if ((arr[0][0][0].get_side(4 - 1) != 'G' || arr[0][0][0].get_side(5 - 1) != 'O') && arr[0][0][0].get_side(1 - 1) == 'W')
        {
            this->rot90('O');
            this->rot270('Y');
            this->rot270('O');
            tmp = false;

            answer.append(" L T' L'");
            // cout << "6" << endl;
        }

        if (!tmp)
        {
            c = 0;
        }
        else
        {
            this->rot90('Y');
            c++;
            answer.append(" T");
            // cout << c << endl;
        }

        m++;
        if (m == 1000)
        {
            return m;
        }
    }

    return m;
}

int Cube::step3(string &answer)
{
    int c = 0;
    int m = 0;

    while (c != 4)
    {
        bool tmp = true;

        // 1
        if (arr[2][1][2].get_side(2 - 1) == 'B' && arr[2][1][2].get_side(6 - 1) == 'O')
        {
            this->rot270('Y');
            this->rot270('O');
            this->rot90('Y');
            this->rot90('O');

            this->rot90('Y');
            this->rot90('B');
            this->rot270('Y');
            this->rot270('B');

            answer.append(" T' L' T L T F T' F'");
            tmp = false;
        }

        if (arr[1][2][2].get_side(3 - 1) == 'R' && arr[1][2][2].get_side(6 - 1) == 'B')
        {
            this->rot270('Y');
            this->rot270('B');
            this->rot90('Y');
            this->rot90('B');

            this->rot90('Y');
            this->rot90('R');
            this->rot270('Y');
            this->rot270('R');

            answer.append(" T' F' T F T R T' R'");
            tmp = false;
        }

        if (arr[0][1][2].get_side(4 - 1) == 'G' && arr[0][1][2].get_side(6 - 1) == 'R')
        {
            this->rot270('Y');
            this->rot270('R');
            this->rot90('Y');
            this->rot90('R');

            this->rot90('Y');
            this->rot90('G');
            this->rot270('Y');
            this->rot270('G');

            answer.append(" T' R' T R T B T' B'");
            tmp = false;
        }

        if (arr[1][0][2].get_side(5 - 1) == 'O' && arr[1][0][2].get_side(6 - 1) == 'G')
        {
            this->rot270('Y');
            this->rot270('G');
            this->rot90('Y');
            this->rot90('G');

            this->rot90('Y');
            this->rot90('O');
            this->rot270('Y');
            this->rot270('O');

            answer.append(" T' B' T B T L T' L'");
            tmp = false;
        }

        // 2
        if (arr[2][1][2].get_side(6 - 1) == 'R' && arr[2][1][2].get_side(2 - 1) == 'B')
        {
            this->rot90('Y');
            this->rot90('R');
            this->rot270('Y');
            this->rot270('R');

            this->rot270('Y');
            this->rot270('B');
            this->rot90('Y');
            this->rot90('B');

            answer.append(" T R T' R' T' F' T F");
            tmp = false;
        }

        if (arr[1][0][2].get_side(6 - 1) == 'B' && arr[1][0][2].get_side(5 - 1) == 'O')
        {
            this->rot90('Y');
            this->rot90('B');
            this->rot270('Y');
            this->rot270('B');

            this->rot270('Y');
            this->rot270('O');
            this->rot90('Y');
            this->rot90('O');

            answer.append(" T F T' F' T' L' T L");
            tmp = false;
        }

        if (arr[0][1][2].get_side(4 - 1) == 'G' && arr[0][1][2].get_side(6 - 1) == 'O')
        {
            this->rot90('Y');
            this->rot90('O');
            this->rot270('Y');
            this->rot270('O');

            this->rot270('Y');
            this->rot270('G');
            this->rot90('Y');
            this->rot90('G');

            answer.append(" T L T' L' T' B' T B");
            tmp = false;
        }

        if (arr[1][2][2].get_side(6 - 1) == 'G' && arr[1][2][2].get_side(3 - 1) == 'R')
        {
            this->rot90('Y');
            this->rot90('G');
            this->rot270('Y');
            this->rot270('G');

            this->rot270('Y');
            this->rot270('R');
            this->rot90('Y');
            this->rot90('R');

            answer.append(" T B T' B' T' R' T R");
            tmp = false;
        }

        if (!tmp)
        {
            c = 0;
        }
        else
        {
            this->rot90('Y');
            c++;
            answer.append(" T");

            if (c == 4)
            {
                if (arr[2][2][1].get_side(2 - 1) != 'B' || arr[2][2][1].get_side(3 - 1) != 'R')
                {
                    this->rot90('Y');
                    this->rot90('R');
                    this->rot270('Y');
                    this->rot270('R');

                    this->rot270('Y');
                    this->rot270('B');
                    this->rot90('Y');
                    this->rot90('B');

                    answer.append(" T R T' R' T' F' T F");
                    c = 0;
                }
                else if (arr[2][0][1].get_side(2 - 1) != 'B' || arr[2][0][1].get_side(5 - 1) != 'O')
                {
                    this->rot90('Y');
                    this->rot90('B');
                    this->rot270('Y');
                    this->rot270('B');

                    this->rot270('Y');
                    this->rot270('O');
                    this->rot90('Y');
                    this->rot90('O');

                    answer.append(" T F T' F' T' L' T L");
                    c = 0;
                }
                else if (arr[0][0][1].get_side(4 - 1) != 'G' || arr[0][0][1].get_side(5 - 1) != 'O')
                {
                    this->rot90('Y');
                    this->rot90('O');
                    this->rot270('Y');
                    this->rot270('O');

                    this->rot270('Y');
                    this->rot270('G');
                    this->rot90('Y');
                    this->rot90('G');

                    answer.append(" T L T' L' T' B' T B");
                    c = 0;
                }
                else if (arr[0][2][1].get_side(4 - 1) != 'G' || arr[0][2][1].get_side(3 - 1) != 'R')
                {
                    this->rot90('Y');
                    this->rot90('G');
                    this->rot270('Y');
                    this->rot270('G');

                    this->rot270('Y');
                    this->rot270('R');
                    this->rot90('Y');
                    this->rot90('R');

                    answer.append(" T B T' B' T' R' T R");
                    c = 0;
                }
            }
        }

        m++;
        if (m == 1000)
        {
            return m;
        }
    }

    return m;
}

void Cube::step4(string &answer)
{
    if (
        arr[2][1][2].get_side(2 - 1) == 'Y' && arr[1][2][2].get_side(3 - 1) == 'Y' && arr[1][0][2].get_side(6 - 1) == 'Y' && arr[0][1][2].get_side(6 - 1) == 'Y')
    {
        this->rot90('B');
        this->rot90('Y');
        this->rot90('R');

        this->rot270('Y');
        this->rot270('R');
        this->rot270('B');

        answer.append(" F T R T' R' F'");
    }
    else if (
        arr[2][1][2].get_side(2 - 1) == 'Y' && arr[1][0][2].get_side(5 - 1) == 'Y' && arr[0][1][2].get_side(6 - 1) == 'Y' && arr[1][2][2].get_side(6 - 1) == 'Y')
    {
        this->rot90('O');
        this->rot90('Y');
        this->rot90('B');

        this->rot270('Y');
        this->rot270('B');
        this->rot270('O');

        answer.append(" L T F T' F' L'");
    }
    else if (
        arr[0][1][2].get_side(4 - 1) == 'Y' && arr[1][2][2].get_side(3 - 1) == 'Y' && arr[2][1][2].get_side(6 - 1) == 'Y' && arr[1][0][2].get_side(6 - 1) == 'Y')
    {
        this->rot90('R');
        this->rot90('Y');
        this->rot90('G');

        this->rot270('Y');
        this->rot270('G');
        this->rot270('R');

        answer.append(" R T B T' B' R'");
    }
    else if (
        arr[0][1][2].get_side(4 - 1) == 'Y' && arr[1][0][2].get_side(5 - 1) == 'Y' && arr[2][1][2].get_side(6 - 1) == 'Y' && arr[1][2][2].get_side(6 - 1) == 'Y')
    {
        this->rot90('G');
        this->rot90('Y');
        this->rot90('O');

        this->rot270('Y');
        this->rot270('O');
        this->rot270('G');

        answer.append(" B T L T' L' B'");
    }
    else if (
        arr[2][1][2].get_side(2 - 1) == 'Y' && arr[0][1][2].get_side(4 - 1) == 'Y' && arr[1][0][2].get_side(6 - 1) == 'Y' && arr[1][2][2].get_side(6 - 1) == 'Y')
    {
        this->rot90('B');
        this->rot90('R');
        this->rot90('Y');

        this->rot270('R');
        this->rot270('Y');
        this->rot270('B');

        answer.append(" F R T R' T' F'");
    }
    else if (
        arr[2][1][2].get_side(6 - 1) == 'Y' && arr[0][1][2].get_side(6 - 1) == 'Y' && arr[1][0][2].get_side(5 - 1) == 'Y' && arr[1][2][2].get_side(3 - 1) == 'Y')
    {
        this->rot90('R');
        this->rot90('G');
        this->rot90('Y');

        this->rot270('G');
        this->rot270('Y');
        this->rot270('R');

        answer.append(" R B T B' T' R'");
    }
    else if (
        arr[2][1][2].get_side(2 - 1) == 'Y' && arr[1][0][2].get_side(5 - 1) == 'Y' && arr[0][1][2].get_side(4 - 1) == 'Y' && arr[1][2][2].get_side(3 - 1) == 'Y')
    {
        this->rot90('B');
        this->rot90('Y');
        this->rot90('R');

        this->rot270('Y');
        this->rot270('R');
        this->rot270('B');

        this->rot90('R');
        this->rot90('G');
        this->rot90('Y');

        this->rot270('G');
        this->rot270('Y');
        this->rot270('R');

        answer.append(" F T R T' R' F' R B T B' T' R'");
    }
}

void Cube::step5(string &answer)
{
    // 1
    if (arr[1][2][2].get_side(3 - 1) == 'B')
    {
        this->rot90('Y');
        this->rot270('O');
        this->rot180('Y');

        this->rot90('O');
        this->rot90('Y');
        this->rot270('O');

        this->rot90('Y');
        this->rot90('O');

        answer.append(" T L' T2 L T L' T L");
    }
    else if (arr[1][0][2].get_side(5 - 1) == 'B')
    {
        this->rot90('Y');
        this->rot270('G');
        this->rot180('Y');

        this->rot90('G');
        this->rot90('Y');
        this->rot270('G');

        this->rot90('Y');
        this->rot90('G');

        answer.append(" T B' T2 B T B' T B");
    }
    else if (arr[0][1][2].get_side(4 - 1) == 'B')
    {
        this->rot90('Y');
        this->rot270('R');
        this->rot180('Y');

        this->rot90('R');
        this->rot90('Y');
        this->rot270('R');

        this->rot90('Y');
        this->rot90('R');
        this->rot90('Y');

        this->rot270('G');
        this->rot180('Y');
        this->rot90('G');

        this->rot90('Y');
        this->rot270('G');
        this->rot90('Y');

        this->rot90('G');
        this->rot90('Y');
        this->rot270('R');

        this->rot180('Y');
        this->rot90('R');
        this->rot90('Y');

        this->rot270('R');
        this->rot90('Y');
        this->rot90('R');

        answer.append(" T R' T2 R T R' T R T B' T2 B T B' T B T R' T2 R T R' T R");
    }

    // 2
    if (arr[0][1][2].get_side(4 - 1) == 'R')
    {
        this->rot90('Y');
        this->rot270('B');

        this->rot180('Y');
        this->rot90('B');

        this->rot90('Y');
        this->rot270('B');

        this->rot90('Y');
        this->rot90('B');

        answer.append(" T F' T2 F T F' T F");
    }
    else if (arr[1][0][2].get_side(5 - 1) == 'R')
    {
        this->rot90('Y');
        this->rot270('G');

        this->rot180('Y');
        this->rot90('G');

        this->rot90('Y');
        this->rot270('G');

        this->rot90('Y');
        this->rot90('G');

        this->rot90('Y');
        this->rot270('O');

        this->rot180('Y');
        this->rot90('O');

        this->rot90('Y');
        this->rot270('O');

        this->rot90('Y');
        this->rot90('O');

        this->rot90('Y');
        this->rot270('G');

        this->rot180('Y');
        this->rot90('G');

        this->rot90('Y');
        this->rot270('G');

        this->rot90('Y');
        this->rot90('G');

        answer.append(" T B' T2 B T B' T B T L' T2 L T L' T L T B' T2 B T B' T B");
    }

    if (arr[1][0][2].get_side(5 - 1) == 'G')
    {
        this->rot90('Y');
        this->rot270('R');

        this->rot180('Y');
        this->rot90('R');

        this->rot90('Y');
        this->rot270('R');

        this->rot90('Y');
        this->rot90('R');

        answer.append(" T R' T2 R T R' T R");
    }
}

void Cube::step6(string &answer)
{

    if (
        (arr[2][0][2].get_side(5 - 1) == 'B' || arr[2][0][2].get_side(5 - 1) == 'R' || arr[2][0][2].get_side(5 - 1) == 'Y') &&
        (arr[2][0][2].get_side(2 - 1) == 'B' || arr[2][0][2].get_side(2 - 1) == 'R' || arr[2][0][2].get_side(2 - 1) == 'Y') &&
        (arr[2][0][2].get_side(6 - 1) == 'B' || arr[2][0][2].get_side(6 - 1) == 'R' || arr[2][0][2].get_side(6 - 1) == 'Y'))
    {
        this->rot90('O');
        this->rot90('B');
        this->rot90('R');

        this->rot270('B');
        this->rot270('O');

        this->rot90('B');
        this->rot270('R');

        this->rot270('B');

        answer.append(" L F R F' L' F R' F'");
        // tmp = false;

        // cout << "aboba1" << endl;
    }
    else if (
        (arr[0][2][2].get_side(3 - 1) == 'B' || arr[0][2][2].get_side(3 - 1) == 'R' || arr[0][2][2].get_side(3 - 1) == 'Y') &&
        (arr[0][2][2].get_side(4 - 1) == 'B' || arr[0][2][2].get_side(4 - 1) == 'R' || arr[0][2][2].get_side(4 - 1) == 'Y') &&
        (arr[0][2][2].get_side(6 - 1) == 'B' || arr[0][2][2].get_side(6 - 1) == 'R' || arr[0][2][2].get_side(6 - 1) == 'Y'))
    {
        this->rot270('R');
        this->rot270('B');
        this->rot270('O');

        this->rot90('B');
        this->rot90('R');

        this->rot270('B');
        this->rot90('O');
        this->rot90('B');

        answer.append(" R' F' L' F R F' L F");
        // tmp = false;

        // cout << "aboba2" << endl;
    }
    else if (
        (arr[0][0][2].get_side(4 - 1) == 'B' || arr[0][0][2].get_side(4 - 1) == 'R' || arr[0][0][2].get_side(4 - 1) == 'Y') &&
        (arr[0][0][2].get_side(5 - 1) == 'B' || arr[0][0][2].get_side(5 - 1) == 'R' || arr[0][0][2].get_side(5 - 1) == 'Y') &&
        (arr[0][0][2].get_side(6 - 1) == 'B' || arr[0][0][2].get_side(6 - 1) == 'R' || arr[0][0][2].get_side(6 - 1) == 'Y'))
    {
        this->rot90('R');
        this->rot90('G');
        this->rot90('O');

        this->rot270('G');
        this->rot270('R');

        this->rot90('G');
        this->rot270('O');

        this->rot270('G');

        answer.append(" R B L B' R' B L' B'");
        // tmp = false;

        // cout << "aboba3" << endl;
    }

    if (
        (arr[2][0][2].get_side(5 - 1) == 'R' || arr[2][0][2].get_side(5 - 1) == 'G' || arr[2][0][2].get_side(5 - 1) == 'Y') &&
        (arr[2][0][2].get_side(2 - 1) == 'R' || arr[2][0][2].get_side(2 - 1) == 'G' || arr[2][0][2].get_side(2 - 1) == 'Y') &&
        (arr[2][0][2].get_side(6 - 1) == 'R' || arr[2][0][2].get_side(6 - 1) == 'G' || arr[2][0][2].get_side(6 - 1) == 'Y'))
    {
        this->rot90('G');
        this->rot90('O');
        this->rot90('B');

        this->rot270('O');
        this->rot270('G');

        this->rot90('O');
        this->rot270('B');
        this->rot270('O');

        answer.append(" B L F L' B' L F' L'");
        // cout << "aboba1" << endl;
    }

    if (
        (arr[0][0][2].get_side(4 - 1) == 'R' || arr[0][0][2].get_side(4 - 1) == 'G' || arr[0][0][2].get_side(4 - 1) == 'Y') &&
        (arr[0][0][2].get_side(5 - 1) == 'R' || arr[0][0][2].get_side(5 - 1) == 'G' || arr[0][0][2].get_side(5 - 1) == 'Y') &&
        (arr[0][0][2].get_side(6 - 1) == 'R' || arr[0][0][2].get_side(6 - 1) == 'G' || arr[0][0][2].get_side(6 - 1) == 'Y'))
    {
        this->rot270('O');
        this->rot270('G');

        this->rot270('R');
        this->rot90('G');

        this->rot90('O');
        this->rot270('G');

        this->rot90('R');
        this->rot90('G');

        answer.append(" L' B' R' B L B' R B");
        // cout << "aboba2" << endl;
    }
}

int Cube::step7(string &answer)
{
    int c = 0;
    // 1
    while (*this != Cube())
    {
        if (arr[2][2][2].get_side(3 - 1) == 'Y')
        {
            this->rot270('B');
            this->rot90('R');

            this->rot90('B');
            this->rot270('R');

            this->rot270('B');
            this->rot90('R');

            this->rot90('B');
            this->rot270('R');

            answer.append(" F' R F R' F' R F R'");
        }
        else if (arr[2][2][2].get_side(2 - 1) == 'Y')
        {
            this->rot90('R');
            this->rot270('B');

            this->rot270('R');
            this->rot90('B');

            this->rot90('R');
            this->rot270('B');

            this->rot270('R');
            this->rot90('B');

            answer.append(" R F' R' F R F' R' F");
        }

        this->rot90('Y');
        answer.append(" T");
        c++;

        if (c == 1000)
        {
            break;
        }
    }

    return c;
}

string Cube::solve()
{
    string answer;

    step1(answer);
    step2(answer);
    step3(answer);
    step4(answer);
    step5(answer);
    step6(answer);
    step7(answer);

    return answer;
}

int Cube::solve(int &m)
{
    Cube kub = *this;
    string answer;

    if (kub.step1(answer) == 1000)
    {
        return 1000;
    }

    if (kub.step2(answer) == 1000)
    {
        return 1000;
    }

    if (kub.step3(answer) == 1000)
    {
        return 1000;
    }

    kub.step4(answer);

    kub.step5(answer);

    kub.step6(answer);

    if (kub.step7(answer) == 1000)
    {
        return 1000;
    }

    return 0;
}

void Cube::scramble(string s)
{
    istringstream iss(s);

    string move;
    while (iss >> move){
        if (move == "D")
        {
            rot90('W');
        }
        else if (move == "D2")
        {
            rot180('W');
        }
        else if (move == "D'")
        {
            rot270('W');
        }
        else if (move == "F")
        {
            rot90('B');
        }
        else if (move == "F2")
        {
            rot180('B');
        }
        else if (move == "F'")
        {
            rot270('B');
        }
        else if (move == "R")
        {
            rot90('R');
        }
        else if (move == "R2")
        {
            rot180('R');
        }
        else if (move == "R'")
        {
            rot270('R');
        }
        else if (move == "B")
        {
            rot90('G');
        }
        else if (move == "B2")
        {
            rot180('G');
        }
        else if (move == "B'")
        {
            rot270('G');
        }
        else if (move == "L")
        {
            rot90('O');
        }
        else if (move == "L2")
        {
            rot180('O');
        }
        else if (move == "L'")
        {
            rot270('O');
        }
        else if (move == "T")
        {
            rot90('Y');
        }
        else if (move == "T2")
        {
            rot180('Y');
        }
        else if (move == "T'")
        {
            rot270('Y');
        }
    }
}

istream &operator>>(istream &is, Cube &cube)
{
    char white[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            is >> white[i][j];
        }
    }

    Face whiteFace(white);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cube.arr[i][j][0].set_side(0, whiteFace.at(3 - i - 1, j));
        }
    }

    char blue[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            is >> blue[i][j];
        }
    }

    Face blueFace(blue);
    for (int j = 0; j < 3; j++)
    {
        for (int k = 0; k < 3; k++)
        {
            cube.arr[2][k][j].set_side(1, blueFace.at(3 - k - 1, j));
        }
    }

    char red[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            is >> red[i][j];
        }
    }

    Face redFace(red);
    for (int i = 0; i < 3; i++)
    {
        for (int k = 0; k < 3; k++)
        {
            cube.arr[k][2][i].set_side(2, redFace.at(3 - k - 1, 3 - i - 1));
        }
    }

    char green[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            is >> green[i][j];
        }
    }

    Face greenFace(green);
    for (int j = 0; j < 3; j++)
    {
        for (int k = 0; k < 3; k++)
        {
            cube.arr[0][k][j].set_side(3, greenFace.at(3 - k - 1, 3 - j - 1));
        }
    }

    char orange[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            is >> orange[i][j];
        }
    }

    Face orangeSide(orange);
    for (int i = 0; i < 3; i++)
    {
        for (int k = 0; k < 3; k++)
        {
            cube.arr[k][0][i].set_side(4, orangeSide.at(3 - k - 1, i));
        }
    }

    char yellow[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            is >> yellow[i][j];
        }
    }

    Face yellowSide(yellow);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cube.arr[i][j][2].set_side(5, yellowSide.at(i, j));
        }
    }

    return is;
}

bool Cube::isCorrect()
{
    int m;
    if (this->solve(m) == 1000)
    {
        return false;
    }
    else
    {
        return true;
    }
}

string Cube::random_scramble()
{
    int low_dist = 1;
    int high_dist = 6;
    std::srand((unsigned int)std::time(nullptr));
    string scramble;

    for (int i = 0; i < 25; i++)
    {
        int side = low_dist + std::rand() % (high_dist + 1 - low_dist);
        int type = low_dist + std::rand() % (4 - low_dist);

        if (side == 1)
        {
            if (type == 1)
            {
                this->rot90('W');
                scramble.append(" D");
            }
            else if (type == 2)
            {
                this->rot180('W');
                scramble.append(" D2");
            }
            else
            {
                this->rot270('W');
                scramble.append(" D'");
            }
        }
        else if (side == 2)
        {
            if (type == 1)
            {
                this->rot90('B');
                scramble.append(" F");
            }
            else if (type == 2)
            {
                this->rot180('B');
                scramble.append(" F2");
            }
            else
            {
                this->rot270('B');
                scramble.append(" F'");
            }
        }
        else if (side == 3)
        {
            if (type == 1)
            {
                this->rot90('R');
                scramble.append(" R");
            }
            else if (type == 2)
            {
                this->rot180('R');
                scramble.append(" R2");
            }
            else
            {
                this->rot270('R');
                scramble.append(" R'");
            }
        }
        else if (side == 4)
        {
            if (type == 1)
            {
                this->rot90('G');
                scramble.append(" B");
            }
            else if (type == 2)
            {
                this->rot180('G');
                scramble.append(" B2");
            }
            else
            {
                this->rot270('G');
                scramble.append(" B'");
            }
        }
        else if (side == 5)
        {
            if (type == 1)
            {
                this->rot90('O');
                scramble.append(" L");
            }
            else if (type == 2)
            {
                this->rot180('O');
                scramble.append(" L2");
            }
            else
            {
                this->rot270('O');
                scramble.append(" L'");
            }
        }
        else
        {
            if (type == 1)
            {
                this->rot90('Y');
                scramble.append(" T");
            }
            else if (type == 2)
            {
                this->rot180('Y');
                scramble.append(" T2");
            }
            else
            {
                this->rot270('Y');
                scramble.append(" T'");
            }
        }
    }

    return scramble;
}