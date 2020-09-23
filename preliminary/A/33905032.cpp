#include<bits/stdc++.h>

#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")

using namespace std;

typedef long long ll;
typedef long double ld;


void solve() {
	int k;
	cin >> k;
	if (k == 1) {
		cout << "YES\n";
		return;
	}
	for (int sq = 1; sq <= k; ++sq) {
		ll have = sq * 4 - 4;
		if (have == k) {
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}