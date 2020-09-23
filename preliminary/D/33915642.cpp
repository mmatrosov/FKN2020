#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define int long long
#define double long double
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define TIME ((clock() - start_time) / CLOCKS_PER_SEC)

using namespace std;
//using namespace __gnu_pbds;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count() + 'd'+'o'+'i'+'n'+'g' + 'g'+'e'+'y');

const int inf = 1e18;
const double eps = 1e-6;
double start_time;

struct Point {
    double x, y;
};

Point operator-(Point a, Point b) {
    return {a.x - b.x, a.y - b.y};
}

double operator*(Point a, Point b) {
    return a.x * b.x + a.y * b.y;
}

double operator%(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}

double ang(Point a, Point b, Point c) {
    Point v1 = b - a, v2 = b - c;
    return abs(atan2(v1 % v2, v1 * v2));
}

signed main()
{
    start_time = clock();
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout.precision(20);
    double r1 = sqrt(x1 * x1 + y1 * y1);
    double r2 = sqrt(x2 * x2 + y2 * y2);
    Point p1 = {x1, y1}, p2 = {x2, y2};
    if (abs(p1 % p2) < eps) {
        double dx = x1 - x2, dy = y1 - y2;
        cout << sqrt(dx * dx + dy * dy);
        return 0;
    }
    double ans = r1 + r2;
    double a = ang(p1, {0, 0}, p2);
    ans = min(ans, min(r1, r2) * a + abs(r1 - r2));
    cout << ans;
    return 0;
}