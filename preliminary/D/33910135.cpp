#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

struct Vector {
    ld x, y;
    Vector() {
        x = y = 0;
    }
    Vector(Vector a, Vector b) {
        x = b.x - a.x;
        y = b.y - a.y;
    }
    Vector(ld x, ld y) : x(x), y(y) {}
    ld operator*(Vector v) {
        return x * v.x + y * v.y;
    }
    ld operator^(Vector v) {
        return x * v.y - y * v.x;
    }
    ld len() {
        return sqrt(x * x + y * y);
    }
};

ld angel(Vector a, Vector b) {
    return abs(atan2(a ^ b, a * b));
}

int main() {
    Vector a, b;
    cin >> a.x >> a.y >> b.x >> b.y;
    if (a.len() > b.len()) {
        swap(a, b);
    }
    ld ans = 0;
    if (angel(a, b) > 2) {
        ans += a.len() + b.len();
    } else {
        ans += angel(a, b) * a.len() + (b.len() - a.len());
    }
    cout << setprecision(10) << fixed << ans << endl;
}
