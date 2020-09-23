#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(aaa) aaa.begin(), aaa.end()

struct E {
	int to, w;
};

const ll INF = 1e18;
const int N = 2e5 + 5;
ll dd[N], restr[N];
vector<E> g[N];


void dijk(ll d[N], bool ban, vector<int> st) {


	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

	for (int x : st) {
		d[x] = 0;
		pq.push({0, x});
	}

	while (!pq.empty()) {
		int node = pq.top().second;
		ll cd = pq.top().first;
		pq.pop();

		if (d[node] != cd)
			continue;

		for (const E &e : g[node]) {
			ll nd = cd + e.w;
			if (ban && nd >= restr[e.to])
				continue;
			if (d[e.to] > nd) {
				d[e.to] = nd;
				pq.push({nd, e.to});
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	vector<int> fire;

	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		x--;
		fire.push_back(x);
	}

	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		x--, y--;
		g[x].push_back({y, w});
		g[y].push_back({x, w});
	}

	int st, fin;
	cin >> st >> fin;
	st--, fin--;

	fill(restr, restr + N, INF);
	fill(dd, dd + N, INF);

	dijk(restr, false, fire);
	dijk(dd, true, {st});

	if (dd[fin] == INF) {
		cout << "-1";
	}
	else {
		cout << dd[fin];
	}

	return 0;
}