#define _CRT_SECURE_NO_WARNINGS
#define REL
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <deque>
#include <queue>
#include <iomanip>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <string>
#include <set>
#include <bitset>
#include <cstdint>
#include <cstring>
#include <cassert>
#include <complex>
#include <stack> 
#include <random>

using namespace std;

typedef int64_t i64;
typedef long long LL;
typedef long long ll;
typedef long double LD;
typedef complex <LD> cld;
typedef unsigned int uint;
typedef complex <double> cd;
typedef unsigned long long ULL;

#define endl "\n"
#define dendl "\n\n"
#define mp make_pair
#define mt make_tuple
#define size(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

/////////////////////////////////////////////////////////////////////

template <typename T>
T sqr(T a) {
	return a * a;
}

template <typename T>
int sign(T a) {
	if (a == 0)
		return 0;
	return (a > 0 ? 1 : -1);
}

template <typename T>
bool uax(T& a, const T b) {
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
istream& operator >> (istream& in, pair<T1, T2>& p) {
	in >> p.first >> p.second;
	return in;
}

template <typename T1, typename T2>
ostream& operator << (ostream& out, pair<T1, T2>& p) {
	out << p.first << ' ' << p.second;
	return out;
}

mt19937_64 rnd(0);

const int LOG = 22;
const int N = (int)2e5 + 7;
const int MAXN = (int)1e6 + 7;
const int MOD = (int)1e9 + 7;
const int INF = (int)2e9 + 7;
const int CONST = 450;
const LL LINF = (i64)1e18;
const LD PI = 3.1415926535897932384626433832795;
const LD EPS = 1;

/////////////////////////////////////////////////////////////////////

struct Vector {
	int x, y;
	Vector() {};
	Vector(int x, int y) :
		x(x), y(y) {};
};

Vector operator - (const Vector& a, const Vector& b) {
	return Vector(a.x - b.x, a.y - b.y);
}

LL operator * (const Vector& a, const Vector& b) {
	return 1LL * a.x * b.y - 1LL * b.x * a.y;
}

LL operator % (const Vector& a, const Vector& b) {
	return 1LL * a.x * b.x + 1LL * a.y * b.y;
}

double dist(int a, int b, int c, int d) {
	return sqrt(1LL * (a - c) * (a - c) + 1LL * (b - d) * (b - d));
}

void solve() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	Vector v1 = Vector(a, b), v2 = Vector(c, d);
	if (v1 * v2 == 0) {
		cout << dist(a, b, c, d);
		return;
	}
	LD r1 = dist(0, 0, a, b) + dist(0, 0, c, d);
	LD r2 = abs(dist(0, 0, a, b) - dist(0, 0, c, d));
	LD ang = atan2(v1 * v2, v1 % v2);
	ang = abs(ang);
	r2 += ang * min(dist(0, 0, a, b), dist(0, 0, c, d));
	cout << min(r1, r2);
}

int main() {
	double start = clock();
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cout << fixed << setprecision(20);
	cerr << fixed << setprecision(20);
#else
	cout << fixed << setprecision(20);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	rnd.seed(time(0));
#endif

	int t = 1;
	for (int i = 0; i < t; i++) {
		solve();
	}

#ifdef _DEBUG
	cout << endl << "Time is " << (clock() - start) / 1000.0;
#endif
}