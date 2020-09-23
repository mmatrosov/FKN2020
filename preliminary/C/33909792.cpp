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
    int n;
    cin >> n;
    vec<int> a(n);
    loop(i, n) cin >> a[i];
    sort(all(a));
    Unique(a);
    int q;
    cin >> q;
    loop(i, q) {
        int b;
        cin >> b;
        int ans = (int) (lower_bound(all(a), b) - a.begin());
        cout << ans << endl;
    }
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
