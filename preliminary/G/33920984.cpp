#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<vector<pair<int, ll>>> g;
vector<pair<ll, int>> v;
ll dist = -1;
int v1_ans, v2_ans;

void dfs(int cv, int pv, ll val) {
    v.emplace_back(val, cv);
    for (auto nv : g[cv]) {
        if (nv.first != pv) {
            dfs(nv.first, cv, val ^ nv.second);
        }
    }
}

int find_border(int l, int r, ll bit) {
    l--;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (v[mid].first & bit) {
            r = mid;
        } else {
            l = mid;
        }
    }
    return r;
}

void solve(int l1, int r1, int l2, int r2, ll bit) {
    bit /= 2;
    if (bit == 0) {
        ll cur_dist = (v[l1].first ^ v[l2].first);
        if (dist < cur_dist) {
            dist = cur_dist;
            v1_ans = v[l1].second + 1;
            v2_ans = v[l2].second + 1;
        }
        return;
    }
    int b1 = find_border(l1, r1, bit);
    int b2 = find_border(l2, r2, bit);
    if ((b1 == l1 && b2 == l2) || (b1 == r1 && b2 == r2)) {
        solve(l1, r1, l2, r2, bit);
    } else if (b1 == l1) {
        solve(b1, r1, l2, b2, bit);
    } else if (b1 == r1) {
        solve(l1, b1, b2, r2, bit);
    } else if (b2 == l2) {
        solve(l1, b1, b2, r2, bit);
    } else if (b2 == r2) {
        solve(b1, r1, l2, b2, bit);
    } else {
        solve(l1, b1, b2, r2, bit);
        solve(b1, r1, l2, b2, bit);
    }
}

int main() {
    int n;
    cin >> n;
    g.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        g[a - 1].emplace_back(b - 1, c);
        g[b - 1].emplace_back(a - 1, c);
    }
    dfs(0, 0, 0);
    sort(v.begin(), v.end());

    ll bit = (1ll << 31);
    int bord = find_border(0, n, 1ll << 31);
    while ((bord == 0 || bord == n) && bit > 0) {
        bit /= 2;
        bord = find_border(0, n, bit);
    }
    if (bit == 0) {
        cout << 1 << " " << 1 << endl;
        return 0;
    }

    solve(0, bord, bord, n, bit);

//    for (int i = 0; i < n; ++i) {
//        for (int j = i; j < n; ++j) {
//            ll cur = v[i].first ^ v[j].first;
//            if (cur > dist) {
//                dist = cur;
//                v1_ans = v[i].second + 1;
//                v2_ans = v[j].second + 1;
//            }
//        }
//    }
    cout << v1_ans << " " << v2_ans << endl;
}
