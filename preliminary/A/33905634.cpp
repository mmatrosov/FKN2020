#include <iostream>
using namespace std;

int main() {
	int k;
	cin >> k;
	if (k == 1) {
		cout << "YES";
		return 0;
	}
	for (int n = 1; n <= 100000; n++) {
		if ((n - 1) * 4 == k) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}
