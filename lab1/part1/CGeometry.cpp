#include "CGeometry.h"
#include <math.h>
#include <iostream>

using namespace std;

#define PI 3.141592653589793238462643

Point::Point(double x, double y)
    : x_(x), y_(y)
{
}

double Point::calculate_distance(const Point &other) const
{
    double dx = x_ - other.x_;
    double dy = y_ - other.y_;

    return sqrt(dx * dx + dy * dy);
}

double Point::get_x() const
{
    return x_;
}

double Point::get_y() const
{
    return y_;
}

BrokenLine::~BrokenLine()
{
    delete vector_of_points_;
}

BrokenLine::BrokenLine(vector<Point> &vector_of_points)
{
    vector_of_points_ = new vector<Point>(vector_of_points.begin(), vector_of_points.end());
}

BrokenLine::BrokenLine(const BrokenLine &other)
{
    if (vector_of_points_ != nullptr)
    {
        delete vector_of_points_;
    }
    vector_of_points_ = new vector<Point>(other.vector_of_points_->begin(), other.vector_of_points_->end());
}

BrokenLine &BrokenLine::operator=(const BrokenLine &other)
{
    if (&other != this)
    {
        return *this;
    }
    if (vector_of_points_ != nullptr)
    {
        delete vector_of_points_;
    }
    vector_of_points_ = new vector<Point>(other.vector_of_points_->begin(), other.vector_of_points_->end());

    return *this;
}

vector<Point> *BrokenLine::get_vector_of_points() const
{
    return vector_of_points_;
}

void BrokenLine::print_line() const
{
    for (int i = 0; i < vector_of_points_->size(); i++)
    {
        cout << vector_of_points_->at(i).get_x() << " " << vector_of_points_->at(i).get_y() << endl;
    }
}

double BrokenLine::get_length() const
{
    double length = 0;
    if (vector_of_points_->size() < 2)
    {
        return length;
    }
    else
    {
        for (int i = 1; i < vector_of_points_->size(); i++)
        {
            length += vector_of_points_->at(i).calculate_distance(vector_of_points_->at(i - 1));
        }
    }

    return length;
}

ClosedBrokenLine::~ClosedBrokenLine() {}

ClosedBrokenLine::ClosedBrokenLine(vector<Point> &vector_of_points)
    : BrokenLine(vector_of_points)
{
}

ClosedBrokenLine::ClosedBrokenLine(const ClosedBrokenLine &other)
    : BrokenLine(other)
{
}

ClosedBrokenLine &ClosedBrokenLine::operator=(const ClosedBrokenLine &other)
{
    BrokenLine::operator=(other);
    return *this;
}

void ClosedBrokenLine::print_line() const
{
    Point begin;
    Point end;

    for (int i = 0; i < vector_of_points_->size(); i++)
    {
        if (i == 0)
        {
            begin = vector_of_points_->at(i);
        }
        if (i == vector_of_points_->size() - 1)
        {
            end = vector_of_points_->at(i);
        }
        cout << vector_of_points_->at(i).get_x() << " " << vector_of_points_->at(i).get_y() << endl;
    }

    if (begin.get_x() == end.get_x() && begin.get_y() == end.get_y())
    {
    }
    else
    {
        cout << begin.get_x() << " " << begin.get_y() << endl;
    }
}

double ClosedBrokenLine::get_length() const
{
    double length = 0;
    Point begin;
    Point end;

    if (vector_of_points_->size() < 2)
    {
        return length;
    }
    else
    {
        for (int i = 1; i < vector_of_points_->size(); i++)
        {
            if (i == 0)
            {
                begin = vector_of_points_->at(i);
            }
            if (i == vector_of_points_->size() - 1)
            {
                end = vector_of_points_->at(i);
            }
            length += vector_of_points_->at(i).calculate_distance(vector_of_points_->at(i - 1));
        }
    }

    if (begin.get_x() == end.get_x() && end.get_y() == begin.get_y())
    {
    }
    else
    {
        length += end.calculate_distance(begin);
    }

    return length;
}

Polygon::~Polygon()
{
    delete vector_of_points_;
}

Polygon::Polygon(vector<Point> &other)
{
    vector_of_points_ = new vector<Point>(other.begin(), other.end());
    is_intersects();
}

Polygon::Polygon(const Polygon &other)
{
    if (vector_of_points_ != nullptr)
    {
        delete vector_of_points_;
    }

    vector_of_points_ = new vector<Point>(other.vector_of_points_->begin(), other.vector_of_points_->end());

    is_intersects();
}

