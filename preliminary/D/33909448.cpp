#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

double dist(double a, double b, double r)
{
    double cw = fabs(b - a);
    double ccw = fabs(2 * M_PI - b + a);

    double dis1 = cw * r;
    double dis2 = ccw * r;

    //cout << fixed << setprecision(7)<< dis1 << " " << dis2;
    return min(dis1, dis2);
}

int main()
{
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    double a, b;

    double x1n, y1n, x2n, y2n;
    double dis1 = sqrt(x1 * x1 + y1 * y1);
    x1n = x1 / dis1;
    y1n = y1 / dis1;
    double dis2 = sqrt(x2 * x2 + y2 * y2);
    x2n = x2 / dis2;
    y2n = y2 / dis2;

    if (y1n >= 0)
    {
        a = acos(x1n);
    } else
    {
        a = M_PI * 2 - acos(x1n);
    }
    if (y2n >= 0)
    {
        b = acos(x2n);
    } else
    {
        b = M_PI * 2 - acos(x2n);
    }

    cout << fixed << setprecision(7) << min(dis1 + dis2, dist(a, b, min(dis1, dis2)) + fabs(dis1 - dis2));


    return 0;
}
