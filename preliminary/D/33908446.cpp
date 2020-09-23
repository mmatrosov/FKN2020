#include<bits/stdc++.h>

#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 1e5 + 5;

struct Vector {
	ld x, y;
	Vector() {}
	Vector(ld x1, ld y1) : x(x1), y(y1) {}

	ld len() {
		return hypot(x, y);
	}

	void normalize() {
		ld l = len();
		x /= l; y /= l;
	}

	void longen(ld k) {
		x *= k; y *= k;
	}

	ld operator*(Vector& a) {
		return a.x * x + a.y * y;
	}

	ld operator%(Vector& a) {
		return x * a.y - y * a.x;
	}
};

void solve() {
	cout.precision(100);
	ll xa, xb, ya, yb;
	cin >> xa >> ya >> xb >> yb;
	if (xa == xb && ya == yb) {
		cout << 0 << "\n";
		return;
	}
	ld dist1 = hypot(xa, ya), dist2 = hypot(xb, yb);
	if (dist2 < dist1) {
		swap(xa, xb); swap(ya, yb);
		swap(dist2, dist1);
	}
	ld ans = dist2 - dist1;
	ld ans2 = dist2 + dist1;
	//cout << dist1 << ' ' << dist2 << "\n";
	Vector a(xa, ya), b(xb, yb);
	b.normalize();
	b.longen(dist1);
	ld angle = fabs(atan2(a % b, a * b));
	//cout << "an: " << angle << endl;
	ans += angle * dist1;
	cout << min(ans, ans2) << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}