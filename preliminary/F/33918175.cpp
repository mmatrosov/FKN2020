#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <bitset>
#include <iomanip>

using namespace std;

typedef map<int, int> mp;
typedef vector<mp> vc;
typedef vector<char> vi;
typedef vector<unsigned long long> vll;
typedef long long ull;
typedef long long ll;
typedef pair<int, int> pr;

#define pb  push_back
#define ff  first
#define ss  second
#define sz	size()

const int NN = 500;
long long dp[NN][NN];
pr prv[NN][NN];
long long used[NN][NN];

int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n, k;
	cin >> n >> k;
	vector<long long> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	dp[1][1] = v[0];
	used[1][1] = v[0];
	prv[1][1] = { 0,0 };
	for (int i = 1; i <= k; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int l = 1; l <= j; ++l) {
				if (dp[i][j] < dp[i - 1][j - l] + l * v[j - 1]) {
					dp[i][j] = dp[i - 1][j - l] + l * v[j - 1];
					used[i][j] = v[j - 1];
					prv[i][j] = { i - 1, j - l };
				}
			}
			if (dp[i][j] < dp[i - 1][j]) {
				dp[i][j] = dp[i - 1][j];
				used[i][j] = 0;
				prv[i][j] = { i - 1, j };
			}
			if (dp[i][j] < dp[i][j - 1]) {
				dp[i][j] = dp[i][j - 1];
				used[i][j] = 0;
				prv[i][j] = { i, j - 1};
			}
		}
	}
	vector<long long> ans;
	int i1 = k, j1 = n;
	while (i1 * j1 > 0) {
		if (used[i1][j1])
			ans.push_back(used[i1][j1]);
		pr next = prv[i1][j1];
		i1 = next.ff;
		j1 = next.ss;
	}
	sort(ans.begin(), ans.end());
	for (long long p : ans) {
		cout << p << ' ';
	}
	for (int i = 0; i < k - (int)ans.size(); ++i) {
		cout << v[0] + i + 1 << ' ';
	}

	system("pause");
	return 0;
}