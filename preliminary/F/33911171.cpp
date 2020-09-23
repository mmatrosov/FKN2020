#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("O3")

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define double long double
#define _ << ' ' <<
#define For(i,z) for(int i=0;i<int32_t(z);++i)
#define printObj(a) {for (auto &i : a) cout << i << ' '; cout << '\n';}
#define sqr(a) ((a)*(a))

#define pii pair<int, int>
#define pdd pair<double, double>
#define x first
#define y second

template<typename T>
using orset = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T, typename K>
using ormap = tree <T, K, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T, typename K> inline void umax(T &a, K b) { a = max(a, (T)b); }
template<typename T, typename K> inline void umin(T &a, K b) { a = min(a, (T)b); }
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int32_t N = 3e2 + 10;
const int64_t INF = 1e16;
const pair<int64_t, int64_t> PINF = make_pair(INF, INF);
const double EPS = 1e-7;
const int MOD = 1e9 + 7;
const int II = 1e9 + 10;
const int64_t AMOD = 99194853094755497;
const double PI = 3.14159265359;

int n, k;
int a[N];
int dp[N][N];
pii p[N][N];

int32_t main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

	cin >> n >> k;

	For (i, n) cin >> a[i];

	sort(a, a + n);

	fill(*dp, *dp + N * N, 0);
	fill(*p, *p + N * N, make_pair(-1, -1));
	dp[0][0] = 0;

	For (i, n)
		For (j, k) {
			for (int z = i + 1; z <= n; ++z) {
				int nval = dp[i][j] + (z - i) * a[i];
				if (dp[z][j + 1] < nval)
				{
					dp[z][j + 1] = nval;
					p[z][j + 1] = { i, j };
				}
			}
		}

	pii cur = {n, k};
	vector<int> ans;
	while (cur.x != -1) {
		cur = p[cur.x][cur.y];
		if (cur.x != -1)
			ans.push_back(a[cur.x]);
	}
	sort(ans.begin(), ans.end());
	if (k && ans.empty()) ans.push_back(1);
	while (ans.size() < k) ans.push_back(ans.back() + 1);

	sort(ans.begin(), ans.end());
	for (auto it : ans)
		cout << it << " ";
}
