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
const int maxn = 2e6;
vector<vector<pair<int,int> > > g;
vector<int> ans;
struct node{
    int next[2];
    vector<int> ww;
};
node t[maxn + 1];
int sz = 1;
void dfs(int v, int y, int p){
    ans[v] = y;
    for (auto x : g[v]){
        if (x.fi == p) continue;
        dfs(x.fi, y^x.se, v);
    }
}
void add(int x,int id){
   // cout << x << endl;
    int v = 0;
    for (int j = 31; j >= 0; j--){
    //        cout << j << endl;
        int f = ((x >> j) & 1);

        if (t[v].next[f] == -1){
      //          cout << "*";
            t[sz].next[0] = t[sz].next[1] = -1;
            t[v].next[f] = sz;
            sz++;
        }
    //    cout << "&";
        v = t[v].next[f];
    }
   // cout << "________________" << endl;
  //  cout << v << endl;
    t[v].ww.pb(id);
}
int go_into(int v1, int v2, int id){
    if (id == -1) return 0;
    int ans = 0;
    bool fl = 0;
 //   cout << v1 << ' ' << v2 << ' ' << id << endl;
    if (t[v1].next[0] != -1 && t[v2].next[1] != -1){
            fl = 1;
        ans = max(ans, ((1ll << id) ^ go_into(t[v1].next[0], t[v2].next[1], id - 1)));
    }
    if (t[v1].next[1] != -1 && t[v2].next[0] != -1){
            fl = 1;
        ans = max(ans, ((1ll << id) ^ go_into(t[v1].next[1], t[v2].next[0], id - 1)));
    }
    if (!fl && t[v1].next[1] != -1 && t[v2].next[1] != -1){
        ans = max(ans,  go_into(t[v1].next[1], t[v2].next[1], id - 1));
    }
    if (!fl && t[v1].next[0] != -1 && t[v2].next[0] != -1){
        ans = max(ans, go_into(t[v1].next[0], t[v2].next[0], id - 1));
    }
    return ans;
}
int ANS;
int ansek1, ansek2;
void go(int v1, int v2, int id, int nowans){
    if (id == -1){
            if (nowans == ANS){
                ansek1 = t[v1].ww.back();
                ansek2 = t[v2].ww.back();
            }
            return ;
    }
    int ans = 0;
    bool fl = 0;
    if (t[v1].next[0] != -1 && t[v2].next[1] != -1){
            fl = 1;
        go(t[v1].next[0], t[v2].next[1], id - 1, nowans ^ (1ll << id));
    }
    if (t[v1].next[1] != -1 && t[v2].next[0] != -1){
            fl = 1;
        go(t[v1].next[1], t[v2].next[0], id - 1, nowans ^ (1ll << id));
    }
    if (!fl && t[v1].next[1] != -1 && t[v2].next[1] != -1){
        go(t[v1].next[1], t[v2].next[1], id - 1, nowans);
    }
    if (!fl && t[v1].next[0] != -1 && t[v2].next[0] != -1){
        go(t[v1].next[0], t[v2].next[0], id - 1, nowans);
    }
}
signed main(){
    t[0].next[0] = t[0].next[1] = -1;
    int n;
    cin >> n;
    g.resize(n);
    ans.resize(n);
    for (int i = 0; i < n - 1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        g[a].pb({b, c});
        g[b].pb({a, c});
    }
    dfs(0, 0, -1);
    for (int j = 0; j < n; j++){
        add(ans[j], j);
    }
    int v1 = 0, v2 = 0;
    ANS =  go_into(v1, v2, 31);
    go(v1, v2, 31, 0);
    cout << ansek1 + 1 << ' ' << ansek2 + 1;
}
