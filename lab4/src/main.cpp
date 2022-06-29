// #include <cstdlib>
// #include <iostream>
// #include <ctime>
// #include <GL/glut.h>
// #include <queue>
// #include <string>
// #include <sstream>
#include "GraphicCube.h"

#define TIMER 1

char title[] = "3D Cube";

struct Rotations
{
    int side;
    int angle;
    int mode;
};

// void chooseColor(char c)
// {
//     if (c == 'W')
//     {
//         glColor3f(1.0f, 1.0f, 1.0f);
//     }
//     else if (c == 'B')
//     {
//         glColor3f(0.0f, 0.0f, 1.0f);
//     }
//     else if (c == 'R')
//     {
//         glColor3f(1.0f, 0.0f, 0.0f);
//     }
//     else if (c == 'G')
//     {
//         glColor3f(0.0f, 1.0f, 0.0f);
//     }
//     else if (c == 'O')
//     {
//         glColor3f(1.0f, 0.5f, 0.0f);
//     }
//     else if (c == 'Y')
//     {
//         glColor3f(1.0f, 1.0f, 0.0f);
//     }
//     else if (c == 'N')
//     {
//         glColor3f(0.0f, 0.0f, 0.0f);
//     }
// }

// void drawCube()
// {
//     glBegin(GL_QUADS); // Begin drawing the color cube with 6 quads
//     // Top face (y = 1.0f)
//     // Define vertices in counter-clockwise (CCW) order with normal pointing out
//     glColor3f(1.0f, 1.0f, 0.0f); // Yellow
//     glVertex3f(1.0f, 1.0f, -1.0f);
//     glVertex3f(-1.0f, 1.0f, -1.0f);
//     glVertex3f(-1.0f, 1.0f, 1.0f);
//     glVertex3f(1.0f, 1.0f, 1.0f);

//     // Bottom face (y = -1.0f)
//     glColor3f(1.0f, 1.0f, 1.0f); // White
//     glVertex3f(1.0f, -1.0f, 1.0f);
//     glVertex3f(-1.0f, -1.0f, 1.0f);
//     glVertex3f(-1.0f, -1.0f, -1.0f);
//     glVertex3f(1.0f, -1.0f, -1.0f);

//     // Front face  (z = 1.0f)
//     glColor3f(0.0f, 0.0f, 1.0f); // Blue
//     glVertex3f(1.0f, 1.0f, 1.0f);
//     glVertex3f(-1.0f, 1.0f, 1.0f);
//     glVertex3f(-1.0f, -1.0f, 1.0f);
//     glVertex3f(1.0f, -1.0f, 1.0f);

//     // Back face (z = -1.0f)
//     glColor3f(0.0f, 1.0f, 0.0f); // Green
//     glVertex3f(1.0f, -1.0f, -1.0f);
//     glVertex3f(-1.0f, -1.0f, -1.0f);
//     glVertex3f(-1.0f, 1.0f, -1.0f);
//     glVertex3f(1.0f, 1.0f, -1.0f);

//     // Left face (x = -1.0f)
//     glColor3f(1.0f, 0.5f, 0.0f); // Orange
//     glVertex3f(-1.0f, 1.0f, 1.0f);
//     glVertex3f(-1.0f, 1.0f, -1.0f);
//     glVertex3f(-1.0f, -1.0f, -1.0f);
//     glVertex3f(-1.0f, -1.0f, 1.0f);

//     // Right face (x = 1.0f)
//     glColor3f(1.0f, 0.0f, 0.0f); // Red
//     glVertex3f(1.0f, 1.0f, -1.0f);
//     glVertex3f(1.0f, 1.0f, 1.0f);
//     glVertex3f(1.0f, -1.0f, 1.0f);
//     glVertex3f(1.0f, -1.0f, -1.0f);
//     glEnd(); // End of drawing color-cube
// }

// class SmallCube
// {
// private:
//     char colors[6];

// public:
//     SmallCube(const SmallCube &other)
//     {
//         for (int i = 0; i < 6; i++)
//         {
//             colors[i] = other.colors[i];
//         }
//     }

//     SmallCube()
//     {
//         for (int i = 0; i < 6; i++)
//         {
//             colors[i] = 'N';
//         }
//     }

//     SmallCube(char *cols)
//     {
//         for (int i = 0; i < 6; i++)
//         {
//             colors[i] = cols[i];
//         }
//     }

//     SmallCube &operator=(const SmallCube &other)
//     {
//         if (this == &other)
//         {
//             return *this;
//         }

//         for (int i = 0; i < 6; i++)
//         {
//             colors[i] = other.colors[i];
//         }

//         return *this;
//     }

//     char get_side(int i)
//     {
//         return colors[i];
//     }

//     SmallCube rot90(int i)
//     {
//         char fake_cols[6];
//         for (int i = 0; i < 6; i++)
//         {
//             fake_cols[i] = colors[i];
//         }

//         if (i == 0)
//         {
//             char tmp = fake_cols[4];

//             fake_cols[4] = fake_cols[3];
//             fake_cols[3] = fake_cols[2];
//             fake_cols[2] = fake_cols[1];
//             fake_cols[1] = tmp;
//         }
//         else if (i == 1)
//         {
//             char tmp = fake_cols[0];

//             fake_cols[0] = fake_cols[2];
//             fake_cols[2] = fake_cols[5];
//             fake_cols[5] = fake_cols[4];
//             fake_cols[4] = tmp;
//         }
//         else if (i == 2)
//         {
//             char tmp = fake_cols[0];

//             fake_cols[0] = fake_cols[3];
//             fake_cols[3] = fake_cols[5];
//             fake_cols[5] = fake_cols[1];
//             fake_cols[1] = tmp;
//         }
//         else if (i == 3)
//         {
//             char tmp = fake_cols[0];

//             fake_cols[0] = fake_cols[4];
//             fake_cols[4] = fake_cols[5];
//             fake_cols[5] = fake_cols[2];
//             fake_cols[2] = tmp;
//         }
//         else if (i == 4)
//         {
//             char tmp = fake_cols[0];

//             fake_cols[0] = fake_cols[1];
//             fake_cols[1] = fake_cols[5];
//             fake_cols[5] = fake_cols[3];
//             fake_cols[3] = tmp;
//         }
//         else if (i == 5)
//         {
//             char tmp = fake_cols[1];

//             fake_cols[1] = fake_cols[2];
//             fake_cols[2] = fake_cols[3];
//             fake_cols[3] = fake_cols[4];
//             fake_cols[4] = tmp;
//         }

//         return SmallCube(fake_cols);
//     }

//     void draw()
//     {
//         glPushMatrix();
//         glBegin(GL_QUADS);
//         // Bot
//         chooseColor(colors[0]);
//         glNormal3f(0, 0, -1);
//         glVertex3f(1.0f, -1.0f, 1.0f);
//         glVertex3f(-1.0f, -1.0f, 1.0f);
//         glVertex3f(-1.0f, -1.0f, -1.0f);
//         glVertex3f(1.0f, -1.0f, -1.0f);

//         // Front
//         chooseColor(colors[1]);
//         glNormal3f(0, -1, 0);
//         glVertex3f(1.0f, 1.0f, 1.0f);
//         glVertex3f(-1.0f, 1.0f, 1.0f);
//         glVertex3f(-1.0f, -1.0f, 1.0f);
//         glVertex3f(1.0f, -1.0f, 1.0f);

//         // Right
//         chooseColor(colors[2]);
//         glNormal3f(1, 0, 0);
//         glVertex3f(1.0f, 1.0f, -1.0f);
//         glVertex3f(1.0f, 1.0f, 1.0f);
//         glVertex3f(1.0f, -1.0f, 1.0f);
//         glVertex3f(1.0f, -1.0f, -1.0f);

//         // Back
//         chooseColor(colors[3]);
//         glNormal3f(0, 0, -1);
//         glVertex3f(1.0f, -1.0f, -1.0f);
//         glVertex3f(-1.0f, -1.0f, -1.0f);
//         glVertex3f(-1.0f, 1.0f, -1.0f);
//         glVertex3f(1.0f, 1.0f, -1.0f);

//         // Left
//         chooseColor(colors[4]);
//         glNormal3f(-1, 0, 0);
//         glVertex3f(-1.0f, 1.0f, 1.0f);
//         glVertex3f(-1.0f, 1.0f, -1.0f);
//         glVertex3f(-1.0f, -1.0f, -1.0f);
//         glVertex3f(-1.0f, -1.0f, 1.0f);

//         // Top
//         chooseColor(colors[5]);
//         glNormal3f(0, 0, 1);
//         glVertex3f(1.0f, 1.0f, -1.0f);
//         glVertex3f(-1.0f, 1.0f, -1.0f);
//         glVertex3f(-1.0f, 1.0f, 1.0f);
//         glVertex3f(1.0f, 1.0f, 1.0f);

//         glEnd();
//         glPopMatrix();
//     }

//     void setSide(char c, int i)
//     {
//         colors[i] = c;
//     }

//     friend bool operator==(const SmallCube &lhs, const SmallCube &rhs)
//     {
//         for (int i = 0; i < 6; i++)
//         {
//             if (lhs.colors[i] != rhs.colors[i])
//             {
//                 return false;
//             }
//         }

//         return true;
//     }

