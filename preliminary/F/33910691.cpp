#include<bits/stdc++.h>

#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 105;

int n, k;
int a[MAXN];
ll dp[MAXN][MAXN];
int par[MAXN][MAXN];

void solve() {
	cin >> n >> k;
	int orig = k;	k = min(k, n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i <= n; ++i) for (int j = 0; j <= n; ++j) par[i][j] = -1;
	sort(a, a + n);
	dp[0][0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 1; j <= k; ++j) {
			int qty = 0;
			if (i != 0) {
				dp[i][j] = dp[i - 1][j];
				par[i][j] = par[i - 1][j];
			}
			for (int rightbound = i; rightbound >= 0; --rightbound) {
				++qty;
				ll cost = a[rightbound] * 1ll * qty;
				if (rightbound - 1 >= 0) cost += dp[rightbound - 1][j - 1];
				if (dp[i][j] <= cost) {
					dp[i][j] = cost;
					par[i][j] = rightbound;
				}
			}
		}
	}
	//cout << "cost: " << dp[n - 1][k] << "\n";
	int take = k, last = n - 1;
	vector<int> costs;
	while (take != 0 && last >= 0) {
		int p = par[last][take];
		if (p < 0) break;
		costs.push_back(a[p]);
		last = p - 1;
		--take;
	}
	reverse(costs.begin(), costs.end());
	while (int(costs.size()) < orig) costs.push_back(costs.back() + 1);
	for (auto val : costs) cout << val << ' ';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}