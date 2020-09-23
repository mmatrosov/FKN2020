//#define _GLIBCXX_DEBUG 	
 
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
	int n;
	cin >> n;
	vector <int> v(n);
	for (int &i: v) {
		cin >> i;
	}
	sort(all(v));
	v.resize(unique(all(v)) - v.begin());
	n = v.size();
	int k;
	cin >> k;
	for (int i = 0; i < k; ++i) {
		int a;
		cin >> a;
		cout << n - (v.end() - lower_bound(all(v), a)) << '\n';
	}
	return 0;
}