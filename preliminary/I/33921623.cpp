//#define _GLIBCXX_DEBUG 	
 
#include  <bits/stdc++.h>
 
#define f first
#define s second
#define push push_back
#define pop pop_back
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
const int MAXN = 101, X = 1e6;
const ll INF = ll(3e18) + 1;


signed main() {
	#ifdef _GLIBCXX_DEBUG
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	int n, m, k;
	cin >> n >> m >> k;
	vector <ll> dp(n + 1, INF), ans(n + 1, INF);
	set <pair <ll, ll>> s;
	for (int i = 0; i < k; ++i) {
		int a;
		cin >> a;
		dp[a] = 0;
		s.insert({0ll, a});
	}
	vector <vector <pair <ll, ll>>> e(n + 1);
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		e[a].push({b, c});
		e[b].push({a, c});
	}
	for (int i = 0; i < n; ++i) {
		if (s.size() == 0) {
			break;
		}
		int v = s.begin()->s;
		s.erase(s.begin());
		for (auto j: e[v]) {
			if (dp[j.f] > dp[v] + j.s) {
				if (s.count({dp[j.f], j.f})) {
					s.erase({dp[j.f], j.f});
				}
				dp[j.f] = dp[v] + j.s;
				s.insert({dp[j.f], j.f});
			}
		}
	}
	int st, fn;
	cin >> st >> fn;
	ans[st] = 0;
	s.clear();
	s.insert({0ll, st});
	for (int i = 0; i < n; ++i) {
		if (s.size() == 0) {
			break;
		}
		int v = s.begin()->s;
		s.erase(s.begin());
		for (auto &j: e[v]) {
			if (ans[j.f] > ans[v] + j.s && ans[v] + j.s < dp[j.f]) {
				if (s.count({ans[j.f], j.f})) {
					s.erase({ans[j.f], j.f});
				}
				ans[j.f] = ans[v] + j.s;
				s.insert({ans[j.f], j.f});
			}
		}
	}
	cout << (ans[fn] == INF? -1: ans[fn]);
	return 0;
}