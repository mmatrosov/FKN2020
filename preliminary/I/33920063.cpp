//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("no-stack-protector")
//#pragma GCC target("popcnt")
//#pragma GCC target("sse4")
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define rng(a) a.begin(),a.end()
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(a) (int)(a.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef long double ld;





#define int long long

const int INF = 1e18;

vector<vector<pair<int,int> > > g;


vector<int> d;
vector<int> dead;


signed main(){
    int n, m, k;
    cin >> n >> m >> k;
    g.resize(n);
    d.resize(n, INF);
    dead.resize(n, INF);
    int a[k];
    for (int i = 0; i < k; i++){
        cin >> a[i];
        a[i]--;
    }
    for (int j = 0; j < m; j++){
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        g[a].pb({b, c});
        g[b].pb({a, c});
    }
    set<pair<int, pair<int,int> > > q;
    for (int i = 0; i < k; i++){
        q.insert({0,{0, a[i]}});
        dead[a[i]] = 0;
    }
    int s, f;
    cin >> s >> f;
    s--, f--;
    d[s] = 0;
    q.insert({0,{1, s}});
    while(q.size()){
        int time = q.begin() -> first;
        int type = q.begin() -> second.first;
        int v = q.begin() -> second.second;
        q.erase(q.begin());
        if (type && dead[v] <= d[v]){
                d[v] = INF;
                continue;
        }
        for (int j = 0; j < g[v].size(); j++){
            int to = g[v][j].fi;
            int cost = g[v][j].se;
            if (type){
                if (d[v] + cost < d[to]){
                    q.erase({d[to],{1, to}});
                    d[to] = d[v] + cost;
                    q.insert({d[to],{1, to}});
                }
            }else{
                if (dead[v] + cost < dead[to]){
                    q.erase({dead[to],{0, to}});
                    dead[to] = dead[v] + cost;
                    q.insert({dead[to],{0, to}});
                }
            }
        }
    }
    if (d[f] == INF) cout << -1;
    else cout << d[f];

}
