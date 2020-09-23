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
ld ang(ld xa, ld ya, ld xb, ld yb) {
    return abs(atan2(xa * yb - xb * ya, xa * xb + ya * yb));
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int xa, ya, xb, yb;
    cout.precision(16);
    cin >> xa >> ya >> xb >> yb;
    ld ans = sqrtl(xa * xa + ya * ya) + sqrtl(xb * xb + yb * yb);
    ld rd = max(sqrtl(xa * xa + ya * ya), sqrtl(xb * xb + yb * yb)) - min(sqrtl(xa * xa + ya * ya), sqrtl(xb * xb + yb * yb));
    ld r = min(sqrtl(xa * xa + ya * ya), sqrtl(xb * xb + yb * yb));
    ans = min(ans, ang(xa, ya, xb, yb) * r + rd);
    cout << ans;
}