//     friend bool operator!=(const SmallCube &lhs, const SmallCube &rhs)
//     {
//         return !(lhs == rhs);
//     }
// };

// class Cube
// {
// private:
//     SmallCube arr[3][3][3];
//     int rotate[6];
//     bool isRot[3][3][3];
// 	int current;
//     int rotatingMode;
// public:
// 	Cube& operator=(const Cube& other){
// 		if(this == &other){
// 			return *this;
// 		}

// 		for(int i = 0; i < 6; i++){
// 			rotate[i] = other.rotate[i];
// 		}

// 		current = other.current;
// 		rotatingMode = other.rotatingMode;

// 		for(int i = 0; i < 3; i++){
// 			for(int j = 0; j < 3; j++){
// 				for(int k = 0; k < 3; k++){
// 					arr[i][j][k] = other.arr[i][j][k];
// 				}
// 			}
// 		}
// 	}

// 	Cube(const Cube& other){
// 		for(int i = 0; i < 6; i++){
// 			rotate[i] = other.rotate[i];
// 		}

// 		current = other.current;
// 		rotatingMode = other.rotatingMode;

// 		for(int i = 0; i < 3; i++){
// 			for(int j = 0; j < 3; j++){
// 				for(int k = 0; k < 3; k++){
// 					arr[i][j][k] = other.arr[i][j][k];
// 				}
// 			}
// 		}
// 	}

//     Cube(int)
//     {
// 		for(int i = 0; i < 3; i++){
// 			for(int j = 0; j < 3; j++){
// 				for(int k = 0; k < 3; k++){
// 					arr[i][j][k] = SmallCube();
// 				}
// 			}
// 		}

//         for (int i = 0; i < 6; i++)
//         {
//             rotate[i] = 0;
//         }

//         rotatingMode = -1;
//         current = -1;

//         for (int i = 0; i < 3; i++)
//         {
//             for (int j = 0; j < 3; j++)
//             {
//                 arr[i][j][0].setSide('W', 0);
//             }
//         }

//         for (int j = 0; j < 3; j++)
//         {
//             for (int k = 0; k < 3; k++)
//             {
//                 arr[2][k][j].setSide('B', 1);
//             }
//         }

//         for (int i = 0; i < 3; i++)
//         {
//             for (int k = 0; k < 3; k++)
//             {
//                 arr[k][2][i].setSide('R', 2);
//             }
//         }

//         for (int j = 0; j < 3; j++)
//         {
//             for (int k = 0; k < 3; k++)
//             {
//                 arr[0][k][j].setSide('G', 3);
//             }
//         }

//         for (int i = 0; i < 3; i++)
//         {
//             for (int k = 0; k < 3; k++)
//             {
//                 arr[k][0][i].setSide('O', 4);
//             }
//         }

//         for (int i = 0; i < 3; i++)
//         {
//             for (int j = 0; j < 3; j++)
//             {
//                 arr[i][j][2].setSide('Y', 5);
//             }
//         }
//     }

	

//     void draw()
//     {
//         glPushMatrix();
//         glColor3f(0, 0, 0);
//         glutSolidCube(4.04f);
//         glPopMatrix();

//         for (int k = 0; k < 3; k++)
//         {
//             for (int i = 0; i < 3; i++)
//             {
//                 for (int j = 0; j < 3; j++)
//                 {
//                     isRot[i][j][k] = false;
//                 }
//             }
//         }

//         if (current != -1)
//         {
//             if (current == 0)
//             {
//                 for (int i = 0; i < 3; i++)
//                 {
//                     for (int j = 0; j < 3; j++)
//                     {
//                         isRot[i][j][0] = true;
//                         glPushMatrix();
//                         glRotatef(rotate[current], 0, 1, 0);

//                         glTranslatef(-2.02f + 2.02 * j, -2.02f, -2.02f + 2.02 * i);
//                         arr[i][j][0].draw();
//                         glPopMatrix();
//                     }
//                 }
//             }
//             else if (current == 5)
//             {
//                 for (int i = 0; i < 3; i++)
//                 {
//                     for (int j = 0; j < 3; j++)
//                     {
//                         isRot[i][j][2] = true;
//                         glPushMatrix();
//                         glRotatef(rotate[current], 0, -1, 0);

//                         glTranslatef(-2.02f + 2.02 * j, 2.02f, -2.02f + 2.02 * i);
//                         arr[i][j][2].draw();
//                         glPopMatrix();
//                     }
//                 }
//             }
//             else if (current == 1)
//             {
//                 for (int k = 0; k < 3; k++)
//                 {
//                     for (int j = 0; j < 3; j++)
//                     {
//                         isRot[2][j][k] = true;
//                         glPushMatrix();
//                         glRotatef(rotate[current], 0, 0, -1);

//                         glTranslatef(-2.02f + 2.02 * j, -2.02f + 2.02 * k, 2.02f);
//                         arr[2][j][k].draw();
//                         glPopMatrix();
//                     }
//                 }
//             }
//             else if (current == 3)
//             {
//                 for (int k = 0; k < 3; k++)
//                 {
//                     for (int j = 0; j < 3; j++)
//                     {
//                         isRot[0][j][k] = true;
//                         glPushMatrix();
//                         glRotatef(rotate[current], 0, 0, 1);

//                         glTranslatef(-2.02f + 2.02 * j, -2.02f + 2.02 * k, -2.02f);
//                         arr[0][j][k].draw();
//                         glPopMatrix();
//                     }
//                 }
//             }
//             else if (current == 2)
//             {
//                 for (int k = 0; k < 3; k++)
//                 {
//                     for (int i = 0; i < 3; i++)
//                     {
//                         isRot[i][2][k] = true;
//                         glPushMatrix();
//                         glRotatef(rotate[current], -1, 0, 0);

//                         glTranslatef(2.02f, -2.02f + 2.02 * k, -2.02f + 2.02 * i);
//                         arr[i][2][k].draw();
//                         glPopMatrix();
//                     }
//                 }
//             }
//             else if (current == 4)
//             {
//                 for (int k = 0; k < 3; k++)
//                 {
//                     for (int i = 0; i < 3; i++)
//                     {
//                         isRot[i][0][k] = true;
//                         glPushMatrix();
//                         glRotatef(rotate[current], 1, 0, 0);

//                         glTranslatef(-2.02f, -2.02f + 2.02 * k, -2.02f + 2.02 * i);
//                         arr[i][0][k].draw();
//                         glPopMatrix();
//                     }
//                 }
//             }
//         }

//         for (int k = 0; k < 3; k++)
//         {
//             for (int i = 0; i < 3; i++)
//             {
//                 for (int j = 0; j < 3; j++)
//                 {
//                     if (!isRot[i][j][k])
//                     {
//                         glPushMatrix();
//                         glTranslatef(-2.02f + 2.02 * j, -2.02f + 2.02 * k, -2.02f + 2.02 * i);
//                         arr[i][j][k].draw();
//                         glPopMatrix();
//                     }
//                 }
//             }
//         }
//     }

//     void rot90(char c, int sign)
//     {
//         while (sign > 0)
//         {
//             if (c == 'W')
//             {
//                 SmallCube *firstA = &arr[0][0][0];
//                 SmallCube *secondA = &arr[2][0][0];
//                 SmallCube *thirdA = &arr[2][2][0];
//                 SmallCube *fourthA = &arr[0][2][0];

//                 SmallCube tmpA = *fourthA;
//                 *fourthA = thirdA->rot90(0);
//                 *thirdA = secondA->rot90(0);
//                 *secondA = firstA->rot90(0);
//                 *firstA = tmpA.rot90(0);

//                 SmallCube *firstE = &arr[0][1][0];
//                 SmallCube *secondE = &arr[1][0][0];
//                 SmallCube *thirdE = &arr[2][1][0];
//                 SmallCube *fourthE = &arr[1][2][0];

//                 SmallCube tmpE = *fourthE;
//                 *fourthE = thirdE->rot90(0);
//                 *thirdE = secondE->rot90(0);
//                 *secondE = firstE->rot90(0);
//                 *firstE = tmpE.rot90(0);
//             }
//             else if (c == 'Y')
//             {
//                 SmallCube *firstA = &arr[0][0][2];
//                 SmallCube *secondA = &arr[0][2][2];
//                 SmallCube *thirdA = &arr[2][2][2];
//                 SmallCube *fourthA = &arr[2][0][2];

//                 SmallCube tmpA = *fourthA;
//                 *fourthA = thirdA->rot90(5);
//                 *thirdA = secondA->rot90(5);
//                 *secondA = firstA->rot90(5);
//                 *firstA = tmpA.rot90(5);

//                 SmallCube *firstE = &arr[0][1][2];
//                 SmallCube *secondE = &arr[1][2][2];
//                 SmallCube *thirdE = &arr[2][1][2];
//                 SmallCube *fourthE = &arr[1][0][2];

//                 SmallCube tmpE = *fourthE;
//                 *fourthE = thirdE->rot90(5);
//                 *thirdE = secondE->rot90(5);
//                 *secondE = firstE->rot90(5);
//                 *firstE = tmpE.rot90(5);
//             }
//             else if (c == 'B')
//             {
//                 SmallCube *firstA = &arr[2][0][0];
//                 SmallCube *secondA = &arr[2][0][2];
//                 SmallCube *thirdA = &arr[2][2][2];
//                 SmallCube *fourthA = &arr[2][2][0];

