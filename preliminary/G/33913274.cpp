#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define F first
#define S second
#define pb push_back
mt19937 rnd;

struct Edge {
    int to;
    ll w;
};

const int N = 1e5 + 10;
int n;
vector<Edge> g[N];
ll a[N];
int tpos[N], vpos[N];
int sub[N], out[N][2];
int sz = 1;
map<ll, int> mem;

void dfs(int v, int p) {
	for (Edge e : g[v]) {
        if (e.to != p) {
            a[e.to] = a[v] ^ e.w;
            dfs(e.to, v);
        }
	}
}

int add_node() {
	sub[sz] = 0;
	return sz++;
}

bool getBit(ll mask, int bit) {
    return mask & (1ll << bit);
}

void push(int bit) {
	sz = 0;
	for (int i = 1; i <= n; i++) {
        int d = getBit(a[i], bit);
		if (out[vpos[i]][d] == -1) {
            out[vpos[i]][d] = add_node();
		}
		vpos[i] = out[vpos[i]][d];
		++sub[vpos[i]];
	}
}

ll get(ll x, int bit) {
	ll res = 0;
	for (int i = 1; i <= n; i++) {
		int d = getBit(x, bit) != getBit(a[i], bit);
		if (tpos[i] != -1 && out[tpos[i]][d] != -1) {
			res += sub[out[tpos[i]][d]];
		}
	}
	return res;
}

void add(ll x, int bit) {
    for (int i = 1; i <= n; i++) {
		int d = getBit(x, bit) != getBit(a[i], bit);
		if (tpos[i] != -1) {
			tpos[i] = out[tpos[i]][d];
		}
	}
	for (int i = 0; i < sz; i++) {
        out[i][0] = out[i][1] = -1;
	}
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    out[0][0] = out[0][1] = -1;
    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
	dfs(1, 1);
	for (int i = 1; i <= n; i++) {
        mem[a[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
        g[i].clear();
	}
	ll k = 1ll * n * n - 1;
	sub[0] = n;
	ll ans = 0;
	for (int bit = 35; bit >= 0; bit--) {
		push(bit);
		ll cur = get(ans, bit);
		if(cur <= k) {
			k -= cur;
			ans |= (1ll << bit);
		}
		add(ans, bit);
	}
	for (int i = 1; i <= n; i++) {
        if (mem.count(a[i] ^ ans)) {
            cout << i << " " << mem[a[i] ^ ans] << "\n";
            break;
        }
	}

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
