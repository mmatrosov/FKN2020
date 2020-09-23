/*

Code for problem I by cookiedoth
Generated 30 Aug 2020 at 12.30 PM


______▄███████▄_______
______█▄█████▄█_______
______█▼▼▼▼▼█_______
_____██________ ██______
______█▲▲▲▲▲█_______
______█████████_______
_______██____ ██________

~_^
=_=
¯\_(ツ)_/¯

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <cassert>
#include <random>
#include <cstring>
#include <numeric>
#include <random>
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)
#define length(a) (int)a.size()

using namespace std;

template<class T> int chkmax(T &a, T b) {
	if (b > a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class T> int chkmin(T &a, T b) {
	if (b < a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class iterator> void output(iterator begin, iterator end, ostream& out = cerr) {
	while (begin != end) {
		out << (*begin) << " ";
		begin++;
	}
	out << endl;
}

template<class T> void output(T x, ostream& out = cerr) {
	output(x.begin(), x.end(), out);
}

void fast_io() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

const ll INF = 1e18;
int n, m, k, s, f;
vector<ll> fire_d, sp_d;
vector<int> used, campfires;
vector<vector<pair<int, ll> > > g;

void read() {
	cin >> n >> m >> k;
	campfires.resize(k);
	for (int i = 0; i < k; ++i) {
		cin >> campfires[i];
		campfires[i]--;
	}
	g.resize(n);
	for (int i = 0; i < m; ++i) {
		int u, v;
		ll w;
		cin >> u >> v >> w;
		u--;
		v--;
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
	}
	cin >> s >> f;
	s--;
	f--;
}

void fire_djkstra() {
	used.resize(n);
	fire_d.resize(n, INF);
	set<pair<ll, int> > S;
	for (auto v : campfires) {
		fire_d[v] = 0;
		S.insert({0, v});
	}
	while (!S.empty()) {
		int v = S.begin()->second;
		S.erase(S.begin());
		if (used[v]) {
			continue;
		}
		used[v] = 1;
		for (auto pp : g[v]) {
			int v1 = pp.first;
			if (chkmin(fire_d[v1], fire_d[v] + pp.second)) {
				S.insert({fire_d[v1], v1});
			}
		}
	}
}

void escape() {
	fill(all(used), 0);
	sp_d.resize(n, INF);
	sp_d[s] = 0;
	set<pair<ll, int> > S;
	S.insert({0, s});
	while (!S.empty()) {
		int v = S.begin()->second;
		S.erase(S.begin());
		if (used[v]) {
			continue;
		}
		used[v] = 1;
		for (auto pp : g[v]) {
			int v1 = pp.first;
			if (sp_d[v] + pp.second < fire_d[v1] && chkmin(sp_d[v1], sp_d[v] + pp.second)) {
				S.insert({sp_d[v1], v1});
			}
		}
	}
}

void print_ans() {
	cout << (sp_d[f] == INF ? -1 : sp_d[f]) << '\n';
}

signed main() {
	fast_io();
	read();
	fire_djkstra();
	escape();
	print_ans();
}
