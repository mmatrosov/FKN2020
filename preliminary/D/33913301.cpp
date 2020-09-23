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

ld r(ld x1, ld y1, ld x2, ld y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

ld crs(ld x1, ld y1, ld x2, ld y2) {
    return x1 * y2 - x2 * y1;
}

ld dot(ld x1, ld y1, ld x2, ld y2) {
    return x1 * x2 + y1 * y2;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

	ld xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;

    ld r1 = r(xa, ya, 0, 0), r2 = r(xb, yb, 0, 0);
    // cerr <<  xa << ' ' << ya << endl;
    debug(crs(xa, ya, xb, yb));
    debug(dot(xa, ya, xb, yb));
    cout << fixed << setprecision(9) << min(r1 + r2, abs(r1 - r2) + min(r1, r2) * abs(atan2(crs(xa, ya, xb, yb), dot(xa, ya, xb, yb)))) << endl;
}
