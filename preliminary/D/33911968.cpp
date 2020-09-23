#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#pragma optimizitaion_level 3
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <bitset>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <unordered_map>
#include <tuple>
#include <cmath>
#include <functional>
#include <algorithm>
#include <set>
#include <cassert>
#include <deque>
#include <unordered_set>
#include <numeric>
using namespace std;
#define kekek ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

struct pt {
	long long x, y;

	long double dist(pt p) {
		return hypot(p.x - x, p.y - y);
	}
};

long long vecmulti(pt a, pt b) {
	return a.x * b.y - a.y * b.x;
}

long long skmulti(pt a, pt b) {
	return a.x * b.x + a.y * b.y;
}

long double angle(pt a, pt b) {
	return abs(atan2(vecmulti(a, b), skmulti(a, b)));
}

signed main() {
	kekek;
	pt a, b, zero = { 0, 0 };
	cin >> a.x >> a.y >> b.x >> b.y;
	long double r = min(a.dist(zero), b.dist(zero)), R = max(a.dist(zero), b.dist(zero));
	
	long double d1 = r + R, d2 = angle(a, b) * r + R - r;

	cout << fixed << setprecision(10) << min(d1, d2);

	return 0;
}