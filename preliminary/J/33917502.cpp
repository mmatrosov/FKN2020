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

int n, m;
set <char> near;
char f[1000][1000];

pair <int, int> getx(int val) {
	int x = val / m;
	int y = 6453253;
	if (x % 2 == 0)
		y = val % m;
	else
		y = m - val % m - 1;
	return mp(x, y);
}

pair <int, int> gety(int val) {
	int y = val / n;
	int x = 6453253;
	if (y % 2 == 0)
		x = val % n;
	else
		x = n - val % n - 1;
	return mp(x, y);
}

void get_near(int x, int y) {
	int h[4] = { -1, 0, 0, 1 }, v[4] = { 0, -1, 1, 0 };
	for (int i = 0; i < 4; i++) {
		int nx = x + h[i], ny = y + v[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			continue;
		near.insert(f[nx][ny]);
	}
}

char find() {
	for (char c = 'A'; c <= 'Z'; c++) {
		if (!near.count(c))
			return c;
	}
	return '0';
}

void solve() {
	cin >> n >> m;
	int cnt = 0;
	while ((cnt + 1) * (cnt + 2) / 2 <= n * m)
		cnt++;
	if (n <= m) {
		int ind = 0, cur = 1;
		while (ind < n * m) {
			near.clear();
			if (cur == cnt) {
				for (int i = ind; i < n * m; i++) {
					auto p = getx(i);
					get_near(p.first, p.second);
				}
				char c = find();
				for (int i = ind; i < n * m; i++) {
					auto p = getx(i);
					f[p.first][p.second] = c;
				}
				ind = n * m;
			}
			else {
				for (int i = ind; i < ind + cur; i++) {
					auto p = getx(i);
					get_near(p.first, p.second);
				}
				char c = find();
				for (int i = ind; i < ind + cur; i++) {
					auto p = getx(i);
					f[p.first][p.second] = c;
				}
				ind += cur;
				cur++;
			}
		}
	}
	else {
		int ind = 0, cur = 1;
		while (ind < n * m) {
			near.clear();
			if (cur == cnt) {
				for (int i = ind; i < n * m; i++) {
					auto p = gety(i);
					get_near(p.first, p.second);
				}
				char c = find();
				for (int i = ind; i < n * m; i++) {
					auto p = gety(i);
					f[p.first][p.second] = c;
				}
				ind = n * m;
			}
			else {
				for (int i = ind; i < ind + cur; i++) {
					auto p = gety(i);
					get_near(p.first, p.second);
				}
				char c = find();
				for (int i = ind; i < ind + cur; i++) {
					auto p = gety(i);
					f[p.first][p.second] = c;
				}
				ind += cur;
				cur++;
			}
		}
	}
	cout << cnt << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << f[i][j];
		cout << endl;
	}
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