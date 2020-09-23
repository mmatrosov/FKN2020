#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ll long long
#define all(aaa) aaa.begin(), aaa.end()

struct E {
	int to;
	ll w;
};

const int N = 1e5 + 5, B = 35, V = N * B;
vector<E> g[N];
ll h[N];
int to[V][2], num[V];

void dfs(int node, int anc) {
	for (const E &e : g[node]) {
		if (e.to != anc) {
			h[e.to] = (h[node] ^ e.w);
			dfs(e.to, node);
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int x, y;
		ll w;
		cin >> x >> y >> w;
		x--, y--;
		g[x].push_back({y, w});
		g[y].push_back({x, w});
	}

	dfs(0, -1);

	memset(to, -1, sizeof(to));

	int cv = 1;

	int ans = -1, p = 0, q = 0;

	for (int i = 0; i < n; i++) {
		if (i != 0) {
			int v = 0;
			ll cur = 0;
			for (int j = B - 1; j >= 0; j--) {
				int c = ((h[i] >> j) & 1);

				for (int k = 1; k >= 0; k--) {
					if (to[v][c ^ k] != -1) {
						v = to[v][c ^ k];
						if (k)
							cur |= (1ll << j);
						break;
					}
				}
			}

			if (cur > ans) {
				ans = cur;
				p = i;
				q = num[v];
			}
		}

		int v = 0;
		for (int j = B - 1; j >= 0; j--) {
			int c = ((h[i] >> j) & 1);
			if (to[v][c] == -1) {
				to[v][c] = cv++;
			}
			v = to[v][c];
		}
		num[v] = i;
	}

	cout << p + 1 << " " << q + 1 << "\n";

	return 0;
}