Polygon &Polygon::operator=(const Polygon &other)
{
    if (vector_of_points_ != nullptr)
    {
        delete vector_of_points_;
    }
    vector_of_points_ = new vector<Point>(other.vector_of_points_->begin(), other.vector_of_points_->end());
    return *this;
}

bool Polygon::is_intersects()
{
    bool p = false;
    for (int i = 0; i <= vector_of_points_->size() - 4; i++)
    {
        Point a(vector_of_points_->at(i));
        Point b(vector_of_points_->at(i + 1));
        Point c(vector_of_points_->at(i + 2));
        Point d(vector_of_points_->at(i + 3));

        long xN = (d.get_x() - c.get_x()) * (a.get_y() - c.get_y()) - (d.get_y() - c.get_y()) * (a.get_x() - c.get_x());
        long yN = (b.get_x() - a.get_x()) * (a.get_y() - c.get_y()) - (b.get_y() - a.get_y()) * (a.get_x() - c.get_x());
        long t = (d.get_y() - c.get_y()) * (b.get_x() - a.get_x()) - (d.get_x() - c.get_x()) * (b.get_y() - a.get_y());
        if (max(min(a.get_x(), b.get_x()), min(c.get_x(), d.get_x())) > min(max(a.get_x(), b.get_x()), max(c.get_x(), d.get_x())) or
            max(min(a.get_y(), b.get_y()), min(c.get_y(), d.get_y())) > min(max(a.get_y(), b.get_y()), max(c.get_y(), d.get_y())))
        {
            p = false;
        }
        else if (t == 0)
        {
            p = (xN == 0);
        }
        else if (t < 0)
        {
            xN = -xN;
            yN = -yN;
            t = -t;
        }
        p = xN >= 0 and xN <= t and yN >= 0 and yN <= t;
        if (p)
        {
            cout << "polygon intercets" << endl;
            return p;
        }
    }
    return p;
}

double Polygon::calculate_perimeter()
{
    double perimeter = 0;
    Point begin(vector_of_points_->at(0));
    Point end(vector_of_points_->at(vector_of_points_->size() - 1));
    if (vector_of_points_->size() >= 2)
    {
        for (int i = 1; i < vector_of_points_->size(); i++)
        {
            perimeter += vector_of_points_->at(i).calculate_distance(vector_of_points_->at(i - 1));
        }
    }

    if (begin.get_x() == end.get_x() && begin.get_y() == end.get_y())
    {
    }
    else
    {
        perimeter += begin.calculate_distance(end);
    }

    return perimeter;
}

double Polygon::calculate_area()
{
    double area = 0;
    if (vector_of_points_->size() >= 3)
    {
        Point begin(vector_of_points_->at(0));
        int i = 3;
        do
        {
            Triangle tmp(begin, vector_of_points_->at(i - 1), vector_of_points_->at(i - 2));
            area += tmp.calculate_area();
            i++;
        } while (i <= vector_of_points_->size());
    }
    else
    {
        cout << "something wrong with ur Polygon" << endl;
        return 0;
    }
    return area;
}

Triangle::~Triangle() {}

Triangle::Triangle(Point a, Point b, Point c)
    : a_(a), b_(b), c_(c)
{
    is_correct();
}

Triangle::Triangle(const Triangle &other)
    : a_(other.a_), b_(other.b_), c_(other.c_)
{
    is_correct();
}

bool Triangle::compare_distances(Point a, Point b, Point c)
{
    return (a.calculate_distance(b) + a.calculate_distance(c)) == b.calculate_distance(c);
}

void Triangle::is_correct()
{
    if (compare_distances(a_, b_, c_))
    {
        cout << "incorrect triangle" << endl;
    }
    else if (compare_distances(b_, a_, c_))
    {
        cout << "incorrect triangle" << endl;
    }
    else if (compare_distances(c_, a_, b_))
    {
        cout << "incorrect triangle" << endl;
    }
}

const Triangle &Triangle::operator=(const Triangle &other)
{
    a_ = other.a_;
    b_ = other.b_;
    c_ = other.c_;

    return *this;
}

double Triangle::calculate_perimeter()
{
    double perimeter = 0;

    perimeter += a_.calculate_distance(b_);
    perimeter += a_.calculate_distance(c_);
    perimeter += b_.calculate_distance(c_);

    return perimeter;
}

double Triangle::calculate_area()
{
    double perimeter = calculate_perimeter() / 2;
    double ab = a_.calculate_distance(b_);
    double ac = a_.calculate_distance(c_);
    double bc = b_.calculate_distance(c_);
    return sqrt(perimeter * (perimeter - ab) * (perimeter - ac) * (perimeter - bc));
}

