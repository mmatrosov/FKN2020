#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

const long long inf = 1'000'000'000'000'000'000;
vector<vector<pair<int, int> > > g;

void print(set<pair<long long, int> > q){
    for(auto it = q.begin(); it!=q.end(); it++)
        cout << (it->first) << ':' << (it->second) << ' ';
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    g.resize(n);
    vector<int> a(k);
    for(int i = 0; i<k; i++){
        cin >> a[i];
        a[i]--;
    }
    for(int i = 0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    int s, f;
    cin >> s >> f;
    s--;
    f--;
    vector<long long> d(n, inf), d1(n, inf);
    set<pair<long long, int> > q;
    for(int i = 0; i<n; i++)
        q.insert({inf, i});
    q.erase(q.find({inf, s}));
    q.insert({0, s});
    d[s] = 0;
    while(!q.empty()){
        int v = (q.begin()->second);
        q.erase(q.begin());
        for(int i = 0; i<g[v].size(); i++){
            int to = g[v][i].first, len = g[v][i].second;
            if(d[to]>d[v]+len){
                //cout << d[to] << ':' << to << endl;
                //print(q);
                q.erase(q.find({d[to], to}));
                d[to] = d[v]+len;
                q.insert({d[to], to});
            }
        }
    }
    if(d[f]==inf){
        cout << -1;
        return 0;
    }
    for(int i = 0; i<n; i++)
        q.insert({inf, i});
    for(int i = 0; i<k; i++){
        q.erase(q.find({inf, a[i]}));
        d1[a[i]] = 0;
        q.insert({0, a[i]});
    }
    while(!q.empty()){
        int v = (q.begin()->second);
        q.erase(q.begin());
        for(int i = 0; i<g[v].size(); i++){
            int to = g[v][i].first, len = g[v][i].second;
            if(d1[to]>d1[v]+len){
                q.erase(q.find({d1[to], to}));
                d1[to] = d1[v]+len;
                q.insert({d1[to], to});
            }
        }
    }
    if(d1[f]<=d[f])
        cout << -1;
    else
        cout << d[f];

    return 0;
}
