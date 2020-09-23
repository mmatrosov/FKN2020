#include <bits/stdc++.h>
#define int long long
#define to first
#define wt second
using namespace std;

const int N = 1.1e5;
vector<pair<int, int>> g[N];
vector<pair<int, int>> xors;

struct node {
    int sz;
    node * zero = 0, * one = 0;
    node(): sz(1) {};
};

typedef node* pnode;

void add(pnode root, int x, int i) {
    root->sz++;
    if (!i) return;
    int ch = (x >> i - 1 & 1);
    if (ch) {
        if (!root->one) root->one = new node(), root->one->sz--;
        add(root->one, x, i - 1);
    }
    else {
        if (!root->zero) root->zero = new node(), root->zero->sz--;
        add(root->zero, x, i - 1);
    }
}

int qr(pnode root, int x, int i) {
    if (!i) {
        return 0;
    }
    int r = x >> i - 1 & 1;
    if (r) {
        if (root->zero && root->zero->sz) return qr(root->zero, x, i - 1) ^ (1ll << i - 1);
        else return qr(root->one, x, i - 1);
    }
    if (!r) {
        if (root->one && root->one->sz) return qr(root->one, x, i - 1) ^ (1ll << i - 1);
        else return qr(root->zero, x, i - 1);
    }
}

void dfs(int v, int cx, int from = 0) {
    xors.push_back({cx, v});
    for (auto i : g[v]) {
        if (i.to == from) continue;
        dfs(i.to, cx ^ i.wt, v);
    }
}

map<int, int> M;

signed main() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    dfs(1, 0);
    pnode root = new node();
    add(root, 0, 35);
    int mx = 0, bu = 1, bv = 1;
    for (int i = 0; i < n; i++) {
        int t = qr(root, xors[i].first, 35);
        if (t > mx) mx = t, bu = xors[i].second, bv = M[t ^ xors[i].first];
        add(root, xors[i].first, 35);
        M[xors[i].first] = xors[i].second;
    }
    cout << bu << " " << bv;
}
