#include<bits/stdc++.h>

#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 1e5 + 5;

vector<pair<int, ll>> g[MAXN];
int n;
vector<pair<ll, int>> have;

struct node {
	int next1, next0;
	vector<int> term;
	node() : next1(-1), next0(-1) {}
};

vector<node> tree;

void dfs(int v = 0, ll cost = 0, int p = -1) {
	have.push_back({cost, v});
	for (auto to : g[v]) {
		if (to.first == p) continue;
		dfs(to.first, cost ^ to.second, v);
	}
}

bool check_bit(ll mask, int bit) {
	return mask & (1ll << bit);
}

void insert(ll mask, int index, int bit = 50, int v = 0) {
	if (bit == -1) {
		tree[v].term.push_back(index);
		return;
	}
	bool yes = check_bit(mask, bit);
	int neigh = -1;
	if (yes) {
		if (tree[v].next1 == -1) {
			tree.push_back(node());
			tree[v].next1 = int(tree.size()) - 1;
		}
		neigh = tree[v].next1;
	} else {
		if (tree[v].next0 == -1) {
			tree.push_back(node());
			tree[v].next0 = int(tree.size()) - 1;
		}
		neigh = tree[v].next0;
	}
	insert(mask, index, bit - 1, neigh);
}

ll maxians = 0;
int a = -1, b = -1;
set<pair<int, int>> used;

void count(int u = 0, int v = 0, int bit = 50, ll ans = 0) {
	if (u > v) swap(u, v);
	pair<int, int> lookfor = {u, v};
	if (used.find(lookfor) != used.end()) return;
	used.insert(lookfor); 
	if (bit == -1) {
		if (ans >= maxians) {
			maxians = ans;
			a = tree[u].term.back();
			b = tree[v].term.back();
		}
		return;
	}
	bool uone = false, uzero = false, vzero = false, vone = false;
	if (tree[u].next1 != -1) uone = true;
	if (tree[u].next0 != -1) uzero = true;
	if (tree[v].next1 != -1) vone = true;
	if (tree[v].next0 != -1) vzero = true; 
	if ((uone && vzero) || (vone && uzero)) {
		ans += (1ll << bit);
		if (uone && vzero) count(tree[u].next1, tree[v].next0, bit - 1, ans);
		if (vone && uzero) count(tree[u].next0, tree[v].next1, bit - 1, ans);
	} else {
		if (uone && vone) count(tree[u].next1, tree[v].next1, bit - 1, ans);
		if (uzero && vzero) count(tree[u].next0, tree[v].next0, bit - 1, ans);
	}
}

void solve() {
	tree.push_back(node());
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int u, v; ll w;
		cin >> u >> v >> w; --u; --v;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	dfs();
	if (n == 1) {
		cout << 1 << ' ' << 1 << "\n";
		return;
	}
	for (auto val : have) {
		insert(val.first, val.second);
	}
	count();
	cout << a + 1 << ' ' << b + 1 << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}