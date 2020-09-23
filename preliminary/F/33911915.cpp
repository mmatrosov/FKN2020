#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fast ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

ll INF = (ll) 1e20;
int iINF = (int) 1e20;
ll mod = (ll) 1e9 + 7;

mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());

ll n, m;
char tb[1000][1000];
vector<pair<ll, ll>> v;

void go(ll i, ll j, ll left) {
    if (tb[i][j] == '$')
        tb[i][j] = '@';
    v.push_back({i, j});
    --left;
    if (left == 0) {
        return;
    }
    if (j + 1 < m) {
        if (tb[i][j + 1] == '$') {
            go(i, j + 1, left);
            return;
        }
    }
    if (j - 1 >= 0) {
        if (tb[i][j - 1] == '$') {
            go(i, j - 1, left);
            return;
        }
    }
    if (i + 1 < n) {
        if (tb[i + 1][j] == '$') {
            go(i + 1, j, left);
            return;
        }
    }
}

char get(ll i, ll j) {
    if (i >= 0 && i < n && j >= 0 && j < m) {
        if (tb[i][j] == '@')
            return '$';
        return tb[i][j];
    }
    return '$';
}

signed main() {
    fast
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll dp[n + 1][k + 1][n];
    pair<ll, ll> p[n + 1][k + 1][n];
    fill(&dp[0][0][0], &dp[0][0][0] + (n + 1) * (k + 1) * n, 0);
    fill(&p[0][0][0], &p[0][0][0] + (n + 1) * (k + 1) * n, make_pair(-1, -1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= k; ++j) {
            for (int l = 0; l < i; ++l) {
                if (j < k) {
                    if (dp[i + 1][j + 1][i] < dp[i][j][l] + a[i]) {
                        dp[i + 1][j + 1][i] = max(dp[i + 1][j + 1][i], dp[i][j][l] + a[i]);
                        p[i + 1][j + 1][i] = {j, l};
                    }
                }
                if (j) {
                    if (dp[i + 1][j][l] < dp[i][j][l] + a[l]) {
                        dp[i + 1][j][l] = max(dp[i + 1][j][l], dp[i][j][l] + a[l]);
                        p[i + 1][j][l] = {j, l};
                    }
                }
            }
            if (dp[i + 1][1][i] < a[i]) {
                dp[i + 1][1][i] = max(dp[i + 1][1][i], a[i]);
                p[i + 1][1][i] = {1, i};
            }
        }
    }
    ll ans = -1;
    ll id, num, last;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            for (int l = 0; l < i; ++l) {
                if (dp[i][j][l] > ans) {
                    ans = dp[i][j][l];
                    id = i, num = j, last = l;
                }
            }
        }
    }
    set<ll> st;
    while (id >= 0) {
        if (num > 0) {
            st.insert(a[last]);
        }
        pair<ll, ll> x = p[id][num][last];
        num = x.first, last = x.second;
        --id;
    }
//    cout << ans << '\n';
    for (auto i : st) {
        cout << i << ' ';
    }
    ll now = 1000000;
    for(int i = 0; i < k - st.size(); ++i) {
        cout << now << ' ';
        ++now;
    }

}
