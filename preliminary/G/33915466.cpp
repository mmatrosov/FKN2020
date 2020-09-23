#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define int long long
const int N = 1e5 + 20;

struct node {
    node *g[2];
    int v;
};
const int MEM = 4e6;
node mem[MEM];
int _ptr = 0;
node *new_node() {
    mem[_ptr].v = -1;
    return mem + _ptr++;
}

vector<pair<int, int>> g[N];
int pf[N];
const int L = 32;
void add(node *root, int v, int x) {
    for (int i = L; i >= 0; --i) {
        int z = ((x >> i) & 1LL);
        if (root->g[z] == nullptr) {
            root->g[z] = new_node();
        }
        root = root->g[z];
    }
    root->v = v;
}
int find(node *root, int x) {
    for (int i = L; i >= 0; --i) {
        int z = ((x >> i) & 1L);
        if (root->g[1 - z] != nullptr) {
            z = 1 - z;
        }
        root = root->g[z];
    }
    return root->v;
}
int A = 1, B = 1;
void dfs(int v, int pr, int x) {
    pf[v] = x;
    add(mem, v, pf[v]);
    int u = find(mem, x);
    if ((pf[u] ^ pf[v]) > (pf[A] ^ pf[B])) {
        A = u, B = v;
    }
    for (auto [i, c] : g[v]) {
        if (i != pr) {
            dfs(i, v, x ^ c);
        }
    }
}
signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    node *root = new_node();
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }
    dfs(1, 0, 0);
    cout << A << " " << B;
}
