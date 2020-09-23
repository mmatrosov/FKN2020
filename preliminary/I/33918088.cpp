#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define ff first
#define ss second
using namespace std;

const int INF = 1e17;
vector<int> starts;
vector<vector<pair<int, int>>> g;
vector<int> fire;
vector<int> dist;
set<pair<int, int>> q;

signed main() {
	int n, m, k;
	cin >> n >> m >> k;
	starts.resize(k);
	g.resize(n + 1);
	fire.resize(n + 1, INF);
	for (int i = 0; i < k; i++ ) {
		cin >> starts[i];
		fire[starts[i]] = 0;
		q.insert({0, starts[i]});
	}
	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		g[a].push_back({b, w});
		g[b].push_back({a, w});
	}
	while (q.size() != 0) {
		auto we = (*q.begin()).ss;
		q.erase(q.begin());
		//cout << "we: " << we << " " << fire[we] << endl;
		for (auto el: g[we]) {
			//cout << el.ff << " " << el.ss << endl;
			if (fire[el.ff] > fire[we] + el.ss) {
				if (fire[el.ff] != INF) {
					q.erase(q.find({fire[el.ff], el.ff}));
				}
				fire[el.ff] = fire[we] + el.ss;
				q.insert({fire[el.ff], el.ff});
			}
		}
	}
	//cout <<"$$$$$$" << endl;
	//return 0;
	int s, f;
	cin >> s >> f;
	dist.resize(n + 1, INF);
	dist[s] = 0;
	if (fire[s] == 0) {
		cout << -1;
		return 0;
	}
	q.insert({0, s});
	while (q.size() != 0) {
		auto we = (*q.begin()).ss;
		q.erase(q.begin());
		for (auto el: g[we]) {
			if (fire[el.ff] <= dist[we] + el.ss) {
				continue;
			}
			if (dist[el.ff] > dist[we] + el.ss) {
				if (dist[el.ff] != INF) {
					q.erase(q.find({dist[el.ff], el.ff}));
				}
				dist[el.ff] = dist[we] + el.ss;
				q.insert({dist[el.ff], el.ff});
			}
		}
	}
	if (dist[f] == INF) {
		cout << -1;
	} else {
		cout << dist[f];
	}
	// your code goes here
	return 0;
}