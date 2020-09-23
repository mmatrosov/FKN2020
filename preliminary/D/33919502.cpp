#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
struct pt {
    double x, y;
    double len() {
        return sqrt(x * x + y * y);
    }
};
pt vec(pt a, pt b) {
    return {b.x - a.x, b.y - a.y};
}
double operator*(pt a, pt b) {
    return a.x * b.y - a.y * b.x;
}
double operator%(pt a, pt b) {
    return a.x * b.x + a.y * b.y;
}
signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    pt a, b;
    cin >> a.x >> a.y >> b.x >> b.y;
    cout.precision(20);

    if ((a * b) == 0) {
        cout << vec(a, b).len();
    } else {
        cout << min(a.len() + b.len(),
                    abs(a.len() - b.len()) + min(a.len(), b.len()) * abs(atan2(a * b, a % b)));
    }
}
