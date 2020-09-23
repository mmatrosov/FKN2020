#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <deque>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <ctime>
#include <iterator>
#include <bitset>
#include <numeric>
#include <list>
#include <iomanip>
#include <cassert>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <random>
using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define div div228
#define prev prev228
#define free free228
#define close close228
#define int long long
typedef long double ld;
const int BINF = 9e18, LINF = 2e9, mod = 1e9 + 7, P = 179, Q = 1791791791;
typedef long long ll;
typedef long double ld;
ld len(ld x, ld y) {
	return sqrt(x * x + y * y);
}
void solve() {
    ld x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (len(x1, y1) < len(x2, y2))
    	swap(x1, x2), swap(y1, y2);
    ld ans = len(x1, y1) - len(x2, y2);
    ld ang = atan2(abs(x1 * y2 - x2 * y1), x1 * x2 + y1 * y2);
    //cout << ans << endl;
    ans += ang * len(x2, y2);
    cout << min(ans, len(x1, y1) + len(x2, y2));
    return;
}
signed main() {
    //freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cout.precision(40);
    cout << fixed;
    int t = 1;
    //cin >> t;
    for (int i = 0; i < t; ++i)
        solve();

    return 0;
}
