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

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef LOCAL
    freopen("text.txt", "r", stdin);
#endif
    int k1, b1;
    cin >> k1 >> b1;
    int k2, b2;
    cin >> k2 >> b2;
    if (k1 == k2) {
        if (b1 == b2) {
            cout << "coincide" << endd;
        } else {
            cout << "parallel" << endd;
        }
    }
    cout << setprecision(7) << fixed;
    cout << "intersect\n";
    double x = (double) (b2 - b1) / (double) (k1 - k2);
    cout << x << endl;
    cout << (double) k1 * x + b1 << endl;
    return 0;
}
