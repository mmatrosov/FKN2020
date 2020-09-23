/*

Code for problem J by cookiedoth
Generated 30 Aug 2020 at 12.17 PM


   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="

^_^
~_^
=_=

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

const int mx = 1010;
int n, m, cmp[mx][mx], cmp_id;
vector<pair<int, int> > order;

void read() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		if (i % 2 == 0) {
			for (int j = 0; j < m; ++j) {
				order.emplace_back(i, j);
			}
		} else {
			for (int j = m - 1; j >= 0; --j) {
				order.emplace_back(i, j);
			}
		}
	}
	int cmp_sz = 1, nxt = 1;
	for (int i = 0; i < n * m; ++i) {
		if (i == nxt) {
			cmp_sz++;
			if (nxt + cmp_sz <= n * m) {
				cmp_id++;
			}
			nxt += cmp_sz;
		}
		cmp[order[i].first][order[i].second] = cmp_id;
	}
	// for (int i = 0; i < n; ++i) {
	// 	for (int j = 0; j < m; ++j) {
	// 		cerr << cmp[i][j] << ' ';
	// 	}
	// 	cerr << '\n';
	// }
}

vector<set<int> > g;
int cmp_cnt;
vector<pair<int, int> > dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int ok(int x, int y) {
	return (x >= 0 && x < n && y >= 0 && y < m);
}

void build_graph() {
	cmp_cnt = cmp_id + 1;
	g.resize(cmp_cnt);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (auto pp : dir) {
				int i1 = i + pp.first;
				int j1 = j + pp.second;
				if (ok(i1, j1) && cmp[i][j] > cmp[i1][j1]) {
					g[cmp[i][j]].insert(cmp[i1][j1]);
				}
			}
		}
	}
}

const int K = 26;
int clr[mx * mx], used[K], used_clr;

void color() {
	for (int i = 0; i < cmp_cnt; ++i) {
		// cerr << "i = " << i << endl;
		used_clr++;
		clr[i] = -1;
		for (auto v : g[i]) {
			// cerr << "v = " << v << endl;
			used[clr[v]] = used_clr;
		}
		for (int j = 0; j < K; ++j) {
			if (used[j] != used_clr) {
				clr[i] = j;
				break;
			}
		}
		assert(clr[i] != -1);
	}
}

void print() {
	cout << cmp_cnt << '\n';
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << (char)('A' + clr[cmp[i][j]]);
		}
		cout << '\n';
	}
}

signed main() {
	fast_io();
	read();
	build_graph();
	color();
	print();
}
