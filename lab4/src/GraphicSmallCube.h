#ifndef GR_SMALLCUBE_H
#define GR_SMALLCUBE_H

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <GL/glut.h>
#include <queue>
#include <string>
#include <sstream>



class GraphicSmallCube
{
private:
    char colors[6];

public:
    GraphicSmallCube(const GraphicSmallCube &other);

    GraphicSmallCube();

    GraphicSmallCube(char *cols);

    GraphicSmallCube &operator=(const GraphicSmallCube &other);

    char get_side(int i);

    GraphicSmallCube rot90(int i);

    void draw();

    void setSide(char c, int i);

    friend bool operator==(const GraphicSmallCube &lhs, const GraphicSmallCube &rhs);

    friend bool operator!=(const GraphicSmallCube &lhs, const GraphicSmallCube &rhs);
};


#endif