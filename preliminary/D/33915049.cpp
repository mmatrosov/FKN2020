#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

const long double pi = 3.14159265358979326;
const long double eps = 1e-10;

struct point {
	long long x, y;

	long long sqr_len() {
		return x * x + y * y;
	}

	long double len() {
		return sqrt(x * x + y * y);
	}

	long double angle() {
		return atan2(y, x);
	}
};

bool is_equal(long double a, long double b) {
	return abs(a - b) < eps;
}

bool is_less(long double a, long double b) {
	return a < b || is_equal(a, b);
}

long double get_circ_len(point A, point B) {
	long double ang = A.angle() - B.angle();
	if (is_less(ang, 0))
		ang += 2 * pi;
	if (is_less(pi, ang))
		ang = 2 * pi - ang;
	return ang;
}

int main() {
	point A, B;
	cin >> A.x >> A.y >> B.x >> B.y;
	if (A.sqr_len() > B.sqr_len())
		swap(A, B);
	long double ang1 = get_circ_len(A, B);
	long double ang2 = get_circ_len(A, { -B.x, -B.y });
	long double ans1 = ang1 * A.len() + (B.len() - A.len());
	long double ans2 = ang2 * A.len() + (B.len() + A.len());
	long double ans3 = A.len() + B.len();
	if (is_less(ans1, ans2) && is_less(ans1, ans3))
		cout << fixed << setprecision(30) << ans1;
	else if (is_less(ans2, ans1) && is_less(ans2, ans3))
		cout << fixed << setprecision(30) << ans2;
	else
		cout << fixed << setprecision(30) << ans3;
	return 0;
}
