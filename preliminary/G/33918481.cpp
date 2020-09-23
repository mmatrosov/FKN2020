#include <bits/stdc++.h>
#define fori(n) for (int i = 0; i < n; i++)
#define forj(n) for (int j = 0; j < n; j++)
#define pb push_back
#define ff first
#define ss second
#define all(v) v.begin(), v.end()
#define int long long
typedef long long ll;
#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector", "fast-math", "O3")
//#pragma GCC target("avx2")
using namespace std;

vector < vector < int > > g;
vector < vector < int > > cost;
vector < bool > isUsed;
int n;
int cur = 0;
vector < pair < int, int > > a;
void f(int x) {
	isUsed[x] = 1;
	a.pb({x, cur});
	for (int i = 0; i < g[x].size(); i++) {
		int v = g[x][i];
		if (isUsed[v] == 1) continue;
		cur ^= cost[x][i];
		f(v);
		cur ^= cost[x][i];
	}
}
struct vertex{
	int l = -1;
	int r = -1;
};
vector < vertex > bor;
vertex nul;
map < int, int > inde; // для каждой вершины бора запоминаем
void add(int v, int x) {
	int ind = 0;
	int cur = 0;
	for (int i = 31; i >= 0; i--) {
		cur = ((x>>i)&1);
		if (cur == 0) {
			if (bor[ind].l == -1) {
				bor[ind].l = bor.size();
				bor.pb(nul);
			}
			ind = bor[ind].l;
		} else {
			if (bor[ind].r == -1) {
				bor[ind].r = bor.size();
				bor.pb(nul);
			}
			ind = bor[ind].r;
		}
	}
	inde[ind] = v;
}
pair < int, pair < int, int > > ans;
void find(int v, int x) {
	int ind = 0;
	int bestval = 0;
	for (int i = 31; i >= 0; i--) {
		bestval *= 2;
		if (((x>>i)&1) == 1) {
			if (bor[ind].l != -1){
				ind = bor[ind].l;
			} else { 
				ind = bor[ind].r;
				bestval += 1;
			}
		} else {
			if (bor[ind].r != -1) {
				ind = bor[ind].r;
				bestval += 1;
			} else {
				ind = bor[ind].l;
			}
		}
	}
	int curans = x ^ bestval;
	if (curans > ans.ff) {
		ans.ff = curans;
		ans.ss = {v, inde[ind]};
	}
}
main () {
	bor.resize(1);
	int n;
	cin >> n;
	if (n == 1) {
		cout << "1 1";
		return 0;
	}	
	g.resize(n);
	isUsed.resize(n);
	cost.resize(n);
	fori(n - 1) {
		int x, y;
		int val;
		cin >> x >> y >> val;
		x--; y--;
		g[x].pb(y);
		g[y].pb(x);
		cost[x].pb(val);
		cost[y].pb(val);
	}
	f(0);
	fori(a.size()) {
		add(a[i].ff, a[i].ss);
	}
	ans.ss = {1, 1};
	fori(a.size()) {
		find(a[i].ff, a[i].ss);
	}
	//cout << ans.ff << "\n";
	cout << ans.ss.ff + 1 << " " << ans.ss.ss + 1;
	return 0;
}