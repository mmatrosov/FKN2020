#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#define PI 3.14159265359

using namespace std;

long double len(long double x1, long double y1, long double x2, long double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    long double xa, ya, xb, yb, z = 0;
    cin >> xa >> ya >> xb >> yb;
    cout << fixed;
    cout.precision(15);
    long double len0a = len(xa, ya, z, z);
    long double len0b = len(xb, yb, z, z);
    long double lenab = len(xa, ya, xb, yb);
    long double ans = len0a + len0b;
    if (len0a + lenab == len0b || len0b + lenab == len0a)
        ans = min(ans, lenab);
    if (len0a == len0b) {
        long double r = len0a;
        long double alpha = atan2(xa * yb - ya * xb, xa * xb + ya * yb);
        alpha = abs(alpha);
        long double now = min(2 * PI * r - r * alpha, r * alpha);
        ans = min(ans, now);
    }
    long double k = len0a / len0b;
    long double xc = xb * k, yc = yb * k;
    long double r = len0a;
    long double alpha = atan2(xa * yc - ya * xc, xa * xc + ya * yc);
    alpha = abs(alpha);
    long double now = min(2 * PI * r - r * alpha, r * alpha);
    now += len(xb, yb, xc, yc);
    ans = min(ans, now);

    k = len0b / len0a;
    xc = xa * k; yc = ya * k;
    r = len0b;
    alpha = atan2(xb * yc - yb * xc, xb * xc + yb * yc);
    alpha = abs(alpha);
    now = min(2 * PI * r - r * alpha, r * alpha);
    now += len(xa, ya, xc, yc);
    ans = min(ans, now);
    cout << ans;
}


