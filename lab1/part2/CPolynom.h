#pragma once
#include<vector>
#include<iostream>


using namespace std;

class Member{
private:
    double value_;
    int degree_;
public:
    Member(double value, int degree);

    double get_value() const;

    int get_degree() const;
};

class Polynomial{
private:
    vector<Member>* vector_of_coeffs_ = nullptr;
public:
    ~Polynomial();

    Polynomial(const vector<double>& vector_of_coeffs);

    Polynomial(const vector<Member>& vector_of_coeffs);

    Polynomial(string s);

    vector<double> member_to_double(const vector<Member>& member);

    vector<Member>* double_to_member(const vector<double>& db);

    Polynomial(const Polynomial& other);

    Polynomial& operator=(const Polynomial& other);

    bool operator==(const Polynomial& rhs);

    bool operator!=(const Polynomial& rhs);

    Polynomial operator+(const Polynomial& rhs);

    void operator+=(const Polynomial& rhs);

    Polynomial operator-();

    Polynomial operator-(const Polynomial& rhs);

    void operator-=(const Polynomial& rhs);

    Polynomial operator/(double x);

    void operator/=(double x);

    Polynomial operator*(double x);

    void operator*=(double x);

    Polynomial operator*(const Polynomial& rhs);

    void operator*=(const Polynomial& rhs);

    double operator[](int index);

    friend ostream& operator<<(ostream& os,const Polynomial& p);

    friend istream& operator>>(istream& is, Polynomial& polynom);
};
