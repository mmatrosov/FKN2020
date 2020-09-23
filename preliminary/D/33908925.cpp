#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<iomanip>
using namespace std;
typedef long long ll;

struct Point {
	ll x, y;
	Point() {};
	Point(int x, int y) :x(x), y(y) {};
};

double dist(Point a, Point b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

ll scalar(Point a, Point b) {
	return a.x * b.x + a.y * b.y;
}

ll cross(Point a, Point b) {
	return a.x * b.y - a.y * b.x;
}

void solve() {
	Point a, b;
	cin >> a.x >> a.y >> b.x >> b.y;
	double r1 = dist(Point(0, 0), a);
	double r2 = dist(Point(0, 0), b);
	double al = atan2(abs(cross(a, b)), scalar(a, b));
	double res = al * min(r1, r2) + fabs(r1 - r2);
	res = min(res, r1 + r2);
	printf("%.8f", res);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	solve();
	return 0;
}