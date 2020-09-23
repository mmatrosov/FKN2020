#include <iostream>
#include <vector>
#include <deque>

#define int long long

#define x first
#define y second
#define le(v) ((int)v.size())
#define pb push_back

using namespace std;

typedef pair<int, int> pii;

int n, m, k;
vector<vector<pii>> g;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;
	vector<int> dest(n, 1e18);
	deque<int> deq;
	for (int i = 0; i < k; i++) {
		int pos; cin >> pos; pos--;
		deq.pb(pos);
		dest[pos] = 0;
	}
	g.resize(n);
	for (int i = 0; i < m; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		a--;b--;
		g[a].emplace_back(b, l);
		g[b].emplace_back(a, l);
	}
	while (!deq.empty()) {
		int v = deq.front(); deq.pop_front();
		for (pii pp : g[v]) {
			if (dest[pp.x] > dest[v] + pp.y) {
				dest[pp.x] = dest[v] + pp.y;
				deq.pb(pp.x);
			}
		}
	}
	vector<int> dist(n, 1e18);
	int s, t;
	cin >> s >> t; s--; t--;
	dist[s] = 0;
	deq.clear();
	deq.pb(s);
	while (!deq.empty()) {
		int v = deq.front(); deq.pop_front();
		for (pii pp : g[v]) {
			if (dist[pp.x] > dist[v] + pp.y && dist[v] + pp.y < dest[pp.x]) {
				dist[pp.x] = dist[v] + pp.y;
				deq.pb(pp.x);
			}
		}
	}
	if (dist[t] < 1e18) {
		cout<< dist[t];
	} else {
		cout<< -1;
	}
}