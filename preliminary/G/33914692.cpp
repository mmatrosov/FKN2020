#include <bits/stdc++.h>
 
#define pii pair<int, int>
#define endl "\n"
#define int long long
#define F first
#define S second
#define B begin
#define E end
#define RB rbegin
#define RE rend
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
 
const int INF = 1e18 + 1;
const double EPS = 1e-10;
const ll P = 1e9 + 7;
const int Q = 47;
 
using namespace std;
 
void hello()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}
 
void show(vector<int>& arr)
{
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
}
void show(vector<vector<int>>& arr)
{
    for (auto i : arr)
        show(i);
    cout << endl;
}

void dfs(int v, int p, int val, vector <vector <pii>>& graph, vector <pii>& seq)
{
    seq[v].F = val;
    seq[v].S = v;
    for (auto to : graph[v])
        if (to.F != p)
            dfs(to.F, v, (val ^ to.S), graph, seq);
}

int last = 0;
const int MAXN = 1e5 * 33 + 5;
const int MAXLOG = 32;
int bor[MAXN][2];
int term[MAXN];
void add(int val, int indx)
{
    int ind = 0;
    for (int i = MAXLOG - 1; i >= 0; --i)
        if ((val & (1 << i)))
        {
            if (bor[ind][1] == -1)
            {
                ++last;
                bor[ind][1] = last;
            }
            ind = bor[ind][1];
        }
        else
        {
            if (bor[ind][0] == -1)
            {
                ++last;
                bor[ind][0] = last;
            }
            ind = bor[ind][0];
        }
    term[ind] = indx;
}


signed main()
{
    hello();
    
    int n;
    cin >> n;
    vector <vector <pii>> graph(n);
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y, len;
        cin >> x >> y >> len;
        graph[x - 1].push_back({y - 1, len});
        graph[y - 1].push_back({x - 1, len});
    }
    vector <pii> seq(n);
    dfs(0, -1, 0, graph, seq);

    sort(seq.B(), seq.E());
    for (int i = 0; i < MAXN; ++i)
        bor[i][0] = bor[i][1] = -1;

    int ares = 0;
    pii res = {1, 1};
    int cnt = -1;
    for (auto val : seq)
    {
        ++cnt;
        add(val.F, cnt);
        int ind = 0;
        // cout << val.F << " " << val.S << " ";
        for (int i = MAXLOG - 1; i >= 0; --i)
        {
            if (val.F & (1 << i))
            {
                if (bor[ind][0] != -1)
                    ind = bor[ind][0];
                else
                    ind = bor[ind][1];
            }
            else
            {
                if (bor[ind][1] != -1)
                    ind = bor[ind][1];
                else
                    ind = bor[ind][0];
            }
        }
        // cout << term[ind] << endl;
        if ((val.F ^ seq[term[ind]].F) > ares)
        {
            ares = (val.F ^ seq[term[ind]].F);
            res = {val.S + 1, seq[term[ind]].S + 1};
            
        }
        // cout << ares << endl;
    }

    cout << res.F << " " << res.S << endl;

}