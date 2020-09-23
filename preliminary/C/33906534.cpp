#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(20);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(all(a));
	a.resize(unique(all(a)) - a.begin());
	int q;
	cin >> q;
	while (q--) {
		int x;
		cin >> x;
		int cnt = lower_bound(all(a), x) - a.begin();
		cout << cnt << '\n';
	}
}