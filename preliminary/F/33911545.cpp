#include <iostream>
#include <cmath>
#include <array>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
#define prev prev1234
using namespace std;

const int N = 104;
int dp[N][N][N];
array<int, 3> prev[N][N][N];
int arr[N];
const int INF = 1e9;

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n + 1);
	/*cout << "arr: ";
	for (int i = 0; i <= n; i++) {
		cout << arr[i] << " ";
	} cout << endl;*/
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				prev[i][j][k] = {-1, -1, -1};
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			for (int lst = 0; lst < i; lst++) {
				if (j == k && lst != 0) {
					dp[i][j][lst] = -INF;
					continue;
				}
				dp[i][j][lst] = dp[i - 1][j][lst] + arr[lst];
				prev[i][j][lst] = {i - 1, j, lst};
			}
			if (j == k) continue;
			for (int pr = 0; pr < i; pr++) {
				int curr = dp[i - 1][j + 1][pr] + arr[i];
				if (curr >= dp[i][j][i]) {
					dp[i][j][i] = curr;
					prev[i][j][i] = {i - 1, j + 1, pr};
				}
			}
			//cout << "dp[" << i << "][" << j << "][" << i << "] " << dp[i][j][i] << endl;
			//cout << prev[i][j][i][2] << " " << dp[i - 1][j + 1][prev[i][j][i][2]]<< endl;
		}
	}
	
	int ans_j = 0;
	int ans_lst = 0;
	for (int j = 0; j < k; j++) {
		for (int lst = 0; lst <= n; lst++) {
			if (dp[n][ans_j][ans_lst] < dp[n][j][lst]) {
				ans_j = j;
				ans_lst = lst;
			}
		}
	}
	//cout << "total: " << dp[n][ans_j][ans_lst] << endl;
	vector<int> tars;
	
	int i = n;
	while (i > 0) {
		int nw_j = prev[i][ans_j][ans_lst][1];
		int nw_lst = prev[i][ans_j][ans_lst][2];
		if (nw_j == -1) break;
		if (nw_j != ans_j) {
			/*cout << "h0 " << i << " " << ans_j << " " << ans_lst << endl;
			cout << "hist " << i - 1<< " " << nw_j << " " << nw_lst << endl;
			cout << endl;*/
			if (arr[ans_lst] != 0) tars.push_back(arr[ans_lst]);
		}
		ans_j = nw_j;
		ans_lst = nw_lst;
		i--;
	}
	
	int mx = 1e9;
	while (tars.size() < k) {
		tars.push_back(mx--);
	}
	
	sort(tars.begin(), tars.end());
	for (auto el: tars) cout << el << " ";
	cout << endl;
	return 0;
}