#include<bits/stdc++.h>

using namespace std;

using ll = long long int;
using vi = vector<int>;
#define f(n) for(int i = 0; i < n; i++)
#define fj(n) for(int j = 0; j < n; j++)
#define fk(n) for(int k = 0; k < n; k++)
#define ci(n) cin >> n;
#define ic(n) int n; cin >> n;
#define lc(n) int n; cin >> n;
#define all(a) a.begin(), a.end()
#define pri(a, n) for(int i = 0; i < n; i++) cout << a[i] << " "; cout << "\n";
#define scn(a, n) int a[n] = {0}; for(int i = 0; i < n; i++) cin >> a[i];
#define scl(a, n) ll a[n] = {0}; for(int i = 0; i < n; i++) cin >> a[i];
#define pb push_back
#define eb emplace_back
#define pii pair<int, int>
#define sc second
#define ft first
#define int long long
const int inf = 1e18, maxn = 1e5, lg = 32;
struct edge
{
    int u, w;
    edge(int _u = 0, int _w = 0) : u(_u), w(_w) {}
};
struct vrt
{
    int v, d;
    vrt(int _v = 0, int _d = 0) : v(_v), d(_d) {}
};
bool operator < (vrt a, vrt b)
{
    return a.d != b.d ? a.d > b.d : a.v > b.v;
}

void dijkstra(vector<edge> g[], vector<int> s, int n, int d[])
{
    priority_queue<vrt> q;
    int used[n] = {0};
    for(int i = 0; i < n; i++) d[i] = inf;
    for(int i : s) d[i] = 0;
    for(int i = 0; i < n; i++) q.emplace(i, d[i]);
    while(q.size())
    {
        vrt v = q.top();
        q.pop();
        if(used[v.v]) continue;
        used[v.v] = 1;
        for(edge e : g[v.v])
        {
            if(v.d + e.w < d[e.u])
            {
                d[e.u] = v.d + e.w;
                q.emplace(e.u, d[e.u]);
            }
        }
    }
}

void adijkstra(vector<edge> g[], int s, int n, int d[], int dk[])
{
    priority_queue<vrt> q;
    int used[n] = {0};
    for(int i = 0; i < n; i++) d[i] = inf;
    d[s] = 0;
    for(int i = 0; i < n; i++) q.emplace(i, d[i]);
    while(q.size())
    {
        vrt v = q.top();
        q.pop();
        if(used[v.v]) continue;
        used[v.v] = 1;
        for(edge e : g[v.v])
        {
            if(v.d + e.w < d[e.u] && v.d + e.w < dk[e.u])
            {
                d[e.u] = v.d + e.w;
                q.emplace(e.u, d[e.u]);
            }
        }
    }
}
main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> ks(k);
    f(k) cin >> ks[i], ks[i]--;
    vector<edge> g[n];
    f(m)
    {
        ic(v) ic(u) ic(w)
        g[v - 1].eb(u - 1, w);
        g[u - 1].eb(v - 1, w);
    }
    int dk[n], d[n];
    dijkstra(g, ks, n, dk);
    int s, f;
    cin >> s >> f;
    s--, f--;
    adijkstra(g, s, n, d, dk);
    cout << (d[f] < inf ? d[f] : -1);
}
