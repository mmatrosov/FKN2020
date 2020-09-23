#include <bits/stdc++.h>
#define int long long
#define pi pair<int, int>
#define l first
#define r second
#define pb push_back
#define int long long
#define double long double
#define sqrt sqrtl

using namespace std;

const int maxn = 2e5 + 1, mod = 1e9 + 7;

int gd(int x, int y) {
    return x * x + y * y;
}

double gan(int x, int y, int a, int b) {
    if (x * b == y * a) {
        if (x * a >= 0 && y * b >= 0)
            return 0;
        return acosl(-1);
    }
    double ans = acosl((x * a + y * b) / (sqrt(gd(x, y)) * sqrt(gd(a, b))));
    return min(ans, 2 * acos(-1) - ans);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    cout << fixed << setprecision(12);
    double ans1 = sqrt(gd(x, y)) + sqrt(gd(a, b));
    if (gd(a, b) < gd(x, y)) {
        swap(a, x); swap(b, y);
    }
    double ans2 = sqrt(gd(a, b)) - sqrt(gd(x, y)) + sqrt(gd(x, y)) * gan(a, b, x, y);
    cout << min(ans1, ans2);
    return 0;
}
