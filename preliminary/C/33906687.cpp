
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

int main () {
	srand(time(NULL));
	cout << fixed << setprecision(15);
	vector < int > a;
	int n;
	cin >> n;
	a.resize(n);
	fori(n) cin >> a[i];
	sort(all(a));
	vector < int > aa;
	aa.pb(a[0]);
	for (int i = 0; i < n - 1; i++) {
		if (a[i] == a[i + 1]) continue;
		else aa.pb(a[i + 1]);
	}
	n = aa.size();
	a = aa;
	aa.clear();
	map < int, int > ans;
	set < int > all;
	for (int i = 0; i < n; i++) {
		ans[a[i]] = i + 1;
		all.insert(a[i]);
	}
	int k;
	cin >> k;
	fori(k) {
		int x;
		cin >> x;
		auto it = all.lower_bound(x);
		if (it == all.begin()) {
			cout << 0 << "\n";
			continue;
		}
		it--;
		cout << ans[*it] << "\n";
	}
}