#include <bits/stdc++.h>

using namespace std;

struct vect{
    double x, y;
}v, u, z;

double vect_mult(vect v, vect u)
{
    return (v.x * u.y - v.y * u.x);
}

double scal_mult(vect v, vect u)
{
    return (v.x * u.x + v.y * u.y);
}

double dist(vect p1, vect p2){
    return pow((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y), 0.5);
}

int main()
{
    cin >> v.x >> v.y >> u.x >> u.y;
    z.x = 0;
    z.y = 0;
    double angle = abs(atan2(vect_mult(v, u), scal_mult(v, u)));
    double d1 = dist(v, z);
    double d2 = dist(u, z);
    double ans;
    if (d1 < d2 ) {
        ans = d2 - d1 + angle * d1;
    }
    else {
        ans = d1 - d2 + angle * d2;
    }
    cout << fixed << setprecision(10) << min(ans, d1 + d2);
    return 0;
}

