#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(aaa) aaa.begin(), aaa.end()

const int N = 105, INF = 1e9;
int a[N], dp[N][N], p[N][N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	n++;

	for (int i = 1; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);

	memset(dp, -1, sizeof(dp));

	k++;

	dp[0][0] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			if (dp[i][j] != -1) {
				for (int h = i + 1; h <= n; h++) {
					if (dp[h][j + 1] < dp[i][j] + (h - i) * a[i]) {
						dp[h][j + 1] = dp[i][j] + (h - i) * a[i];
						p[h][j + 1] = i;
					}
				}
			}
		}
	}

	int x = n, y = 0;
	for (int i = 0; i <= k; i++) {
		if (dp[n][i] > dp[n][y]) {
			y = i;
		}
	}

	vector<int> ans;

	while (y > 1) {
		ans.push_back(p[x][y]);
		x = p[x][y];
		y--;
	}

	sort(all(ans));

	for (const int &el : ans) {
		cout << a[el] << " ";
	}

	int add = k - ans.size() - 1;

	for (int i = add - 1; i >= 0; i--) {
		cout << INF - i << " ";
	}

	cout << "\n";

	return 0;
}