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
void solve() {
    int k1, b1; cin >> k1 >> b1;
    int k2, b2; cin >> k2 >> b2;
    if (k1 == k2 && b1 == b2){
        cout << "coincide" << endl;
        return;
    }
    if (k1 == k2){
        cout << "parallel" << endl;
        return;
    }
    cout << "intersect" << endl;
    ld k1_ = k1, b1_ = b1;
    ld k2_ = k2, b2_ = b2;
    ld y = (k2_ * b1_ - k1_ * b2_) / (k2_ - k1_);
    ld x;
    if (k1 != 0)
        x = (y - b1_) / k1_;
    else
        x = (y - b2_) / k2_;
    cout << x << " " << y << endl;
}
