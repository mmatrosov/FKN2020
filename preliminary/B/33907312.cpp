#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int k1, b1, k2, b2;
	cin >> k1 >> b1 >> k2 >> b2;
	if (k1 == k2 && b1 == b2) {
		cout << "coincide";
	} else if (k1 == k2) {
		cout << "parallel";
	} else {
		cout << "intersect\n";
		long double x = (long double)(b1 - b2) / (k2 - k1);
		long double y = k1 * x + b1;
		cout << fixed << setprecision(30) << x << ' ' << y;
	}
	return 0;
}
