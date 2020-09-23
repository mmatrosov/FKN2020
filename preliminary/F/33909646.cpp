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

template<typename T>
istream &operator>>(istream &in, vector<T> &v) {
    for (auto &it : v)
        in >> it;
    return in;
}

template<typename T>
ostream &operator<<(ostream &out, vector<T> &v) {
    for (auto &it : v)
        out << it << endl;
    return out;
}

class DBG {
public:
    template<typename T>
    friend DBG operator<<(const DBG &out, T f) {
#ifdef LOCAL
        cerr << f;
#endif
        return out;
    }
};

DBG dbg;

const int maxn = 120;

int dp[maxn][maxn];
int last[maxn][maxn];

int mx = 1e7 + 228;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    cin >> v;
    sort(rall(v));
    for (int i = 0; i < n; i++)
        dbg << v[i] << " ";
    for (int i = 0; i < maxn; i++) {
        for (int j = 1; j < maxn; j++) {
            dp[i][j] = -1;
        }
    }
    dp[0][1] = v[0];
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= i + 1; j++) {
            for (int g = i; g >= j - 1; g--) {
                if (dp[g - 1][j - 1] != -1) {
                    int x = dp[g - 1][j - 1] + (i - g + 1) * v[i];
                    if (x > dp[i][j]) {
                        last[i][j] = g - 1;
                        dp[i][j] = x;
                    }
                }
            }
        }
    }
    int q = -1;
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {

        for (int j = 0; j <= k; j++) {
            dbg << dp[i][j] << " ";
            if (dp[i][j] > q) {
                x = i;
                q = dp[i][j];
                y = j;
            }
        }
        dbg << endl;
    }
    vector <int> ans;
    while (y) {
        ans.pb(v[x]);
        x = last[x][y];
        y--;
    }
    sort(all(ans));
    while (len(ans) < k) {
        ans.pb(mx++);
    }
    for (int i = 0; i < k; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}