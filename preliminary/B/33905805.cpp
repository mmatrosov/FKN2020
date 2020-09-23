#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fast ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

ll INF = (ll) 1e20;
int iINF = (int) 1e20;
ll mod = (ll) 1e9 + 7;

mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
    fast
    ld k, b, k1, b1;
    cin >> k >> b >> k1 >> b1;
    if(k == k1 && b == b1) {
        cout << "coincide";
        return 0;
    }
    if(k == k1) {
        cout << "parallel";
        return 0;
    }
    ld A1 = k, B1 = -1, C1 = b;
    ld A2 = k1, B2 = -1, C2 = b1;
    ld x = - (C1 * B2 - C2 * B1) / (A1 * B2 - A2 * B1);
    ld y = - (A1 * C2 - A2 * C1) / (A1 * B2 - A2 * B1);
    cout << "intersect\n";
    cout << fixed << setprecision(6) << x << ' ' << y << '\n';
}
