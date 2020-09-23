#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

ld dist(ld x1, ld y1, ld x2, ld y2) {
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

ld dist1(ld x1, ld y1, ld x2, ld y2) {
	return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

const ld pi = acos(-1);

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(20);

	ll xx1, yy1, xx2, yy2;
	cin >> xx1 >> yy1 >> xx2 >> yy2;
	ld x1, y1, x2, y2;
	x1 = xx1, y1 = yy1, x2 = xx2, y2 = yy2;
	ld ans1 = dist(x1, y1, 0, 0) + dist(0, 0, x2, y2);
	ld r1 = dist(x1, y1, 0, 0);
	ld r2 = dist(x2, y2, 0, 0);
	ld tx = x2 / r2, ty = y2 / r2;
	tx *= r1;
	ty *= r1;
	ld s = x1 * x2 + y1 * y2;
	s /= sqrt(dist1(x1, y1, 0, 0) * dist1(x2, y2, 0, 0));
	ld ang = acos(s);
	ld d1 = ang * r1;
	ld d2 = dist(tx, ty, x2, y2);
	ld ans2 = (d1 + d2);
	swap(x1, x2);
	swap(y1, y2);
	r1 = dist(x1, y1, 0, 0);
	r2 = dist(x2, y2, 0, 0);
	tx = x2 / r2, ty = y2 / r2;
	tx *= r1;
	ty *= r1;
	s = x1 * x2 + y1 * y2;
	s /= sqrt(dist1(x1, y1, 0, 0) * dist1(x2, y2, 0, 0));
	ang = acos(s);
	d1 = ang * r1;
	d2 = dist(tx, ty, x2, y2);
	ld ans3 = (d1 + d2);
	cout << min(ans1, min(ans2, ans3)) << '\n';
}