/*

Code for problem D by cookiedoth
Generated 30 Aug 2020 at 11.08 AM


▅███████ ]▄▄▄▄▄▄▄ 
█████████▅▄▃ 
Il████████████████] 
◥⊙▲⊙▲⊙▲⊙▲⊙▲⊙▲⊙◤

o_O
-_-
z_z

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <cassert>
#include <random>
#include <cstring>
#include <numeric>
#include <random>
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)
#define length(a) (int)a.size()

using namespace std;

template<class T> int chkmax(T &a, T b) {
	if (b > a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class T> int chkmin(T &a, T b) {
	if (b < a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class iterator> void output(iterator begin, iterator end, ostream& out = cerr) {
	while (begin != end) {
		out << (*begin) << " ";
		begin++;
	}
	out << endl;
}

template<class T> void output(T x, ostream& out = cerr) {
	output(x.begin(), x.end(), out);
}

void fast_io() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

const ld pi = acosl(-1);

ld dist(ld x, ld y) {
	return sqrtl(x * x + y * y);
}

signed main() {
	cerr << setprecision(4) << fixed;
	fast_io();
	ld x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	ld d1 = dist(x1, y1);
	ld d2 = dist(x2, y2);
	ld ang1 = atan2(y1, x1);
	ld ang2 = atan2(y2, x2);
	// cerr << d1 << " " << d2 << endl;
	ld diff = ang2 - ang1;
	while (diff < 0.0) {
		diff += 2 * pi;
	}
	while (diff >= 2 * pi) {
		diff -= 2 * pi;
	}
	if (diff >= pi) {
		diff = 2 * pi - diff;
	}
	// cerr << "diff = " << diff << endl;
	if (d1 > d2) {
		swap(d1, d2);
	}
	ld ans = min(d1 + d2, d2 - d1 + d1 * diff);
	cout << setprecision(10) << fixed << ans << '\n';
}
