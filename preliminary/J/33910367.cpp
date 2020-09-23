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
char ans[1000][1000];
void solve() {
	int n, m;
	cin >> n >> m;
	int s = n * m;
	int cnt = 0;
	while (s - (cnt + 1) >= 0) {
		++cnt;
		s -= cnt;
	}
	vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
    	vector<pair<int, int>> lv;
    	for (int j = 0; j < m; ++j)
    		lv.push_back({i, j});
    	if (i % 2 == 1)
    		reverse(lv.begin(), lv.end());
    	copy(lv.begin(), lv.end(), back_inserter(v));
    }
    int bg = 0;
    for (int c = 1; c <= cnt; ++c) {
    	auto first = v[bg];
    	int clr = 5 * (first.x % 5) + (c % 5);
    	char ch = 'A' + clr;
    	for (int i = bg; i < bg + c; ++i)
    		ans[v[i].x][v[i].y] = ch;
    	bg += c;
    	if (c == cnt) {
    		for (int i = bg; i < v.size(); ++i)
    			ans[v[i].x][v[i].y] = ch;
    	}
    }
    cout << cnt << "\n";
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < m; ++j)
    		cout << ans[i][j];
    	cout << "\n";
    }
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
