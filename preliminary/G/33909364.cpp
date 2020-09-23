#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define int long long
#define double long double
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define TIME ((clock() - start_time) / CLOCKS_PER_SEC)

using namespace std;
//using namespace __gnu_pbds;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count() + 'd'+'o'+'i'+'n'+'g' + 'g'+'e'+'y');

const int inf = 1e18;
const double eps = 1e-6;
double start_time;

const int maxn = 1e5 + 1;
const int mb = 32;

int s[maxn];
vector<pair<int, int>> g[maxn];

void dfs(int v, int pr) {
    for (auto to : g[v]) {
        if (to.ff == pr) continue;
        s[to.ff] = (s[v] ^ to.ss);
        dfs(to.ff, v);
    }
}


struct Node
{
    int next[2] = {-1}, x;
};

vector<Node> bor;

void add(int x)
{
    int v = 0;
    for (int i = mb - 1; i >= 0; --i) {
        int b = (((1ll << i) & x) >> i);
        if (bor[v].next[b] == -1) {
            bor[v].next[b] = (int)bor.size();
            bor.pb({{-1, -1}, -1});
        }
        v = bor[v].next[b];
    }
    bor[v].x = x;
}

int get(int x)
{
    int v = 0;
    for (int i = mb - 1; i >= 0; --i) {
        int b = (((1ll << i) & x) >> i);
        if (bor[v].next[(b ^ 1)] != -1) {
            v = bor[v].next[(b ^ 1)];
        } else {
            v = bor[v].next[b];
        }
    }
    return bor[v].x;
};

signed main()
{
    start_time = clock();
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b, w;
        cin >> a >> b >> w, --a, --b;
        g[a].pb({b, w});
        g[b].pb({a, w});
    }
    dfs(0, -1);
    int ans = 0;
    int p1 = 0, p2 = 0;
    bor.pb({{-1, -1}, -1});
    map<int, int> idx;
    for (int i = 0; i < n; ++i) {
        idx[s[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        add(s[i]);
        int val = get(s[i]);
        if ((val ^ s[i]) > ans) {
            ans = (val ^ s[i]);
            p1 = i;
            p2 = idx[val];
        }
    }
    cout << p1 + 1 << " " << p2 + 1 << "\n";
    return 0;
}