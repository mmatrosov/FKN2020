#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#define pb emplace_back
#define sz(x) (int)x.size()
#define ll long long
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define ve vector
#define fi first
#define se second

using namespace std;
const int INF = 1000000000;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, k;
	cin >> n >> k;
	vi ar(n);
	for (auto &i : ar) cin >> i;
	sort(all(ar));
	reverse(all(ar));
	vvi dp(n, vi(k, -1));
	ve<ve<pii>> fat(n, ve<pii>(k));
	pair<int, pii> mx = {-1, {-1, -1}};
	for (int i = 0; i < n; ++i) {
		dp[i][0] = ar[i] * (i + 1);
		fat[i][0] = {-1, -1};
		for (int uz = 1; uz < k; ++uz) {
			for (int la = 0; la < i; ++la) {
				if (dp[i][uz] < dp[la][uz - 1] + ar[i] * (i - la)) {
					fat[i][uz] = {la, uz - 1};
					dp[i][uz] = dp[la][uz - 1] + ar[i] * (i - la);
				}
			}
			mx = max(mx, {dp[i][uz], {i, uz}});
		}
		mx = max(mx, {dp[i][0], {i, 0}});
	}
	pii crmx = mx.se;
	int la = 0;
	if (crmx.se < k - 1) for (int i = 0; i < (k - 1 - crmx.se); ++i) {
		cout << ++la << ' ';
	}
	while (crmx.fi != -1) {
		cout << max(la + 1, ar[crmx.fi]) << ' ';
		la = max(la + 1, ar[crmx.fi]);
		crmx = fat[crmx.fi][crmx.se];
	}
	cout << endl;
	return 0;
}