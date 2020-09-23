#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define sh cin.tie(0); cin.sync_with_stdio(0); cout.tie(0);
#define FILE freopen("test.in", "r", stdin);
#define vprint(v) for (int ii = 0; ii < v.size(); ii++){cout << v[ii] << " ";}
#define debugv(v) if (v.size() != 0) {cout << "[ "; for (int __ = 0; __ < (int)(v.size()) - 1; __++){cout << v[__] << ", ";} cout << v[(int)(v.size()) - 1] << " ]" << endl;} else {cout << "[]" << endl;}
#define debug cout << "-----------------------------------------------" << endl;
#define print1(a) cout << "{ " << a << " }" << endl;
#define print2(a, b) cout << "{ " << a << ", " << b << " }" << endl;
#define print3(a, b, c) cout << "{ " << a << ", " << b << ", " << c << " }" << endl;
#define print4(a, b, c, d) cout << "{ " << a << ", " << b << ", " << c << ", " << d << " }" << endl;
using namespace std;
#define int long long
const int INF = 1e9 + 228;
const int MAXN = 122;
 
int dp[MAXN][MAXN][2];
struct e
{
	int now, cnt, id;
};
e par[MAXN][MAXN][2];
signed main()
{
#ifdef LOCAL
    FILE;
#endif
    sh;
	int n, k;
	cin >> n >> k;
	vector<int> v;
	vector<int> p;
	for (int i = 0; i < n; i++) {
		int aa;
		cin >> aa;
		if (aa > 0) {
			v.pb(aa);
		}
		p.pb(aa);
	}    
	sort(all(v));
	sort(all(p));
	v.erase(unique(all(v)), v.end());
	if (v.size() == 0) {
		for (int i = 0; i < k; i++) {
			cout << 1 << ' ';
		}
		return 0;
	}
	int m = n;
	n = v.size();
	int ans1 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= k; j++){ 
			for (int t = 0; t < 2; t++) {
				par[i][j][t] = {-1, -1, -1};
			}
		}
	}
	dp[0][1][1] = (m - (lower_bound(all(p), v[0]) - p.begin())) * v[0];
	//print1(dp[0][1][1]);
	dp[0][0][0] = 0;
	for (int i = 1; i < n; i++) {
		for (int count = 0; count <= k; count++) {
			if (dp[i - 1][count][1] > dp[i - 1][count][0]) {
				par[i][count][0] = {i - 1, count, 1};
			} else {
				par[i][count][0] = {i - 1, count, 0};
			}
			dp[i][count][0] = max(dp[i - 1][count][1], dp[i - 1][count][0]);
			if (count == 0)
				continue;
			dp[i][count][1] = (m - (lower_bound(all(p), v[i]) - p.begin())) * v[i];
			par[i][count][1] = {-1, -1, -1};
			for (int last = 0; last < i; last++) {
				int offset = v[i] - v[last];
				offset *= (m - (lower_bound(all(p), v[i]) - p.begin()));
				if (dp[i][count][1] < dp[last][count - 1][1] + offset) {
					par[i][count][1] = {last, count - 1, 1};
				}
				dp[i][count][1] = max(dp[i][count][1], dp[last][count - 1][1] + offset);
			}
			//print3(i, count, dp[i][count][1]);
		}
	}
	e best = {-1, -1, -1};
	for (int i = 0; i < n; i++) {
		for (int count = 0; count <= k; count++) {
			for (int t = 0; t < 2; t++) {
				if (dp[i][count][t] > ans1) {
					best = {i, count, t};
					ans1 = dp[i][count][t];
				}
			}
			//ans = max(ans, max(dp[i][count][1], dp[i][count][0]));
		}
	}
	//cout << ans1 << endl;
	vector<int> ans;
	while (best.now != -1) {
		ans.pb(v[best.now]);
		best = par[best.now][best.cnt][best.id];
	}
	while (ans.size() < k) {
		ans.pb(1);
	}
	sort(all(ans));
	for (auto to : ans) {
		cout << to << ' ';
	}
    return 0;
}
