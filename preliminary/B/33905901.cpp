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

	int k1, b1, k2, b2;
	cin >> k1 >> b1 >> k2 >> b2;
	if (k1 == k2) {
		if (b1 == b2) {
			cout << "coincide\n";
		}
		else {
			cout << "parallel\n";
		}
	}
	else {
		cout << "intersect\n";
		ld x = (b2 - b1) / 1. / (k1 - k2);
		ld y = k1 * x + b1;
		cout << x << ' ' << y << '\n';
	}
}