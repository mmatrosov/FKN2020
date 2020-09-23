#pragma GCC optimize ("O3")
#pragma GCC target (sse, sse1, sse2, tune=native, popcnt)

#include <bits/stdc++.h>
/*
const int MAX_MEM = 5e8;
int mpos = 0;
char mem[MAX_MEM];
inline void* operator new(size_t n) {
    char *res = mem + mpos;
    mpos += n;
    assert(mpos <= MAX_MEM);
    return (void *) res;
}
inline void operator delete(void *) {}*/

using namespace std;

#define loop(i, n) for(int i = 0; i < n; ++i)
#define FOR(i, a, n) for(int i = a; i < n; ++i)
#define vec vector
#define paii pair<int, int>
#define fr first
#define sc second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define SZ(x) (int)x.size()
#define Unique(x) x.erase(unique(all(x)), x.end())
#define ll long long

#define int long long

const int inf = 1e17 + 47, MAXN = 2e5 + 47, BL = 500;

mt19937 rnd(time(0));

void solve() {
    int n, k;
    cin >> n >> k;
    vec<int> a(n + 1, 0);
    loop(i, n) cin >> a[i + 1];
    sort(all(a));

    vec<vec<int> > dp(n + 1, vec<int>(k + 1, 0));
    vec<vec<int> > pr(n + 1, vec<int>(k + 1, -1));

    FOR(lvl, 1, k + 1) {
        FOR(pos, 1, n + 1) {
            for(int fin = pos - 1; fin >= 0; --fin) {
                int d = dp[fin][lvl - 1] + (pos - fin) * a[fin + 1];
                if(d >= dp[pos][lvl]) {
                    dp[pos][lvl] = d;
                    pr[pos][lvl] = fin;
                }
            }
        }
    }/*
    loop(i, k + 1) {
        loop(j, n + 1) cout << dp[j][i] << " ";
        cout << endl;
    }
    cout << endl;
    loop(i, k + 1) {
        loop(j, n + 1) cout << pr[j][i] << " ";
        cout << endl;
    }*/

    vec<int> ans;
    int j = n;
    for(int i = k; i > 0; --i) {
        if(pr[j][i] == -1) break;
        ans.pb(a[pr[j][i] + 1]);
        j = pr[j][i];
    }
    int uk = a.back();
    while(SZ(ans) < k) ans.pb(++uk);
    sort(all(ans));
    for(int a: ans) cout << a << " ";

}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie();

    #ifdef COFFEE_MACHINE
        freopen("imput.cpp", "r", stdin);
        freopen("output.cpp", "w", stdout);
    #endif // COFFEE_MACHINE

    int t = 1;
    while(t--) {
        solve();
    }
}
