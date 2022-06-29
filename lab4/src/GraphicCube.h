#ifndef GR_CUBE_H
#define GR_CUBE_H

#include "GraphicSmallCube.h"


class GraphicCube
{
private:
    GraphicSmallCube arr[3][3][3];
    int rotate[6];
    bool isRot[3][3][3];
	int current;
    int rotatingMode;
public:
	GraphicCube& operator=(const GraphicCube& other);

	GraphicCube(const GraphicCube& other);

    GraphicCube(int);

    void draw();

    void rot90(char c, int sign);

    bool Rotate(int side, int angle);

	bool Rotate2(int side, int angle);

	bool Rotate3(int side, int angle);


    void rot90(char c);

    void rot180(char c);

    void rot270(char c);

    int step1(std::string &answer);

    int getCurrent();

    int getRotatingMode();

    int step2(std::string &answer);

    int step3(std::string &answer);

    void step4(std::string &answer);

    void step5(std::string &answer);

    void step6(std::string &answer);

    int step7(std::string &answer);

    std::string solve();

    friend bool operator==(const GraphicCube &lhs, const GraphicCube &rhs);

    friend bool operator!=(const GraphicCube &lhs, const GraphicCube &rhs);

    bool isTrue();

    std::string random_scramble();
};


#endif