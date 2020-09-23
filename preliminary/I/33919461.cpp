#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define sh cin.tie(0); cin.sync_with_stdio(0); cout.tie(0);
#define FILE freopen("test.in", "r", stdin);
#define vprint(v) for (int ii = 0; ii < v.size(); ii++){cout << v[ii] << " ";}
#define debugv(v) if (v.size() != 0) {cout << "[ "; for (int __ = 0; __ < (int)(v.size()) - 1; __++){cout << v[__] << ", ";} cout << v[(int)(v.size()) - 1] << " ]" << endl;} else {cout << "[]" << endl;}
#define debug cout << "-----------------------------------------------" << endl;
#define print1(a) cout << "{ " << a << " }" << endl;
#define print2(a, b) cout << "{ " << a << ", " << b << " }" << endl;
#define print3(a, b, c) cout << "{ " << a << ", " << b << ", " << c << " }" << endl;
#define print4(a, b, c, d) cout << "{ " << a << ", " << b << ", " << c << ", " << d << " }" << endl;
using namespace std;
#define int long long
const int INF = 1e18 + 228;
const int MAXN = 2e5 + 228;

vector<pair<int, int>> g[MAXN];
int d[MAXN];
int ans[MAXN];
signed main()
{
#ifdef LOCAL
    FILE;
#endif
    sh;
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> v;
	for (int i = 0; i < k; i++) {
		int aa;
		cin >> aa;
		aa--;
		v.pb(aa);
	}
	for (int i = 0; i < m; i++) {
		int aa, bb, cc;
		cin >> aa >> bb >> cc;
		aa--;
		bb--;
		g[aa].pb({bb, cc});
		g[bb].pb({aa, cc});
	}    
	//print1("ok1")
	for (int i = 0; i < n; i++) {
		d[i] = ans[i] = INF;
	}
	set<pair<int, int>> s;
	for (int i = 0; i < k; i++) {
		d[v[i]] = 0;
		s.insert({0, v[i]});
	}
	while (!s.empty()) {
		pair<int, int> now = *s.begin();
		s.erase(now);
		for (auto to : g[now.S]) {
			if (d[to.F] > now.F + to.S) {
				s.erase({d[to.F], to.F});
				d[to.F] = now.F + to.S;
				s.insert({d[to.F], to.F});
			}
		}
	}
	s.clear();
	int st, f;
	cin >> st >> f;
	st--;
	f--;
	ans[st] = 0;
	s.insert({0, st});
	while (!s.empty()) {
		pair<int, int> now = *s.begin();
		s.erase(now);
		if (now.F >= d[now.S]) {
			ans[now.S] = INF;
			now.F = INF;
		}
		for (auto to : g[now.S]) {
			if (ans[to.F] > now.F + to.S) {
				s.erase({ans[to.F], to.F});
				ans[to.F] = now.F + to.S;
				s.insert({ans[to.F], to.F});
			}
		}
	}
	if (ans[f] >= INF) {
		cout << -1 << endl;
	} else {
		cout << ans[f] << endl;
	}
    return 0;
}