Section::~Section() {}

Section::Section(Point a, Point b)
    : a_(a), b_(b)
{
}

Section::Section(const Section &other)
    : a_(other.a_), b_(other.b_)
{
}

const Section &Section::operator=(const Section &other)
{
    a_ = other.a_;
    b_ = other.b_;
    return *this;
}

Point Section::get_starting_point()
{
    return a_;
}

Point Section::get_end_point()
{
    return b_;
}

double Section::get_dx()
{
    return a_.get_x() - b_.get_x();
}

double Section::get_dy()
{
    return a_.get_y() - b_.get_y();
}

double Section::calculate_coeff()
{
    double coeff = 0;
    double dx = a_.get_x() - b_.get_x();
    double dy = a_.get_y() - b_.get_y();

    if (dx != 0)
    {
        coeff = dy / dx;
    }

    return coeff;
}

bool Section::is_parallel(Section &other)
{
    double k1 = (*this).calculate_coeff();
    double k2 = other.calculate_coeff();

    if (k1 == k2 && k1 != 0)
    {
        return true;
    }
    else if (k1 != k2)
    {
        return false;
    }
    else if (k1 == k2 && k1 == 0)
    {
        double dx1 = (*this).get_dx();
        double dx2 = other.get_dx();

        double dy1 = (*this).get_dy();
        double dy2 = other.get_dy();

        if (dx1 == dx2 && dx1 == 0)
        {
            return true;
        }
        else if (dy1 == dy2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

double Section::get_length()
{
    double length = 0;

    double dx = (*this).get_dx();
    double dy = (*this).get_dy();

    length = sqrt(dx * dx + dy * dy);
    return length;
}

Trapezoid::Trapezoid(Section ab, Section cd)
    : ab_(ab), cd_(cd)
{
    bool is_parallel = ab.is_parallel(cd);
    if (is_parallel)
    {
    }
    else
    {
        cout << "incorrect trapezoid" << endl;
    }

    Section ac(ab.get_starting_point(), cd.get_starting_point());
    Section bd(ab.get_end_point(), cd.get_end_point());

    if (ac.is_parallel(bd))
    {
        cout << "incorrect trapezoid" << endl;
    }
}

Trapezoid::Trapezoid(const Trapezoid &other)
    : ab_(other.ab_), cd_(other.cd_)
{
}

const Trapezoid &Trapezoid::operator=(const Trapezoid &other)
{
    ab_ = other.ab_;
    cd_ = other.cd_;
    return *this;
}

double Trapezoid::calculate_perimeter()
{
    double perimeter = 0;

    perimeter += ab_.get_starting_point().calculate_distance(cd_.get_starting_point());
    perimeter += ab_.get_end_point().calculate_distance(cd_.get_end_point());

    perimeter += ab_.get_length();
    perimeter += cd_.get_length();

    return perimeter;
}

double Trapezoid::calculate_area()
{
    double area = 0;
    double half_sum_of_bases = (ab_.get_length() + cd_.get_length()) / 2;
    double height = abs(ab_.get_starting_point().get_y() - cd_.get_starting_point().get_y());

    area = half_sum_of_bases * height;

    return area;
}

RegularPolygon::RegularPolygon(vector<Point> &vector_of_points)
    : Polygon(vector_of_points)
{
    is_intersects();
}

RegularPolygon::RegularPolygon(const RegularPolygon &other)
    : Polygon(other)
{
    is_intersects();
}

const RegularPolygon &RegularPolygon::operator=(const RegularPolygon &other)
{
    Polygon::operator=(other);
    return *this;
}

bool RegularPolygon::is_intersects()
{
    bool p = false;
    for (int i = 0; i <= vector_of_points_->size() - 4; i++)
    {
        Point a(vector_of_points_->at(i));
        Point b(vector_of_points_->at(i + 1));
        Point c(vector_of_points_->at(i + 2));
        Point d(vector_of_points_->at(i + 3));

        long xN = (d.get_x() - c.get_x()) * (a.get_y() - c.get_y()) - (d.get_y() - c.get_y()) * (a.get_x() - c.get_x());
        long yN = (b.get_x() - a.get_x()) * (a.get_y() - c.get_y()) - (b.get_y() - a.get_y()) * (a.get_x() - c.get_x());
        long t = (d.get_y() - c.get_y()) * (b.get_x() - a.get_x()) - (d.get_x() - c.get_x()) * (b.get_y() - a.get_y());
        if (max(min(a.get_x(), b.get_x()), min(c.get_x(), d.get_x())) > min(max(a.get_x(), b.get_x()), max(c.get_x(), d.get_x())) or
            max(min(a.get_y(), b.get_y()), min(c.get_y(), d.get_y())) > min(max(a.get_y(), b.get_y()), max(c.get_y(), d.get_y())))
        {
            p = false;
        }
        else if (t == 0)
        {
            p = (xN == 0);
        }
        else if (t < 0)
        {
            xN = -xN;
            yN = -yN;
            t = -t;
        }
        p = xN >= 0 and xN <= t and yN >= 0 and yN <= t;
        if (p)
        {
            cout << "polygon intercets" << endl;
            return p;
        }
    }
    return p;
}

double RegularPolygon::calculate_perimeter()
{
    double perimeter = 0;
    double prev = 0;
    double angle;
    Point begin(vector_of_points_->at(0));
    Point end(vector_of_points_->at(vector_of_points_->size() - 1));

    if (vector_of_points_->size() >= 3)
    {
        for (int i = 1; i < vector_of_points_->size(); i++)
        {
            if (i + 2 < vector_of_points_->size())
            {
                Triangle(vector_of_points_->at(i), vector_of_points_->at(i + 1), vector_of_points_->at(i + 2));
                angle =
                    (acos((pow(vector_of_points_->at(i).calculate_distance(vector_of_points_->at(i + 2)), 2) -
                           pow(vector_of_points_->at(i).calculate_distance(vector_of_points_->at(i + 1)), 2) -
                           pow(vector_of_points_->at(i + 1).calculate_distance(vector_of_points_->at(i + 2)), 2)) /
                          (-2 * vector_of_points_->at(i).calculate_distance(vector_of_points_->at(i + 1)) *
                           vector_of_points_->at(i + 1).calculate_distance(vector_of_points_->at(i + 2))))) *
                    180 / PI;
                if (angle != ((vector_of_points_->size()) - 2) * 180 / (vector_of_points_->size()))
                {
                    cout << "something wrong with ur RegularPolygon" << endl;
                    return 0;
                }
            }

            if (i == 1)
            {
                prev = vector_of_points_->at(i).calculate_distance(vector_of_points_->at(i - 1));
            }
            else
            {
                if (prev == vector_of_points_->at(i).calculate_distance(vector_of_points_->at(i - 1)))
                {
                }
                else
                {
                    cout << "something wrong with ur RegularPolygon" << endl;
                    return 0;
                }
            }
            perimeter += vector_of_points_->at(i).calculate_distance(vector_of_points_->at(i - 1));
        }
    }
    else
    {
        cout << "something wrong with ur RegularPolygon" << endl;
        return 0;
    }
    if (begin.get_x() == end.get_x() && begin.get_y() == end.get_y())
    {
    }
    else
    {
        perimeter += end.calculate_distance(begin);
    }

    return perimeter;
}

double RegularPolygon::calculate_area()
{
    double area = 0;
    double angle;
    int number_of_sides = vector_of_points_->size();

    if (number_of_sides >= 3)
    {
        for (int i = 0; i < number_of_sides; i++)
        {
            if (i + 2 < vector_of_points_->size())
            {
                Triangle(vector_of_points_->at(i), vector_of_points_->at(i + 1), vector_of_points_->at(i + 2));
                angle =
                    (acos((pow(vector_of_points_->at(i).calculate_distance(vector_of_points_->at(i + 2)), 2) -
                           pow(vector_of_points_->at(i).calculate_distance(vector_of_points_->at(i + 1)), 2) -
                           pow(vector_of_points_->at(i + 1).calculate_distance(vector_of_points_->at(i + 2)), 2)) /
                          (-2 * vector_of_points_->at(i).calculate_distance(vector_of_points_->at(i + 1)) *
                           vector_of_points_->at(i + 1).calculate_distance(vector_of_points_->at(i + 2))))) *
                    180 / PI;
                if (angle != ((vector_of_points_->size()) - 2) * 180 / (vector_of_points_->size()))
                {
                    cout << "something wrong with ur RegularPolygon" << endl;
                    return 0;
                }
            }
        }

        double one_side = vector_of_points_->at(0).calculate_distance(vector_of_points_->at(1));
        area = (number_of_sides * one_side * one_side) / (4 * tan(PI / number_of_sides));
    }
    else
    {
        cout << "something wrong with ur RegularPolygon" << endl;
        return 0;
    }
    return area;
}