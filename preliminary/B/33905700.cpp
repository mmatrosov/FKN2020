#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<iomanip>
using namespace std;
typedef long long ll;

void solve() {
	int k1, b1, k2, b2; cin >> k1 >> b1 >> k2 >> b2;
	if (k1 == k2 && b1 == b2) {
		cout << "coincide";
	} else if (k1 == k2) {
		cout << "parallel";
	} else {
		cout << "intersect\n";
		printf("%.6f %.6f", 1.0 * (b1 - b2) / (k2 - k1), 1.0 * (b1 - b2) / (k2 - k1) * k1 + b1);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
//	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	solve();
	return 0;
}