#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

signed main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	sort(a.begin(), a.end());
	vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
	vector<vector<int>> next(n + 1, vector<int>(k + 1, -1));
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 1; j <= k; j++) {
			for (int t = i + 1; t <= n; t++) {
				int W = dp[t][j - 1] + (t - i) * a[i];
				if (dp[i][j] < W) {
					dp[i][j] = W;
					next[i][j] = t;
				}
			}
		}
	}
	int rez = 0; int st = -1;
	for (int i = 0; i < n; i++) {
		if (rez < dp[i][k]) {
			rez = dp[i][k];
			st = i;
		}
	}
	vector<int> pick;
	while (st != -1 && k && st < n) {
		pick.push_back(a[st]);
		st = next[st][k];
		k--;
	}
	while (k--) {
		pick.push_back(1e9);
	}
	for (int &x : pick) {
		if (x == 0) {
			x = 1e9;
		}
	}
	sort(pick.begin(), pick.end());
	for (int x : pick) {
		cout << x << " ";
	}
}