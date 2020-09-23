#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <set>
#include <math.h>
#define ll long long
#define ld long double

using namespace std;

const ll inf = 1e18;

struct edge {
	int v;
	ll w;
	edge(){}
	edge(int v, ll w) : v(v), w(w) {}
};

int n, m, k;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> m >> k;
	vector<int> a(k);
	for (int i = 0; i < k; i++) {
		cin >> a[i];
		a[i]--;
	}
	vector<vector<edge> > graph(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		ll w;
		cin >> u >> v >> w;
		u--; v--;
		graph[u].push_back({ v, w });
		graph[v].push_back({ u, w });
	}
	int s, f;
	cin >> s >> f;
	s--; f--;
	vector<ll> dist(n);
	for (int i = 0; i < n; i++) {
		dist[i] = inf;
	}
	for (int i = 0; i < k; i++) {
		dist[a[i]] = 0;
	}
	set<pair<ll, int> > mn;
	for (int i = 0; i < n; i++) {
		mn.insert({ dist[i], i });
	}
	while (mn.size() > 0) {
		auto now = *mn.begin();
		mn.erase(now);
		int u = now.second;
		for (auto ed : graph[u]) {
			if (dist[u] + ed.w < dist[ed.v]) {
				mn.erase({ dist[ed.v], ed.v });
				dist[ed.v] = dist[u] + ed.w;
				mn.insert({ dist[ed.v], ed.v });
			}
		}
	}
	vector<ll> dist2(n);
	for (int i = 0; i < n; i++) {
		dist2[i] = inf;
	}
	dist2[s] = 0;
	mn.clear();
	for (int i = 0; i < n; i++) {
		mn.insert({ dist2[i], i });
	}
	while (mn.size() > 0) {
		auto now = *mn.begin();
		mn.erase(now);
		int u = now.second;
		for (auto ed : graph[u]) {
			if (dist2[u] + ed.w < dist2[ed.v] && dist2[u] + ed.w < dist[ed.v]) {
				mn.erase({ dist2[ed.v], ed.v });
				dist2[ed.v] = dist2[u] + ed.w;
				mn.insert({ dist2[ed.v], ed.v });
			}
		}
	}
	if (dist2[f] >= inf) {
		cout << -1 << endl;
	}
	else {
		cout << dist2[f] << endl;
	}
}
//*/