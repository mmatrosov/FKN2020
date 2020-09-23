/*
 #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma warning(disable : 4996)
*/

#include <iostream>
#include <iomanip>
#include <random>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <sstream>
#include <bitset>
#include <cassert>
#include <fstream>
#include <queue>
#include <functional>
#include <chrono>
#include <tuple>
#include <unordered_map>
#include <immintrin.h>
#include <iterator>
#include <stdlib.h>



using ll = long long;
using ld = long double;
using ull = unsigned long long;

#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define len(v) (int)(v.size())
#define F first
#define S second
#define mp make_pair

using namespace std;

inline void accell() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout.tie(0);
}

inline void say(const string s) {
    cout << s << endl;
}
template<class T> ostream& operator<< (ostream& out, const pair<T, T>&X) {
    out << "{ " << X.F << ", " << X.S << " }";
    return out;
}

template<class T> ostream& operator<< (ostream& out, const vector<T>&X) {
    cout << "[ ";
    for (const auto& it : X) {
        out << it << ", ";
    }
    out << "]" << endl;
    return out;
}
template<class T> ostream& operator<< (ostream& out, const set<T>&X) {
    cout << "[ ";
    for (const auto& it : X) {
        out << it << ", ";
    }
    out << "]" << endl;
    return out;
}
/*
string a, b;


map<string, int>key;

map<string, pair<int, int> >mp;

bool is_digit(char x) {
    return (x >= '0' && x <= '9');
}

void go(string &x) {
    if (a == "no") {
        for (int i = 0; i < len(x); ++i) {
            if (x[i] >= 'A' && x[i] <= 'Z') {
                x[i] = x[i] - 'A' + 'a';
            }
        }
    }
}


bool check(string x) {
    if (len(x) == 0) return false;
    if (b == "no" && is_digit(x[0])) return false;
    bool ok = false;
    for (int i = 0; i < len(x); ++i) {
        if (!is_digit(x[i]))
            ok = true;
    }
    if (!ok) return false;
    if (!key.count(x)) {
        return true;
    }
    return false;
}
*/
const int N = 2e5 + 5;

vector<pair<int, int> > g[N];

signed main() {
    accell();
    int n, m, k;
    cin >> n >> m >> k;
    set<pair<int, int> > st;
    vector<int>d(n, 1e18);
    for (int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        --x;
        d[x] = 0;
        st.insert(mp(0, x));
    }
    for (int i = 0; i < m; ++i) {
        int v, u, w;
        cin >> v >> u >> w;
        --v;
        --u;
        g[v].push_back(mp(u, w));
        g[u].push_back(mp(v, w));
    }
    while (!st.empty()) {
        int ds, v;
        tie(ds, v) = *st.begin();
        st.erase(st.begin());
        if (ds > d[v])
            continue;
        for (auto &to : g[v]) {
            if (d[to.F] > d[v] + to.S) {
                d[to.F] = d[v] + to.S;
                st.insert(mp(d[to.F], to.F));
            }
        }
    }
    vector<int>d2(n, 1e18);
    int s, f;
    cin >> s >> f;
    --s; --f;
    d2[s] = 0;
    st.insert({0, s});
    while (!st.empty()) {
        int ds, v;
        tie(ds, v) = *st.begin();
        st.erase(st.begin());
        if (ds > d2[v]) continue;
        for (auto &to : g[v]) {
            if (d2[to.F] > d2[v] + to.S && d2[v] + to.S < d[to.F]) {
                d2[to.F] = d2[v] + to.S;
                st.insert(mp(d2[to.F], to.F));
            }
        }
    }
    if (d2[f] == 1e18) {
        cout << -1 << endl;
    } else {
        cout << d2[f] << endl;
    }
    return 0;
}

