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



signed main() {
    accell();
    int n;
    cin >> n;
    if (n == 1) {
        cout << "YES";
        return 0;
    }
    if (n <= 0) {
        cout << "NO" << endl;
        return 0;
    }
    if (n % 4 == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}

