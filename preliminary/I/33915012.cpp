#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <bitset>
#include <fstream>
#include <unordered_set>
#include <unordered_map>

using namespace std;


#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")


#define int long long
#define eb emplace_back
#define pb push_back
#define ld long double
#define mp make_pair
#define f first
#define s second
#define deb(a) cerr << #a << " = " << a << '\n';
#define fast() { \
    ios_base::sync_with_stdio(0); \
    cin.tie(0); \
    cout << fixed << setprecision(20); \
    cerr << fixed << setprecision(11); \
}



const int INF = 1e18 + 7;
const ld EPS = 1e-7;
const int MAXI = 350;
const int MOD = 1e9 + 7;
const int MOD1 = 998244353;
const int MAXST = 2000000;
const int P = 31;
const int P1 = 37;
const ld PI = 3.14159265358979323;


ostream &operator<<(ostream &stream, const pair <int, int> &p) {
    stream << p.first << ' ' << p.second << ' ';
    return stream;
}


set < pair < int, int > > s, s1;
int d[200000], d1[200000];
vector < vector < pair < int, int > > > v(200000);

signed main(){
    fast();
    srand(time(0));

    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++){
        d[i] = INF;
        d1[i] = INF;
    }
    for (int i = 0; i < k; i++){
        int x;
        cin >> x;
        x--;
        s1.insert({0, x});
        d1[x] = 0;
    }

    for (int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        x--;
        y--;
        v[x].eb(y, w);
        v[y].eb(x, w);
    }
    while (!s1.empty()){
        pair < int, int > x = *s1.begin();
        s1.erase(s1.begin());
        int ver = x.s;
        for (auto i: v[ver]){
            if (d1[ver] + i.s < d1[i.f]){
                s1.erase({d1[i.f], i.f});
                d1[i.f] = d1[ver] + i.s;
                s1.insert({d1[i.f], i.f});
            }
        }
    }
    int f, ss;
    cin >> f >> ss;
    f--;
    ss--;
    d[f] = 0;
    s.insert({d[f], f});
    while (!s.empty()){
        pair < int, int > x = *s.begin();
        s.erase(s.begin());
        int ver = x.s;
        if (d[ver] >= d1[ver])
            continue;
        for (auto i: v[ver]){
            if (d[ver] + i.s < d[i.f] && d[ver] + i.s < d1[i.f]){
                s.erase({d[i.f], i.f});
                d[i.f] = d[ver] + i.s;
                s.insert({d[i.f], i.f});
            }
        }
    }
    if (d[ss] == INF)
        cout << -1;
    else
        cout << d[ss];

    return 0;
}