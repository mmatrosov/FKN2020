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
 
const int MAXN = 101, X = 1e6;
const ll INF = ll(3e18) + 1;


signed main() {
	#ifdef _GLIBCXX_DEBUG
	// freopen("in.txt", "r", stdin);
	freopen("in.txt", "w", stdout);
	#endif
	cout << 30 << ' ' << X << '\n' << X << '\n';
	for (int i = 1; i < 30; ++i) {
		cout << X / 15 - 1 << '\n';
	}
	return 0;
}