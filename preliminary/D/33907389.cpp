#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>


using namespace std;


using ld = long double;


ld al, bl, angl;


ld f(ld r) {
    return abs(al - r) + abs(bl - r) + angl * r;
}


int main() {
    cout << fixed;

    cout.precision(10);

    ld xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;

    al = sqrt(xa * xa + ya * ya);
    bl = sqrt(xb * xb + yb * yb);

    angl = abs(atan2(xa * yb - ya * xb, xa * xb + ya * yb));
    ld ang2 = abs(atan2(xb * ya - yb * xa, xa * xb + ya * yb));

    angl = min(angl, ang2);

    ld r1 = min(al, bl);
    ld r2 = 0;

    cout << min(f(r1), f(r2));

    return 0;
}
