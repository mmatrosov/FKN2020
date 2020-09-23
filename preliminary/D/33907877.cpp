//#pragma optimization_level 3
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <math.h>
#include <cmath>
#include <string>
#include <random>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <string.h>
#include <stack>
#include <assert.h>
#include <list>
#include <time.h>
#include <memory>
#include <chrono>
using namespace std;
//
#define fast cin.tie(0);cout.tie(0);cin.sync_with_stdio(0);cout.sync_with_stdio(0);
//#define cin in
//#define cout out
#define ll long long
#define db double
#define ld long double
#define uset unordered_set
#define umap unordered_map
#define ms multiset
#define pb push_back
#define pq priority_queue
#define umap unordered_map
#define uset unordered_set
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<ld, ld>
#define pnn pair<Node*, Node*>
#define uid uniform_int_distribution
#define PI acos(-1.0)
//#define sort(a, b) sort(a.begin(), a.end(), b())
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ifstream in("input.txt");
ofstream out("output.txt");

struct pnt {
	ld x, y;
};

ld dist(pnt a, pnt b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

ld angle(pnt a, pnt b, pnt c) {
	ld A = dist(a, b);
	ld B = dist(a, c);
	ld C = dist(b, c);
	
	ld cs = (A * A + B * B - C * C) / (2 * A * B);
	return acos(cs);
}

int main() {
	cout.precision(8);
	cout << fixed;

	pnt a, b;
	cin >> a.x >> a.y >> b.x >> b.y;
	pnt O = { 0, 0 };

	ld r1 = dist(a, O), r2 = dist(b, O);
	if (r1 < r2) {
		swap(r1, r2);
		swap(a, b);
	}

	ld ans = 0;
	ans += r1 - r2;

	if (r2 == 0) {
		cout << ans;
		return 0;
	}

	ld alph = angle(O, a, b);
	ans += min(2 * r2, r2 * alph);
	cout << ans;
}