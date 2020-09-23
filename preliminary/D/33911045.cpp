#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <set>
#include <cmath>
#define all(a) a.begin(), a.end()
///#pragma GCC optimize("Ofast")
#define int long double
#define ft first
#define sd second


using namespace std;

void fast_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

const int INF = 1e18;
const int DEBUG = 1;
const long double Pi = acos(-1);

struct point {
    int x, y;
    point(int x1 = 0, int y1 = 0) {
        x = x1;
        y = y1;
    }
};

long double dist(point P1, point P2) {
    return sqrt((P1.x - P2.x) * (P1.x - P2.x) + (P1.y - P2.y) * (P1.y - P2.y));
}

point A;
point B;
point O;

void init() {
    ///ifstream cin("task.in"); ofstream cout("task.out");
    ///fast_IO();
    cin >> A.x >> A.y;
    cin >> B.x >> B.y;
    O.x = 0;
    O.y = 0;
    /// cin.close(); cout.close();
}



signed main()
{
    ///ifstream cin("task.in"); ofstream cout("task.out");
    ///fast_IO();
    init();
    if (A.x == O.x && A.y == O.y) {
        cout << dist(A, B);
        return 0;
    }
    if (B.x == O.x && B.y == O.y) {
        cout << dist(A, B);
        return 0;
    }
    long double ans1 = dist(A, O) + dist(O, B);

    long double a1 = atan2(A.y, A.x);
    long double a2 = atan2(B.y, B.x);
    long double ang1 = abs(a1 - a2);
    long double ang2 = abs(a1 - a2 + 2 * Pi);
    long double ang3 = abs(a1 - a2 - 2 * Pi);
    long double ang = min(min(ang1, ang2), ang3);

    long double ans2 = abs(dist(A, O) - dist(B, O)) + ang * min(dist(O, B), dist(O, A));

    cout.precision(100);
    cout << min(ans1, ans2);
    ///cin.close(); cout.close();
    return 0;
}
