#include "CPolynom.h"
#include <vector>
#include <sstream>

using namespace std;

Member::Member(double value, int degree)
{
    value_ = value;
    degree_ = degree;
}

double Member::get_value() const
{
    return value_;
}

int Member::get_degree() const
{
    return degree_;
}

Polynomial::~Polynomial()
{
    if (vector_of_coeffs_ != nullptr)
    {
        delete vector_of_coeffs_;
    }
}

Polynomial::Polynomial(const vector<double> &vector_of_coeffs)
{
    if (vector_of_coeffs_ != nullptr)
    {
        delete vector_of_coeffs_;
    }

    vector_of_coeffs_ = double_to_member(vector_of_coeffs);
}

Polynomial::Polynomial(const vector<Member> &vector_of_coeffs)
{
    if (vector_of_coeffs_ != nullptr)
    {
        delete vector_of_coeffs_;
    }

    vector_of_coeffs_ = new vector<Member>(vector_of_coeffs.begin(), vector_of_coeffs.end());
}

Polynomial::Polynomial(string s)
{
    istringstream ss(s);
    double c;
    vector<double> p_double;

    while (ss >> c)
    {
        p_double.push_back(c);
    }

    vector_of_coeffs_ = double_to_member(p_double);
}
vector<double> Polynomial::member_to_double(const vector<Member> &member)
{
    vector<double> res(member.at(0).get_degree() + 1, 0);

    for (int i = 0; i < member.size(); i++)
    {
        res.at(member.at(0).get_degree() - member.at(i).get_degree()) = member.at(i).get_value();
    }
    return res;
}

vector<Member> *Polynomial::double_to_member(const vector<double> &db)
{
    vector<Member> *res = new vector<Member>;

    for (int i = 0; i < db.size(); i++)
    {
        Member tmp(db.at(i), db.size() - i - 1);
        if (tmp.get_value() != 0)
        {
            res->push_back(tmp);
        }
    }

    return res;
}

Polynomial::Polynomial(const Polynomial &other)
{
    if (vector_of_coeffs_ != nullptr)
    {
        delete vector_of_coeffs_;
    }
    vector_of_coeffs_ = other.vector_of_coeffs_;
}

Polynomial &Polynomial::operator=(const Polynomial &other)
{
    if (this == &other)
    {
        return *this;
    }

    if (vector_of_coeffs_ != nullptr)
    {
        delete vector_of_coeffs_;
    }
    vector_of_coeffs_ = other.vector_of_coeffs_;
    return *this;
}

bool Polynomial::operator==(const Polynomial &rhs)
{

    vector<double> lhs_ = member_to_double(*vector_of_coeffs_);
    vector<double> rhs_ = member_to_double(*rhs.vector_of_coeffs_);

    if (lhs_.size() != rhs_.size())
    {
        return false;
    }
    else
    {
        for (int i = 0; i < lhs_.size(); i++)
        {
            if (lhs_.at(i) != rhs_.at(i))
            {
                return false;
            }
        }
    }
    return true;
}

bool Polynomial::operator!=(const Polynomial &rhs)
{
    return !(*this == rhs);
}

Polynomial Polynomial::operator+(const Polynomial &rhs)
{

    vector<double> lhs_ = member_to_double(*vector_of_coeffs_);
    vector<double> rhs_ = member_to_double(*rhs.vector_of_coeffs_);

    if (lhs_.size() > rhs_.size())
    {
        for (int i = 0; i < rhs_.size(); i++)
        {
            lhs_.at(lhs_.size() - rhs_.size() + i) += rhs_.at(i);
        }

        vector<Member> *lhs_ptr = double_to_member(lhs_);
        Polynomial r(*lhs_ptr);

        delete lhs_ptr;
        return r;
    }
    else
    {
        for (int i = 0; i < lhs_.size(); i++)
        {
            rhs_.at(rhs_.size() - lhs_.size() + i) += lhs_.at(i);
        }

        vector<Member> *rhs_ptr = double_to_member(rhs_);
        Polynomial r(*double_to_member(rhs_));

        delete rhs_ptr;
        return r;
    }
}

void Polynomial::operator+=(const Polynomial &rhs)
{
    *this = *this + rhs;
}

Polynomial Polynomial::operator-()
{
    vector<Member> res;
    for (int i = 0; i < vector_of_coeffs_->size(); i++)
    {
        res.push_back(Member(vector_of_coeffs_->at(i).get_value() * -1, vector_of_coeffs_->at(i).get_degree()));
    }
    Polynomial r(res);
    return r;
}

