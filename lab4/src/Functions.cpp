#include "Functions.h"

#include <iostream>

using namespace std;

void print_color(char c){
	if(c == 'W'){
		cout << "\033[01;38;05;15m" << "\u25A0" << "\033[0m ";
	}
	else if(c == 'Y'){
		cout << "\033[01;38;05;226m"<< "\u25A0" << "\033[0m ";
	}
	else if(c == 'B'){
		cout << "\033[01;38;05;21m" << "\u25A0" << "\033[0m ";
	}
	else if(c == 'R'){
		cout << "\033[01;38;05;196m" << "\u25A0" << "\033[0m ";
	}
	else if(c == 'G'){
		cout << "\033[01;38;05;46m" << "\u25A0" << "\033[0m ";
	}
	else if(c == 'O'){
		cout << "\033[01;38;05;208m" << "\u25A0" << "\033[0m ";
	}
	else{
		cout << "\033[01;38;05;201m" << "\u25A0" << "\033[0m ";
	}
}