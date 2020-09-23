// Bippolar disorder is very cool

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <set>

using namespace std;

typedef int64_t ll;
typedef long double ld;

const ld EPS = 1e-8;
const ld PI = acos(-1);

struct Point {
	ld x, y;

	Point() {}

	Point(ld x, ld y)
		: x(x), y(y) {}

	Point operator +(Point other) {
		return Point(x + other.x, y + other.y);
	}

	Point operator -(Point other) {
		return Point(x - other.x, y - other.y);
	}

	ld operator *(Point other) {
		return x * other.y - y * other.x;
	}

	ld operator %(Point other) {
		return x * other.x + y * other.y;
	}
};

istream& operator >>(istream& in, Point& point) {
	in >> point.x >> point.y;
	return in;
}

ld f(Point p1, Point p2, ld k) {
	return fabs(atan2(p1 * p2, p1 % p2)) * k + fabs(sqrt(p1 % p1) - k) + fabs(sqrt(p2 % p2) - k);
}

int main() {
	Point p1, p2;
	cin >> p1 >> p2;
	if (p1 % p1 < p2 % p2) {
		swap(p1, p2);
	}
	if (sqrt(p2 % p2) < EPS) {
		cout << fixed << setprecision(12) << sqrt(p1 % p1) << endl;
		return 0;
	}
	ld left = 0;
	ld right = sqrt(p1 % p1);
	for (ll i = 0; i < 666; ++i) {
		ld m1 = left + (right - left) / 2.1;
		ld m2 = right - (right - left) / 2.1;
		ld value1 = f(p1, p2, m1);
		ld value2 = f(p1, p2, m2);
		if (value1 > value2) {
			left = m1;
		} else {
			right = m2;
		}
	}
	cout << fixed << setprecision(12) << f(p1, p2, left) << endl;
    return 0;
}
