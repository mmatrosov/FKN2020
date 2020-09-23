#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define pb push_back
#define pf push_front
#define ft first
#define sc second
#define all(v) v.begin(), v.end()
using namespace std;
const int maxn = 100000, inf = 1e18;
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int k1, b1, k2, b2;
    cout.precision(16);
    cin >> k1 >> b1 >> k2 >> b2;
    if (k1 == k2 && b1 == b2) {
        cout << "coincide\n";
        return 0;
    }
    if (k1 == k2) {
        cout << "parallel\n";
        return 0;
    }
    cout << "intersect\n";
    ld x = (b2 - b1 + 0.0) / (k1 - k2 + 0.0);
    ld y = k1 * x + b1;
    cout << x << " " << y << "\n";
}
