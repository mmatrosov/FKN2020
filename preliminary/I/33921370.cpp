#pragma GCC optimize ("O3")
#pragma GCC target (sse, sse1, sse2, tune=native, popcnt)

#include <bits/stdc++.h>

const int MAX_MEM = 25e7;
int mpos = 0;
char mem[MAX_MEM];
inline void* operator new(size_t n) {
    char *res = mem + mpos;
    mpos += n;
    assert(mpos <= MAX_MEM);
    return (void *) res;
}
inline void operator delete(void *) {}

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

const int inf = 1e17 + 47, MAXN = 2e5 + 47;

mt19937 rnd(time(0));

int n, m, k, s, f;
vec<int> stat;
int fire[MAXN], d[MAXN];
vec<paii> graf[MAXN];

void djk1() {
    loop(i, n) d[i] = inf;
    set<paii> q;
    for(int s: stat) d[s] = 0, q.insert({0LL, s});
    while(!q.empty()) {
        int p1 = q.begin()->sc;
        q.erase(q.begin());

        for(paii pw: graf[p1]) {
            int p2 = pw.fr, w = pw.sc;

            if(d[p2] > d[p1] + w) {
                q.erase({d[p2], p2});
                d[p2] = d[p1] + w;
                q.insert({d[p2], p2});
            }
        }
    }

    loop(i, n) fire[i] = d[i];
}

bool djk2(int mid) {
    loop(i, n) d[i] = inf;
    set<paii> q;
    q.insert({0LL, s});
    d[s] = 0;
    while(!q.empty()) {
        int p1 = q.begin()->sc;
        q.erase(q.begin());

        for(paii pw: graf[p1]) {
            int p2 = pw.fr, w = pw.sc;

            if(d[p2] > d[p1] + w && d[p1] + w < fire[p2]) { //!!!
                q.erase({d[p2], p2});
                d[p2] = d[p1] + w;
                q.insert({d[p2], p2});
            }
        }
    }

    if(d[f] <= mid) return 1;
    return 0;
}


bool fun(int mid) {
    return djk2(mid);
}

void solve() {
    cin >> n >> m >> k;
    stat.resize(k);
    loop(i, k) {
        cin >> stat[i];
        stat[i]--;
    }
    loop(i, m) {
        int a, b, s;
        cin >> a >> b >> s;
        --a, --b;
        graf[a].pb({b, s});
        graf[b].pb({a, s});
    }
    cin >> s >> f;
    --s, --f;

    djk1();
    int N = 1e10 + 7;
    int l = 0, r = N;
    while(l < r) {
        int mid = (l + r) / 2;

        if(!fun(mid)) l = mid + 1;
        else r = mid;
    }
    if(l == N) l = -1;
    cout << l << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie();

    #ifdef COFFEE_MACHINE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // COFFEE_MACHINE

    int t = 1;
    while(t--) {
        solve();
    }
}
