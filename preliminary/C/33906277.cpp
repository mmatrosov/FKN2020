#include<bits/stdc++.h>

#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 1e5 + 5;

int n, k;
vector<int> a;

void solve() {
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a.begin(), a.end());
	a.resize(int(unique(a.begin(), a.end()) - a.begin()));
	cin >> k;
	while (k--) {
		int p;
		cin >> p;
		int ind = int(lower_bound(a.begin(), a.end(), p) - a.begin());
		cout << ind << "\n";
	}
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}