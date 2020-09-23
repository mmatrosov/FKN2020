// Bippolar disorder is very cool

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <set>

using namespace std;

typedef int64_t ll;
typedef long double ld;

vector<vector<pair<ll, ll>>> tree;
vector<ll> sum;

void dfs(ll v, ll p) {
    for (auto e : tree[v]) {
        if (e.first == p) {
            continue;
        }
        sum[e.first] = sum[v] ^ e.second;
        dfs(e.first, v);
    }
}

typedef struct Node* pNode;
struct Node {
    vector<pNode> next;

    Node() {
        next.resize(2, nullptr);
    }
};

void add(pNode root, ll x, ll level) {
    if (level == -1) {
        return;
    }
    ll id = (x >> level) & 1;
    if (root->next[id] == nullptr) {
        root->next[id] = new Node();
    }
    add(root->next[id], x, level - 1);
}

ll get(pNode root, ll x, ll level) {
    if (level == -1) {
        return 0;
    }
    ll id = ((x >> level) & 1) ^ 1;
    ll result;
    if (root->next[id] == nullptr) {
        result = get(root->next[id ^ 1], x, level - 1);
    } else {
        result = ((ll)1 << level) ^ get(root->next[id], x, level - 1);
    }
    return result;
}

int main() {
    ll n;
    cin >> n;
    tree.resize(n);
    sum.resize(n);
    for (ll i = 0; i < n - 1; ++i) {
        ll v, u, w;
        cin >> v >> u >> w;
        tree[v - 1].emplace_back(u - 1, w);
        tree[u - 1].emplace_back(v - 1, w);
    }
    dfs(0, 0);
    pNode root = new Node();
    for (ll i = 0; i < n; ++i) {
        add(root, sum[i], 33);
    }
    ll mx = -1;
    ll id = -1;
    for (ll i = 0; i < n; ++i) {
        ll local_mx = get(root, sum[i], 33);
        if (local_mx > mx) {
            mx = local_mx;
            id = i;
        }
    }
    ll id2 = id;
    for (ll i = 0; i < n; ++i) {
        if ((sum[id] ^ sum[id2]) < (sum[id] ^ sum[i])) {
            id2 = i;
        }
    }
    cout << id2 + 1 << " " << id + 1 << endl;
    return 0;
}
