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

struct line {
	int k, b;

	long double f(long double x) {
		return k * x + b;
	}
};

bool operator == (const line& a, const line& b) {
	return (a.k == b.k && a.b == b.b);
}

bool operator | (const line& a, const line& b) {
	return (a.k == b.k && a.b != b.b);
}

signed main() {
	kekek;
	line L1, L2;
	cin >> L1.k >> L1.b >> L2.k >> L2.b;

	if (L1 == L2) {
		cout << "coincide";
	}
	else if (L1 | L2) {
		cout << "parallel";
	}
	else {
		cout << "intersect\n";
		long double x0 = ((long double)L2.b - L1.b) / ((long double)L1.k - L2.k);
		cout << fixed << setprecision(10) << x0 << " " << L1.f(x0);
	}

	return 0;
}