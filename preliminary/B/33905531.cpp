#include<bits/stdc++.h>

#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")

using namespace std;

typedef long long ll;
typedef long double ld;


void solve() {
	ll k1, m1, k2, m2;
	cin >> k1 >> m1 >> k2 >> m2;
	if (k1 == k2 && m1 == m2) {
		cout << "coincide\n";
		return;
	}
	if (k1 == k2) {
		cout << "parallel\n";
		return;
	}
	cout << "intersect\n";
	ld point = m2 - m1; point /= (k1 - k2);
	ld y = k1 * point + m1;
	cout.precision(20);
	cout << point << ' ' << y << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}