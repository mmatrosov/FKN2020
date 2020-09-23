#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define eb emplace_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define int long long

using namespace std;
const int INF = 2e9;
const int MB = 20;
const int MOD = 1e9 + 7;
const ld PI = atan2(0, -1);
const ld e = 1e-10;
struct point {
	ld x, y;
	point(ld a = 0, ld b = 0) {
		x = a;
		y = b;
	}
};

struct vec {
	ld x, y;
	vec(ld a = 0, ld b = 0) {
		x = a;
		y = b;
	}

	vec(point& a, point& b) {
		x = b.x - a.x;
		y = b.y - a.y;
	}

	ld dist() {
		return sqrtl(x * x + y * y);
	}

	ld dist2() {
		return x * x + y * y;
	}

	ld angle() {
		return atan2(y, x);
	}

	void norm() {
		ld d = dist();
		x /= d;
		y /= d;
	}
};

vec operator/(vec& a, const ld& k) {
	return vec(a.x / k, a.y / k);
}

vec operator+ (vec& a, vec& b) {
	return vec(a.x + b.x, a.y + b.y);
}

vec operator* (vec& a, ld k) {
	return vec(a.x * k, a.y * k);
}

ld operator*(const vec& a, const vec& b) {
	return a.x * b.x + a.y * b.y;
}

ld operator^(const vec& a, const vec& b) {
	ld d = a.x * b.y - a.y * b.x;
	return a.x * b.y - a.y * b.x;
}



istream& operator>>(istream& in, point& a) {
	in >> a.x >> a.y;
	return in;
}

ostream& operator<<(ostream& out, point& b) {
	out << b.x << " " << b.y;
	return out;
}

istream& operator>>(istream& in, vec& a) {
	in >> a.x >> a.y;
	return in;
}

ostream& operator<<(ostream& out, vec& b) {
	out << b.x << " " << b.y;
	return out;
}

ld deg(ld rad) {
	return rad / PI * 180;
}

ld angle(vec& a, vec& b) {
	return atan2(a ^ b, a * b);
}

ld get(ld r, ld ang, ld len) {
	return ang * r + (len - r) * 2;
}

void solve() {
	vec one, two;
	cin >> one >> two;
	if (one.dist2() < two.dist2()) swap(one, two);
	ld ans = one.dist() - two.dist();
	ld ang = abs(angle(one, two));
	one.norm();
	one = one * two.dist();
	
	cout << ans + min(two.dist() * 2, ang * two.dist());
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed;
    cout.precision(12);
    //srand(time(0));
    int t = 1;
    //int t;
    //cin >> t;
    while (t--) solve();
}