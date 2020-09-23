#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

signed main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int x; cin >> x;
		cout << lower_bound(v.begin(), v.end(), x) - v.begin() << "\n";
	}
}