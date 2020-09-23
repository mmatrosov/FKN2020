#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <algorithm>
#include <string>
#include <iostream>
#include <complex>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <stack>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <random>
#include <set>
#include <vector>
#include <unordered_map>
#include <bitset>
#include <unordered_set>
#include <array>
#include <forward_list>
#include <chrono>
#include <iomanip>
#include <utility>
#include <assert.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("sse")

#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

mt19937 gen(34);

ld triangle_area_2(ld x1, ld y1, ld x2, ld y2, ld x3, ld y3) {
	return abs((x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1));
}

ld distance(ld x1, ld y1, ld x2, ld y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("memory.in", "r", stdin);
	//freopen("memory.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ld xa, ya, xb, yb;
	cin >> xa >> ya >> xb >> yb;
	if (xa * yb == ya * xb)
	{
		cout << fixed << setprecision(10) << distance(xa, ya, xb, yb);
		return 0;
	}
	ld r1 = xa * xa + ya * ya;
	ld r2 = xb * xb + yb * yb;
	if (r1 == r2)
	{
		ld d1 = 2 * sqrt(ld(r1));
		ld sina = triangle_area_2(0, 0, xa, ya, xb, yb) / r1;
		ld grad = asin(sina);
		if (xa * xb + ya * yb < 0)
			grad = acos(-1) - grad;
		ld l = grad * sqrt(r1);
		ld ANS = min(d1, l);
		cout << fixed << setprecision(10) << ANS;
		return 0;
	}
	if (r1 > r2)
	{
		swap(xa, xb);
		swap(ya, yb);
		swap(r1, r2);
	}
	ld A = yb, B = -xb, C = 0;
	ld x0 = 0, y0 = 0;
	ld dist = r1 - C * C / (A * A + B * B);
	ld mult = sqrt(dist / (A * A + B * B));
	ld p1x, p1y, p2x, p2y;
	p1x = x0 + B * mult;
	p2x = x0 - B * mult;
	p1y = y0 - A * mult;
	p2y = y0 + A * mult;
	ld d1 = 2 * sqrt(ld(r1));
	ld sina = triangle_area_2(0, 0, xa, ya, p1x, p1y) / r1;
	ld grad = asin(sina);
	if (xa * p1x + ya * p1y < 0)
		grad = acos(-1) - grad;
	ld l = grad * sqrt(r1);
	ld ANS = min(d1, l) + distance(p1x, p1y, xb, yb);

	sina = triangle_area_2(0, 0, xa, ya, p2x, p2y) / r1;
	grad = asin(sina);
	if (xa * p2x + ya * p2y < 0)
		grad = acos(-1) - grad;
	l = grad * sqrt(r1);
	ANS = min(ANS, min(d1, l) + distance(p2x, p2y, xb, yb));
	cout << fixed << setprecision(10) << ANS;
	return 0;
}