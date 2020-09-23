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

const int N = 1e5 + 7;

int n, k;
vector<int> a;

void SOLVE() {
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(all(a));
	a.resize(unique(all(a)) - a.begin());
	cin >> k;
	int x;
	for (int i = 0; i < k; i++) {
		cin >> x;
		int y = lower_bound(all(a), x) - a.begin();
		cout << y << nn;
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