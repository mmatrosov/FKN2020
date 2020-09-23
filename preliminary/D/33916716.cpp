#include <bits/stdc++.h>
#define endl '\n'
#define all(a) (a).begin(), (a).end()
#define len(a) (int) (a).size()
#define forn(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define int long long
using namespace std;
void solve();
mt19937 rnd(2007);
signed main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    swap(rng, rnd);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cout.precision(20);
    cout << fixed;
    solve();
}
typedef long double ld;
ld xa, ya, xb, yb, angle, lng1, lng2;

ld f(ld l){
    return abs(l - lng1) + abs(lng2 - l) + l * angle;
}
ld ans = 1e18;


void solve(){
    cin >> xa >> ya;
    cin >> xb >> yb;
    angle = abs(atan2(xa * yb - xb * ya, xa * xb + ya * yb));
    lng1 = hypot(xa, ya);
    lng2 = hypot(xb, yb);


    ld l = 0, r = min(lng1, lng2) + 1e-9;
    forn (kek, 300){
        ld m = (l + r) * 0.5;
        if (f(m) > f(m + 1e-7))
            l = m;
        else
            r = m;
    }
    cout << min(f(l), f(r)) << endl;
}
