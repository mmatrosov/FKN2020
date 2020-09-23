#include <iostream>
#include <vector>
#include <map>

#define int long long
#define x first
#define y second
using namespace std;
typedef pair<int, int> pii;

int n;
vector<vector<pii>> g;
vector<int> d;

void dfs(int v, int _p) {
	for (pii pp : g[v]) {
		if (pp.x == _p) continue;
		d[pp.x] ^= pp.y ^ d[v];
		dfs(pp.x, v);
	}
}

struct Node {
	vector<int> go;
	int id = -1;
	Node() {
		go.resize(2);
	}
};
vector<Node> S(1);

int create() {
	int id = S.size();
	S.emplace_back();
	return id;
}

int root = create();

void add(int i, int depth, int val, int id) {
	if (depth == -1) {
		S[i].id = id;
	} else {
		if (!S[i].go[(val >> depth) & 1]) {
			int _new = create();
			S[i].go[(val >> depth) & 1] = _new;
		}
		add(S[i].go[(val >> depth) & 1], depth - 1, val, id);
	}
}

int query(int i, int depth, int val) {
	if (depth == -1) {
		return S[i].id;
	} else {
		if (S[i].go[~(val >> depth) & 1])
			return query(S[i].go[~(val >> depth) & 1], depth - 1, val);
		else
			return query(S[i].go[(val >> depth) & 1], depth - 1, val);
	}
}

signed main() {
	cin >> n;
	g.resize(n);
	d.resize(n);
	for (int i = 0; i < n - 1; i++) {
		int a, b, w;
		cin >> a >> b >> w; a--;b--;
		g[a].emplace_back(b, w);
		g[b].emplace_back(a, w);
	}
	dfs(0, -1);
	int rez = 0;
	int A = 0; int B = 0;
	for (int i = 0; i < n; i++) {
		add(root, 39, d[i], i);
		int sub = query(root, 39, d[i]);
		if (rez < (d[sub] ^ d[i])) {
			rez = (d[sub] ^ d[i]);
			A = i;
			B = sub;
		}
	}
	cout << A + 1 << " " << B + 1;
}