#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<iomanip>
using namespace std;
typedef long long ll;

vector<vector<pair<int, ll>>>ad;

vector<ll>xo;

struct Ver {
	vector<int>leaf;
	int L, R;
	Ver() {
		L = R = - 1;
	}
};

vector<Ver>bohr;

void add(ll x, int v) {
	ll i = 31;
	int st = 0;
	while (i >= 0) {
		ll d = x & (1ll << i);
		if (d == 0) {
			if (bohr[st].L == -1) {
				bohr[st].L = bohr.size();
				bohr.push_back(Ver());
			}
			st = bohr[st].L;
		}
		else {
			if (bohr[st].R == -1) {
				bohr[st].R = bohr.size();
				bohr.push_back(Ver());
			}
			st = bohr[st].R;
		}
		i--;
	}
	bohr[st].leaf.push_back(v);
}

vector<int>used;
void dfs(int u, ll x) {
	used[u] = 1;
	for (auto v : ad[u]) {
		if (used[v.first])continue;
		xo[v.first] = x ^ v.second;
		dfs(v.first, xo[v.first]);
	}
}

void solve() {
	int n; cin >> n;
	ad.resize(n); used.resize(n, 0);
	xo.resize(n);
	for (int i = 0; i < n - 1; i++) {
		int a, b; ll x; cin >> a >> b >> x; a--; b--;
		ad[a].push_back({ b, x });
		ad[b].push_back({ a, x });
	}
	dfs(0, 0);
	bohr.push_back(Ver());
	for (int i = 0; i < xo.size(); i++) {
		add(xo[i], i);
	}
	ll ans = 0, t1 = 0, t2 = 0;
	for (int j = 0; j < xo.size(); j++) {
		ll i = 31;
		ll x = xo[j];
		int st = 0;
		while (i >= 0) {
			ll d = x & (1ll << i);
			if (d == 0) {
				if (bohr[st].R == -1)st = bohr[st].L;
				else st = bohr[st].R;
			} else {
				if (bohr[st].L == -1)st = bohr[st].R;
				else st = bohr[st].L;
			}
			if (st == -1)break;
			for (auto v : bohr[st].leaf) {
				if (ans < (xo[v] ^ xo[j])) {
					ans = (xo[v] ^ xo[j]);
					t1 = v; t2 = j;
				}
			}
			i--;
		}
		if (ans < xo[j]) {
			ans = xo[j];
			t1 = 0; t2 = j;
		}
	}
	cout << t1 + 1 << ' ' << t2 + 1;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	solve();
	return 0;
}