//                 SmallCube tmpA = *fourthA;
//                 *fourthA = thirdA->rot90(1);
//                 *thirdA = secondA->rot90(1);
//                 *secondA = firstA->rot90(1);
//                 *firstA = tmpA.rot90(1);

//                 SmallCube *firstE = &arr[2][0][1];
//                 SmallCube *secondE = &arr[2][1][2];
//                 SmallCube *thirdE = &arr[2][2][1];
//                 SmallCube *fourthE = &arr[2][1][0];

//                 SmallCube tmpE = *fourthE;
//                 *fourthE = thirdE->rot90(1);
//                 *thirdE = secondE->rot90(1);
//                 *secondE = firstE->rot90(1);
//                 *firstE = tmpE.rot90(1);
//             }
//             else if (c == 'G')
//             {
//                 SmallCube *firstA = &arr[0][0][0];
//                 SmallCube *secondA = &arr[0][2][0];
//                 SmallCube *thirdA = &arr[0][2][2];
//                 SmallCube *fourthA = &arr[0][0][2];

//                 SmallCube tmpA = *fourthA;
//                 *fourthA = thirdA->rot90(3);
//                 *thirdA = secondA->rot90(3);
//                 *secondA = firstA->rot90(3);
//                 *firstA = tmpA.rot90(3);

//                 SmallCube *firstE = &arr[0][1][0];
//                 SmallCube *secondE = &arr[0][2][1];
//                 SmallCube *thirdE = &arr[0][1][2];
//                 SmallCube *fourthE = &arr[0][0][1];

//                 SmallCube tmpE = *fourthE;
//                 *fourthE = thirdE->rot90(3);
//                 *thirdE = secondE->rot90(3);
//                 *secondE = firstE->rot90(3);
//                 *firstE = tmpE.rot90(3);
//             }
//             else if (c == 'R')
//             {
//                 SmallCube *firstA = &arr[2][2][0];
//                 SmallCube *secondA = &arr[2][2][2];
//                 SmallCube *thirdA = &arr[0][2][2];
//                 SmallCube *fourthA = &arr[0][2][0];

//                 SmallCube tmpA = *fourthA;
//                 *fourthA = thirdA->rot90(2);
//                 *thirdA = secondA->rot90(2);
//                 *secondA = firstA->rot90(2);
//                 *firstA = tmpA.rot90(2);

//                 SmallCube *firstE = &arr[2][2][1];
//                 SmallCube *secondE = &arr[1][2][2];
//                 SmallCube *thirdE = &arr[0][2][1];
//                 SmallCube *fourthE = &arr[1][2][0];

//                 SmallCube tmpE = *fourthE;
//                 *fourthE = thirdE->rot90(2);
//                 *thirdE = secondE->rot90(2);
//                 *secondE = firstE->rot90(2);
//                 *firstE = tmpE.rot90(2);
//             }
//             else if (c == 'O')
//             {
//                 SmallCube *firstA = &arr[0][0][0];
//                 SmallCube *secondA = &arr[0][0][2];
//                 SmallCube *thirdA = &arr[2][0][2];
//                 SmallCube *fourthA = &arr[2][0][0];

//                 SmallCube tmpA = *fourthA;
//                 *fourthA = thirdA->rot90(4);
//                 *thirdA = secondA->rot90(4);
//                 *secondA = firstA->rot90(4);
//                 *firstA = tmpA.rot90(4);

//                 SmallCube *firstE = &arr[0][0][1];
//                 SmallCube *secondE = &arr[1][0][2];
//                 SmallCube *thirdE = &arr[2][0][1];
//                 SmallCube *fourthE = &arr[1][0][0];

//                 SmallCube tmpE = *fourthE;
//                 *fourthE = thirdE->rot90(4);
//                 *thirdE = secondE->rot90(4);
//                 *secondE = firstE->rot90(4);
//                 *firstE = tmpE.rot90(4);
//             }

//             sign--;
//         }
//     }

//     bool Rotate(int side, int angle)
//     {
//         if (current == -1 || current == side)
//         {
//             rotatingMode = 0;
//             rotate[side] += angle;

//             if (rotate[side] % 90 != 0)
//             {
//                 current = side;
//                 rotatingMode = 0;
//             }
//             else
//             {
//                 if (side == 0)
//                 {
//                     this->rot90('W', 1);
//                 }
//                 else if (side == 5)
//                 {
//                     this->rot90('Y', 1);
//                 }
//                 else if (side == 1)
//                 {
//                     this->rot90('B', 1);
//                 }
//                 else if (side == 3)
//                 {
//                     this->rot90('G', 1);
//                 }
//                 else if (side == 2)
//                 {
//                     this->rot90('R', 1);
//                 }
//                 else if (side == 4)
//                 {
//                     this->rot90('O', 1);
//                 }
//                 rotate[side] = 0;
//                 current = -1;
//                 rotatingMode = -1;

//                 return true;
//             }
//         }

//         return false;
//     }

// 	bool Rotate2(int side, int angle)
//     {
//         if (current == -1 || current == side)
//         {
//             rotatingMode = 1;
//             rotate[side] += angle;

//             if (rotate[side] % 180 != 0)
//             {
//                 current = side;
//                 rotatingMode = 1;
//             }
//             else
//             {
//                 if (side == 0)
//                 {
//                     this->rot90('W', 2);
//                 }
//                 else if (side == 5)
//                 {
//                     this->rot90('Y', 2);
//                 }
//                 else if (side == 1)
//                 {
//                     this->rot90('B', 2);
//                 }
//                 else if (side == 3)
//                 {
//                     this->rot90('G', 2);
//                 }
//                 else if (side == 2)
//                 {
//                     this->rot90('R', 2);
//                 }
//                 else if (side == 4)
//                 {
//                     this->rot90('O', 2);
//                 }
//                 rotate[side] = 0;
//                 current = -1;
//                 rotatingMode = -1;

//                 return true;
//             }
//         }

//         return false;
//     }

// 	bool Rotate3(int side, int angle)
//     {
//         if (current == -1 || current == side)
//         {
//             rotatingMode = 2;
//             rotate[side] -= angle;

//             if ((360 + rotate[side]) % 270 != 0)
//             {
//                 current = side;
//                 rotatingMode = 2;
//             }
//             else
//             {
//                 if (side == 0)
//                 {
//                     this->rot90('W', 3);
//                 }
//                 else if (side == 5)
//                 {
//                     this->rot90('Y', 3);
//                 }
//                 else if (side == 1)
//                 {
//                     this->rot90('B', 3);
//                 }
//                 else if (side == 3)
//                 {
//                     this->rot90('G', 3);
//                 }
//                 else if (side == 2)
//                 {
//                     this->rot90('R', 3);
//                 }
//                 else if (side == 4)
//                 {
//                     this->rot90('O', 3);
//                 }
//                 rotate[side] = 0;
//                 current = -1;
//                 rotatingMode = -1;

//                 return true;
//             }
//         }

//         return false;
//     }


//     void rot90(char c)
//     {
//         this->rot90(c, 1);
//     }

//     void rot180(char c)
//     {
//         this->rot90(c, 2);
//     }

//     void rot270(char c)
//     {
//         this->rot90(c, 3);
//     }

//     int step1(std::string &answer)
//     {
//         int c = 0;
//         int m = 0;

//         while (c != 4)
//         {
//             bool tmp = true;

//             // 1
//             if (arr[2][1][2].get_side(2 - 1) == 'B' && arr[2][1][2].get_side(6 - 1) == 'W')
//             {
//                 this->rot180('B');
//                 answer.append(" F2");
//                 tmp = false;
//             }

//             if (arr[1][2][2].get_side(3 - 1) == 'R' && arr[1][2][2].get_side(6 - 1) == 'W')
//             {
//                 this->rot180('R');
//                 answer.append(" R2");
//                 tmp = false;
//             }

//             if (arr[1][0][2].get_side(5 - 1) == 'O' && arr[1][0][2].get_side(6 - 1) == 'W')
//             {
//                 this->rot180('O');
//                 answer.append(" L2");
//                 tmp = false;
//             }

//             if (arr[0][1][2].get_side(4 - 1) == 'G' && arr[0][1][2].get_side(6 - 1) == 'W')
//             {
//                 this->rot180('G');
//                 answer.append(" B2");
//                 tmp = false;
//             }

//             // 2
//             if (arr[2][1][2].get_side(2 - 1) == 'W' && arr[2][1][2].get_side(6 - 1) == 'B')
//             {
//                 this->rot270('Y');
//                 this->rot270('R');
//                 this->rot90('B');
//                 this->rot90('R');
//                 answer.append(" T' R' F R");
//                 tmp = false;
//             }

//             if (arr[1][2][2].get_side(3 - 1) == 'W' && arr[1][2][2].get_side(6 - 1) == 'R')
//             {
//                 this->rot270('Y');
//                 this->rot270('G');
//                 this->rot90('R');
//                 this->rot90('G');
//                 answer.append(" T' B' R B");
//                 tmp = false;
//             }

