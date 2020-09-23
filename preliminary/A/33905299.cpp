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
	ll k;
	cin >> k;
	if (k == 1) {
		return cout << "YES", 0;
	}
	for (ll i = 1; i * i - (i - 2) * (i - 2) <= k; ++i) {
		if (i * i - (i - 2) * (i - 2) == k) {
			return cout << "YES", 0;
		}
	}
	cout << "NO";
	return 0;
}