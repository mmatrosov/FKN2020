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

    solve();
}

void solve() {
    int n; cin >> n;
    vector<int> a(n); forn (i, n) cin >> a[i];
    sort(all(a));
    a.resize(unique(all(a)) - a.begin());
    int q; cin >> q;
    forn (qwe, q){
        int val; cin >> val;
        int cnt = lower_bound(all(a), val) - a.begin();
        cout <<  cnt << endl;
    }

}
