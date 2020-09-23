/*

Code for problem G by cookiedoth
Generated 30 Aug 2020 at 11.39 AM


______▄███████▄_______
______█▄█████▄█_______
______█▼▼▼▼▼█_______
_____██________ ██______
______█▲▲▲▲▲█_______
______█████████_______
_______██____ ██________

>_<
o_O
-_-

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
#define ui unsigned int
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

const int mx = 1e5 + 228;
vector<vector<pair<int, ui> > > g;
int n;
ui tot[mx];

void dfs(int v, int pv) {
	for (auto pp : g[v]) {
		int v1 = pp.first;
		if (v1 != pv) {
			tot[v1] = tot[v] ^ pp.second;
			dfs(v1, v);
		}
	}
}

void read() {
	cin >> n;
	g.resize(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		ui w;
		cin >> u >> v >> w;
		u--;
		v--;
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
	}
	dfs(0, 0);
}

vector<vector<int> > go;
vector<int> id;

int new_vertex() {
	go.push_back(vector<int> (2, -1));
	id.push_back(-1);
	return (int)go.size() - 1;
}

const int B = 32;

void add_number(ui x, int put_id) {
	int v = 0;
	for (int i = B - 1; i >= 0; --i) {
		int b = (int)((x >> i) & (ui)1);
		if (go[v][b] == -1) {
			int v1 = new_vertex();
			go[v][b] = v1;
		}
		v = go[v][b];
	}
	id[v] = put_id;
}

pair<ui, pair<int, int> > max_xor(int v1, int v2, int level) {
	if (level == -1) {
		return {0, {id[v1], id[v2]}};
	}
	int t1 = (go[v1][0] != -1 && go[v2][1] != -1);
	int t2 = (go[v1][1] != -1 && go[v2][0] != -1);
	int s1 = (go[v1][0] != -1 && go[v2][0] != -1);
	int s2 = (go[v1][1] != -1 && go[v2][1] != -1);
	if (t1 || t2) {
		pair<ui, pair<int, int> > res = {0, {0, 0}};
		if (t1) {
			chkmax(res, max_xor(go[v1][0], go[v2][1], level - 1));
		}
		if (t2) {
			chkmax(res, max_xor(go[v1][1], go[v2][0], level - 1));
		}
		res.first ^= ((ui)1 << level);
		return res;
	} else {
		pair<ui, pair<int, int> > res = {0, {0, 0}};
		if (s1) {
			chkmax(res, max_xor(go[v1][0], go[v2][0], level - 1));
		}
		if (s2) {
			chkmax(res, max_xor(go[v1][1], go[v2][1], level - 1));
		}
		return res;
	}
}

signed main() {
	fast_io();
	read();
	new_vertex();
	for (int i = 0; i < n; ++i) {
		add_number(tot[i], i);
	}
	pair<ui, pair<int, int> > res = max_xor(0, 0, B - 1);
	cout << res.second.first + 1 << ' ' << res.second.second + 1 << '\n';
}
