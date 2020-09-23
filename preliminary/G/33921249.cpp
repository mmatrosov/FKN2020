#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <set>
#include <math.h>
#define ll unsigned int
#define ld long double

using namespace std;

int all = 0;
ll ans = 0;
int ans_u = 0;
int ans_v = 0;

struct edge {
	int v;
	ll w;
	edge() {}
	edge(int v, ll w) : v(v), w(w) {}
};


const int LG = 20;
const int MAXN = 1e5 + 5;
int cent[MAXN];
int tree[LG][MAXN];
ll dist[LG][MAXN];
int sz[MAXN];
int maxsz[MAXN];
vector<edge> graph[MAXN];
vector<edge> graph1[MAXN];
int pos[MAXN];
vector<int> tin;
int n;

void dfs_renum(int u, int par) {
	tin.push_back(u);
	for (auto elem : graph[u]) {
		if (elem.v != par)
			dfs_renum(elem.v, u);
	}
}

void renum() {
	for (int i = 0; i < n; i++)
		pos[tin[i]] = i;
	for (int i = 0; i < n; i++) {
		graph1[i] = graph[tin[i]];
	}
	for (int i = 0; i < n; i++) {
		graph[i] = graph1[i];
		for (int j = 0; j < graph[i].size(); j++)
			graph[i][j].v = pos[graph[i][j].v];
	}
}

struct node {
	int one = -1;
	int zero = -1;
	int numb = -1;
	node() {}
};

const int MAXK = 31;


void add(ll val, int x, vector<node>& pool) {
	int root = 0;
	for (int k1 = MAXK; k1 >= 0; k1--) {
		if (val & ((ll)1 << k1)) {
			if (pool[root].one == -1) {
				int sz = pool.size();
				pool[root].one = sz;
				pool.push_back(node());
			}
			root = pool[root].one;
		}
		else {
			if (pool[root].zero == -1) {
				int sz = pool.size();
				pool[root].zero = sz;
				pool.push_back(node());
			}
			root = pool[root].zero;
		}
	}
	pool[root].numb = x;
}


void build(vector<pair<ll, int> >& vals, vector<node>& pool) {
	pool.push_back(node());
	for (auto elem : vals) {
		add(elem.first, elem.second, pool);
	}
}


void dfs_1(int u, int par, vector<pair<ll, int>>& val) {
	for (auto elem : graph[u]) {
		int v = elem.v;
		if (v == par)
			continue;
		val[v].second = v;
		val[v].first = val[u].first ^ elem.w;
		dfs_1(v, u, val);
	}
}

void dfs_sz(int u, int par, int j) {
	all += 1;
	sz[u] = 1;
	maxsz[u] = 0;
	for (auto elem : graph[u]) {
		int v = elem.v;
		if (cent[v] != -1)
			continue;
		if (tree[j][v] != -1)
			continue;
		if (v == par)
			continue;
		dfs_sz(v, u, j);
		maxsz[u] = max(maxsz[u], sz[v]);
		sz[u] += sz[v];
	}
}

int dfs_find(int u, int par, int j) {
	if (maxsz[u] < (all + 1) / 2)
		return u;
	for (auto elem : graph[u]) {
		int v = elem.v;
		if (cent[v] != -1)
			continue;
		if (tree[j][v] != -1)
			continue;
		if (v == par)
			continue;
		if (sz[v] < (all + 1) / 2)
			continue;
		return dfs_find(v, u, j);
	}
	return u;
}

void paint(int u, int par, int j, ll D, int C, vector<pair<ll, int>>& arr) {
	dist[j][u] = D;
	arr.push_back({ D, u });
	tree[j][u] = C;
	for (auto elem : graph[u]) {
		int v = elem.v;
		if (cent[v] != -1)
			continue;
		if (tree[j][v] != -1)
			continue;
		if (v == par)
			continue;
		paint(v, u, j, D ^ elem.w, C, arr);
	}
}

void solve(vector<pair<ll, int> >& vals) {
	vector<node> pool;
	build(vals, pool);
	for (int i = 0; i < vals.size(); i++) {
		int x = vals[i].second;
		ll y = vals[i].first;
		ll now = 0;
		int root = 0;
		for (int k1 = MAXK; k1 >= 0; k1--) {
			if (y & ((ll)1 << k1)) {
				if (pool[root].zero != -1) {
					root = pool[root].zero;
					now += ((ll)1 << k1);
					continue;
				}
				else {
					root = pool[root].one;
				}
			}
			else {
				if (pool[root].one != -1) {
					root = pool[root].one;
					now += ((ll)1 << k1);
					continue;
				}
				else {
					root = pool[root].zero;
				}
			}
		}
		if (now > ans) {
			ans = now;
			ans_u = x;
			ans_v = pool[root].numb;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//int n;
	cin >> n;
	//graph.resize(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		ll w;
		cin >> u >> v >> w;
		graph[u - 1].push_back({ v - 1, w });
		graph[v - 1].push_back({ u - 1, w });
	}
	vector<pair<ll, int> > vals(n);
	vals[0] = { 0, 0 };
	dfs_1(0, -1, vals);
	solve(vals);
	//for (auto elem : vals)
	//	cerr << elem.first << "/" << elem.second << " ";
	//cerr << endl;
	cout << ans_u + 1 << " " << ans_v + 1 << endl;
	return 0;



	dfs_renum(0, -1);
	renum();
	for (int i = 0; i < n; i++) {
		cent[i] = -1;
		for (int j = 0; j < LG; j++) {
			tree[j][i] = -1;
		}
	}
	for (int j = 0; j < LG; j++) {
		for (int i = 0; i < n; i++) {
			if (tree[j][i] != -1)
				continue;
			if (cent[i] != -1)
				continue;
			all = 0;
			dfs_sz(i, -1, j);
			int C = dfs_find(i, -1, j);
			cent[C] = j;
			vector<pair<ll, int> > vals;
			paint(C, -1, j, 0, C, vals);
			solve(vals);
		}
	}
	cout << tin[ans_u] + 1 << " " << tin[ans_v] + 1 << endl;
}
//*/