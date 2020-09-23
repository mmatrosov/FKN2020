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


signed main() {
    accell();
    int n, k;
    cin >> n >> k;
    vector<int>a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(rall(a));
    vector<vector<int> >dp(n + 1, vector<int>(k + 1, -1));
    vector<vector<int> >par(n + 1, vector<int>(k + 1, -1));
    dp[0][1] = *a.begin();
    for (int i = 0; i < n; ++i)
        dp[i][0] = 0;
    for (int i = 0; i < n; ++i) {
        dp[i][1] = a[i] * (i + 1);
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= min(i + 1, k); ++j) {
            for (int p = i; p >= j - 1; --p) {
                if (p != 0 && dp[p - 1][j - 1] != -1) {
                    int cur = dp[p - 1][j - 1] + a[i] * (i - p + 1);
                    if (cur > dp[i][j]) dp[i][j] = cur, par[i][j] = p - 1;
                }
            }
        }
    }
    int ans = -1;
    pair<int, int>x = {-1, -1};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= k; ++j) {
            if (dp[i][j] != -1 && dp[i][j] > ans) {
                ans = dp[i][j];
                x = mp(i, j);
            }
        }
    }
    int y = x.first;
    vector<int>b;
    for (int i = x.second; i >= 1; --i) {
        b.push_back(a[y]);
        y = par[y][i];
    }
    while (len(b) < k) b.push_back(len(b) + 1e9);
    sort(all(b));
    for (auto it : b) cout << it << ' ';
    return 0;
}


