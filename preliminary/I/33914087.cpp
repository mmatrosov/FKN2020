#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())
#define ld long double

const int maxn = 2e5 + 9;
vector<pii> g[maxn];
int t[maxn];
int n, m, k;
int inf = 1e18;
int d[maxn];

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        t[i] = inf;
    priority_queue<pii> q;
    for (int i = 0; i < k; i++)
    {
        int a;
        cin >> a;
        a--;
        t[a] = 0;
        q.emplace(0, a);
    }
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        g[a].pb(b, c);
        g[b].pb(a, c);
    }
    while (!q.empty())
    {
        int v = q.top().ss;
        int cur = -q.top().ff;
        q.pop();
        if (cur != t[v])
            continue;
        for (pii to : g[v])
        {
            if (t[v] + to.ss < t[to.ff])
            {
                t[to.ff] = t[v] + to.ss;
                q.emplace(-t[to.ff], to.ff);
            }
        }
    }
    int s, f;
    cin >> s >> f;
    s--, f--;
    if (!t[s])
    {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < n; i++)
        d[i] = inf;
    d[s] = 0;
    q.emplace(0, s);
    while (!q.empty())
    {
        int v = q.top().ss;
        int cur = -q.top().ff;
        q.pop();
        if (cur != d[v])
            continue;
        for (pii to : g[v])
        {
            if (d[v] + to.ss < d[to.ff] && d[v] + to.ss < t[to.ff])
            {
                d[to.ff] = d[v] + to.ss;
                q.emplace(-d[to.ff], to.ff);
            }
        }
    }
    if (d[f] >= inf)
        cout << -1;
    else
        cout << d[f];
}
