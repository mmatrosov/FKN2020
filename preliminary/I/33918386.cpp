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
const int MAXN = 2e5 + 7;
vector<pair<int, int>> g[MAXN];
int n;
bool vis[MAXN];
void calc(int *d, vector<int> v) {
	fill(d, d + n, BINF);
	fill(vis, vis + n, 0);
	set<pair<int, int>> q;
	for (int x : v)
		q.insert({0, x}), d[x] = 0;
	while (q.size()) {
		int v = q.begin()->y;
		q.erase(q.begin());
		if (vis[v])
			continue;
		vis[v] = 1;
		for (auto e : g[v]) {
			int u = e.x;
			int c = e.y;
			if (!vis[u] && d[u] > d[v] + c) {
				q.erase({d[u], u});
				d[u] = d[v] + c;
				q.insert({d[u], u});
			}
		}
	}
}
int d1[MAXN], d2[MAXN];
bool ok[MAXN];
void dfs(int v) {
	if (vis[v] || !ok[v])
		return;
	vis[v] = 1;
	for (auto e : g[v]) {
		int u = e.x;
		dfs(u);
	}
}
void solve() {
	int m, k;
	cin >> n >> m >> k;
	vector<int> st;
	for (int i = 0; i < k; ++i) {
		int x;
		cin >> x;
		--x;
		st.push_back(x);
	}
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		--a, --b;
		g[a].push_back({b, c});
		g[b].push_back({a, c});
	}
	int s, f;
	cin >> s >> f;
	--s, --f;
	calc(d1, st);
	calc(d2, vector<int>(1, s));
	for (int i = 0; i < n; ++i)
		ok[i] = d1[i] > d2[i];
	fill(vis, vis + n, 0);
	dfs(s);
	if (vis[f])
		cout << d2[f] << "\n";
	else
		cout << "-1\n";
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