//             if (arr[1][0][2].get_side(5 - 1) == 'W' && arr[1][0][2].get_side(6 - 1) == 'O')
//             {
//                 this->rot270('Y');
//                 this->rot270('B');
//                 this->rot90('O');
//                 this->rot90('B');
//                 answer.append(" T' F' L F");
//                 tmp = false;
//             }

//             if (arr[0][1][2].get_side(4 - 1) == 'W' && arr[0][1][2].get_side(6 - 1) == 'G')
//             {
//                 this->rot270('Y');
//                 this->rot270('O');
//                 this->rot90('G');
//                 this->rot90('O');
//                 answer.append(" T' L' B L");
//                 tmp = false;
//             }

//             // 3
//             if (arr[2][2][1].get_side(2 - 1) == 'W')
//             {
//                 this->rot270('B');
//                 this->rot270('Y');
//                 this->rot90('B');
//                 answer.append(" F' T' F");
//                 tmp = false;
//             }

//             if (arr[0][2][1].get_side(3 - 1) == 'W')
//             {
//                 this->rot270('R');
//                 this->rot270('Y');
//                 this->rot90('R');
//                 answer.append(" R' T' R");
//                 tmp = false;
//             }

//             if (arr[2][0][1].get_side(5 - 1) == 'W')
//             {
//                 this->rot270('O');
//                 this->rot270('Y');
//                 this->rot90('O');
//                 answer.append(" L' T' L");
//                 tmp = false;
//             }

//             if (arr[0][0][1].get_side(4 - 1) == 'W')
//             {
//                 this->rot270('G');
//                 this->rot270('Y');
//                 this->rot90('G');
//                 answer.append(" B' T' B");
//                 tmp = false;
//             }

//             // 4
//             if (arr[2][0][1].get_side(2 - 1) == 'W')
//             {
//                 this->rot90('B');
//                 this->rot270('Y');
//                 this->rot270('B');
//                 answer.append(" F T' F'");
//                 tmp = false;
//             }

//             if (arr[2][2][1].get_side(3 - 1) == 'W')
//             {
//                 this->rot90('R');
//                 this->rot270('Y');
//                 this->rot270('R');
//                 answer.append(" R T' R'");
//                 tmp = false;
//             }

//             if (arr[0][0][1].get_side(5 - 1) == 'W')
//             {
//                 this->rot90('O');
//                 this->rot270('Y');
//                 this->rot270('O');
//                 answer.append(" L T' L'");
//                 tmp = false;
//             }

//             if (arr[0][2][1].get_side(4 - 1) == 'W')
//             {
//                 this->rot90('G');
//                 this->rot270('Y');
//                 this->rot270('G');
//                 answer.append(" B T' B'");
//                 tmp = false;
//             }

//             // 5
//             if (arr[2][1][0].get_side(2 - 1) == 'W')
//             {
//                 this->rot180('B');
//                 this->rot270('Y');
//                 this->rot180('B');
//                 answer.append(" F2 T' F2");
//                 tmp = false;
//             }

//             if (arr[1][2][0].get_side(3 - 1) == 'W')
//             {
//                 this->rot180('R');
//                 this->rot270('Y');
//                 this->rot180('R');
//                 answer.append(" R2 T' R2");
//                 tmp = false;
//             }

//             if (arr[1][0][0].get_side(5 - 1) == 'W')
//             {
//                 this->rot180('O');
//                 this->rot270('Y');
//                 this->rot180('O');
//                 answer.append(" L2 T' L2");
//                 tmp = false;
//             }

//             if (arr[0][1][0].get_side(4 - 1) == 'W')
//             {
//                 this->rot180('G');
//                 this->rot270('Y');
//                 this->rot180('G');
//                 answer.append(" B2 T' B2");
//                 tmp = false;
//             }

//             // 6
//             if (arr[2][1][0].get_side(2 - 1) != 'B' && arr[2][1][0].get_side(1 - 1) == 'W')
//             {
//                 this->rot180('B');
//                 this->rot270('Y');
//                 this->rot180('B');
//                 answer.append(" F2 T' F2");
//                 tmp = false;
//             }

//             if (arr[1][2][0].get_side(3 - 1) != 'R' && arr[1][2][0].get_side(1 - 1) == 'W')
//             {
//                 this->rot180('R');
//                 this->rot270('Y');
//                 this->rot180('R');
//                 answer.append(" R2 T' R2");
//                 tmp = false;
//             }

//             if (arr[1][0][0].get_side(5 - 1) != 'O' && arr[1][0][0].get_side(1 - 1) == 'W')
//             {
//                 this->rot180('O');
//                 this->rot270('Y');
//                 this->rot180('O');
//                 answer.append(" L2 T' L2");
//                 tmp = false;
//             }

//             if (arr[0][1][0].get_side(4 - 1) != 'G' && arr[0][1][0].get_side(1 - 1) == 'W')
//             {
//                 this->rot180('G');
//                 this->rot270('Y');
//                 this->rot180('G');
//                 answer.append(" B2 T' B2");
//                 tmp = false;
//             }

//             //
//             if (!tmp)
//             {
//                 c = 0;
//             }
//             else
//             {
//                 this->rot90('Y');
//                 answer.append(" T");
//                 c++;
//             }

//             m++;
//             if (m == 1000)
//             {
//                 return m;
//             }
//         }

//         return m;
//     }

//     int getCurrent()
//     {
//         return current;
//     }

//     int getRotatingMode()
//     {
//         return rotatingMode;
//     }

//     int step2(std::string &answer)
//     {
//         int c = 0;
//         int m = 0;

//         while (c != 4)
//         {
//             bool tmp = true;

//             // 1
//             if (arr[2][2][2].get_side(2 - 1) == 'W' && arr[2][2][2].get_side(6 - 1) == 'B' && arr[2][2][2].get_side(3 - 1) == 'R')
//             {
//                 this->rot270('B');
//                 this->rot270('Y');
//                 this->rot90('B');
//                 tmp = false;

//                 answer.append(" F' T' F");
//                 // cout << "1" << endl;
//             }

//             if (arr[2][0][2].get_side(5 - 1) == 'W' && arr[2][0][2].get_side(2 - 1) == 'B' && arr[2][0][2].get_side(6 - 1) == 'O')
//             {
//                 this->rot270('O');
//                 this->rot270('Y');
//                 this->rot90('O');
//                 tmp = false;

//                 answer.append(" L' T' L");
//                 // cout << "1" << endl;
//             }

//             if (arr[0][2][2].get_side(4 - 1) == 'G' && arr[0][2][2].get_side(3 - 1) == 'W' && arr[0][2][2].get_side(6 - 1) == 'R')
//             {
//                 this->rot270('R');
//                 this->rot270('Y');
//                 this->rot90('R');
//                 tmp = false;

//                 answer.append(" R' T' R");
//                 // cout << "1" << endl;
//             }

//             if (arr[0][0][2].get_side(4 - 1) == 'W' && arr[0][0][2].get_side(6 - 1) == 'G' && arr[0][0][2].get_side(5 - 1) == 'O')
//             {
//                 this->rot270('G');
//                 this->rot270('Y');
//                 this->rot90('G');
//                 tmp = false;

//                 answer.append(" B' T' B");
//                 // cout << "1" << endl;
//             }

//             // 2
//             if (arr[2][2][2].get_side(2 - 1) == 'B' && arr[2][2][2].get_side(3 - 1) == 'W' && arr[2][2][2].get_side(6 - 1) == 'R')
//             {
//                 this->rot90('R');
//                 this->rot90('Y');
//                 this->rot270('R');
//                 tmp = false;

//                 answer.append(" R T R'");
//                 // cout << "2" << endl;
//             }

//             if (arr[2][0][2].get_side(2 - 1) == 'W' && arr[2][0][2].get_side(6 - 1) == 'B' && arr[2][0][2].get_side(5 - 1) == 'O')
//             {
//                 this->rot90('B');
//                 this->rot90('Y');
//                 this->rot270('B');
//                 tmp = false;

//                 answer.append(" F T F'");
//                 // cout << "2" << endl;
//             }

//             if (arr[0][2][2].get_side(4 - 1) == 'W' && arr[0][2][2].get_side(6 - 1) == 'G' && arr[0][2][2].get_side(3 - 1) == 'R')
//             {
//                 this->rot90('G');
//                 this->rot90('Y');
//                 this->rot270('G');
//                 tmp = false;

//                 answer.append(" B T B'");
//                 // cout << "2" << endl;
//             }

//             if (arr[0][0][2].get_side(4 - 1) == 'G' && arr[0][0][2].get_side(6 - 1) == 'O' && arr[0][0][2].get_side(5 - 1) == 'W')
//             {
//                 this->rot90('O');
//                 this->rot90('Y');
//                 this->rot270('O');
//                 tmp = false;

//                 answer.append(" L T L'");
//                 // cout << "2" << endl;
//             }

//             // 3
//             if (arr[2][2][2].get_side(2 - 1) == 'R' && arr[2][2][2].get_side(3 - 1) == 'B' && arr[2][2][2].get_side(6 - 1) == 'W')
//             {
//                 this->rot90('R');

//                 this->rot270('Y');

//                 this->rot270('R');

//                 this->rot180('Y');

//                 this->rot90('R');

//                 this->rot90('Y');

//                 this->rot270('R');
//                 tmp = false;

