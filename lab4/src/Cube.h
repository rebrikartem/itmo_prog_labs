#ifndef CUBE_H
#define CUBE_H

#include "SmallCube.h"
#include "Face.h"
#include <string>

// Развертка:
// 		 Y Y Y
//		 Y Y Y
//		 Y Y Y
// O O O B B B R R R G G G
// O O O B B B R R R G G G
// O O O B B B R R R G G G
// 		 W W W
// 		 W W W
// 		 W W W
// W - 1, B - 2, R - 3, G - 4, O - 5, Y - 6

class Cube
{
private:
	SmallCube arr[3][3][3];

public:
	Cube();

	void print();

	SmallCube &get_sc(int i, int j, int k);

	friend bool operator==(const Cube &lhs, const Cube &rhs);

	friend bool operator!=(const Cube &lhs, const Cube &rhs);

	bool isCorrect();

	void rot90(char c);

	void rot180(char c);

	void rot270(char c);

	int step1(std::string& answer);

	int step2(std::string& answer);

	int step3(std::string& answer);

	void step4(std::string& answer);

	void step5(std::string& answer);

	void step6(std::string& answer);

	int step7(std::string& answer);

	std::string solve();

	int solve(int& m);

	void scramble(std::string s);

	friend std::istream &operator>>(std::istream& stream, Cube& d);

	std::string random_scramble();
};

#endif
