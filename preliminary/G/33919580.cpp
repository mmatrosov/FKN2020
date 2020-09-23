#include <iostream>
#include <vector>
#include <set>

#define int long long

using namespace std;

vector<vector<pair<int, int> > > g;
vector<int> x;
vector<bool> used;

void dfs(int v, int r){
    used[v] = 1;
    x[v] = r;
    for (auto i : g[v]){
        if (!used[i.first]){
            dfs(i.first, r ^ i.second);
        }
    }
}

signed main()
{
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    g.resize(n);
    used.resize(n);
    x.resize(n);
    for (int i = 0; i < n - 1; i++){
        int u, v, w;
        cin >> u >>v >> w;
        u--;
        v--;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    dfs(0, 0);
    /*x.resize(n);
    for (int i = 0; i < n; i++){
        cin >> x[i];
    }*/
    int ans1 = 0;
    int ans2 = 0;
    set<int> s;
    for (auto i : x){
        s.insert(i);
    }
    for (int i = 0; i < n; i++){
        int len = 0;
        while ((x[i] >> len) > 0){
            len++;
        }
        int mx = len;
        while (len >= 0){
            int sup = mx - len;
            int look = (((1 << len) - 1) ^ (x[i] >> sup)) << sup;
            if (s.lower_bound(look) != s.end()){
                int now = *s.lower_bound(look);
                if ((now ^ x[i]) > (ans1 ^ ans2)){
                    ans1 = x[i];
                    ans2 = now;
                }
            }
            len--;
        }
    }
    int r1 = 0;
    int r2 = 0;
    for (int i = 0; i < n; i++){
        if (x[i] == ans1){
            r1 = i;
        }
        if (x[i] == ans2){
            r2 = i;
        }
    }
    cout << r1 + 1 << ' ' << r2 + 1 << endl;
    return 0;
}
