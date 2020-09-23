#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <set>
#include <cmath>
#include <vector>
#include <bitset>
#include <iomanip>


using namespace std;

typedef long long ll;
typedef long double ld;

const ld INF = 1e16;

int main() {
    int n, s, k, f, w, m, x, y;
    cin >> n >> m >> k;
    vector<vector<pair<ll, ll>>> g(n);
    vector<int> bonf(k);
    for (int i = 0; i < k; i++) {
        cin >> x;
        bonf[i] = x - 1;
    }
    vector<ll> dist1(n, INF);
    vector<ll> dist2(n, INF);
    for (int i = 0; i < m; i++){
        cin >> x >> y >> w;
        g[x - 1].push_back({y - 1, w});
        g[y - 1].push_back({x - 1, w});
    }
    cin >> s >> f;
    s--;
    f--;
    dist1[s] = 0;
    set<pair<ll, int>> oc;
    oc.insert({0, s});
    while(!oc.empty()) {
        int curr = oc.begin()->second;
        oc.erase(oc.begin());
        for (auto v : g[curr]){
            if (dist1[curr] + v.second < dist1[v.first]){
                oc.erase({dist1[v.first], v.first});
                dist1[v.first] = dist1[curr] + v.second;
                oc.insert({dist1[v.first], v.first});
            }
        }
    }
    for (int i = 0; i < k; i++) {
        dist2[bonf[i]] = 0;
        oc.insert({0, bonf[i]});
    }
    dist1[s] = 0;
    oc.insert({0, s});
    while(!oc.empty()) {
        int curr = oc.begin()->second;
        oc.erase(oc.begin());
        for (auto v : g[curr]){
            if (dist2[curr] + v.second < dist2[v.first]){
                oc.erase({dist2[v.first], v.first});
                dist2[v.first] = dist2[curr] + v.second;
                oc.insert({dist2[v.first], v.first});
            }
        }
    }
    if (dist2[f] > dist1[f]) cout << dist1[f];
    else cout << -1;
}
