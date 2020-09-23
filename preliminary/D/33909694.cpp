#include <iostream>
#include <set>
#include <map>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <deque>
#include <stack>
#include <climits>
#include <math.h>
#include <cassert>
#include <unordered_map>
#include <chrono>
#include <random>
#include <ctime>
#include <complex>
using namespace std;
#pragma warning(disable : 4996)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ld PI = acosl(-1.0);
const ll MOD = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


struct point {
	ld x, y;
};

ld len(point a) {
	return sqrt(a.x * a.x + a.y * a.y);
}


ll operator*(point a, point b) {
	return a.x * b.y - b.x * a.y;
}


ll operator^(point a, point b) {
	return a.x * b.x + a.y * b.y;
}


point operator-(point a, point b) {
	return { b.x - a.x, b.y - a.y };
}


ld calc_angle(point a, point b, point c) {
	return abs(atan2((a - b) * (c - b), (a - b) ^ (c - b)));
}

ld dist(point a, point b) {
	return hypot(a.x - b.x, a.y - b.y);
}

int main() {
#ifdef _DEBUG
	freopen("input1.txt", "r", stdin);
	freopen("output2.txt", "w", stdout);
#endif
	srand(time(0));
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	point a, b;
	cin >> a.x >> a.y >> b.x >> b.y;
	ld an = calc_angle(a, { 0, 0 }, b);
	cout << fixed << setprecision(10);
	if (a * b == 0) {
		cout << dist(a, b);
	}
	else {
		ld d1 = dist(a, { 0, 0 });
		ld d2 = dist(b, { 0, 0 });
		ld fv = d1 + d2;
		ld sv = an * min(d1, d2) + abs(d1 - d2);
		cout << min(fv, sv);
	}
}