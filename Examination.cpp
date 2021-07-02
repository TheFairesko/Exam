

#include <iostream>
#include <cmath>
using namespace std;

class Point {
protected:
    double x0 = 0;
    double y0 = 0;
public:
    Point(double x, double y) {
        x0 = x;
        y0 = y;
    };
    Point(){x0 = 0;y0 = 0;  };
    double set_x(){ return x0; };
    double set_y(){ return y0; };
    double* _x(){ return &x0; };
    Point operator=(Point x) { x0 = x.x0; y0 = x.y0; return *this; };
    virtual void move(double dx, double dy) {
        x0 = x0 + dx;
        y0 = y0 + dy;
    }
    virtual void output(){
        cout << x0 << ' ' << y0 << endl;
    }
};

class Circle : public Point {
    double r0 = 0;
public:
    Circle() { r0 = 1; };
    Circle(double x, double y, double r) {
        x0 = x;
        y0 = y;
        r0 = r;
    };
    Circle(Point x, double r) {
        x0 = x.set_x();
        y0 = x.set_y();
        r0 = r;
    }
    virtual void move(double dx, double dy) {
        Point::move(dx, dy);
    }
    virtual void output() {
        cout << x0 << ' ' << y0 << endl;
    }

};


int main()
{
    Point point(1, 2);
    double dx = -7, dy = 9;
    point.move(dx, dy);
    point.output();
    Circle cir(3, 4, 4);
    cir.move(dx, dy);
    cir.output();
}

