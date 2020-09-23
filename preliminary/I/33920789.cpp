#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("O3")

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define double long double
#define _ << ' ' <<
#define For(i,z) for(int i=0;i<int32_t(z);++i)
#define printObj(a) {for (auto &i : a) cout << i << ' '; cout << '\n';}
#define sqr(a) ((a)*(a))

#define pii pair<int, int>
#define pdd pair<double, double>
#define f first
#define s second

template<typename T>
using orset = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T, typename K>
using ormap = tree <T, K, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T, typename K> inline void umax(T &a, K b) { a = max(a, (T)b); }
template<typename T, typename K> inline void umin(T &a, K b) { a = min(a, (T)b); }
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int32_t N = 2e5 + 10;
const int64_t INF = 1e16;
const pair<int64_t, int64_t> PINF = make_pair(INF, INF);
const double EPS = 1e-7;
const int MOD = 1e9 + 7;
const int II = 1e9 + 10;
const int64_t AMOD = 99194853094755497;
const double PI = 3.14159265359;

int smoke[N];
int dst[N];
vector <pii> gr[N];
vector <int> fires(N);

int32_t main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, k; cin >> n >> m >> k;
    fires.resize(k);
    for (int &i : fires) cin >> i, i--;
    For (i, m) {
        int a, b, l; cin >> a >> b >> l; a--; b--;
        gr[a].emplace_back(l, b);
        gr[b].emplace_back(l, a);
    }

    For (i, N) smoke[i] = dst[i] = INF;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    for (int &i : fires) q.emplace(0, i);
    while (q.size()) {
        int v = q.top().s, dst = q.top().f;
        q.pop();
        if (smoke[v] < dst) continue;
        smoke[v] = dst;
        for (pii &i : gr[v])
            if (smoke[i.s] > dst + i.f) {
                smoke[i.s] = dst + i.f;
                q.emplace(dst + i.f, i.s);
            }
    }
    int s, f; cin >> s >> f; s--; f--;
    q.push({0, s});
    while (q.size()) {
        int v = q.top().s, d = q.top().f;
        q.pop();
        if (dst[v] < d) continue;
        dst[v] = d;
        for (pii &i : gr[v]) {
            int nd = d + i.f;
            if (dst[i.s] > nd && smoke[i.s] > nd) {
                dst[i.s] = nd;
                q.emplace(nd, i.s);
            }
        }
    }
    cout << (dst[f] == INF ? -1 : dst[f]);
}
