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
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
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

#define int long long

const int maxn = 2e5 + 228, inf = 2e18;

vector <int> dp1(maxn, inf), dp2(maxn, inf);
vector <pair<int, int> > g[maxn];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m, k;
    cin >> n >> m >> k;
    set <pair<int, int>> st;
    while (k--) {
        int x;
        cin >> x;
        dp1[x] = 0;
        st.insert({0, x});
    }
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        g[x].pb({y, z});
        g[y].pb({x, z});
    }
    while (len(st)) {
        pair<int, int> t = *st.begin();
        int x = t.first, y = t.second;
        st.erase(t);
        if (x > dp1[y]) {
            continue;
        }
        for (auto to : g[y]) {
            if (dp1[to.first] > to.second + dp1[y]) {
                dp1[to.first] = to.second + dp1[y];
                st.insert({dp1[to.first], to.first});
            }
        }
    }
    int s, f;
    cin >> s >> f;
    dp2[s] = 0;
    st.insert({0, s});
    while (len(st)) {
        pair<int, int> t = *st.begin();
        int x = t.first, y = t.second;
        st.erase(t);
        if (x > dp2[y]) {
            continue;
        }
        for (auto to : g[y]) {
            if (dp2[to.first] > to.second + dp2[y]
            && dp1[to.first] > dp2[y] + to.second) {
                dp2[to.first] = to.second + dp2[y];
                st.insert({dp2[to.first], to.first});
            }
        }
    }
    if (dp2[f] == inf) {
        cout << -1;
    } else {
        cout << dp2[f];
    }



    return 0;
}