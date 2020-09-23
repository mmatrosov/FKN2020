#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <iomanip>
#include <set>
#include <math.h>
#define ll long long
#define ld long double

using namespace std;

struct vec {
	ll x;
	ll y;
	vec(){}
	vec(ll x, ll y) : x(x), y(y){}
};

vec input() {
	ll x, y;
	cin >> x >> y;
	return { x, y };
}

ll cross(vec &A, vec &B) {
	return A.x * B.y - A.y * B.x;
}

ll dot(vec& A, vec& B) {
	return A.x * B.x + A.y * B.y;
}

ld angle(vec& A, vec& B) {
	return atan2(cross(A, B), dot(A, B));
}

ld dist(vec& A, vec& B) {
	return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}
const ld pi = 3.14159265358979323846264;

int main() {
	cout.precision(30);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vec O = { 0, 0 };
	vec A = input();
	vec B = input();
	ld d1 = dist(O, A);
	ld d2 = dist(O, B);
	ld ang = abs(angle(A, B));
	//ang = min(abs(ang), pi - abs(ang));
	if (d1 > d2)
		swap(d1, d2);
	cout << min(d1 + d2, d2 - d1 + d1 * ang) << endl;
}
//*/