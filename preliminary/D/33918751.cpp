#include <bits/stdc++.h>

#define int long long
#define endl '\n'
#define vc vector
#define sz(v) (int) v.size()
#define endd endl; return 0;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define rep(n, i) for (int i = 0; i < n; ++i)
#define per(n, i) for (int i = n - 1; i >= 0; --i)
#define mp make_pair
#define pr pair
#define fs first
#define sc second
#ifdef LOCAL
#define cerr cout
#else
#define cerr if (0) cout
#endif

using namespace std;

typedef long long ll;

const long long INF = 1e18;
const int N = 1e5 + 5;
const double EPS = 1e-9;
const int MOD = 1e9 + 7;
const int A = 1e6 + 5;

struct Vec {
    double x, y;

    double len() {
        return hypot(x, y);
    }
};

void to_norm(Vec &v) {
    double lenght = v.len();
    v.x /= lenght;
    v.y /= lenght;
}

Vec operator*(Vec &v, double k) {
    v.x *= k;
    v.y *= k;
    return v;
}

double dot(const Vec &v1, const Vec &v2) {
    return v1.x * v2.x + v1.y * v2.y;
}

double cross(const Vec &v1, const Vec &v2) {
    return v1.x * v2.y - v1.y * v2.x;
}

double angle(const Vec &a, const Vec &b) {
    double ans = atan2(cross(a, b), dot(a, b));
    cerr << ans << endl;
    return abs(ans);
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef LOCAL
    freopen("text.txt", "r", stdin);
#endif
    double xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;
    cout << setprecision(7) << fixed;
    double ra = hypot(xa, ya), rb = hypot(xb, yb);
    double ans = ra + rb;
    ans = min(ans, abs(ra - rb) + angle({xa, ya}, {xb, yb}) * min(ra, rb));
    cout << ans;
    return 0;
}
