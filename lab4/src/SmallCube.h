#ifndef SMALLCUBE_H
#define SMALLCUBE_H


class SmallCube{
private:
	char colors[6];
public:
	SmallCube();

	SmallCube(const SmallCube& other);

	SmallCube(char* col);

	SmallCube& operator=(const SmallCube& other);

	void set_side(int i, char c);

	char get_side(int i);

	void print();

	SmallCube rot90(int i);

	friend bool operator==(const SmallCube& lhs, const SmallCube& rhs);

	friend bool operator!=(const SmallCube& lhs, const SmallCube& rhs);
};

#endif