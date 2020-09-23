#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;

struct pt {
    double x, y;
};

double ks(pt a, pt b) {
    return a.x * b.y - a.y * b.x;
}

double sc(pt a, pt b) {
    return a.x * b.x + a.y * b.y;
}

int sign(double x) {
    if (x < 0) return -1;
    if (x == 0) return 0;
    return +1;
}

double dst(double x, double y) {
    return sqrt(x * x + y * y);
}

double tryto(pt a, pt b) {
    double angle = atan2(ks(a, b), sc(a, b));
    double len = 2 * acos(-1) * dst(a.x, a.y) * (fabs(angle) / acos(-1) / 2);
    return len + abs(dst(b.x, b.y) - dst(a.x, a.y));
}

double solve(pt a, pt b) {
    return min({dst(a.x, a.y) + dst(b.x, b.y), tryto(a, b), tryto(b, a)});
}

void PUNKS_NOT_DEAD() {
    pt a, b;
    cin >> a.x >> a.y >> b.x >> b.y;
    cout << fixed << setprecision(10) << min(solve(a, b), solve(b, a));
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    PUNKS_NOT_DEAD();
}