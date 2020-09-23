#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

const double P = M_PI;

struct point{
    ll x, y;
};

struct vec{
    ll x, y;
};

ll cross(vec a, vec b) {
    return a.x * b.y - a.y * b.x;
}

ll dot(vec a, vec b) {
    return a.x * b.x + a.y * b.y;
}

vec operator-(point a, point b) {
    return {a.x - b.x, a.y - b.y};
}

ll len(vec a) {
    return a.x * a.x + a.y * a.y;
}

int main() {
    point a, b;
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    point null = {0, 0};
    if (len(a - null) > len(b - null)) {
        swap(a, b);
    }
    vec c = a - null;
    vec d = b - null;
    double ans = sqrt(len(c)) + sqrt(len(d));
    double r = sqrt(len(c));
    double alpha = fabs(atan2(cross(c, d), dot(c, d)));
    double l = min((2 * P - alpha) * r, alpha * r);
    ans = min(ans, l - sqrt(len(c)) + sqrt(len(d)));
    cout << fixed << setprecision(6);
    cout << ans;

    return 0;
}
