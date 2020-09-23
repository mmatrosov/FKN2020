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

signed main()
{
    hello();
    
    int n, m, k;
    cin >> n >> m >> k;
    vector <vector <pii>> graph(n);
    vector <int> tmp(k);
    for (int i = 0; i < k; ++i)
        cin >> tmp[i];
    for (int i = 0; i < m; ++i)
    {
        int x, y, len;
        cin >> x >> y >> len;
        graph[x - 1].push_back({y - 1, len});
        graph[y - 1].push_back({x - 1, len});
    }

    vector <int> times(n, INF);
    set <pii> mres;
    for (int i = 0; i < k; ++i)
    {
        int x = tmp[i] - 1;
        times[x] = 0;
        mres.insert({0, x});
    }

    while (mres.size())
    {
        int ind = mres.B()->S;
        mres.erase(mres.B());
        // cout << ind << endl;
        for (auto to : graph[ind])
        {
            if (times[to.F] > times[ind] + to.S)
            {
                mres.erase({times[to.F], to.F});
                times[to.F] = times[ind] + to.S;
                mres.insert({times[to.F], to.F});
            }
        }
    }

    int s, f;
    cin >> s >> f;
    --s; --f;
    vector <int> dist(n, INF);
    dist[s] = 0;
    mres.insert({0, s});
    if (times[s] == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    while (mres.size())
    {
        int ind = mres.B()->S;
        mres.erase(mres.B());
        for (auto to : graph[ind])
            if (dist[to.F] > dist[ind] + to.S && dist[ind] + to.S < times[to.F])
            {
                mres.erase({dist[to.F], to.F});
                dist[to.F] = dist[ind] + to.S;
                mres.insert({dist[to.F], to.F});
            }
    }

    if (dist[f] == INF)
        cout << -1 << endl;
    else
        cout << dist[f] << endl;
}