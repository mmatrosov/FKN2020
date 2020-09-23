
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
	int k;
	cin >> k;
	if (k == 1) {
		cout << "YES";
		return 0;
	}
	for (int n = 2; n < 1000000; n++) {
		int curk = n + n + n - 2 + n - 2;
		if (curk == k) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}