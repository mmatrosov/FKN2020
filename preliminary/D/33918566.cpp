#include <bits/stdc++.h>

/*#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native") */

//#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
//using namespace __gnu_pbds;

#define ss second
#define ff first
#define int long long
#define double long double
#define pb push_back

const int N = 4e6 + 51, MOD = 1e9 + 7, mod = 998244353,INF = 2e16;

mt19937 Flash_new_51(51515);

using vi = vector <int>;
using vp = vector <pair <int, int>>;

double dist(double x1, double y1, double x2, double y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

signed main() {
    #ifdef Flash
     freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    double x1, y1, x2, y2, ans, ans1;
    cin >> x1 >> y1 >> x2 >> y2;

    double A = sqrt(x1 * x1 + y1 * y1), B = sqrt(x2 * x2 + y2 * y2);
    ans = A + B, ans1 = abs(A - B);

    if (A < B) swap(x1, x2), swap(y1, y2), swap(A, B);

    double pov = B / A;
    x1 *= pov;
    y1 *= pov;

    A = x1 * x1 + y1 * y1;
    B = x2 * x2 + y2 * y2;

    double cos = (A + B - dist(x1, y1, x2, y2)) / (2 * A);
    ans1 += (sqrt(A) * acos(cos));

    ans = min(ans, ans1);
    cout << setprecision(300) << fixed << ans;
}
