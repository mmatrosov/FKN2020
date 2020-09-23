#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <set>
#include <math.h>
#include <iomanip>
#define ll long long
#define ld long double

using namespace std;

int main() {
	cout.precision(30);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ll k1, b1;
	cin >> k1 >> b1;
	ll k2, b2;
	cin >> k2 >> b2;
	if (k1 == k2) {
		if (b1 == b2) {
			cout << "coincide\n";
			return 0;
		}
		if (b1 != b2) {
			cout << "parallel\n";
			return 0;
		}
	}
	cout << "intersect\n";
	ld x = (b2 - b1);
	x /= (k1 - k2);
	ld y = x * k1 + b1;
	cout << x << " " << y << "\n";
}
//*/