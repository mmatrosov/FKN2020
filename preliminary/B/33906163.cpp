// #define _GLIBCXX_DEBUG 	
 
#include  <bits/stdc++.h>
 
#define f first
#define s second
#define push push_back
#define pop pop_back
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
const int MAXN = 2e4 + 2;
const ll INF = ll(3e18) + 1;

signed main() {
	#ifdef _GLIBCXX_DEBUG
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	int k1, b1, k2, b2;
	cin >> k1 >> b1 >> k2 >> b2;
	if (k1 == k2) {
		return cout << (b1 == b2? "coincide": "parallel"), 0;
	}
	double x = double(b2 - b1) / (k1 - k2);
	cout << fixed << setprecision(10) << "intersect\n" << x << ' ' << x * k1 + b1;
	return 0;
}