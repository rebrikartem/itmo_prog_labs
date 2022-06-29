#include "GraphicSmallCube.h"

void chooseColor(char c)
{
    if (c == 'W')
    {
        glColor3f(1.0f, 1.0f, 1.0f);
    }
    else if (c == 'B')
    {
        glColor3f(0.0f, 0.0f, 1.0f);
    }
    else if (c == 'R')
    {
        glColor3f(1.0f, 0.0f, 0.0f);
    }
    else if (c == 'G')
    {
        glColor3f(0.0f, 1.0f, 0.0f);
    }
    else if (c == 'O')
    {
        glColor3f(1.0f, 0.5f, 0.0f);
    }
    else if (c == 'Y')
    {
        glColor3f(1.0f, 1.0f, 0.0f);
    }
    else if (c == 'N')
    {
        glColor3f(0.0f, 0.0f, 0.0f);
    }
}

GraphicSmallCube::GraphicSmallCube(const GraphicSmallCube &other)
{
    for (int i = 0; i < 6; i++)
    {
        colors[i] = other.colors[i];
    }
}

GraphicSmallCube::GraphicSmallCube()
{
    for (int i = 0; i < 6; i++)
    {
        colors[i] = 'N';
    }
}

GraphicSmallCube::GraphicSmallCube(char *cols)
{
    for (int i = 0; i < 6; i++)
    {
        colors[i] = cols[i];
    }
}

GraphicSmallCube &GraphicSmallCube::operator=(const GraphicSmallCube &other)
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

char GraphicSmallCube::get_side(int i)
{
    return colors[i];
}
GraphicSmallCube GraphicSmallCube::rot90(int i)
{
    char fake_cols[6];
    for (int i = 0; i < 6; i++)
    {
        fake_cols[i] = colors[i];
    }

    if (i == 0)
    {
        char tmp = fake_cols[4];

        fake_cols[4] = fake_cols[3];
        fake_cols[3] = fake_cols[2];
        fake_cols[2] = fake_cols[1];
        fake_cols[1] = tmp;
    }
    else if (i == 1)
    {
        char tmp = fake_cols[0];

        fake_cols[0] = fake_cols[2];
        fake_cols[2] = fake_cols[5];
        fake_cols[5] = fake_cols[4];
        fake_cols[4] = tmp;
    }
    else if (i == 2)
    {
        char tmp = fake_cols[0];

        fake_cols[0] = fake_cols[3];
        fake_cols[3] = fake_cols[5];
        fake_cols[5] = fake_cols[1];
        fake_cols[1] = tmp;
    }
    else if (i == 3)
    {
        char tmp = fake_cols[0];

        fake_cols[0] = fake_cols[4];
        fake_cols[4] = fake_cols[5];
        fake_cols[5] = fake_cols[2];
        fake_cols[2] = tmp;
    }
    else if (i == 4)
    {
        char tmp = fake_cols[0];

        fake_cols[0] = fake_cols[1];
        fake_cols[1] = fake_cols[5];
        fake_cols[5] = fake_cols[3];
        fake_cols[3] = tmp;
    }
    else if (i == 5)
    {
        char tmp = fake_cols[1];

        fake_cols[1] = fake_cols[2];
        fake_cols[2] = fake_cols[3];
        fake_cols[3] = fake_cols[4];
        fake_cols[4] = tmp;
    }

    return GraphicSmallCube(fake_cols);
}

void GraphicSmallCube::draw()
{
    glPushMatrix();
    glBegin(GL_QUADS);
    // Bot
    chooseColor(colors[0]);
    glNormal3f(0, 0, -1);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);

    // Front
    chooseColor(colors[1]);
    glNormal3f(0, -1, 0);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);

    // Right
    chooseColor(colors[2]);
    glNormal3f(1, 0, 0);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);

    // Back
    chooseColor(colors[3]);
    glNormal3f(0, 0, -1);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);

    // Left
    chooseColor(colors[4]);
    glNormal3f(-1, 0, 0);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);

    // Top
    chooseColor(colors[5]);
    glNormal3f(0, 0, 1);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);

    glEnd();
    glPopMatrix();
}

void GraphicSmallCube::setSide(char c, int i)
{
    colors[i] = c;
}

bool operator==(const GraphicSmallCube &lhs, const GraphicSmallCube &rhs)
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

bool operator!=(const GraphicSmallCube &lhs, const GraphicSmallCube &rhs)
{
    return !(lhs == rhs);
}
