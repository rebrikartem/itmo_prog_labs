#include "CRational.h"
#include <numeric>
#include <stdlib.h>

using namespace std;

CRational::CRational(int numerator, unsigned denominator)
:   numerator_(numerator)
,   denominator_(denominator)
{
    unsigned gcd = std::gcd(numerator_, denominator_);
    numerator_ /= gcd;
    denominator_ /= gcd;
}

CRational::CRational(const CRational& other)
:   numerator_(other.numerator_)
,   denominator_(other.denominator_)
{}

unsigned CRational::denominator() const {
    return denominator_;
}

int CRational::numerator() const {
    return numerator_;
}

CRational& CRational::operator=(const CRational& other){
    if(this == &other){
        return *this;
    }

    numerator_ = other.numerator_;
    denominator_ = other.denominator_;

    return *this;
}

bool operator==(const CRational& lhs, const CRational& rhs){
    return lhs.numerator() * rhs.denominator() == lhs.denominator() * rhs.numerator();
}

bool operator!=(const CRational& lhs, const CRational& rhs){
    return !operator==(lhs, rhs);
}

bool operator<(const CRational& lhs, const CRational& rhs){
    return lhs.numerator() * rhs.denominator() < lhs.denominator() * rhs.numerator();
}

bool operator>(const CRational& lhs, const CRational& rhs){
    return rhs < lhs;
}

bool operator<=(const CRational& lhs, const CRational& rhs){
    return !operator>(lhs, rhs);
}

bool operator>=(const CRational& lhs, const CRational& rhs){
    return !operator<(lhs, rhs);
}

CRational& CRational::operator++(){
    numerator_ += denominator_;
    return *this;
}

CRational CRational::operator++(int){
    CRational tmp(*this);
    operator++();
    return *this;
}

CRational::operator float() const {
    return (float) numerator_ / denominator_;
}

void* CRational::operator new[](size_t n){
    void* ptr = std::malloc(n);
    return ptr;
}