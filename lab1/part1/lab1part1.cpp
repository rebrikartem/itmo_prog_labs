#include<iostream>
#include"CGeometry.h"

#define PI 3.141592653589793238462643

using namespace std;

int main(){
    cout << "hello world!" << endl;

    Point d1;
    Point d2(3,4);

    cout << d1.calculate_distance(d2) << endl;
    cout << endl;

    Point d3(6,8);

    vector<Point> points;
    points.push_back(d1);
    points.push_back(d2);
    points.push_back(d3);

    BrokenLine bl1(points);
    bl1.print_line();
    cout << endl;

    points.push_back(d3);

    bl1.print_line();
    cout << endl;
    cout << bl1.get_length() << endl;
    cout << endl;

    BrokenLine bl2 = BrokenLine(bl1);
    bl2.print_line();
    cout << endl;

    ClosedBrokenLine cbl1 = ClosedBrokenLine(points);
    cbl1.print_line();
    cout << endl;

    ClosedBrokenLine cbl2 = cbl1;
    cbl2.print_line();
    cout << cbl2.get_length() << endl;
    cout << endl;

    ClosedBrokenLine cbl3(cbl2);
    cbl3.print_line();
    cout << endl;

    Point d11(0,0);
    Point d22(5,0);
    Point d33(2,3);
    Point d44(3,3);

    Section ab(d11,d22);
    Section cd(d33,d44);

    Trapezoid tr1(ab,cd);

    cout << "area " << tr1.calculate_area() << endl;
    cout << "perimeter " <<tr1.calculate_perimeter() << endl;
    cout << endl;

    Point d111(1,1);
    Point d222(-2,4);
    Point d333(-2,-2);

    Triangle tri1(d111,d222,d333);

    cout << "area " << tri1.calculate_area() << endl;
    cout << "perimeter " << tri1.calculate_perimeter() << endl;
    cout << endl;

    Point dd1(0,0);
    Point dd2(-3,4);
    Point dd3(0,8);
    Point dd4(5,8);
    Point dd5(8,4);
    Point dd6(5,0);

    vector<Point> p;
    p.push_back(dd1);
    p.push_back(dd2);
    p.push_back(dd3);
    p.push_back(dd4);
    p.push_back(dd5);
    p.push_back(dd6);

    RegularPolygon rp(p);

    cout << "area " << rp.calculate_area() << endl;
    cout << "perimeter " << rp.calculate_perimeter() << endl;
    cout << endl;

    Polygon p1(p);
    
    cout << "area " << p1.calculate_area() << endl;
    cout << "perimeter " << p1.calculate_perimeter() << endl;
    cout << endl;

    Point m1(0,0);
    Point m2(3,4);
    Point m3(2,0);
    Point m4(0,2);

    vector<Point> m;
    m.push_back(m1);
    m.push_back(m2);
    m.push_back(m3);
    m.push_back(m4);

    RegularPolygon rm(m);
    Polygon ppp(m);

    Shape* ptr;

    vector<Shape*> shapes;

    shapes.push_back(&tr1);
    shapes.push_back(&tri1);
    shapes.push_back(&rp);
    shapes.push_back(&p1);

    cout << endl;
    cout << "POLYMORPHISM";
    cout << endl;
    
    for(int i = 0; i < shapes.size(); i++){
        ptr = shapes.at(i);
        cout << "area " << ptr->calculate_area() << endl;
        cout << "perimeter " << ptr->calculate_perimeter() << endl;
        cout << endl;
    }

    return 0;
}