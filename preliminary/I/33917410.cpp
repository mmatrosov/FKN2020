#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<map>
#include<set>
#include<random>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<deque>
#include<bitset>
#include<cstdio>
#include<cassert>
#include<sstream>
#include<set>

#define int long long int

using namespace std;

int n, m, k;
vector<vector<pair<int, int>>> g;
vector<int> a;
vector<int> minD;

void getD(){
    set<pair<int, int>> se;
    minD.resize(n, 1e15);
    for(int i = 0; i < k; i++){
        minD[a[i]] = 0;
        se.insert({0, a[i]});
    }
    while(!se.empty()){
        int v = se.begin()->second; se.erase(se.begin());
        for(auto t : g[v]){
            int to = t.first, w = t.second;
            if(minD[to] > minD[v] + w){
                se.erase({minD[to], to});
                minD[to] = minD[v] + w;
                se.insert({minD[to], to});
            }
        }
    }
}

signed main(){
    cin >> n >> m >> k;
    a.resize(k);
    g.resize(n);
    for(int i = 0; i < k; i++){
        cin >> a[i];
        a[i]--;
    }
    for(int i = 0; i < m; i++){
        int a, b, w; cin >> a >> b >> w; a--; b--;
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }
    int s, f; cin >> s >> f; s--; f--;
    getD();
    vector<int> dist(n, 1e15); dist[s] = 0;
    set<pair<int, int>> se; se.insert({0, s});
    while(!se.empty()){
        int v = se.begin()->second; se.erase(se.begin());
        for(auto t : g[v]){
            int to = t.first, w = t.second;
            if(dist[to] > dist[v] + w && dist[v] + w < minD[to]){
                se.erase({dist[to], to});
                dist[to] = dist[v] + w;
                se.insert({dist[to], to});
            }
        }
    }
    if(dist[f] > 1e13)cout << -1 << "\n";
    else cout << dist[f] << "\n";
    return 0;
}

