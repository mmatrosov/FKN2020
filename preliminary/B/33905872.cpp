#include <bits/stdc++.h>
#define int long long
#define pi pair<int, int>
#define l first
#define r second
#define pb push_back
#define int long long

using namespace std;

const int maxn = 2e5 + 1, mod = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int k1, b1, k2, b2;
    cin >> k1 >> b1;
    cin >> k2 >> b2;
    if (k1 == k2 && b1 == b2) {
        cout << "coincide";
        return 0;
    }
    if (k1 == k2) {
        cout << "parallel";
        return 0;
    }
    double x = (b2 - b1) / (double)(k1 - k2);
    double y = k1 * x + b1;
    cout << "intersect\n";
    cout << fixed << setprecision(10) << x << ' ' << y;
    return 0;
}
