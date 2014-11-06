#include "Point.h"
#include "Vector.h"
#include "Line.h"
#include <iostream>

using namespace std;

int main()
{
    Point p(1, 2);
    Vector v(1, 1);
    double len = v.Length();
    v = v.Normal() * len;
    p = p.Translate(v);
    Point p0 = p;
    cout << p.GetX() << " " << p.GetY() << endl;

    Line l1(Point(1, 2), Point(2, 3));
    Line l2(Point(4, 4), Point(3, 3));
    cout << (l1 == l2) << endl;
    cout << l1.Parallel(l2) <<endl;
    return 0;
}
