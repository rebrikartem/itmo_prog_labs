#ifndef POLYNOM_H
#define POLYNOM_H

#include <iostream>
#include <array>

using namespace std;


constexpr int get_pow(int x, int i){
    if (i == 0)
		return 1;
	if (i % 2 == 1)
		return get_pow(x, i-1) * x;
	else {
		int b = get_pow(x, i/2);
		return b * b;
	}
}


class Polynom
{
private:
    int *_coeffs;
    int degree;

public:
    Polynom();

    constexpr Polynom(const int *coeffs, const int deg)
        : _coeffs(const_cast<int*>(coeffs)), degree(deg)
    {}

    constexpr int get_value(int x) const
    {
        int value = 0;
        for (int i = 0; i < degree; i++)
        {
            value += _coeffs[i] * get_pow(x, i);
        }
        return value;
    }

    friend ostream& operator<<(ostream& os, const Polynom& p){
        for(int i = 0; i < p.degree; i++){
            if(p._coeffs[i] != 0){
                os << p._coeffs[i] << "*x^" << i << " "; 
            }
        }
        return os;
    }
};


constexpr int compile_time_calc(int x, const int* arr, int degree){
    Polynom p(const_cast<int*>(arr), degree);

    return p.get_value(x);
}

#endif