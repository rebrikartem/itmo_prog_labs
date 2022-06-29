#ifndef CRATIONAL_H
#define CRATIONAL_H

#include <iostream>

using namespace std;

class CRational{
private:
    int numerator_;
    unsigned denominator_;
public:
    CRational(int numerator = 0, unsigned denominator = 1);

    CRational(const CRational& other);

    int numerator() const;

    unsigned denominator() const;

    CRational& operator=(const CRational& other);

    friend bool operator==(const CRational& lhs, const CRational& rhs);

    friend bool operator!=(const CRational& lhs, const CRational& rhs);

    friend bool operator<(const CRational& lhs, const CRational& rhs);

    friend bool operator>(const CRational& lhs, const CRational& rhs);

    friend bool operator<=(const CRational& lhs, const CRational& rhs);

    friend bool operator>=(const CRational& lhs, const CRational& rhs);

    CRational& operator++();

    CRational operator++(int);

    explicit operator float() const;

    void* operator new[](size_t n);
};

#endif