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

void down(string& s, bool fl) {
	if (fl)
		return;
	for (int i = 0; i < size(s); i++) {
		if ('A' <= s[i] && s[i] <= 'Z')
			s[i] = s[i] - 'A' + 'a';
	}
}

int t;
bool reg, dig;
set <string> com;
map <string, int> in, fin;

void parse(const string& s) {
	int ind = 0, sz = size(s);
	while (ind < sz) {
		string cur = "";
		while (ind < sz && (('a' <= s[ind] && s[ind] <= 'z') || ('A' <= s[ind] && s[ind] <= 'Z') || s[ind] == '_' || ('0' <= s[ind] && s[ind] <= '9')))
			cur += s[ind++];
		bool id = false;
		for (char c : cur)
			id |= c > '9' || c < '0';
		if (size(cur) > 0 && !com.count(cur) && id) {
			in[cur]++;
			if (!fin.count(cur))
				fin[cur] = t++;
		}
		ind++;
	}
}

void solve() {
	int n; cin >> n;
	string r, d;
	cin >> r >> d;
	reg = r == "yes", dig = d == "yes";
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		down(s, reg);
		com.insert(s);
	}
	string s;
	while (cin >> s) {
		down(s, reg);
		parse(s);
	}
	int mxin = 0, tin = INF;
	string ans = "";
	for (auto it : in) {
		if (it.second >= mxin) {
			if (!dig && '0' <= it.first[0] && it.first[0] <= '9')
				continue;
			if (it.second > mxin || (it.second == mxin && tin > fin[it.first]))
				mxin = it.second, ans = it.first, tin = fin[it.first];
		}
	}
	cout << ans;
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