//                 answer.append(" R T' R' T2 R T R'");
//                 // cout << "3" << endl;
//             }

//             if (arr[2][0][2].get_side(2 - 1) == 'O' && arr[2][0][2].get_side(6 - 1) == 'W' && arr[2][0][2].get_side(5 - 1) == 'B')
//             {
//                 this->rot90('B');

//                 this->rot270('Y');

//                 this->rot270('B');

//                 this->rot180('Y');

//                 this->rot90('B');

//                 this->rot90('Y');

//                 this->rot270('B');
//                 tmp = false;

//                 answer.append(" F T' F' T2 F T F'");
//                 // cout << "3" << endl;
//             }

//             if (arr[0][2][2].get_side(4 - 1) == 'R' && arr[0][2][2].get_side(6 - 1) == 'W' && arr[0][2][2].get_side(3 - 1) == 'G')
//             {
//                 this->rot90('G');

//                 this->rot270('Y');

//                 this->rot270('G');

//                 this->rot180('Y');

//                 this->rot90('G');

//                 this->rot90('Y');

//                 this->rot270('G');
//                 tmp = false;

//                 answer.append(" B T' B' T2 B T B'");
//                 // cout << "3" << endl;
//             }

//             if (arr[0][0][2].get_side(4 - 1) == 'O' && arr[0][0][2].get_side(6 - 1) == 'W' && arr[0][0][2].get_side(5 - 1) == 'G')
//             {
//                 this->rot90('O');

//                 this->rot270('Y');

//                 this->rot270('O');

//                 this->rot180('Y');

//                 this->rot90('O');

//                 this->rot90('Y');

//                 this->rot270('O');
//                 tmp = false;

//                 answer.append(" L T' L' T2 L T L'");
//                 // cout << "3" << endl;
//             }

//             // 4
//             if (arr[2][2][0].get_side(2 - 1) == 'W')
//             {
//                 this->rot270('B');
//                 this->rot270('Y');
//                 this->rot90('B');
//                 tmp = false;

//                 answer.append(" F' T' F");
//                 // cout << "4" << endl;
//             }

//             if (arr[2][0][0].get_side(5 - 1) == 'W')
//             {
//                 this->rot270('O');
//                 this->rot270('Y');
//                 this->rot90('O');
//                 tmp = false;

//                 answer.append(" L' T' L");
//                 // cout << "4" << endl;
//             }

//             if (arr[0][2][0].get_side(3 - 1) == 'W')
//             {
//                 this->rot270('R');
//                 this->rot270('Y');
//                 this->rot90('R');
//                 tmp = false;

//                 answer.append(" R' T' R");
//                 // cout << "4" << endl;
//             }

//             if (arr[0][0][0].get_side(4 - 1) == 'W')
//             {
//                 this->rot270('G');
//                 this->rot270('Y');
//                 this->rot90('G');
//                 tmp = false;

//                 answer.append(" B' T' B");
//                 // cout << "4" << endl;
//             }

//             // 5
//             if (arr[2][2][0].get_side(3 - 1) == 'W')
//             {
//                 this->rot270('B');
//                 this->rot270('Y');
//                 this->rot90('B');
//                 tmp = false;

//                 answer.append(" F' T' F");
//                 // cout << "5" << endl;
//             }

//             if (arr[2][0][0].get_side(2 - 1) == 'W')
//             {
//                 this->rot270('O');
//                 this->rot270('Y');
//                 this->rot90('O');
//                 tmp = false;

//                 answer.append(" L' T' L");
//                 // cout << "5" << endl;
//             }

//             if (arr[0][2][0].get_side(4 - 1) == 'W')
//             {
//                 this->rot270('R');
//                 this->rot270('Y');
//                 this->rot90('R');
//                 tmp = false;

//                 answer.append(" R' T' R");
//                 // cout << "5" << endl;
//             }

//             if (arr[0][0][0].get_side(5 - 1) == 'W')
//             {
//                 this->rot270('G');
//                 this->rot270('Y');
//                 this->rot90('G');
//                 tmp = false;

//                 answer.append(" B' T' B");
//                 // cout << "5" << endl;
//             }

//             // 6
//             if ((arr[2][0][0].get_side(2 - 1) != 'B' || arr[2][0][0].get_side(5 - 1) != 'O') && arr[2][0][0].get_side(1 - 1) == 'W')
//             {
//                 this->rot90('B');
//                 this->rot270('Y');
//                 this->rot270('B');
//                 tmp = false;

//                 answer.append(" F T' F'");
//                 // cout << "6" << endl;
//             }

//             if ((arr[2][2][0].get_side(2 - 1) != 'B' || arr[2][2][0].get_side(3 - 1) != 'R') && arr[2][2][0].get_side(1 - 1) == 'W')
//             {
//                 this->rot90('R');
//                 this->rot270('Y');
//                 this->rot270('R');
//                 tmp = false;

//                 answer.append(" R T' R'");
//                 // cout << "6" << endl;
//             }

//             if ((arr[0][2][0].get_side(3 - 1) != 'R' || arr[0][2][0].get_side(4 - 1) != 'G') && arr[0][2][0].get_side(1 - 1) == 'W')
//             {
//                 this->rot90('G');
//                 this->rot270('Y');
//                 this->rot270('G');
//                 tmp = false;

//                 answer.append(" B T' B'");
//                 // cout << "6" << endl;
//             }

//             if ((arr[0][0][0].get_side(4 - 1) != 'G' || arr[0][0][0].get_side(5 - 1) != 'O') && arr[0][0][0].get_side(1 - 1) == 'W')
//             {
//                 this->rot90('O');
//                 this->rot270('Y');
//                 this->rot270('O');
//                 tmp = false;

//                 answer.append(" L T' L'");
//                 // cout << "6" << endl;
//             }

//             if (!tmp)
//             {
//                 c = 0;
//             }
//             else
//             {
//                 this->rot90('Y');
//                 c++;
//                 answer.append(" T");
//                 // cout << c << endl;
//             }

//             m++;
//             if (m == 1000)
//             {
//                 return m;
//             }
//         }

//         return m;
//     }

//     int step3(std::string &answer)
//     {
//         int c = 0;
//         int m = 0;

//         while (c != 4)
//         {
//             bool tmp = true;

//             // 1
//             if (arr[2][1][2].get_side(2 - 1) == 'B' && arr[2][1][2].get_side(6 - 1) == 'O')
//             {
//                 this->rot270('Y');
//                 this->rot270('O');
//                 this->rot90('Y');
//                 this->rot90('O');

//                 this->rot90('Y');
//                 this->rot90('B');
//                 this->rot270('Y');
//                 this->rot270('B');

//                 answer.append(" T' L' T L T F T' F'");
//                 tmp = false;
//             }

//             if (arr[1][2][2].get_side(3 - 1) == 'R' && arr[1][2][2].get_side(6 - 1) == 'B')
//             {
//                 this->rot270('Y');
//                 this->rot270('B');
//                 this->rot90('Y');
//                 this->rot90('B');

//                 this->rot90('Y');
//                 this->rot90('R');
//                 this->rot270('Y');
//                 this->rot270('R');

//                 answer.append(" T' F' T F T R T' R'");
//                 tmp = false;
//             }

//             if (arr[0][1][2].get_side(4 - 1) == 'G' && arr[0][1][2].get_side(6 - 1) == 'R')
//             {
//                 this->rot270('Y');
//                 this->rot270('R');
//                 this->rot90('Y');
//                 this->rot90('R');

//                 this->rot90('Y');
//                 this->rot90('G');
//                 this->rot270('Y');
//                 this->rot270('G');

//                 answer.append(" T' R' T R T B T' B'");
//                 tmp = false;
//             }

//             if (arr[1][0][2].get_side(5 - 1) == 'O' && arr[1][0][2].get_side(6 - 1) == 'G')
//             {
//                 this->rot270('Y');
//                 this->rot270('G');
//                 this->rot90('Y');
//                 this->rot90('G');

//                 this->rot90('Y');
//                 this->rot90('O');
//                 this->rot270('Y');
//                 this->rot270('O');

//                 answer.append(" T' B' T B T L T' L'");
//                 tmp = false;
//             }

//             // 2
//             if (arr[2][1][2].get_side(6 - 1) == 'R' && arr[2][1][2].get_side(2 - 1) == 'B')
//             {
//                 this->rot90('Y');
//                 this->rot90('R');
//                 this->rot270('Y');
//                 this->rot270('R');

//                 this->rot270('Y');
//                 this->rot270('B');
//                 this->rot90('Y');
//                 this->rot90('B');

//                 answer.append(" T R T' R' T' F' T F");
//                 tmp = false;
//             }

//             if (arr[1][0][2].get_side(6 - 1) == 'B' && arr[1][0][2].get_side(5 - 1) == 'O')
//             {
//                 this->rot90('Y');
//                 this->rot90('B');
//                 this->rot270('Y');
//                 this->rot270('B');

//                 this->rot270('Y');
//                 this->rot270('O');
//                 this->rot90('Y');
//                 this->rot90('O');

//                 answer.append(" T F T' F' T' L' T L");
//                 tmp = false;
//             }

//             if (arr[0][1][2].get_side(4 - 1) == 'G' && arr[0][1][2].get_side(6 - 1) == 'O')
//             {
//                 this->rot90('Y');
//                 this->rot90('O');
//                 this->rot270('Y');
//                 this->rot270('O');

