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


#include <vector>
#include <cstdio>
#include <algorithm>

static constexpr int MAX = 2000000;

std::vector<int> items;
std::vector<int> sufSum;
int stepsCounter;

void RunKnapsack(int n, int X, int sum, int i) {
    ++stepsCounter;
    if (stepsCounter >= MAX) {
        printf("NO\n");
        exit(0);
    }
    if (sum == X) {
        printf("YES\n");
        exit(0);
    }
    if ((i == n) || (sum > X) || (sum + sufSum[i] < X))
        return;
    RunKnapsack(n, X, sum, i + 1);
    RunKnapsack(n, X, sum + items[i], i + 1);
}

signed main() {
    /*int n, X;
    n = 30;
    X = 1e4 * 12 + 2;
    items.resize(n);
    sufSum.resize(n);
    items[0] = 1e5 + 1;
    for (int i = 1; i < 29; ++i)
        items[i] = 1e5;
    items[29] = 1;
    sort(items.begin(), items.end());
    reverse(items.begin(), items.end());
    for (int i = n - 1; i >= 0; --i) {
        if (i == n - 1)
            sufSum[i] = items[i];
        else
            sufSum[i] = sufSum[i + 1] + items[i];
    }
    RunKnapsack(n, X, 0, 0);
    */
    cout << 30 << ' ' << 120002 << endl;
    cout << 10001 << ' ';
    for (int i = 1; i < 29; ++i) cout << 10000 << ' ';
    cout << 1 << endl;
}


