
#include <bits/stdc++.h>
/*#define fori(n) for (int i = 0; i < n; i++)
#define forj(n) for (int j = 0; j < n; j++)
#define pb push_back
#define ff first
#define ss second
#define all(v) v.begin(), v.end()*/
typedef long long ll;
#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector", "fast-math", "O3")
//#pragma GCC target("avx2")
using namespace std;

int main () {
	srand(time(NULL));
	cout << fixed << setprecision(15);
	int k1, b1;
	int k2, b2;
	cin >> k1 >> b1;
	cin >> k2 >> b2;
	if (k1 == k2 && b1 == b2) {
		cout << "coincide";
		return 0;
	}
	if (k1 == k2) {
		cout << "parallel";
		return 0;
	}
	cout << "intersect" << "\n";
	double x = double(b2 - b1) / (k1 - k2 + 0.0);
	double y = k1 * x + b1;
	cout << x << " " << y;
}