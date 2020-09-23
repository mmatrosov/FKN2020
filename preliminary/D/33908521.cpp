#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

struct Vec {
    ld x, y;

    Vec(ld x_, ld y_) : x(x_), y(y_) {}

    Vec operator+ (const Vec& other) {
        return {x + other.x, y + other.y};
    }

    Vec operator- (const Vec& other) {
        return {x - other.x, y - other.y};
    }

    ld operator^ (const Vec& other) {
        return x * other.x + y * other.y;
    }

    ld operator% (const Vec& other) {
        return x * other.y - y * other.x;
    }

    ld getR() {
        return sqrtl(x*x + y*y);
    }
};

ld getAngle(Vec& v1, Vec& v2) {
    return abs(atan2(v1%v2, v1^v2));
}

signed main() {
#ifdef LOCAL
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;

    Vec a(xa, ya), b(xb, yb);

    
    ld ra = a.getR();
    ld rb = b.getR();

    cout << fixed << setprecision(7);

    ld ans = abs(ra - rb);
    ans += min(ra, rb) * getAngle(a, b);

    cout << min(ans, ra + rb) << '\n';
}
