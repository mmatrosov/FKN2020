#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;

struct line {
    ll A, B, C;
    line(int k, int b) {
        ll x1 = 0, y1 = b;
        ll x2 = 1, y2 = k + b;
        A = y1 - y2;
        B = x2 - x1;
        C = x1 * y2 - x2 * y1;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll k1, b1, k2, b2;
    cin >> k1 >> b1 >> k2 >> b2;
    line L(k1, b1), M(k2, b2);
    /*if ((L.A * M.C - M.A * L.C == 0) && (L.B * M.C - M.B * L.C == 0)) {
        cout << "coincide";
        return 0;
    }
    if (L.A * M.B - M.A * L.B == 0) {
        cout << "parallel";
        return 0;
    }
    ld x = -(L.C * M.B - M.C * L.B) * 1.0 / (L.A * M.B - M.A * L.B);
    ld y = -(L.A * M.C - M.A * L.C) * 1.0 / (L.A * M.B - M.A * L.B);*/
    if (k1 == k2 && b1 == b2) {
        cout << "coincide";
        return 0;
    }
    if (k1 == k2) {
        cout << "parallel";
        return 0;
    }
    ld x = (b2 - b1) * 1.0 / (k1 - k2);
    ld y = k1 * x + b1;
    cout.precision(15);
    cout << "intersect\n";
    cout << fixed << x << " " << y;
    return 0;
}
