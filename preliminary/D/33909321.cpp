#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define F first
#define S second
#define pb push_back
mt19937 rnd;

const ld pi = acos(-1);

struct Point {
    ld x, y;
    ld calc() {
        if (x == 0) {
            if (y >= 0) {
                return pi / 2;
            }
            else {
                return 3 * pi / 2;
            }
        }
        else {
            return atan(y / x);
        }
    }
};

ld R(Point a) {
    return sqrt(a.x * a.x + a.y * a.y);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    Point a, b;
    cin >> a.x >> a.y >> b.x >> b.y;
    cout << fixed << setprecision(12);
    ld p = a.calc(), q = b.calc();
    ld alpha = abs(p - q);
    if (a.x * b.x < 0) {
        alpha = abs(pi - alpha);
    }
    alpha = min(alpha, 2 * pi - alpha);
    cout << min(R(a) + R(b), abs(R(a) - R(b)) + alpha * min(R(a), R(b))) << "\n";

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
