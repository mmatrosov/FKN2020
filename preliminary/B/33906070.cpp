#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<random>
#include<set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	long long k1, k2, b1, b2;
	cin >> k1 >> b1 >> k2 >> b2;
	if (k1 == k2) {
		if (b1 == b2) {
			cout << "coincide";
		}
		else {
			cout << "parallel";
		}
	}
	else {
		cout.precision(10);
		cout << "intersect\n";
		long double resx = (b2-b1)/((long double)k1-k2), resy=k1*resx+b1;
		cout << resx << ' ' << resy;
	}
	system("pause");
}