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

int n;
vector<string> s, p, gtv;
bool reg = false;
bool cif = false;

bool norm(char t) {
	if (t >= 'a' && t <= 'z') return true;
	if (t >= 'A' && t <= 'Z') return true;
	if (t >= '0' && t <= '9') return true;
	if (t == '_') return true;
	return false;
}

bool isbuk(char t) {
	if (t >= 'A' && t <= 'Z') return true;
	if (t >= 'a' && t <= 'z') return true;
	if (t == '_') return true;
	return false;
}

bool nrstr = false;

void gett(string &res, int i, int j) {
	res = "";
	bool b = false;
	for (int k = j; k < p[i].size(); k++) {
		if (!norm(p[i][k])) {
			break;
		}
		if (isbuk(p[i][k])) b = true;
		res += p[i][k];
	}
	nrstr = true;
	if (res == "") {
		nrstr = false;
		return;
	}
	if (b) {
		bool tr = true;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == res) {
				tr = false;
				break;
			}
		}
		if (!tr) nrstr = false;
		if (res[0] >= '0' && res[0] <= '9' && cif == false) {
			nrstr = false;
		}
	}
	else {
		nrstr = false;
	}
	return;
}

int check(string &h) {
	int hsz = h.size();
	int res = 0;
	for (int i = 0; i < p.size(); i++) {
		for (int j = 0; j + hsz - 1 < int(p[i].size()); j++) {
			if (p[i].substr(j, hsz) == h) res++;
		}
	}
	return res;
}

//void geeet(string &h, int i, int j) {
//	h = "";
//	for (int k = j; k < p[i].size(); k++) {
//		if ()
//	}
//}

void SOLVE() {
	cin >> n;
	s.resize(n);
	string a;
	cin >> a;
	if (a == "yes") reg = true;
	cin >> a;
	if (a == "yes") cif = true;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	getline(cin, a);
	while (a == "") {
		getline(cin, a);
	}
	p.pb(a);
	while (getline(cin, a)) {

		//if (a == "") break;
		p.pb(a);
	}
	if (!reg) {
		for (int i = 0; i < p.size(); i++) {
			for (int j = 0; j < p[i].size(); j++) {
				if (p[i][j] >= 'A' && p[i][j] <= 'Z') {
					p[i][j] = p[i][j] - 'A' + 'a';
				}
			}
		}
		for (int i = 0; i < s.size(); i++) {
			for (int j = 0; j < s[i].size(); j++) {
				if (s[i][j] >= 'A' && s[i][j] <= 'Z') {
					s[i][j] = s[i][j] - 'A' + 'a';
				}
			}
		}
	}
	string h = "";
	string ans = "";
	int res = 0;
	for (int i = 0; i < p.size(); i++) {
		for (int j = 0; j < p[i].size(); j++) {
			if (i == 1 && j == 4) {
				cout << "";
			}
			gett(h, i, j);
			if (nrstr) {
				/*int res = check(h);
				if (res > cnt) {
					cnt = res;
					ans = h;
				}*/
				gtv.pb(h);
			}
			if (h != "") {
				j += int(h.size()) - 1;
			}
		}
	}
	for (int i = 0; i < gtv.size(); i++) {
		int cnt = 0;
		for (int j = 0; j < gtv.size(); j++) {
			if (gtv[i] == gtv[j]) {
				cnt++;
			}
		}
		if (cnt > res) {
			res = cnt;
			ans = gtv[i];
		}
	}
	cout << ans;
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