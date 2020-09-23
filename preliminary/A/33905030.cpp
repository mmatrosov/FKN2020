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


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 1; i <= 1e6; i++) {
        int x = max(1, i * 4 - 4);
        if (x == n) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";



    return 0;
}