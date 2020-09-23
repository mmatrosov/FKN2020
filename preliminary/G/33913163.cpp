#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <string>
#define int long long


using namespace std;

typedef pair<int, int> pa;
typedef long long ll;
typedef long double ld;

ld rad(int x, int y){
	return sqrt(x * x + y * y);
}

const int N = 1e5 + 5;

int ans = 0, U = 1, V = 1;

struct bor{
	int v;
	vector<bor*> nx;
};

struct go{
	int to, w;
};

vector<go> g[N];
vector<int> val[N];

bor* st;

void add(bor* nw, int bit, int val, int v){
	if (bit == -1) {
		nw->v = v;
		return;
	}
	int pos = 0;
	if (val & ((int)1 << bit)) {
		pos = 1;
	}
	if (nw->nx[pos] == 0){
		nw->nx[pos] = new bor();
		(nw->nx[pos])->nx.resize(2, 0);
	}
	add(nw->nx[pos], bit - 1, val, v);
}

int notn(int x){
	return (x + 1) % 2;
}

void find(bor* nw, int val, int bit, int v){
	if (bit == -1){
		if (val >= ans){
			ans = val;
			//cout << ans << '\n';
			V = v;
			U = nw->v;
		}
		return;
	}
	int pos = 0;
	if (((int)1 << bit) & val){
		pos = 1;
	}
	int X = notn(pos);
	if (nw->nx[X] != 0) {
		if (pos == 0)
			val += ((int)1 << bit);
		find(nw->nx[X], val, bit - 1, v);
	}else {
		if (pos == 1)
			val -= ((int)1 << bit);
		find(nw->nx[pos], val, bit - 1, v);
	}
}

void dfs(int v, int p, int val){
	if (v != 1) {
		if (val >= ans){
			ans = val;
			V = 1, U = v;
		}

		add(st, 32, val, v);
		find(st, val, 32, v);
	} else {
		st = new bor();
		st->nx.resize(2, 0);
	}
	for (go e : g[v]){
		if (e.to == p) continue;
		dfs(e.to, v, (val ^ e.w));
	}
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.precision(6);
	cout << fixed;
	
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; ++i){
		int u, v, w;
		cin >> u >> v >> w;
		go X = {v, w}, Y = {u, w};
		g[u].push_back(X);
		g[v].push_back(Y);

	}
	dfs(1, 1, 0);
	cout << U << " " << V;
}