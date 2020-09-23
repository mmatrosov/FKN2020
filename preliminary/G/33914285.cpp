#include <iostream>
#include <vector>
const int N = 1e5;

std::vector<std::pair<int, unsigned int>> g[N];
int p[N], x[N];

void dfs(int v, int p = -1, unsigned int edge_val = 0) {
    ::p[v] = p, x[v] = v ? x[p] ^ edge_val : 0;
    for (std::pair<int, int> u: g[v])
        if (u.first != p)
            dfs(u.first, v, u.second);
}

struct node {
    int id;
    node *go[2] = {nullptr, nullptr};
    void add(int son) {
        go[son] = new node;
    }
};

int main()
{
    int n;
    std::cin >> n;
    for (int i = 1; i < n; ++i) {
        int a, b;
        unsigned int x;
        std::cin >> a >> b >> x;
        g[--a].emplace_back(--b, x);
        g[b].emplace_back(a, x);
    }
    dfs(0);
    node *root = new node;
    for (int i = 0; i < n; ++i) {
        node *v = root;
        for (int j = 31; j >= 0; --j) {
            int bit = x[i] >> j & 1;
            if (!v->go[bit])
                v->add(bit);
            v = v->go[bit];
        }
        v->id = i;
    }
    unsigned int ma = 0, mi, mj;
    for (int i = 0; i < n; ++i) {
        node *v = root;
        for (int j = 31; j >= 0; --j) {
            int bit = x[i] >> j & 1;
            v = v->go[v->go[!bit] ? !bit : bit];
        }
        if ((x[i] ^ x[v->id]) >= ma)
            ma = x[i] ^ x[v->id], mi = i, mj = v->id;
    }
    std::cout << mi + 1 << ' ' << mj + 1;
    return 0;
}
