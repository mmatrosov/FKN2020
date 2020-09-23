#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <set>
#include <map>
#include <string>

using namespace std;

#define int long long

const long long INF = 1e18;
const int SZ = 2e5 + 10;

int n, m, k;
vector<pair<int, long long>> graph[SZ];
long long max_t[SZ];

long long dist[SZ];

void build_maxt() {
	set<pair<long long, int>> st;
	for (int i = 1; i <= n; i++) {
		if (max_t[i] == 0)
			st.insert({ 0, i });
	}
	while (!st.empty()) {
		int v = st.begin()->second;
		st.erase(st.begin());
		for (auto h : graph[v]) {
			if (max_t[h.first] > max_t[v] + h.second) {
				st.erase({ max_t[h.first], h.first });
				max_t[h.first] = max_t[v] + h.second;
				st.insert({ max_t[h.first], h.first });
			}
		}
	}
}

void build_dist(int s) {
	set<pair<long long, int>> st;
	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
	}
	dist[s] = 0;
	st.insert({ 0, s });
	while (!st.empty()) {
		int v = st.begin()->second;
		st.erase(st.begin());
		for (auto h : graph[v]) {
			int now_t = dist[v] + h.second;
			if (dist[h.first] > now_t && max_t[h.first] > now_t) {
				st.erase({ dist[h.first], h.first });
				dist[h.first] = now_t;
				st.insert({ dist[h.first], h.first });
			}
		}
	}
}

signed main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		max_t[i] = INF;
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		max_t[x] = 0;
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		long long w;
		cin >> a >> b >> w;
		graph[a].push_back({ b, w });
		graph[b].push_back({ a, w });
	}

	build_maxt();
	int s, t;
	cin >> s >> t;
	build_dist(s);
	if (dist[t] == INF)
		cout << -1;
	else
		cout << dist[t];
	return 0;
}
