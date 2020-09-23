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
const int MAXN = (int)3e6 + 7;
const int MOD = (int)1e9 + 7;
const int INF = (int)2e9 + 7;
const int CONST = 450;
const LL LINF = (i64)1e18;
const LD PI = 3.1415926535897932384626433832795;
const LD EPS = 1;

/////////////////////////////////////////////////////////////////////

struct Node {
	Node* edg[2];
	int ind = -1;
	Node() {};
};

int node;
Node arr[MAXN];

Node* new_node() {
	return &arr[node++];
}

void add(Node *v, const string& s, int ind) {
	for (char c : s) {
		int pos = c - '0';
		if (!v->edg[pos])
			v->edg[pos] = new_node();
		v = v->edg[pos];
	}
	v->ind = ind;
}

int find_best(Node* v, const string& s) {
	for (int i = 0; i < 40; i++) {
		if (s[i] == '0') {
			if (v->edg[1])
				v = v->edg[1];
			else
				v = v->edg[0];
		}
		else {
			if (v->edg[0])
				v = v->edg[0];
			else
				v = v->edg[1];
		}
	}
	return v->ind;
}

int n;
LL x[N];
string s[N];
vector <pair<int, LL>> gr[N];

string get(LL x) {
	string res = "";
	for (int i = 0; i < 40; i++) {
		if (x & (1LL << i))
			res += '1';
		else
			res += '0';
	}
	reverse(all(res));
	return res;
}

void dfs(int u, int par) {
	for (auto it : gr[u]) {
		if (it.first == par)
			continue;
		x[it.first] = x[u] ^ it.second;
		dfs(it.first, u);
	}
}

void solve() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		LL x; cin >> x;
		u--, v--;
		gr[u].push_back(mp(v, x));
		gr[v].push_back(mp(u, x));
	}
	dfs(0, 0);
	Node* root = new_node();
	for (int i = 0; i < n; i++) {
		s[i] = get(x[i]);
		add(root, s[i], i);
	}
	LL ans = -1, u = -1, v = -1;
	for (int i = 0; i < n; i++) {
		int best = find_best(root, s[i]);
		if (uax(ans, x[i] ^ x[best]))
			u = i + 1, v = best + 1;
	}
	cout << u << ' ' << v;
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