#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fast ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

ll INF = (ll) 1e20;
int iINF = (int) 1e20;
ll mod = (ll) 1e9 + 7;

mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());

ld dist(ld x, ld y) {
    return sqrtl(x * x + y * y);
}
ld dist1(ld x, ld y) {
    return (x * x + y * y);
}

ld dd(ld x1, ld y1, ld x2, ld y2) {
    return sqrtl((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
ld dd1(ld x1, ld y1, ld x2, ld y2) {
    return ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

ld pi = 3.14159265358979323846;

signed main() {
    fast
    ld x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ld ans1 = dist(x1, y1) + dist(x2, y2);
    ld ans2 = abs(dist(x1, y1) - dist(x2, y2));
    if(dist(x1, y1) < dist(x2, y2)) {
        ld num = dist(x1, y1) / dist(x2, y2);
        x2 *= num;
        y2 *= num;
    }
    else {
        ld num = dist(x2, y2) / dist(x1, y1);
        x1 *= num;
        y1 *= num;
    }
    ld a = dist1(x1, y1), b = dist1(x2, y2), d = dd1(x1, y1, x2, y2);
    ld cos = (a + b - d) / (2 * a);
    ld res = acos(cos);
    ans2 += (sqrtl(a) * res);
    cout << fixed << setprecision(7) << min(ans1, ans2);
}