#include <bits/stdc++.h>
 
using namespace std;

//#define int long long
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

const ll INF = 1e18;
const int MAXN = 2e5 + 100;
vector<pii> g[MAXN];
ll d1[MAXN], d2[MAXN];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//cout.setf(ios::fixed);
	//cout.precision(20);

	int n, m, k;
	cin >> n >> m >> k;
	fill(d1, d1 + n, INF);
	fill(d2, d2 + n, INF);
	set<pll> setik;
	for (int i = 0; i < k; ++i) {
		int x;
		cin >> x;
		x--;
		d1[x] = 0;
		setik.insert({d1[x], x});
	}
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		u--;
		v--;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}	
	int s, f;
	cin >> s >> f;
	s--;
	f--;
	while (setik.size()) {
		int u = setik.begin()->second;
		setik.erase(setik.begin());
		for (pii to : g[u]) {
			if (d1[to.first] > d1[u] + to.second) {
				setik.erase({d1[to.first], to.first});
				d1[to.first] = d1[u] + to.second;
				setik.insert({d1[to.first], to.first});
			}
		}
	}
	d2[s] = 0;
	setik.insert({d2[s], s});
	while (setik.size()) {
		int u = setik.begin()->second;
		setik.erase(setik.begin());
		for (pii to : g[u]) {
			if (d2[to.first] > d2[u] + to.second && d2[u] + to.second < d1[to.first]) {
				setik.erase({d2[to.first], to.first});
				d2[to.first] = d2[u] + to.second;
				setik.insert({d2[to.first], to.first});
			}
		}
	}
	cout << (d2[f] == INF ? -1 : d2[f]) << '\n';
}