//                 this->rot270('Y');
//                 this->rot270('G');
//                 this->rot90('Y');
//                 this->rot90('G');

//                 answer.append(" T L T' L' T' B' T B");
//                 tmp = false;
//             }

//             if (arr[1][2][2].get_side(6 - 1) == 'G' && arr[1][2][2].get_side(3 - 1) == 'R')
//             {
//                 this->rot90('Y');
//                 this->rot90('G');
//                 this->rot270('Y');
//                 this->rot270('G');

//                 this->rot270('Y');
//                 this->rot270('R');
//                 this->rot90('Y');
//                 this->rot90('R');

//                 answer.append(" T B T' B' T' R' T R");
//                 tmp = false;
//             }

//             if (!tmp)
//             {
//                 c = 0;
//             }
//             else
//             {
//                 this->rot90('Y');
//                 c++;
//                 answer.append(" T");

//                 if (c == 4)
//                 {
//                     if (arr[2][2][1].get_side(2 - 1) != 'B' || arr[2][2][1].get_side(3 - 1) != 'R')
//                     {
//                         this->rot90('Y');
//                         this->rot90('R');
//                         this->rot270('Y');
//                         this->rot270('R');

//                         this->rot270('Y');
//                         this->rot270('B');
//                         this->rot90('Y');
//                         this->rot90('B');

//                         answer.append(" T R T' R' T' F' T F");
//                         c = 0;
//                     }
//                     else if (arr[2][0][1].get_side(2 - 1) != 'B' || arr[2][0][1].get_side(5 - 1) != 'O')
//                     {
//                         this->rot90('Y');
//                         this->rot90('B');
//                         this->rot270('Y');
//                         this->rot270('B');

//                         this->rot270('Y');
//                         this->rot270('O');
//                         this->rot90('Y');
//                         this->rot90('O');

//                         answer.append(" T F T' F' T' L' T L");
//                         c = 0;
//                     }
//                     else if (arr[0][0][1].get_side(4 - 1) != 'G' || arr[0][0][1].get_side(5 - 1) != 'O')
//                     {
//                         this->rot90('Y');
//                         this->rot90('O');
//                         this->rot270('Y');
//                         this->rot270('O');

//                         this->rot270('Y');
//                         this->rot270('G');
//                         this->rot90('Y');
//                         this->rot90('G');

//                         answer.append(" T L T' L' T' B' T B");
//                         c = 0;
//                     }
//                     else if (arr[0][2][1].get_side(4 - 1) != 'G' || arr[0][2][1].get_side(3 - 1) != 'R')
//                     {
//                         this->rot90('Y');
//                         this->rot90('G');
//                         this->rot270('Y');
//                         this->rot270('G');

//                         this->rot270('Y');
//                         this->rot270('R');
//                         this->rot90('Y');
//                         this->rot90('R');

//                         answer.append(" T B T' B' T' R' T R");
//                         c = 0;
//                     }
//                 }
//             }

//             m++;
//             if (m == 1000)
//             {
//                 return m;
//             }
//         }

//         return m;
//     }

//     void step4(std::string &answer)
//     {
//         if (
//             arr[2][1][2].get_side(2 - 1) == 'Y' && arr[1][2][2].get_side(3 - 1) == 'Y' && arr[1][0][2].get_side(6 - 1) == 'Y' && arr[0][1][2].get_side(6 - 1) == 'Y')
//         {
//             this->rot90('B');
//             this->rot90('Y');
//             this->rot90('R');

//             this->rot270('Y');
//             this->rot270('R');
//             this->rot270('B');

//             answer.append(" F T R T' R' F'");
//         }
//         else if (
//             arr[2][1][2].get_side(2 - 1) == 'Y' && arr[1][0][2].get_side(5 - 1) == 'Y' && arr[0][1][2].get_side(6 - 1) == 'Y' && arr[1][2][2].get_side(6 - 1) == 'Y')
//         {
//             this->rot90('O');
//             this->rot90('Y');
//             this->rot90('B');

//             this->rot270('Y');
//             this->rot270('B');
//             this->rot270('O');

//             answer.append(" L T F T' F' L'");
//         }
//         else if (
//             arr[0][1][2].get_side(4 - 1) == 'Y' && arr[1][2][2].get_side(3 - 1) == 'Y' && arr[2][1][2].get_side(6 - 1) == 'Y' && arr[1][0][2].get_side(6 - 1) == 'Y')
//         {
//             this->rot90('R');
//             this->rot90('Y');
//             this->rot90('G');

//             this->rot270('Y');
//             this->rot270('G');
//             this->rot270('R');

//             answer.append(" R T B T' B' R'");
//         }
//         else if (
//             arr[0][1][2].get_side(4 - 1) == 'Y' && arr[1][0][2].get_side(5 - 1) == 'Y' && arr[2][1][2].get_side(6 - 1) == 'Y' && arr[1][2][2].get_side(6 - 1) == 'Y')
//         {
//             this->rot90('G');
//             this->rot90('Y');
//             this->rot90('O');

//             this->rot270('Y');
//             this->rot270('O');
//             this->rot270('G');

//             answer.append(" B T L T' L' B'");
//         }
//         else if (
//             arr[2][1][2].get_side(2 - 1) == 'Y' && arr[0][1][2].get_side(4 - 1) == 'Y' && arr[1][0][2].get_side(6 - 1) == 'Y' && arr[1][2][2].get_side(6 - 1) == 'Y')
//         {
//             this->rot90('B');
//             this->rot90('R');
//             this->rot90('Y');

//             this->rot270('R');
//             this->rot270('Y');
//             this->rot270('B');

//             answer.append(" F R T R' T' F'");
//         }
//         else if (
//             arr[2][1][2].get_side(6 - 1) == 'Y' && arr[0][1][2].get_side(6 - 1) == 'Y' && arr[1][0][2].get_side(5 - 1) == 'Y' && arr[1][2][2].get_side(3 - 1) == 'Y')
//         {
//             this->rot90('R');
//             this->rot90('G');
//             this->rot90('Y');

//             this->rot270('G');
//             this->rot270('Y');
//             this->rot270('R');

//             answer.append(" R B T B' T' R'");
//         }
//         else if (
//             arr[2][1][2].get_side(2 - 1) == 'Y' && arr[1][0][2].get_side(5 - 1) == 'Y' && arr[0][1][2].get_side(4 - 1) == 'Y' && arr[1][2][2].get_side(3 - 1) == 'Y')
//         {
//             this->rot90('B');
//             this->rot90('Y');
//             this->rot90('R');

//             this->rot270('Y');
//             this->rot270('R');
//             this->rot270('B');

//             this->rot90('R');
//             this->rot90('G');
//             this->rot90('Y');

//             this->rot270('G');
//             this->rot270('Y');
//             this->rot270('R');

//             answer.append(" F T R T' R' F' R B T B' T' R'");
//         }
//     }

//     void step5(std::string &answer)
//     {
//         // 1
//         if (arr[1][2][2].get_side(3 - 1) == 'B')
//         {
//             this->rot90('Y');
//             this->rot270('O');
//             this->rot180('Y');

//             this->rot90('O');
//             this->rot90('Y');
//             this->rot270('O');

//             this->rot90('Y');
//             this->rot90('O');

//             answer.append(" T L' T2 L T L' T L");
//         }
//         else if (arr[1][0][2].get_side(5 - 1) == 'B')
//         {
//             this->rot90('Y');
//             this->rot270('G');
//             this->rot180('Y');

//             this->rot90('G');
//             this->rot90('Y');
//             this->rot270('G');

//             this->rot90('Y');
//             this->rot90('G');

//             answer.append(" T B' T2 B T B' T B");
//         }
//         else if (arr[0][1][2].get_side(4 - 1) == 'B')
//         {
//             this->rot90('Y');
//             this->rot270('R');
//             this->rot180('Y');

//             this->rot90('R');
//             this->rot90('Y');
//             this->rot270('R');

//             this->rot90('Y');
//             this->rot90('R');
//             this->rot90('Y');

//             this->rot270('G');
//             this->rot180('Y');
//             this->rot90('G');

//             this->rot90('Y');
//             this->rot270('G');
//             this->rot90('Y');

//             this->rot90('G');
//             this->rot90('Y');
//             this->rot270('R');

//             this->rot180('Y');
//             this->rot90('R');
//             this->rot90('Y');

//             this->rot270('R');
//             this->rot90('Y');
//             this->rot90('R');

//             answer.append(" T R' T2 R T R' T R T B' T2 B T B' T B T R' T2 R T R' T R");
//         }

//         // 2
//         if (arr[0][1][2].get_side(4 - 1) == 'R')
//         {
//             this->rot90('Y');
//             this->rot270('B');

//             this->rot180('Y');
//             this->rot90('B');

//             this->rot90('Y');
//             this->rot270('B');

//             this->rot90('Y');
//             this->rot90('B');

//             answer.append(" T F' T2 F T F' T F");
//         }
//         else if (arr[1][0][2].get_side(5 - 1) == 'R')
//         {
//             this->rot90('Y');
//             this->rot270('G');

//             this->rot180('Y');
//             this->rot90('G');

