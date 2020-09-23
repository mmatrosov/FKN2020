#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())
#define ld long double

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ld x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ld d1 = sqrt(x1 * x1 + y1 * y1);
    ld d2 = sqrt(x2 * x2 + y2 * y2);
    ld ans = d1 + d2;
    if (d1 > 0 && d2 > 0)
    {
        ld ang = abs(atan2(x1 * y2 - x2 * y1, x1 * x2 + y1 * y2));
        ans = min(ans, abs(d1 - d2) + ang * min(d1, d2));
    }
    cout.precision(20);
    cout << fixed << ans;
}
