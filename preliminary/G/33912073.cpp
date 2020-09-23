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

const int maxn = 1e5 + 9;
vector<pii> g[maxn];
int br[35 * maxn][2];
vector<int> num[35 * maxn];
int pt = 1;
int n;
int w[maxn];

void dfs(int v, int pr, int x)
{
    w[v] = x;
    int u = 0;
    for (int lg = 31; lg >= 0; lg--)
    {
        bool t = (x & (1 << lg));
        if (br[u][t] == -1)
        {
            br[u][t] = pt;
            br[pt][0] = -1;
            br[pt][1] = -1;
            pt++;
        }
        u = br[u][t];
    }
    num[u].pb(v);
    for (pii to : g[v])
    {
        if (to.ff != pr)
            dfs(to.ff, v, x ^ to.ss);
    }
}

pii find_ans(int v1, int v2, int h)
{
    if (h < 0)
    {
        return mp(num[v1][0], num[v2][0]);
    }
    if ((br[v1][0] != -1 && br[v2][1] != -1) || (br[v1][1] != -1 && br[v2][0] != -1))
    {
        pii cur(-1, -1);
        if (br[v1][0] != -1 && br[v2][1] != -1)
        {
            cur = find_ans(br[v1][0], br[v2][1], h - 1);
        }
        if (br[v1][1] != -1 && br[v2][0] != -1)
        {
            pii cur1 = find_ans(br[v1][1], br[v2][0], h - 1);
            if (cur.ff == -1 || (w[cur1.ff] ^ w[cur1.ss]) > (w[cur.ff] ^ w[cur.ss]))
                cur = cur1;
        }
        return cur;
    }
    pii cur(-1, -1);
    if (br[v1][0] != -1 && br[v2][0] != -1)
    {
        cur = find_ans(br[v1][0], br[v2][0], h - 1);
    }
    if (br[v1][1] != -1 && br[v2][1] != -1)
    {
        pii cur1 = find_ans(br[v1][1], br[v2][1], h - 1);
        if (cur.ff == -1 || (w[cur1.ff] ^ w[cur1.ss]) > (w[cur.ff] ^ w[cur.ss]))
            cur = cur1;
    }
    return cur;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        g[a].pb(b, c);
        g[b].pb(a, c);
    }
    br[0][0] = -1;
    br[0][1] = -1;
    dfs(0, -1, 0);
    pii cur = find_ans(0, 0, 31);
    cout << cur.ff + 1 << " " << cur.ss + 1;
}
