#ifndef FACE_H
#define FACE_H

class Face{
private:
	char colors[3][3];
public:
	Face();

	Face(char c);

	Face(char col[3][3]);

	void print();

	char at(int i, int j);

};

#endif