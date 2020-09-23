#include <iostream>
#include <set>
#include <map>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <deque>
#include <stack>
#include <climits>
#include <math.h>
#include <cassert>
#include <unordered_map>
#include <chrono>
#include <random>
#include <ctime>
#include <complex>
using namespace std;
#pragma warning(disable : 4996)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ld PI = acosl(-1.0);
const ll MOD = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());



int main() {
#ifdef _DEBUG
	freopen("input1.txt", "r", stdin);
	freopen("output2.txt", "w", stdout);
#endif
	srand(time(0));
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++)cin >> a[i];
	sort(a.begin(), a.end());
	vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT32_MIN)), pred(n + 1, vector<int>(k + 1, -1));
	dp[0][0] = 0;
	for (int i = 0; i <= n; i++)dp[i][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			for (int pr = i; pr >= 1; pr--) {
				if (dp[pr - 1][j - 1] != INT32_MIN) {
					int val = dp[pr - 1][j - 1] + (i - pr + 1) * a[pr - 1];
					if (val > dp[i][j]) {
						dp[i][j] = val;
						pred[i][j] = pr - 1;
					}
				}
			}
		}
	}
	int bi = 0, mv = -1;
	for (int i = 0; i <= k; i++) {
		if (dp[n][i] > mv) {
			mv = dp[n][i];
			bi = i;
		}
	}
	vector<int> ans;
	for (int i = pred[n][bi]; i != -1; i = pred[i][bi]) {
		bi--;
		ans.push_back(a[i]);
	}
	reverse(ans.begin(), ans.end());
	for (auto i : ans) {
		cout << i << " ";
	}
	if (ans.size()) {
		for (int i = 0; i < k - ans.size(); i++) {
			cout << ans.back() + i + 1 << " ";
		}
	}
	else {
		for (int i = 1; i <= k; i++)cout << i << " ";
	}
}