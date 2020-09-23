#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <set>
#include <math.h>
#define ll long long
#define ld long double

using namespace std;

const int MAXN = 105;

ll dp[MAXN][MAXN];
ll pr[MAXN][MAXN];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	for (int i = 0; i <= k; i++)
		dp[0][i] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			dp[i][j] = 0;
			for (int i1 = 0; i1 < i; i1++) {
				ll val = dp[i1][j - 1] + a[i1] * (i - i1);
				if (val >= dp[i][j]) {
					dp[i][j] = val;
					pr[i][j] = i1;
				}
			}
		}
	}
	vector<ll> ans;
	ll i1 = n, j1 = k;
	while (i1 > 0 && j1 > 0) {
		if (a[pr[i1][j1]] == 0)
			break;
		ans.push_back(a[pr[i1][j1]]);
		i1 = pr[i1][j1];
		j1--;
	}
	reverse(ans.begin(), ans.end());
	ll mx = 0;
	if (ans.size() > 0)
		mx = ans[ans.size() - 1];
	while (ans.size() < k) {
		ans.push_back(mx + 1);
		mx += 1;
	}
	for (auto elem : ans)
		cout << elem << " ";
	cout << endl;
}
//*/