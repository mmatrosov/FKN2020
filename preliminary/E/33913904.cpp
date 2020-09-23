/*

Code for problem E by cookiedoth
Generated 30 Aug 2020 at 11.17 AM


______▄███████▄_______
______█▄█████▄█_______
______█▼▼▼▼▼█_______
_____██________ ██______
______█▲▲▲▲▲█_______
______█████████_______
_______██____ ██________

o_O
-_-
~_^

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

int keywords;
vector<string> kw, words;
int n, reg, number;

void parse_YN(int &res) {
	string token;
	cin >> token;
	res = (token == "yes");
}

int ok(char c) {
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || (c == '_'));
}

void transform(char &c) {
	if (reg == 0 && c >= 'A' && c <= 'Z') {
		c = 'a' + (c - 'A');
	}
}

void parse() {
	cin >> n;
	parse_YN(reg);
	parse_YN(number);
	kw.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> kw[i];
		for (auto &c : kw[i]) {
			transform(c);
		}
	}
	string s;
	while (getline(cin, s)) {
		string last_word = "";
		for (auto c : s) {
			if (ok(c)) {
				transform(c);
				last_word.push_back(c);
			} else {
				if (last_word != "") {
					words.push_back(last_word);
				}
				last_word = "";
			}
		}
		if (last_word != "") {
			words.push_back(last_word);
		}
	}
	// output(all(words));
}

void solve() {
	map<string, int> occ;
	for (auto word : words) {
		int ok = 1;
		for (auto ch : kw) {
			if (word == ch) {
				ok = 0;
				break;
			}
		}
		if (number == 0 && (word[0] >= '0' && word[0] <= '9')) {
			ok = 0;
		}
		int not_digit = 0;
		for (auto c : word) {
			if (!(c >= '0' && c <= '9')) {
				not_digit = 1;
			}
		}
		if (not_digit == 0) {
			ok = 0;
		}
		if (ok) {
			occ[word]++;
		}
	}
	// cerr << "occ" << endl;
	// for (auto pp : occ) {
	// 	cerr << pp.first << ' ' << pp.second << '\n';
	// }
	int opt = 0;
	string opt_word = "-1";
	for (auto word : words) {
		if (chkmax(opt, occ[word])) {
			opt_word = word;
		}
	}
	cout << opt_word << '\n';
}

signed main() {
	fast_io();
	parse();
	solve();
}