Polynomial Polynomial::operator-(const Polynomial &rhs)
{
    vector<double> lhs_ = member_to_double(*vector_of_coeffs_);
    vector<double> rhs_ = member_to_double(*rhs.vector_of_coeffs_);

    if (lhs_.size() >= rhs_.size())
    {
        for (int i = 0; i < rhs_.size(); i++)
        {
            lhs_.at(lhs_.size() - rhs_.size() + i) -= rhs_.at(i);
        }

        vector<Member> *lhs_ptr = double_to_member(lhs_);
        Polynomial r(*lhs_ptr);

        delete lhs_ptr;
        return r;
    }
    else
    {
        for (int i = 0; i < lhs_.size(); i++)
        {
            rhs_.at(rhs_.size() - lhs_.size() + i) = lhs_.at(i) - rhs_.at(rhs_.size() - lhs_.size() + i);
            if (i < rhs_.size() - lhs_.size())
            {
                rhs_.at(i) *= -1;
            }
        }

        vector<Member> *rhs_ptr = double_to_member(rhs_);
        Polynomial r(*rhs_ptr);
        return r;
    }
}

void Polynomial::operator-=(const Polynomial &rhs)
{
    *this = *this - rhs;
}

Polynomial Polynomial::operator/(double x)
{
    vector<Member> res(vector_of_coeffs_->begin(), vector_of_coeffs_->end());

    for (int i = 0; i < vector_of_coeffs_->size(); i++)
    {
        res.at(i) = Member(res.at(i).get_value() / x, res.at(i).get_degree());
    }

    Polynomial r(res);
    return r;
}

void Polynomial::operator/=(double x)
{
    *this = *this / x;
}

Polynomial Polynomial::operator*(double x)
{
    vector<Member> res(vector_of_coeffs_->begin(), vector_of_coeffs_->end());

    for (int i = 0; i < vector_of_coeffs_->size(); i++)
    {
        res.at(i) = Member(res.at(i).get_value() * x, res.at(i).get_degree());
    }

    Polynomial r(res);
    return r;
}

void Polynomial::operator*=(double x)
{
    *this = *this * x;
}

Polynomial Polynomial::operator*(const Polynomial &rhs)
{
    int max_degree = vector_of_coeffs_->at(0).get_degree() + rhs.vector_of_coeffs_->at(0).get_degree();
    vector<double> res(max_degree + 1, 0);
    for (int i = 0; i < vector_of_coeffs_->size(); i++)
    {
        for (int j = 0; j < rhs.vector_of_coeffs_->size(); j++)
        {
            res.at(max_degree - vector_of_coeffs_->at(i).get_degree() - rhs.vector_of_coeffs_->at(j).get_degree()) 
            += vector_of_coeffs_->at(i).get_value() * rhs.vector_of_coeffs_->at(j).get_value();
        }
    }
    vector<Member> *res_member = double_to_member(res);
    Polynomial r(*res_member);
    delete res_member;
    return r;
}

void Polynomial::operator*=(const Polynomial &rhs)
{
    *this = *this * rhs;
}

double Polynomial::operator[](int index)
{
    for (int i = 0; i < vector_of_coeffs_->size(); i++)
    {
        if (vector_of_coeffs_->at(i).get_degree() == index)
        {
            return vector_of_coeffs_->at(i).get_value();
        }
    }
    return 0;
}

ostream &operator<<(ostream &os, const Polynomial &p)
{
    for (int i = 0; i < p.vector_of_coeffs_->size(); i++)
    {
        if (i == 0 || p.vector_of_coeffs_->at(i).get_value() < 0)
        {
            os << p.vector_of_coeffs_->at(i).get_value();
        }
        else if (p.vector_of_coeffs_->at(i).get_value() > 0)
        {
            os << "+" << p.vector_of_coeffs_->at(i).get_value();
        }

        if (p.vector_of_coeffs_->at(i).get_degree() > 0)
        {
            os << "x^" << p.vector_of_coeffs_->at(i).get_degree() << " ";
        }
    }
    return os;
}

istream &operator>>(istream &is, Polynomial &polynom)
{
    string p;

    vector<double> p_double;
    getline(is, p);

    istringstream ss(p);
    double c;
    while (ss >> c)
    {
        p_double.push_back(c);
    }

    vector<Member> *p_member = new vector<Member>;

    for (int i = 0; i < p_double.size(); i++)
    {
        Member tmp(p_double.at(i), p_double.size() - i - 1);
        if (tmp.get_value() != 0)
        {
            p_member->push_back(tmp);
        }
    }

    if (polynom.vector_of_coeffs_ != nullptr)
    {
        delete polynom.vector_of_coeffs_;
    }

    polynom.vector_of_coeffs_ = p_member;

    return is;
}