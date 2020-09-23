#include <iostream>
#include <set>
#include <map>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <deque>
#include <stack>
#include <climits>
#include <math.h>
#include <cassert>
#include <unordered_map>
#include <chrono>
#include <random>
#include <ctime>
#include <complex>
using namespace std;
#pragma warning(disable : 4996)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ld PI = acosl(-1.0);
const ll MOD = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct ed {
	ll to, w;
};

int main() {
#ifdef _DEBUG
	freopen("input1.txt", "r", stdin);
	freopen("output2.txt", "w", stdout);
#endif
	srand(time(0));
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	vector<ll> bad(k), bad_dist(n, INT64_MAX);
	for (int i = 0; i < k; i++) {
		cin >> bad[i];
		bad[i]--;
		bad_dist[bad[i]] = 0;
	}
	vector<vector<ed>> g(n);
	for (int i = 0; i < m;i++) {
		ll a, b, w;
		cin >> a >> b >> w;
		a--, b--;
		g[a].push_back({ b, w });
		g[b].push_back({ a, w });
	}
	set<pair<ll, ll>> s;
	for (int i = 0; i < n; i++) {
		s.insert({ bad_dist[i], i });
	}
	while (!s.empty()) {
		auto cur = *s.begin();
		s.erase(s.begin());
		for (auto i : g[cur.second]) {
			if (bad_dist[cur.second] + i.w < bad_dist[i.to]) {
				s.erase({ bad_dist[i.to], i.to });
				s.insert({ bad_dist[cur.second] + i.w, i.to });
				bad_dist[i.to] = bad_dist[cur.second] + i.w;
			}
		}
	}
	int st, f;
	cin >> st >> f;
	st--, f--;
	vector<ll> dist(n, INT64_MAX);
	dist[st] = 0;
	for (int i = 0; i < n; i++) {
		s.insert({ dist[i], i });
	}
	while (!s.empty()) {
		auto cur = *s.begin();
		s.erase(s.begin());
		if (cur.first == INT64_MAX)continue;
		for (auto i : g[cur.second]) {
			if (dist[cur.second] + i.w < bad_dist[i.to] && dist[cur.second] + i.w < dist[i.to]) {
				s.erase({ dist[i.to], i.to });
				s.insert({ dist[cur.second] + i.w, i.to });
				dist[i.to] = dist[cur.second] + i.w;
				//cout << dist[cur.second] + i.w << " " << i.to << "\n";
			}
		}
	}
	cout << (dist[f] == INT64_MAX ? -1 : dist[f]);
}