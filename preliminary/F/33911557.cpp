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

const int N = 107;

int n, k;
int a[N];
int dp[N][N];
pair<int, int> p[N][N];

int gum(int l, int r) {
	if (r < l) return 0;
	/*if (l == 0) return p[r];
	else return p[r] - p[l - 1];*/
	return (r - l + 1);
}

void SOLVE() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		dp[i][1] = 0;
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	if (k == 1) {
		int ans = 0;
		int y = 0;
		int sum = n;
		for (int i = 0; i < n; i++) {
			if (uax(ans, a[i] * sum)) {
				y = a[i];
			}
			sum--;
		}
		cout << y << nn;
		return;
	}
	int ans = 0;
	pair<int, int> g;
	for (int i = 0; i < n; i++) {
		for (int j = 2; j <= k; j++) {
			dp[i][j] = -1;
			int del = 0;
			if (j < k) del = 0;
			else {
				del = gum(i, n - 1) * a[i];
			}
			if (i == 8 && j == 4) {
				cout << "";
			}
			for (int w = 0; w <= i; w++) {
				if (uax(dp[i][j], dp[w][j - 1] + gum(w, i - 1) * a[w] + del)) {
					p[i][j] = mp(w, j - 1);
				}
			}
			if (j == k) {
				if (uax(ans, dp[i][j])) {
					g = mp(i, j);
				}
			}
		}
	}
	vector<int> ns;
	while (g.second > 0) {
		ns.pb(a[g.first]);
		g = p[g.first][g.second];
	}
	sort(all(ns));
	ns.resize(unique(all(ns)) - ns.begin());
	for (auto e : ns) {
		cout << e << pp;
	}
	int q = 1;
	for (int e = ns.size(); e < k; e++) {
		cout << a[n - 1] + q << pp;
		q++;
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