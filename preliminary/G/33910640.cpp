#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <cassert>
#include <random>
#include <cstring>
#include <numeric>

using namespace std;

#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;

#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
#define debug(x) cerr << #x << " = " << (x) << endl
#else
#define debug(x) 0
#endif

template<typename T = int>
T input() {
    T res;
    cin >> res;
    return res;
}

constexpr int N = 1e5 + 47;
vector<pii> g[N];
vector<pii> vals;


void dfs(int v, int p, int cur) {
    vals.emplace_back(cur, v);
    for (pii nx : g[v]) {
        int u = nx.first, w = nx.second;
        if (u == p) {
            continue;
        }
        dfs(u, v, cur ^ w);
    }
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

	int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    dfs(0, 0, 0);
    sort(all(vals));
    // for (int i : vals) {
    //     cerr << i << ' ';
    // }
    // cerr << endl;
    assert(sz(vals) == n);

    int answer = 0;
    pii vers = {0, 0};
    for (int i = 0; i < n; ++i) {
        int l = 0, r = n;
        for (int bit = 32; bit >= 0; --bit) {
            int le = l - 1, ri = r;
            while (ri - le > 1) {
                int mi = (le + ri) / 2;
                if ((vals[mi].first & (1ll << bit)) == 0) {
                    le = mi;
                } else {
                    ri = mi;
                }
            }
            if (l == ri || r == ri) {
                continue;
            }

            if ((vals[i].first & (1ll << bit)) == 0) {
                l = ri;
            } else {
                r = le;
            }
        }
        // if (vals[i].first == 5) {
        //     cerr << vals[l].first << ' ' << vals[l].second << endl;
        // }
        if (answer < (vals[i].first ^ vals[l].first)) {
            answer = (vals[i].first ^ vals[l].first);
            vers = {vals[i].second, vals[l].second};
        }
    }
    // debug(answer);
    cout << vers.first + 1 << ' ' << vers.second + 1 << endl;
}
