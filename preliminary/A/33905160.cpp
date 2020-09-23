#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <bitset>
#include <fstream>
#include <unordered_set>
#include <unordered_map>


using namespace std;


#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")

#define int long long
#define eb emplace_back
#define pb push_back
#define ld long double
#define f first
#define s second
#define deb(a) cerr << #a << " = " << a << '\n';
#define fast() { \
    ios_base::sync_with_stdio(0); \
    cin.tie(0); \
    cout << fixed << setprecision(20); \
    cerr << fixed << setprecision(11); \
}



const int INF = 1e9 + 7;
const ld EPS = 1e-10;
const int MAXI = 20000;
const int MOD = 998244353;
const int MAXST = 2000000;
const int P = 62;
const ld PI = 3.14159265358979323;

ostream &operator<<(ostream &stream, const pair <int, int> &p) {
    stream << p.first << ' ' << p.second << ' ';
    return stream;
}



signed main() {
    /* freopen("cipher.in", "r", stdin);
     freopen("cipher.out", "w", stdout);*/
    fast();

    int k;
    cin >> k;
    if ((k + 4) % 4 == 0 || k == 1)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}