//             this->rot90('Y');
//             this->rot270('G');

//             this->rot90('Y');
//             this->rot90('G');

//             this->rot90('Y');
//             this->rot270('O');

//             this->rot180('Y');
//             this->rot90('O');

//             this->rot90('Y');
//             this->rot270('O');

//             this->rot90('Y');
//             this->rot90('O');

//             this->rot90('Y');
//             this->rot270('G');

//             this->rot180('Y');
//             this->rot90('G');

//             this->rot90('Y');
//             this->rot270('G');

//             this->rot90('Y');
//             this->rot90('G');

//             answer.append(" T B' T2 B T B' T B T L' T2 L T L' T L T B' T2 B T B' T B");
//         }

//         if (arr[1][0][2].get_side(5 - 1) == 'G')
//         {
//             this->rot90('Y');
//             this->rot270('R');

//             this->rot180('Y');
//             this->rot90('R');

//             this->rot90('Y');
//             this->rot270('R');

//             this->rot90('Y');
//             this->rot90('R');

//             answer.append(" T R' T2 R T R' T R");
//         }
//     }

//     void step6(std::string &answer)
//     {

//         if (
//             (arr[2][0][2].get_side(5 - 1) == 'B' || arr[2][0][2].get_side(5 - 1) == 'R' || arr[2][0][2].get_side(5 - 1) == 'Y') &&
//             (arr[2][0][2].get_side(2 - 1) == 'B' || arr[2][0][2].get_side(2 - 1) == 'R' || arr[2][0][2].get_side(2 - 1) == 'Y') &&
//             (arr[2][0][2].get_side(6 - 1) == 'B' || arr[2][0][2].get_side(6 - 1) == 'R' || arr[2][0][2].get_side(6 - 1) == 'Y'))
//         {
//             this->rot90('O');
//             this->rot90('B');
//             this->rot90('R');

//             this->rot270('B');
//             this->rot270('O');

//             this->rot90('B');
//             this->rot270('R');

//             this->rot270('B');

//             answer.append(" L F R F' L' F R' F'");
//             // tmp = false;

//             // cout << "aboba1" << endl;
//         }
//         else if (
//             (arr[0][2][2].get_side(3 - 1) == 'B' || arr[0][2][2].get_side(3 - 1) == 'R' || arr[0][2][2].get_side(3 - 1) == 'Y') &&
//             (arr[0][2][2].get_side(4 - 1) == 'B' || arr[0][2][2].get_side(4 - 1) == 'R' || arr[0][2][2].get_side(4 - 1) == 'Y') &&
//             (arr[0][2][2].get_side(6 - 1) == 'B' || arr[0][2][2].get_side(6 - 1) == 'R' || arr[0][2][2].get_side(6 - 1) == 'Y'))
//         {
//             this->rot270('R');
//             this->rot270('B');
//             this->rot270('O');

//             this->rot90('B');
//             this->rot90('R');

//             this->rot270('B');
//             this->rot90('O');
//             this->rot90('B');

//             answer.append(" R' F' L' F R F' L F");
//             // tmp = false;

//             // cout << "aboba2" << endl;
//         }
//         else if (
//             (arr[0][0][2].get_side(4 - 1) == 'B' || arr[0][0][2].get_side(4 - 1) == 'R' || arr[0][0][2].get_side(4 - 1) == 'Y') &&
//             (arr[0][0][2].get_side(5 - 1) == 'B' || arr[0][0][2].get_side(5 - 1) == 'R' || arr[0][0][2].get_side(5 - 1) == 'Y') &&
//             (arr[0][0][2].get_side(6 - 1) == 'B' || arr[0][0][2].get_side(6 - 1) == 'R' || arr[0][0][2].get_side(6 - 1) == 'Y'))
//         {
//             this->rot90('R');
//             this->rot90('G');
//             this->rot90('O');

//             this->rot270('G');
//             this->rot270('R');

//             this->rot90('G');
//             this->rot270('O');

//             this->rot270('G');

//             answer.append(" R B L B' R' B L' B'");
//             // tmp = false;

//             // cout << "aboba3" << endl;
//         }

//         if (
//             (arr[2][0][2].get_side(5 - 1) == 'R' || arr[2][0][2].get_side(5 - 1) == 'G' || arr[2][0][2].get_side(5 - 1) == 'Y') &&
//             (arr[2][0][2].get_side(2 - 1) == 'R' || arr[2][0][2].get_side(2 - 1) == 'G' || arr[2][0][2].get_side(2 - 1) == 'Y') &&
//             (arr[2][0][2].get_side(6 - 1) == 'R' || arr[2][0][2].get_side(6 - 1) == 'G' || arr[2][0][2].get_side(6 - 1) == 'Y'))
//         {
//             this->rot90('G');
//             this->rot90('O');
//             this->rot90('B');

//             this->rot270('O');
//             this->rot270('G');

//             this->rot90('O');
//             this->rot270('B');
//             this->rot270('O');

//             answer.append(" B L F L' B' L F' L'");
//             // cout << "aboba1" << endl;
//         }

//         if (
//             (arr[0][0][2].get_side(4 - 1) == 'R' || arr[0][0][2].get_side(4 - 1) == 'G' || arr[0][0][2].get_side(4 - 1) == 'Y') &&
//             (arr[0][0][2].get_side(5 - 1) == 'R' || arr[0][0][2].get_side(5 - 1) == 'G' || arr[0][0][2].get_side(5 - 1) == 'Y') &&
//             (arr[0][0][2].get_side(6 - 1) == 'R' || arr[0][0][2].get_side(6 - 1) == 'G' || arr[0][0][2].get_side(6 - 1) == 'Y'))
//         {
//             this->rot270('O');
//             this->rot270('G');

//             this->rot270('R');
//             this->rot90('G');

//             this->rot90('O');
//             this->rot270('G');

//             this->rot90('R');
//             this->rot90('G');

//             answer.append(" L' B' R' B L B' R B");
//             // cout << "aboba2" << endl;
//         }
//     }

//     int step7(std::string &answer)
//     {
//         int c = 0;
//         int k = 0;
//         // 1

//         while (!this->isTrue())
//         {

//             if (arr[2][2][2].get_side(3 - 1) == 'Y')
//             {
//                 this->rot270('B');
//                 this->rot90('R');

//                 this->rot90('B');
//                 this->rot270('R');

//                 this->rot270('B');
//                 this->rot90('R');

//                 this->rot90('B');
//                 this->rot270('R');

//                 answer.append(" F' R F R' F' R F R'");
//             }
//             else if (arr[2][2][2].get_side(2 - 1) == 'Y')
//             {
//                 this->rot90('R');
//                 this->rot270('B');

//                 this->rot270('R');
//                 this->rot90('B');

//                 this->rot90('R');
//                 this->rot270('B');

//                 this->rot270('R');
//                 this->rot90('B');

//                 answer.append(" R F' R' F R F' R' F");
//             }

//             this->rot90('Y');
//             answer.append(" T");
//             c++;

//             if (c == 1000)
//             {
//                 break;
//             }
//         }

//         return c;
//     }

//     std::string solve()
//     {
//         std::string answer;

//         step1(answer);
//         step2(answer);
//         step3(answer);
//         step4(answer);
//         step5(answer);
//         step6(answer);
//         step7(answer);

//         return answer;
//     }

//     friend bool operator==(const Cube &lhs, const Cube &rhs)
//     {
//         for (int i = 0; i < 3; i++)
//         {
//             for (int j = 0; j < 3; j++)
//             {
//                 for (int k = 0; k < 3; k++)
//                 {
//                     if (lhs.arr[i][j][k] != rhs.arr[i][j][k])
//                     {
//                         return false;
//                     }
//                 }
//             }
//         }

//         return true;
//     }

//     friend bool operator!=(const Cube &lhs, const Cube &rhs)
//     {
//         return !(lhs == rhs);
//     }

//     bool isTrue()
//     {
//         for (int i = 0; i < 3; i++)
//         {
//             for (int j = 0; j < 3; j++)
//             {
//                 if (arr[i][j][0].get_side(0) != 'W')
//                 {
//                     return false;
//                 }
//             }
//         }

//         for (int i = 0; i < 3; i++)
//         {
//             for (int j = 0; j < 3; j++)
//             {
//                 if (arr[i][j][2].get_side(5) != 'Y')
//                 {
//                     return false;
//                 }
//             }
//         }

//         for (int k = 0; k < 3; k++)
//         {
//             for (int i = 0; i < 3; i++)
//             {
//                 if (arr[i][0][k].get_side(4) != 'O')
//                 {
//                     return false;
//                 }
//             }
//         }

//         for (int k = 0; k < 3; k++)
//         {
//             for (int i = 0; i < 3; i++)
//             {
//                 if (arr[i][2][k].get_side(2) != 'R')
//                 {
//                     return false;
//                 }
//             }
//         }

//         for (int k = 0; k < 3; k++)
//         {
//             for (int j = 0; j < 3; j++)
//             {
//                 if (arr[0][j][k].get_side(3) != 'G')
//                 {
//                     return false;
//                 }
//             }
//         }

//         for (int k = 0; k < 3; k++)
//         {
//             for (int j = 0; j < 3; j++)
//             {
//                 if (arr[2][j][k].get_side(1) != 'B')
//                 {
//                     return false;
//                 }
//             }
//         }

