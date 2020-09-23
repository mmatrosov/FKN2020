#include <iostream>

using namespace std;

signed main() {
	int k;
	cin >> k;
	if (k == 1) {
		cout << "YES" << endl;
		return 0;
	}
	for (int n = 2; n <= 1e7; n++) {
		if (4 * n - 4 == k) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
}