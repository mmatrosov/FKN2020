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
#define mp make_pair
#define f first
#define s second
#define deb(a) cerr << #a << " = " << a << '\n';
#define fast() { \
    ios_base::sync_with_stdio(0); \
    cin.tie(0); \
    cout << fixed << setprecision(20); \
    cerr << fixed << setprecision(11); \
}



const int INF = 1e18 + 7;
const ld EPS = 1e-7;
const int MAXI = 350;
const int MOD = 1e9 + 7;
const int MOD1 = 998244353;
const int MAXST = 2000000;
const int P = 31;
const int P1 = 37;
const ld PI = 3.14159265358979323;


ostream &operator<<(ostream &stream, const pair <int, int> &p) {
    stream << p.first << ' ' << p.second << ' ';
    return stream;
}

ld len (ld x, ld y){
    return sqrt(x * x + y * y);
}

ld f (ld r, ld x, ld y, ld x1, ld y1, ld cor){
    return abs(len(x, y) - r) + abs(len(x1, y1) - r) + PI * r * cor / 180;
}

signed main(){
    fast();
    ld x, y, x1, y1;
    cin >> x >> y >> x1 >> y1;
    if (x == x1 && y == y1)
        return cout << 0, 0;
    ld ans = len(x, y) + len(x1, y1);
    ld c = (ld)(x1 * x + y1 * y) / (len(x, y) * len(x1, y1));
    if (c > 1)
        c = 1;
    else if (c < -1)
        c = -1;
    c = acos(c) * 180 / PI;
    ans = min({ans, f(len(x, y), x, y, x1, y1, c), f(len(x1, y1), x, y, x1, y1, c)});
    ld l = 0, r = 1e9;
    for (int i = 0; i < 300; i++){
        ld m1 = (r - l) / 3 + l;
        ld m2 = r - (r - l) / 3;
        if (f(m1, x, y, x1, y1, c) < f(m2, x, y, x1, y1, c))
            r = m2;
        else
            l = m1;
    }
    ans = min({ans, f(l, x, y, x1, y1, c), f(r, x, y, x1, y1, c)});
    cout << ans;
    return 0;
}