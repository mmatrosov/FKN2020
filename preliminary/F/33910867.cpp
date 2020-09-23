#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#pragma optimizitaion_level 3
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <bitset>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <unordered_map>
#include <tuple>
#include <cmath>
#include <functional>
#include <algorithm>
#include <set>
#include <cassert>
#include <deque>
#include <unordered_set>
#include <numeric>
using namespace std;
#define kekek ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

struct node {
	int cnt, l, r;
};

int mx = 100001;

signed main() {
	kekek;

	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (auto& i : a) {
		cin >> i;
	}
	a.push_back(0);
	sort(a.begin(), a.end());

	if (n <= k) {
		for (int i = 1; i <= n; i++) {
			cout << a[i] << " ";
		}
		for (int i = 0; i < k - n; i++) {
			cout << mx << " ";
			mx++;
		}
	}
	else {
		vector<vector<vector<int>>> dp(k + 2, vector<vector<int>>(n + 1, vector<int>(n + 1, -1)));
		vector<vector<vector<node>>> p(k + 2, vector<vector<node>>(n + 1, vector<node>(n + 1)));

		dp[0][0][0] = 0;
		for (int R = 0; R < n; R++) {
			for (int cnt = 0; cnt <= min(R, k); cnt++) {
				for (int L = 0; L <= R; L++) {
					if (dp[cnt][L][R] != -1) {
						if (dp[cnt][L][R + 1] < dp[cnt][L][R] + a[L]) {
							dp[cnt][L][R + 1] = dp[cnt][L][R] + a[L];
							p[cnt][L][R + 1] = { cnt, L, R };
						}

						if (cnt != k && dp[cnt + 1][R + 1][R + 1] < dp[cnt][L][R] + a[R + 1]) {
							dp[cnt + 1][R + 1][R + 1] = dp[cnt][L][R] + a[R + 1];
							p[cnt + 1][R + 1][R + 1] = { cnt, L, R };
						}
					}
				}
			}
		}

		/*
		for (int cnt = 0; cnt <= k; cnt++) {
			for (int L = 0; L <= n; L++) {
				for (int R = 0; R <= n; R++) {
					cout << "cnt = " << cnt << " L = " << L << " R = " << R << " dp = " << dp[cnt][L][R] << '\n';
				}
			}
		}
		*/

		int best_L = 0;
		for (int L = 1; L <= n; L++) {
			if (dp[k][L][n] > dp[k][best_L][n]) {
				best_L = L;
			}
		}

		//cout << dp[k][best_L][n];
		vector<int> ans;
		int cnt = k, L = best_L, R = n;
		while (cnt >= 1) {
			node par = p[cnt][L][R];
			if (par.cnt != cnt) {
				if (a[L] != 0) {
					ans.push_back(a[L]);
				}
				else ans.push_back(mx++);
			}
			cnt = par.cnt;
			L = par.l;
			R = par.r;
		}
		sort(ans.begin(), ans.end());
		for (auto i : ans) {
			cout << i << " ";
		}
	}

	return 0;
}