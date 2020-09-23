/*#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")*/
#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>

#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <stdexcept>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define len(s) (int)s.size()
#define endl std::endl<char, std::char_traits<char>>
#define av(x) #x << " = " << x
#define int long long
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;

template<typename first, typename second>
istream &operator>>(istream &in, pair<first, second> &f) {
    return in >> f.first >> f.second;
}

template<typename First, typename Second>
ostream &operator<<(ostream &out, const pair<First, Second> &p) {
    return out << p.first << " " << p.second;
}

template <typename T> istream &operator>>(istream &in, vector<T> &v) {
    for (auto &it : v)
        in >> it;
    return in;
}

template <typename T> ostream &operator<<(ostream &out, vector<T> &v) {
    for (auto &it : v)
        out << it << endl;
    return out;
}

class DBG {
public:
    template <typename T>
    friend DBG operator<<(const DBG &out, T f) {
#ifdef LOCAL
        cerr << f;
#endif
        return out;
    }
};

DBG dbg;



const int maxn = 5e6 + 228;

struct vert {
    int l, r;
    int val;
    vert() {
        l = r = val = -1;
    }
};

vert bor[maxn];
int cnt = 1;

int st[50];

void add(int x, int num) {
    int v = 0;
    for (int i = 32; i >= 0; i--) {
        int y = st[i] & x;
        if (y) {
            if (bor[v].r == -1) {
                bor[v].r = cnt++;
            }
            v = bor[v].r;
        } else {
            if (bor[v].l == -1) {
                bor[v].l = cnt++;
            }
            v = bor[v].l;
        }
    }
    bor[v].val = num;

}

const int maxnn = 2e5 + 228;

vector <pair<int, int> > g[maxnn], xr;

void dfs(int v = 1, int p = -1, int val = 0) {
    //dbg << v << " " << val << endl;
    xr.pb({v, val});
    add(val, v);
    for (auto [a, b] : g[v]) {
        if (a != p) {
            dfs(a, v, val ^ b);
        }
    }

}

pair<int, int> get(int x) {
    int v = 0, sum = 0;
    for (int i = 32; i >= 0; i--) {
        int y = st[i] & x;
        if (y) {
            if (bor[v].l != -1) {
                v = bor[v].l;
                sum += st[i];
            } else {
                v = bor[v].r;
            }
        } else {
            if (bor[v].r != -1) {
                v = bor[v].r;
                sum += st[i];
            } else {
                v = bor[v].l;
            }
        }
    }
    return {bor[v].val, sum};
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    st[0] = 1;
    for (int i = 1; i < 40; i++)
        st[i] = st[i - 1] * 2;
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        g[x].pb({y, z});
        g[y].pb({x, z});
    }
    dfs();
    int ans = -1;
    int z = 0, t = 0;
    for (auto [a, b] : xr) {
        pair<int, int> x = get(b);
        //dbg << x.first << " " << x.second << endl;
        if (x.second > ans) {
            ans = x.second;
            z = a;
            t = x.first;
        }
    }
    cout << z << " " << t;



    return 0;
}