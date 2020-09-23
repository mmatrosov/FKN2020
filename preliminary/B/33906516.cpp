//#define NDEBUG
#define REL
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <algorithm>
#include <sstream>
#include <ctime>
#include <string>
#include <iomanip>
#include <climits>
#include <set>
#include <map>
#include <cassert>
#include <fstream>
#include <stack>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <random>
#include <chrono>

#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define nn '\n'
#define pp ' '

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#ifdef _DEBUG
mt19937 rnd(1928);
#else
//mt19937 rnd(1928);
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

template <typename T>
bool uax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

template <typename T>
bool uin(T& a, const T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

template <typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& p) {
	in >> p.first >> p.second;
	return in;
}

template <typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2>& p) {
	out << p.first << ' ' << p.second;
	return out;
}

long double GENERAL_TIMER;
long double GET_TIME() {
	return (clock() - GENERAL_TIMER) * 1.00 / CLOCKS_PER_SEC;
}

void PROGRAM_START() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	GENERAL_TIMER = clock();
#else
	ios_base::sync_with_stdio(false);
	cin.tie(0);
#endif
	cout << fixed << setprecision(15);
}

void PROGRAM_END() {
#ifdef _DEBUG
	cout << nn << "----------------------------------------------" << nn << GET_TIME() << nn;
#endif
}

const ld INF = 1e9 + 7;
const ld eps = 1e-7;

bool eq(ld a, ld b) {
	return (a + eps >= b && b + eps >= a);
}

bool bol(ld a, ld b) {
	return (a >= b + eps);
}

bool bolr(ld a, ld b) {
	return (bol(a, b) || eq(a, b));
}

struct Pnt {
	ld x, y;
	Pnt() {}
	Pnt(ld x_, ld y_) {
		x = x_;
		y = y_;
	}
	void in() {
		cin >> x >> y;
	}
	ld atan() { // [-pi; pi]
		return atan2(y, x);
	}
	ld polar() { // [0; 2pi)
		ld ret = atan2(y, x);;
		return bolr(ret, ld(0)) ? ret : ret + 2 * M_PI;
	}
	bool operator==(Pnt a) const {
		return (eq(a.x, x) && eq(a.y, y));
	}
	bool operator!=(Pnt a) const {
		return !(eq(a.x, x) && eq(a.y, y));
	}
	ld operator^(Pnt q) {  //dist PNT 
		return sqrt((x - q.x) * (x - q.x) + (y - q.y) * (y - q.y));
	}
	bool operator<(Pnt q) const {
		return bol(q.x, x) || (eq(q.x, x) && bol(q.y, y));
	}
	bool operator<(Pnt q) {
		return bol(q.x, x) || (eq(q.x, x) && bol(q.y, y));
	}
};

Pnt BAD = Pnt(-INF, -INF);

struct Vector {
	ld x, y;
	Pnt st;
	Vector() {
		st = Pnt(0, 0);
	}
	Vector(ld x_, ld y_) {
		st = Pnt(0, 0);
		x = x_;
		y = y_;
	}
	Vector(Pnt a, Pnt b) {
		st = a;
		x = (b.x - a.x);
		y = (b.y - a.y);
	}
	Vector(Pnt st_, ld x_, ld y_) {
		st = st_;
		x = x_;
		y = y_;
	}
	Vector operator*(ld k) {
		return Vector(st, x * k, y * k);
	}
	ld operator*(Vector q) { // skal
		return q.x * x + q.y * y;
	}
	ld operator^(Vector q) { // vect
		return x * q.y - q.x * y;
	}
	ld len2() {
		return x * x + y * y;
	}
	ld len() {
		return sqrt(x * x + y * y);
	}
	Vector operator+(Vector q) {
		return Vector(st, x + q.x, y + q.y);
	}
};

Pnt shift_pnt(Pnt a, Vector b) {
	return Pnt(a.x + b.x, a.y + b.y);
}

int vec_side(Vector a, Pnt b) {
	Vector f = Vector(a.st, b);
	if (eq((a ^ f), ld(0))) {
		if (bolr(a * f, ld(0)) && bolr(a.len2(), f.len2())) {
			return 3; // on
		}
		return 2; // on line !!!not segment!!!
	}
	else {
		if (bol((a ^ f), ld(0))) {
			return 0;  //left
		}
		else {
			return 1;  // right
		}
	}
}

Pnt line_intersection(Vector a, Vector b) {
	//ld pepa = ((Vector(b.st.x, b.st.y) ^ b) - (Vector(a.st.x, a.st.y) ^ b));
	if (eq((a ^ b), ld(0))) {
		return BAD;
	}
	ld k = ((Vector(b.st.x, b.st.y) ^ b) - (Vector(a.st.x, a.st.y) ^ b)) / ld(a ^ b);
	return shift_pnt(a.st, a * k);
}

void SOLVE() {
	int k1, k2, b1, b2;
	cin >> k1 >> b1;
	cin >> k2 >> b2;
	Pnt a = Pnt(0, b1);
	Pnt b = Pnt(1, k1 + b1);
	Vector f = Vector(a, b);
	a = Pnt(0, b2);
	b = Pnt(1, b2 + k2);
	Vector s = Vector(a, b);
	Pnt y = line_intersection(f, s);
	if (y == BAD) {
		if (b1 == b2) {
			cout << "coincide" << nn;
		}
		else cout << "parallel";
	}
	else {
		cout << "intersect" << nn;
		cout << y.x << pp << y.y << nn;
	}
}

int main() {
	bool MULTITEST = false;
	PROGRAM_START();
	int t = 1;
	if (MULTITEST) cin >> t;
	for (int i = 1; i <= t; i++) {
		//CUR_TEST = i;
		SOLVE();
	}
	PROGRAM_END();
}