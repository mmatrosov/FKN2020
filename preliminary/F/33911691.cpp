#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int SZ = 2e2 + 10;

int n, k;
vector<int> vect;

int dp[SZ][SZ];
int pr[SZ][SZ];

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		vect.push_back(x);
	}
	sort(vect.begin(), vect.end());
	for (int i = 0; i < n; i++) {
		for (int now = 0; now <= k; now++) {
			dp[i][now] = 0;
			pr[i][now] = -1;
			if (now == 0)
				continue;
			for (int j = 0; j <= i; j++) {
				int res_now = (i - j + 1) * vect[j];
				if (j > 0)
					res_now += dp[j - 1][now - 1];
				if (dp[i][now] < res_now) {
					dp[i][now] = res_now;
					pr[i][now] = j - 1;
				}
			}
		}
	}

	/*
	for (int i = 0; i < n; i++) {
		for (int now = 0; now <= k; now++)
			cout << dp[i][now] << ' ';
		cout << endl;
	}
	*/


	int res_i = 0, res_k = 0;
	for (int i = 0; i < n; i++) {
		for (int now = 0; now <= k; now++) {
			if (dp[i][now] > dp[res_i][res_k]) {
				res_i = i;
				res_k = now;
			}
		}
	}
	vector<int> ans;
	while (res_k > 0) {
//		cout << res_i << ' ' << res_k << endl;
		int j = pr[res_i][res_k] + 1;
		ans.push_back(vect[j]);
		res_i = j - 1;
		res_k--;
	}
	for (int i = ans.size() - 1; i >= 0; i--)
		cout << ans[i] << ' ';
	for (int i = 0; i < k - ans.size(); i++)
		cout << 1000000 + i << ' ';
	return 0;
}
