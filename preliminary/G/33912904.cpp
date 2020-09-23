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
const int inf = 1e9, maxn = 1e5, lg = 32;
struct edge
{
    int u, w;
    edge(int _u = 0, int _w = 0) : u(_u), w(_w) {}
};
void DFS(vector<edge> g[], int v, int p, int dp[], int w)
{
    dp[v] = w;
    for(edge e : g[v]) if(e.u != p) DFS(g, e.u, v, dp, w ^ e.w);
}
struct nd
{
    int g[2] = {-1, -1};
    nd() {f(2) g[i] = -1;}
};
struct BOR
{
    nd bor[maxn * lg + 10];
    int ls = 0;
    BOR()
    {
        bor[ls++] = nd();
    }
    void add(int a)
    {
        int cur = 0;
        for(int b = lg - 1; b >= 0; b--)
        {
            int t = (a >> b) & 1ll;
            if(bor[cur].g[t] == -1)
            {
                bor[cur].g[t] = ls;
                bor[ls] = nd();
                ls++;
            }
            cur = bor[cur].g[t];
        }
    }
    int get(int a)
    {
        int cur = 0, ans = 0;
        for(int b = lg - 1; b >= 0; b--)
        {
            int t = (a >> b) & 1;
            if(bor[cur].g[t ^ 1ll] >= 0)
            {
                ans += (1ll << b);
                cur = bor[cur].g[t ^ 1ll];
            }
            else cur = bor[cur].g[t];
        }
        return ans;
    }
};
main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ic(n)
    vector<edge> g[n];
    f(n - 1)
    {
        ic(v) ic(u) ic(w)
        g[u - 1].eb(v - 1, w);
        g[v - 1].eb(u - 1, w);
    }
    int dp[n];
    DFS(g, 0, -1, dp, 0);
    BOR br = BOR();
    f(n) br.add(dp[i]);
    map<int, int> mp;
    f(n) mp[dp[i]] = i;
    int ans = 0, au = 0, av = 0;
    f(n)
    {
        int cw = br.get(dp[i]);
        if(cw > ans)
        {
            ans = br.get(dp[i]);
            au = i, av = mp[dp[i] ^ cw];
        }
    }
    cout << min(au, av) + 1 << ' ' << max(av, au) + 1;
}
