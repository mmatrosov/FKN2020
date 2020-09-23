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

//#define int ll
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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

	int n, m;
    cin >> n >> m;

    int le = 0, ri = 10000;
    while (ri - le > 1) {
        int mi = (le + ri) / 2;
        if (mi * (mi + 1) <= 2 * m * n) {
            le = mi;
        } else {
            ri = mi;
        }
    }
    cout << le << endl;

    vector<vector<int>> ans(n + 2, vector<int>(m + 2, 30));
    pii cell = {1, 1};
    auto nx = [&](pii cl) {
        if (cl.first % 2 == 1) {
            if (cl.second == m) {
                return pii{cl.first + 1, cl.second};
            } else {
                return pii{cl.first, cl.second + 1};
            }
        } else {
            if (cl.second == 1) {
                return pii{cl.first + 1, cl.second};
            } else {
                return pii{cl.first, cl.second - 1};
            }
        }
    };
    for (int sn = le; sn > 0; --sn) {
        int s = sn;
        if (sn == le) {
            s += n * m - le * (le + 1) / 2;
        }
        // cerr << (sn == le) << ' ' << sn << ' ' << s << endl;
        vector<char> ban(26);

        pii cur = cell;
        for (int i = 0; i < s; ++i, cur = nx(cur)) {
            ban[ans[cur.first - 1][cur.second]] = true;
            ban[ans[cur.first][cur.second - 1]] = true;
            ban[ans[cur.first][cur.second + 1]] = true;
        }
        int col = 0;
        for (; ban[col]; ++col);

        for (int i = 0; i < s; ++i, cell = nx(cell)) {
            ans[cell.first][cell.second] = col;
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << char('A' + ans[i][j]);
        }
        cout << endl;
    }
}
