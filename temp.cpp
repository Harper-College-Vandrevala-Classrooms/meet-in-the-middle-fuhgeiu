#include <cassert>


class Point {

    double x,y;

public:

    Point (double X,double Y) {

        x = X;
        y = Y;
    }

    double operator- (double,double) {


    }







};

int main () {

    Point p1(3.2,9.8);
    Point p2(5.5,-1.2);

    assert(p1-p2 < 11.3 && p1-p2 > 11.238);






}