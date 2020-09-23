#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define double long double
#define F first
#define S second
#define forn(i,n) for(int32_t i=0;i<(n);++i)

using namespace std;
using namespace __gnu_pbds;
const int N = 2e5+5;
const int INF = 1e18+7;
const int MOD = 1e9+7;
const double EPS = 1e-8;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> SET;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
uniform_real_distribution<> rnd01(0,1);

int n,m,k,s,f;
vector<pair<int,int>> g[N];
int lol[N];
vector<int> fires;
int ans[N];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    cin>>n>>m>>k;
    forn(i,k){
        int x; cin>>x; x--;
        fires.push_back(x);
    }
    forn(i,m){
        int a,b,w; cin>>a>>b>>w; a--, b--;
        g[a].push_back({b,w});
        g[b].push_back({a,w});
    }
    cin>>s>>f; s--, f--;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    for(int i=0;i<N;i++) lol[i]=INF;
    for(int x : fires){
        q.push({0,x});
        lol[x]=0;
    }
    while (!q.empty()) {
        pair<int, int> c = q.top();
        q.pop();

        int dst = c.first, v = c.second;

        if (lol[v] < dst) {
            continue;
        }

        for (pair<int, int> e: g[v]) {
            int u = e.first, len_vu = e.second;

            int n_dst = dst + len_vu;
            if (n_dst < lol[u]) {
                lol[u] = n_dst;
                q.push({n_dst, u});
            }
        }
    }
    //for(int i=0;i<n;i++) cout<<lol[i]<<" ";

    for (int i = 0; i < n; i++) {
        ans[i] = INF;
    }

    ans[s] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> qq;

    qq.push({0, s});

    while (!qq.empty()) {
        pair<int, int> c = qq.top();
        qq.pop();

        int dst = c.first, v = c.second;

        if (ans[v] < dst) {
            continue;
        }

        for (pair<int, int> e: g[v]) {
            int u = e.first, len_vu = e.second;

            int n_dst = dst + len_vu;
            if (n_dst < ans[u] && n_dst<lol[u]) {
                ans[u] = n_dst;
                qq.push({n_dst, u});
            }
        }
    }
    cout<<(ans[f]==INF?-1:ans[f])<<endl;
}
