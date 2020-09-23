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
vector<pair<int, int>> g[100000];
uint32_t f[100000];
void dfs(int v, int p = -1) {
	f[v] = (p == -1 ? 0 : f[p]);
	for (auto e : g[v])
		if (e.x == p)
			f[v] ^= e.y;
	for (auto e : g[v])
		if (e.x != p)
			dfs(e.x, v);
}
const int MAXV =3200000;
int go[MAXV][2];
int ptr = 1;
int newv() {
	return ptr++;
}
void add(uint32_t x) {
	int v = 0;
	for (int t = 31; t >= 0; --t) {
		int now = ((x >> t) & 1);
		if (go[v][now] == -1)
			go[v][now] = newv();
		v = go[v][now];
	}
}
uint32_t calc(uint32_t x) {
	int v = 0;
	uint32_t ans = 0;
	for (int t = 31; t >= 0; --t) {
		int now = ((x >> t) & 1);
		if (go[v][now ^ 1] != -1) {
			ans ^= 1 << t;
			v = go[v][now ^ 1];
		} else 
			v = go[v][now];
	}
	return ans;
}
void solve() {
	for (int i = 0; i < MAXV; ++i)
		go[i][0] = go[i][1] = -1;
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
    	int a, b, w;
    	cin >> a >> b >> w;
    	--a, --b;
    	g[a].push_back({b, w});
    	g[b].push_back({a, w});
    } 
    dfs(0);
    uint32_t ans = 0, ps = 0;
    for (int i = 0; i < n; ++i) {
    	add(f[i]);
    	uint32_t lans = calc(f[i]);
    	if (ans < lans) 
    		ans = lans, ps = i;
    }
    int ps2 = -1;
    for (int i = 0; i < n; ++i) 
    	if ((f[i] ^ f[ps]) == ans)
    		ps2 = i;
    cerr << ans << endl;
    cout << ps + 1 << " " << ps2 + 1 << endl;
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
