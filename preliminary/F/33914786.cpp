#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<random>
#include<set>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	long long n, k;
	cin >> n >> k;
	vector<long long> m(n);
	for (int i = 0; i < n; i++) {
		cin >> m[i];
	}
	sort(m.begin(), m.end());
	long long ans = 0;
	vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));
	vector<vector<pair<int, int>>> dp1(n + 1, vector<pair<int,int>>(k + 1, { 0,0 }));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			for (int e = i + 1; e <= n; e++) {
				if (dp[i][j] + (e - i)*m[i] > dp[e][j + 1]) {
					dp[e][j + 1] = max(dp[e][j + 1], dp[i][j] + (e - i)*m[i]);
					dp1[e][j + 1] = { i,j };
				}
				ans = max(ans, dp[e][j + 1]);
			}
		}
	}
	long long l=0, r=0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			if (dp[i][j] == ans) {
				l = i;
				r = j;
			}
		}
	}
	set<long long> ansm;
	while (dp1[l][r].first < l && ansm.size()<k) {
		if (m[dp1[l][r].first] > 0) {
			ansm.insert(m[dp1[l][r].first]);
		}
		long long l1 = l;
		l = dp1[l][r].first;
		r = dp1[l1][r].second;
	}
	long long h = 1e8;
	while (ansm.size() < k) {
		ansm.insert(h);
		h--;
	}
	for (auto i : ansm) {
		cout << i << ' ';
	}
	system("pause");
}