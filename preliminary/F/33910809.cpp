#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define eb emplace_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define int long long

using namespace std;
const int INF = 2e15;
const int MB = 20;
const int MOD = 1e9 + 7;

void solve() {
	int n, k;
	cin >> n >> k;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }

    vector<int> b, cnt;
    for (auto& p : mp) {
        if (!p.first) continue;
        b.push_back(p.first);
        cnt.push_back(p.second);
    }

    b.push_back(INF);
    cnt.push_back(0);
    reverse(all(b));
    reverse(all(cnt));
    int m = b.size();
    for (int i = 1; i < m; i++) cnt[i] += cnt[i - 1];

    vector<vector<int>> dp(k + 1, vector<int>(m, -INF));
    dp[0][0] = 0;
    vector<vector<int>> p(k + 1, vector<int>(m, -1));

    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < m; j++) {
            for (int c = j; c >= 0; c--) {
                int val = dp[i - 1][c] + (cnt[j] - cnt[c]) * b[j];
                if (val > dp[i][j]) {
                    dp[i][j] = val;
                    p[i][j] = c;
                }
            }
        }
    }
    
    vector<int> ans;
    int mx = -INF, q = -1, now = k;
    for (int i = 0; i < m; i++) {
        if (dp[k][i] > mx) {
            mx = dp[k][i];
            q = i;
        }
    }

    while (now) {
        ans.push_back(q);
        q = p[now][q];
        now--;
    }
    b[0] = 1e9;
    for (int i : ans) cout << b[i] << " ";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed;
    cout.precision(12);
    //srand(time(0));
    int t = 1;
    //int t;
    //cin >> t;
    while (t--) solve();
}