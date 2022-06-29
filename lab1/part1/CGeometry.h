#pragma once
#include<vector>

using namespace std;

class Point
{
private:
    double x_;
    double y_;
public:
    Point(double x = 0, double y = 0);

    double calculate_distance(const Point &other) const;

    double get_x() const;

    double get_y() const;
};

class BrokenLine{
protected:
    vector<Point>* vector_of_points_ = nullptr;
public:
    virtual ~BrokenLine();

    BrokenLine(vector<Point>& vector_of_points);

    BrokenLine(const BrokenLine& other);

    BrokenLine& operator=(const BrokenLine& other);

    vector<Point>* get_vector_of_points() const;

    virtual void print_line() const;

    virtual double get_length() const;
};

class ClosedBrokenLine : public BrokenLine{
public:
    ~ClosedBrokenLine();

    ClosedBrokenLine(vector<Point>& vector_of_points);

    ClosedBrokenLine(const ClosedBrokenLine& other);

    ClosedBrokenLine& operator=(const ClosedBrokenLine& other);

    void print_line() const;

    double get_length() const;

};

class Shape{
public:
    virtual ~Shape(){}
    virtual double calculate_perimeter() = 0;
    virtual double calculate_area() = 0;
};

class Polygon : public Shape{
protected:
    vector<Point>* vector_of_points_ =  nullptr;
public:
    ~Polygon();

    Polygon(vector<Point>& other);

    Polygon(const Polygon& other);

    Polygon& operator= (const Polygon& other);

    bool is_intersects();

    double calculate_perimeter();

    double calculate_area();
};

class Triangle : public Shape {
private:
    Point a_;
    Point b_;
    Point c_;
public:
    ~Triangle();

    Triangle(Point a, Point b, Point c);

    Triangle(const Triangle& other);

    bool compare_distances(Point a, Point b, Point c);

    void is_correct();

    const Triangle& operator=(const Triangle& other);

    double calculate_perimeter();

    double calculate_area();
};

class Section{
private:
    Point a_;
    Point b_;
public:
    ~Section();

    Section(Point a, Point b);

    Section(const Section& other);

    const Section& operator=(const Section& other);

    Point get_starting_point();

    Point get_end_point();

    double get_dx();

    double get_dy();

    double calculate_coeff();

    bool is_parallel(Section& other);

    double get_length();
};

class Trapezoid : public Shape{
private:
    Section ab_;
    Section cd_;
public:
    ~Trapezoid(){}

    Trapezoid(Section ab, Section cd);

    Trapezoid(const Trapezoid& other);

    const Trapezoid& operator= (const Trapezoid& other);
    double calculate_perimeter();

    double calculate_area();
};

class RegularPolygon :public Polygon{
public:
    ~RegularPolygon(){}

    RegularPolygon(vector<Point> &vector_of_points);

    RegularPolygon(const RegularPolygon& other);

    const RegularPolygon& operator= (const RegularPolygon& other);

    bool is_intersects();

    double calculate_perimeter();

    double calculate_area();
};