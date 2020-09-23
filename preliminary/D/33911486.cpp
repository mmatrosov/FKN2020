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
#define double long double


signed main() {
    accell();
    int xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;
    double r = sqrt(xb * xb * 1.0 + yb * yb * 1.0);
    double r1 = sqrt(xa * xa * 1.0 + ya * ya * 1.0);
    double ans = r + r1;
    if (r1 > r) {
        swap(r, r1);
        swap(xa, xb);
        swap(ya, yb);
    }
    
    double cur = abs(atan2(xa * yb - xb * ya, xa * xb + ya * yb)) * r1 + fabs(r - r1);
    ans = min(ans, cur);
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}

