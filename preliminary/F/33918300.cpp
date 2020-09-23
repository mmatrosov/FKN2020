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
    int k; cin >> k; int ok = k; k = min(k, n);
    vector<int> a(n); forn (i, n) cin >> a[i]; sort(all(a));
    vector<int> vals = a; vals.resize(unique(all(vals)) - vals.begin());
    vals.push_back(0); sort(all(vals));
    vector<vector<int>> dp(k + 2, vector<int>(len(vals)));
    vector<vector<int>> prv(k + 2, vector<int>(len(vals)));
    for (int cnt = 0; cnt < k; ++cnt){
        for (int lastp = 0; lastp < len(vals); ++lastp){
            for (int newp = lastp + 1; newp < len(vals); ++newp){
                int add = 0;
                for (auto i : a){
                    if (i >= vals[newp])
                        add += vals[newp] - vals[lastp];
                }
                if (dp[cnt][lastp] + add > dp[cnt + 1][newp]){
                    dp[cnt + 1][newp] = dp[cnt][lastp] + add;
                    prv[cnt + 1][newp] = lastp;
                }
            }
        }
    }
    auto bst =  *max_element(all(dp[k]));
    int cur_ind = find(all(dp[k]), bst) - dp[k].begin();
    int curcnt = k;
    vector<int> res;
    while (dp[curcnt][cur_ind] != 0){
        res.push_back(vals[cur_ind]);
        int pr = prv[curcnt][cur_ind];
        curcnt--;
        cur_ind = pr;
    }
    while (len(res) < ok){
        int val = rnd() % ((int) 1e9);
        if (!count(all(res), val))
            res.push_back(val);
    }
    sort(all(res));
    for (auto i : res)
        cout << i << ' ';
}