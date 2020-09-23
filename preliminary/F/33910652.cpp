#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<iomanip>
using namespace std;
typedef long long ll;


void solve() {
	int n, k; cin >> n >> k;
	vector<int>mas;
	for (int i = 0; i < n; i++) {
		int y; cin >> y;
		if (y != 0)mas.push_back(y);
	}
	if (mas.size() == 0) {
		for (int i = 1; i <= k; i++) {
			cout << i << ' ';
		}
		return;
	}
	n = mas.size();
	sort(mas.begin(), mas.end());
	vector<int>dp(n + 1, 0), dp1 = dp;
	vector<vector<int>>res(k, vector<int>(n+1, 0));
	vector<int>inds(n + 1, 0);
	for (int i = 0; i < k; i++) {
		for (int i = 0; i < n; i++) {
			int pl = 0, ind = i;
			for (int j = i + 1; j <= n; j++) {
				if ((j - i) * mas[i] + dp[j] > pl) {
					pl = (j - i) * mas[i] + dp[j];
					ind = j;
				}
			}
			inds[i] = ind;
			dp1[i] = pl;
		}
		res[i] = inds;
		dp = dp1;
	}
	int m = 0;
	for (int i = 0; i < n + 1; i++) {
		if (dp[m] < dp[i])m = i;
	}
	int u = k;
	while (u > 0 && m != n) {
		cout << mas[m] << ' ';
		m = res[u - 1][m];
		u--;
	}
	for (int i = 1; i <= u; i++) {
		cout << mas[n - 1] + i<<' ';
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	solve();
	return 0;
}