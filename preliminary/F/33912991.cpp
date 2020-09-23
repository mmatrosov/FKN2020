// #define _GLIBCXX_DEBUG 	
 
#include  <bits/stdc++.h>
 
#define f first
#define s second
#define push push_back
#define pop pop_back
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
const int MAXN = 101;
const ll INF = ll(3e18) + 1;

int dp[MAXN][MAXN], p[MAXN][MAXN];

signed main() {
	#ifdef _GLIBCXX_DEBUG
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	int n, k;
	cin >> n >> k;
	vector <int> v(n);
	for (int &i: v) {
		cin >> i;
	}
	sort(all(v));
	for (int c = 0; c < n; ++c) {
		dp[c][0] = (n - c) * v[c];
	}
	for (int i = 1; i < k; ++i) {
		for (int c = 0; c < n; ++c) {
			for (int j = c; j < n; ++j) {
				if (dp[c][i] < dp[j][i - 1] + (j - c) * v[c]) {
					dp[c][i] = dp[j][i - 1] + (j - c) * v[c];
					p[c][i] = j;
				}
			}
		}
	}
	int ind = 0;
	for (int i = 0; i < n; ++i) {
		if (dp[ind][k - 1] < dp[i][k - 1]) {
			ind = i;
		}
	}
	for (int i = k - 1; i >= 0; --i) {
		cout << v[ind] << ' ';
		ind = p[ind][i];
	}
	return 0;
}