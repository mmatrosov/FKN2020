#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve();

signed main()
{
#ifdef _______
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
#else
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    int _ = _ = _ = 1;
    for (_; _; --_)
        solve();
}

const int N = 2e6 + 13, mod = 1e9 + 7;

void solve()
{
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 * x1 + y1 * y1 < x2 * x2 + y2 * y2)
    {
        swap(x1, x2);
        swap(y1, y2);
    }
    long double ang = atan2(y1, x1) - atan2(y2, x2);
    if (ang < -1e-6)
        ang += 2 * M_PI;
    ang = min(ang, 2 * M_PI - ang);
    long double r1 = sqrtl(x1 * x1 + y1 * y1), r2 = sqrtl(x2 * x2 + y2 * y2);
    long double ans = min(r1 + r2, r1 - r2 + r2 * ang);
    cout << fixed << setprecision(10) << ans;
}