//         return true;
//     }

//     std::string random_scramble()
//     {
//         int low_dist = 1;
//         int high_dist = 6;
//         std::srand((unsigned int)std::time(nullptr));
//         std::string scramble;

//         for (int i = 0; i < 25; i++)
//         {
//             int side = low_dist + std::rand() % (high_dist + 1 - low_dist);
//             int type = low_dist + std::rand() % (4 - low_dist);

//             if (side == 1)
//             {
//                 if (type == 1)
//                 {
//                     this->rot90('W');
//                     scramble.append(" D");
//                 }
//                 else if (type == 2)
//                 {
//                     this->rot180('W');
//                     scramble.append(" D2");
//                 }
//                 else
//                 {
//                     this->rot270('W');
//                     scramble.append(" D'");
//                 }
//             }
//             else if (side == 2)
//             {
//                 if (type == 1)
//                 {
//                     this->rot90('B');
//                     scramble.append(" F");
//                 }
//                 else if (type == 2)
//                 {
//                     this->rot180('B');
//                     scramble.append(" F2");
//                 }
//                 else
//                 {
//                     this->rot270('B');
//                     scramble.append(" F'");
//                 }
//             }
//             else if (side == 3)
//             {
//                 if (type == 1)
//                 {
//                     this->rot90('R');
//                     scramble.append(" R");
//                 }
//                 else if (type == 2)
//                 {
//                     this->rot180('R');
//                     scramble.append(" R2");
//                 }
//                 else
//                 {
//                     this->rot270('R');
//                     scramble.append(" R'");
//                 }
//             }
//             else if (side == 4)
//             {
//                 if (type == 1)
//                 {
//                     this->rot90('G');
//                     scramble.append(" B");
//                 }
//                 else if (type == 2)
//                 {
//                     this->rot180('G');
//                     scramble.append(" B2");
//                 }
//                 else
//                 {
//                     this->rot270('G');
//                     scramble.append(" B'");
//                 }
//             }
//             else if (side == 5)
//             {
//                 if (type == 1)
//                 {
//                     this->rot90('O');
//                     scramble.append(" L");
//                 }
//                 else if (type == 2)
//                 {
//                     this->rot180('O');
//                     scramble.append(" L2");
//                 }
//                 else
//                 {
//                     this->rot270('O');
//                     scramble.append(" L'");
//                 }
//             }
//             else
//             {
//                 if (type == 1)
//                 {
//                     this->rot90('Y');
//                     scramble.append(" T");
//                 }
//                 else if (type == 2)
//                 {
//                     this->rot180('Y');
//                     scramble.append(" T2");
//                 }
//                 else
//                 {
//                     this->rot270('Y');
//                     scramble.append(" T'");
//                 }
//             }
//         }

//         return scramble;
//     }
// };

int xRot = 24, yRot = -34;
GraphicCube c = GraphicCube(xRot);
int timerOn = 0;

bool autoSolve = false;
std::queue<Rotations> q;

void initGL()
{
    glClearColor(0.7f, 0.2f, 1.0f, 1.0f);
    std::srand(std::time(0));

    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	// c.current = -1;
}

void display()
{
    glPushMatrix();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glTranslatef(0.0f, 0.0f, -20.0f);
    glRotatef(xRot, 1, 0, 0);
    glRotatef(yRot, 0, 1, 0);

    c.draw();

    glPopMatrix();

    glutSwapBuffers();
}

void reshape(GLsizei width, GLsizei height)
{
    if (height == 0)
        height = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void specialKeys(int key, int, int)
{
    if (key == GLUT_KEY_DOWN)
    {
        xRot += 3;
        if (xRot >= 360)
            xRot -= 360;
        glutPostRedisplay();
    }

    if (key == GLUT_KEY_UP)
    {
        xRot -= 3;
        if (xRot < 0)
            xRot += 360;
        glutPostRedisplay();
    }

    if (key == GLUT_KEY_RIGHT)
    {
        yRot += 3;
        if (yRot >= 360)
            yRot -= 360;
        glutPostRedisplay();
    }

    if (key == GLUT_KEY_LEFT)
    {
        yRot -= 3;
        if (yRot < 0)
            yRot += 360;
        glutPostRedisplay();
    }
}

void keys(unsigned char key, int, int)
{

    if (c.getCurrent() == -1)
    {
        if (key == '1')
        {
            c.Rotate3(1 - 1, 3);
        }
        else if (key == '6')
        {
            c.Rotate3(6 - 1, 3);
        }
        else if (key == '2')
        {
            c.Rotate3(2 - 1, 3);
        }
        else if (key == '4')
        {
            c.Rotate3(4 - 1, 3);
        }
        else if (key == '3')
        {
            c.Rotate3(3 - 1, 3);
        }
        else if (key == '5')
        {
            c.Rotate3(5 - 1, 3);
        }

		display();
    }    
}

void mouse(int key, int state, int, int)
{
    if (key == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        timerOn = 1 - timerOn;
    }
}

void timer(int)
{
    glutTimerFunc(TIMER, timer, 0);
    if (autoSolve)
    {
        if (c.getCurrent() != -1)
        {
            if (c.getRotatingMode() == 0)
            {
                c.Rotate(c.getCurrent(), 3);
            }
            else if (c.getRotatingMode() == 1)
            {
                c.Rotate2(c.getCurrent(), 3);
            }
            else if (c.getRotatingMode() == 2)
            {
                c.Rotate3(c.getCurrent(), 3);
            }

        }

        if (c.getCurrent() == -1)
        {
            if (q.empty())
            {
                autoSolve = false;
            }
            else
            {
                Rotations tmp = q.front();
                q.pop();
                if (tmp.mode == 0)
                {
                    c.Rotate(tmp.side, tmp.angle);
                }
                else if (tmp.mode == 1)
                {
                    c.Rotate2(tmp.side, tmp.angle);
                }
                else if (tmp.mode == 2)
                {
                    c.Rotate3(tmp.side, tmp.angle);
                }

            }
        }
    }
    else
    {
        if (timerOn)
        {
            if (c.getCurrent() == -1)
            {
                keys(1 + std::rand() % 6 + '0', 0, 0);
            }
            else
            {
                if (c.getRotatingMode() == 0)
                {
                    c.Rotate(c.getCurrent(), 3);
                }
                else if (c.getRotatingMode() == 1)
                {
                    c.Rotate2(c.getCurrent(), 3);
                }
                else if (c.getRotatingMode() == 2)
                {
                    c.Rotate3(c.getCurrent(), 3);
                }

            }
        }
        else
        {
            if (c.getCurrent() != -1)
            {
                if (c.getRotatingMode() == 0)
                {
                    c.Rotate(c.getCurrent(), 3);
                }
                else if (c.getRotatingMode() == 1)
                {
                    c.Rotate2(c.getCurrent(), 3);
                }
                else if (c.getRotatingMode() == 2)
                {
                    c.Rotate3(c.getCurrent(), 3);
                }

            }
        }
    }

    display();
}

void menu(int)
{
    GraphicCube tmp = c;
    std::string answer;
    answer = tmp.solve();

    std::istringstream iss(answer);
    std::string move;
    while (iss >> move)
    {
        if (move == "D")
        {
            q.push({1 - 1, 3, 0});
        }
        else if (move == "D2")
        {
            q.push({1 - 1, 3, 1});
        }
        else if (move == "D'")
        {
            q.push({1 - 1, 3, 2});
        }
        else if (move == "F")
        {
            q.push({2 - 1, 3, 0});
        }
        else if (move == "F2")
        {
            q.push({2 - 1, 3, 1});
        }
        else if (move == "F'")
        {
            q.push({2 - 1, 3, 2});
        }
        else if (move == "R")
        {
            q.push({3 - 1, 3, 0});
        }
        else if (move == "R2")
        {
            q.push({3 - 1, 3, 1});
        }
        else if (move == "R'")
        {
            q.push({3 - 1, 3, 2});
        }
        else if (move == "B")
        {
            q.push({4 - 1, 3, 0});
        }
        else if (move == "B2")
        {
            q.push({4 - 1, 3, 1});
        }
        else if (move == "B'")
        {
            q.push({4 - 1, 3, 2});
        }
        else if (move == "L")
        {
            q.push({5 - 1, 3, 0});
        }
        else if (move == "L2")
        {
            q.push({5 - 1, 3, 1});
        }
        else if (move == "L'")
        {
            q.push({5 - 1, 3, 2});
        }
        else if (move == "T")
        {
            q.push({6 - 1, 3, 0});
        }
        else if (move == "T2")
        {
            q.push({6 - 1, 3, 1});
        }
        else if (move == "T'")
        {
            q.push({6 - 1, 3, 2});
        }
    }

    autoSolve = true;
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(800, 700);
    glutInitWindowPosition(50, 50);
    glutCreateWindow(title);
	initGL();
	glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keys);
    glutMouseFunc(mouse);
    glutTimerFunc(TIMER, timer, 0);
    glutSpecialFunc(specialKeys);
    glutCreateMenu(menu);
    glutAddMenuEntry("Solve", 0);
    glutAttachMenu(GLUT_LEFT_BUTTON);
    glutMainLoop();
    return 0;
} 