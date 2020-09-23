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
int a[100];
int dp[101][101];
int prev[101][101];
void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < 101; ++i)
        for (int j = 0; j < 101; ++j)
            dp[i][j] = -1, prev[i][j] = -1;
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = 0;
        for (int j = 1; j <= k; ++j)
            for (int k = 0; k < i; ++k) {
                int lans = dp[k][j - 1] + a[k] * (i - k);
                if (dp[i][j] < lans) {
                    dp[i][j] = lans;
                    prev[i][j] = k;
                }
            }
    }
    pair<int, int> ans = {-1, -1};
    for (int i = 0; i <= k; ++i)
        ans = max(ans, {dp[n][i], i});
    int x = n;
    int y = ans.y;
    set<int> answ;
    while (x != -1) {
        x = prev[x][y];
        if (x != -1)
            answ.insert(a[x]);
        --y;
    }
    mt19937 rnd;
    while (answ.size() < k) {
        int x = 2000000 + rnd() % 10000000;
        answ.insert(x);
    }
    for (int x : answ)
        cout << x << " ";
    return;
}
signed main() {
    //freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    //cout.precision(40);

    int t = 1;
    //cin >> t;
    for (int i = 0; i < t; ++i)
        solve();

    return 0;
}
