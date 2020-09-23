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

int n;
vector<pair<int,int>> g[N];

int sz=0;

struct edge
{
    int c[2];
    int what = -1;
};

const int NN = 1e7+5;
edge t[NN];

void init()
{
    memset(t[0].c,-1,sizeof t[0].c);
    sz=1;
}

void updateP(int r, int vert)
{
    int v=0;
    for(int i=31;i>=0;i--){
        int x=((r>>i)&1);
        if(t[v].c[x]==-1){
            memset(t[sz].c,-1,sizeof t[sz].c);
            t[v].c[x]=sz++;
        }
        v=t[v].c[x];
    }
    t[v].what=vert;
}

pair<int,int> get(int r)
{
    int v=0;
    int result=0;
    for(int i=31;i>=0;i--){
        int x=((r>>i)&1);
        if(t[v].c[(x==1?0:1)]!=-1){
            result+=(1LL<<i);
            v=t[v].c[(x==1?0:1)];
        }else if(t[v].c[(x==1?1:0)]!=-1){
            v=t[v].c[(x==1?1:0)];
        }else break;
    }
    return {result,t[v].what};
}

int ans = -INF;
pair<int,int> tans = {0,0};

void dfs(int v, int xr=0, int p=-1)
{
    if(p!=-1){
        pair<int,int> mx = get(xr);
        if(mx.F>ans){
            ans=mx.F;
            tans = {v,mx.S};
        }
    }
    updateP(xr, v);
    for(auto u : g[v]){
        if(u.F!=p) dfs(u.F,xr^u.S,v);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    cin>>n;
    init();
    forn(i,n-1){
        int a,b,w; cin>>a>>b>>w; a--, b--;
        g[a].push_back({b,w});
        g[b].push_back({a,w});
    }
    dfs(0);
    cout<<tans.F+1<<" "<<tans.S+1<<endl;
    //cout<<ans<<endl;
}
