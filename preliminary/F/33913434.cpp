#include <bits/stdc++.h>
#define fori(n) for (int i = 0; i < n; i++)
#define forj(n) for (int j = 0; j < n; j++)
#define pb push_back
#define ff first
#define ss second
#define all(v) v.begin(), v.end()
typedef long long ll;
#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector", "fast-math", "O3")
//#pragma GCC target("avx2")
using namespace std;

vector < pair < int, int > > a;
int getcnt(int x1, int x2) {
	int cnt = 0;
	for (int i = x1; i <= x2; i++) cnt += a[i].ss;
	return cnt;
}
int main () {
	cout << fixed << setprecision(20);
	srand(time(NULL));
	int n, k;
	cin >> n >> k;
	vector < int > aa;
	aa.resize(n);
	fori(n) cin >> aa[i];
	sort(all(aa));
	if (aa.back() == 0) {
		fori(k) cout << i + 1 << " ";
		return 0;
	}
	reverse(all(aa));
	while (true) {
		if (aa.back() == 0) {
			aa.pop_back();
			n--;
		} else break;
	}
	reverse(all(aa));
	a.pb({aa[0], 1});
	for (int i = 1; i < n; i++) {
		if (aa[i] == aa[i - 1]) {
			a[a.size() - 1].ss++;
		} else {
			a.pb({aa[i], 1});
		}
	}

	if (a.size() <= k) {
		fori(a.size()) cout << a[i].ff << " ";
		fori(k - a.size()) cout << a.back().ff + i + 1 << " ";
		return 0;
	}
	vector < vector < int > > dp;
	vector < vector < pair < int, int > > > where;
	n = a.size();
	dp.resize(n + 1);
	fori(n + 1) {
		dp[i].resize(k + 1);
	}
	

//	cout << "vector a size = " << a.size() << endl;
//	fori(n) cout << a[i].ff << " " << a[i].ss << endl;
//	cout << endl;


	where.resize(n + 1);
	fori(n) where[i].resize(k + 1);
	for (int i = n - 1; i >= 0; i--) {
		dp[i][1] = getcnt(i, n - 1) * a[i].ff;
		for (int j = 1; j <= k; j++) {
			for (int i1 = i; i1 < n; i1++) {
				if (dp[i1 + 1][j] > dp[i][j]) {
					where[i][j] = {i1 + 1, j};
					dp[i][j] = dp[i1 + 1][j];
				}
				int cursum = dp[i1 + 1][j - 1] + getcnt(i, i1) * a[i].ff;
				if (cursum > dp[i][j]) {
					where[i][j] = {i1 + 1, j - 1};
					dp[i][j] = cursum;
				}
			}
		}
	}
	vector < int > ans;
	int curi = 0, curj = k;
	while(true) {
	//	cout << curi << " " << curj << endl;
		if (curj == 0) break;
		int x = where[curi][curj].ff;
		int y = where[curi][curj].ss;
		if (curj != y) {
			ans.pb(a[curi].ff);
		}
		curi = x;
		curj = y;
	}
	//cout << "\n";
	fori(ans.size()) cout << ans[i] << " ";
// dp[i][j] - сколько максимум наберешь, 
// если тебе заплатили все чуваки >= i и ты взял j тарифов
}