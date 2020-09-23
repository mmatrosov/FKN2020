//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const ld pi = acos(-1);

int main()
{
    cout.precision(20);
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ld r1 = sqrt(x1 * x1 + y1 * y1);
    ld r2 = sqrt(x2 * x2 + y2 * y2);
    ld d1 = r1 + r2;
    ld angle = abs(atan2(x1 * y2 - x2 * y1, x1 * x2 + y1 * y2));
    if (angle > pi) angle = 2 * pi - angle;
    ld d2 = max(r1, r2) - min(r1, r2) + min(r1, r2) * angle;
    cout << min(d1, d2) << endl;
    return 0;
}
