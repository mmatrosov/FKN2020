#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

const ll INF = 1e18;
const int MAXN = 105;
ll dp[MAXN][MAXN];
int par[MAXN][MAXN];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(20);

	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	if (k >= n) {
		vector<int> ans;
		for (int x : a) {
			ans.push_back(x);
		}
		for (int i = 0; i < k - n; ++i) {
			ans.push_back(10000000);
		}
		sort(all(ans));
		for (int x : ans) {
			cout << x << ' ';
		}
		return 0;
	}
	sort(rall(a));
	fill(&dp[0][0], &dp[0][0] + MAXN * MAXN, -INF);
	dp[0][0] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= k; ++j) {
			dp[i][j] = dp[i - 1][j];
			par[i][j] = -1;
			if (j != 0) {
				for (int i1 = 0; i1 < i; ++i1) {
					ll val = dp[i1][j - 1] + (i - i1) * a[i - 1];
					if (val > dp[i][j]) {
						dp[i][j] = val;
						par[i][j] = i1;
					}
				}
			}
		}
	}
	int cnt = k;
	int cur = n;
	vector<int> kek;
	while (cur != 0) {
		if (par[cur][cnt] == -1) {
			cur--;
		}
		else {
			kek.push_back(a[cur - 1]);
			cur = par[cur][cnt];
			cnt--;
		}
	}
	sort(all(kek));
	for (int x : kek) {
		cout << x << ' ';
	}
}