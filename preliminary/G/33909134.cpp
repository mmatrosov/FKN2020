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
const int N = 5e6;

vector<pair<int, int> >a;

struct bor {
    int l, r;
    int num = -1;
    bor() {
        l = r = -1;
    }
};
bor t[N];
int f = 1;

void add(int x, int id) {
    int v = 0;
    for (int i = 32; i >= 0; --i) {
        if (1LL << i & x) {
            if (t[v].r == -1) {
                t[v].r = f++;
            }
            v = t[v].r;
        } else {
            if (t[v].l == -1) {
                t[v].l = f++;
            }
            v = t[v].l;
        }
    }
    t[v].num = id;
}
pair<int, int> get_max(int x) {
    int ans = 0;
    int v = 0;
    for (int i = 32; i >= 0; --i) {
        if (1LL << i & x) {
            if (t[v].l != -1) {
                v = t[v].l;
                ans += (1LL << i);
            } else {
                v = t[v].r;
            }
        } else {
            if (t[v].r != -1) {
                v = t[v].r;
                ans += (1LL << i);
            } else {
                v = t[v].l;
            }
        }
    }
    return mp(ans, t[v].num);
}

vector<pair<int, int> > g[200002];

void dfs(int v, int p, int cur) {
    add(cur, v);
    a.push_back(mp(v, cur));
    for (auto to : g[v]) {
        if (to.F != p) {
            dfs(to.F, v, cur ^ to.S);
        }
    }
}



signed main() {
    accell();
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int v, u, w;
        cin >> v >> u >> w;
        --v;
        --u;
        g[v].push_back(mp(u, w));
        g[u].push_back(mp(v, w));
    }
    dfs(0, -1, 0);
    int ans1 = -1;
    int ans2 = -1;
    int mx = -1;
    for (int i = 0; i < len(a); ++i) {
        auto p = get_max(a[i].S);
        if (p.F > mx) {
            mx = p.F;
            ans1 = p.S;
            ans2 = a[i].F;
        }
    }
    cout << ans1 + 1 << ' ' << ans2 + 1 << endl;
    return 0;
}

