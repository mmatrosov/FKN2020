#include <bits/stdc++.h>
 
using namespace std;

#define int long long
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

struct node {
	node *go[2];
	int id;

	node() : id(-1) {
		go[0] = nullptr;
		go[1] = nullptr;
	}
};

const int MAXN = 1e5 + 100;
vector<pii> g[MAXN];
int val[MAXN];

void dfs(int u, int p) {
	for (pii to : g[u]) {
		if (to.first == p) {
			continue;
		}
		val[to.first] = (val[u] ^ to.second);
		dfs(to.first, u);
	}
}

void add(node *&root, int x, int id) {
	node *cur = root;
	for (int i = 31; i >= 0; --i) {
		int b = ((x >> i) & 1LL);
		if (!cur->go[b]) {
			cur->go[b] = new node();
		}
		cur = cur->go[b];
	}
	cur->id = id;
}

pii get(node *&root, int x) {
	node *cur = root;
	int res = 0;
	for (int i = 31; i >= 0; --i) {
		int b = ((x >> i) & 1LL);
		if (cur->go[!b]) {
			res |= (1LL << i);
			cur = cur->go[!b];
		}
		else {
			cur = cur->go[b];
		}
	}
	return {res, cur->id};
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//cout.setf(ios::fixed);
	//cout.precision(20);

	int n;
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		u--;
		v--;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	dfs(0, -1);
	node *root = new node();
	int ans = 0, a = 0, b = 0;
	add(root, val[0], 0);
	for (int i = 1; i < n; ++i) {
		pii res = get(root, val[i]);
		if (res.first > ans) {
			ans = res.first;
			a = res.second;
			b = i;
		}
		add(root, val[i], i);
	}
	cout << a + 1 << ' ' << b + 1 << '\n';
}