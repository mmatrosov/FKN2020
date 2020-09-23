#include <bits/stdc++.h>

using namespace std;
using ui = unsigned int;

const int lg = 31;

struct node {
    node *l = NULL, *r = NULL;
    int num = -1;
};

node *root = new node();

void add(ui val, int i) {
    auto cur = root;
    for (int i = lg - 1; i >= 0; i--) {
        if ((val >> i) & 1) {
            if (!cur->r) cur->r = new node();
            cur = cur->r;
        }
        else {
            if (!cur->l) cur->l = new node();
            cur = cur->l;
        }
    }
    cur->num = i;
}

int find(ui val) {
    auto cur = root;
    for (int i = lg - 1; i >= 0; i--) {
        assert(cur);
        int bit = (val >> i) & 1;
        if (bit == 1 && cur->r) cur = cur->r;
        else if (bit == 0 && cur->l) cur = cur->l;
        else {
            if (cur->l) cur = cur->l;
            else cur = cur->r;
        }
    }
    return cur->num;
}

void dfs(int u, int p, vector<vector<pair<int, ui> > >& g, vector<ui>& a) {
    for (auto elem: g[u]) {
        if (elem.first != p) {
            a[elem.first] = a[u] ^ elem.second;
            dfs(elem.first, u, g, a);
        }
    }
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<ui> a(n);
    vector<vector<pair<int, ui> > > g(n);
	for (int i = 1; i < n; i++) {
		int u, v;
        ui w;
        cin >> u >> v >> w;
        u--, v--;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
	}
    dfs(0, -1, g, a);
    // for (int i = 0; i < n; i++) cout << a[i] << ' ';
    // cout << endl;
    ui ans = 0;
    int u = -1, v = -1;
    for (int i = 0; i < n; i++) {
        add(a[i], i);
        int j = find(~a[i]);
        if (ans <= (a[j] ^ a[i])) {
            ans = a[j] ^ a[i];
            u = i, v = j;
        }
    }
    //cout << ans << endl;
    cout << u + 1 << ' ' << v + 1 << endl;
	return 0;
}
