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
	ll x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	double ans = hypot(x1, y1) + hypot(x2, y2);
	if (hypot(x1, y1) < hypot(x2, y2)) {
		swap(x1, x2);
		swap(y1, y2);
	}
	double ang = atan2(x1 * y2 - x2 * y1, x1 * x2 + y1 * y2);
	ang = min(abs(ang), 2 * M_PI - abs(ang));
	ans = min(ans, ang * hypot(x2, y2) + hypot(x1, y1) - hypot(x2, y2));
	cout << fixed << setprecision(10) << ans;
	return 0;
}