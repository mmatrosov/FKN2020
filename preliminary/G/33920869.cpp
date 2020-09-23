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
const int B = 31;

struct Node {
	Node* l;
	Node* r;
	int cnt = 0;
	Node() {
		l = r = nullptr;
		cnt = 0;
	}
};

const int MAXN = 5e6 + 7;
Node nodes[MAXN];
int last_node = 0;
Node* new_node() {
	return &nodes[last_node++];
}

int n;
vector<vector<pair<int, ll>>> g;
ll d[N];

Node* rt = new_node();

void dfs(int v, int p) {
	for (int i = 0; i < g[v].size(); i++) {
		int to = g[v][i].first;
		ll len = g[v][i].second;
		if (to == p) continue;
		d[to] = d[v] ^ len;
		dfs(to, v);
	}
	return;
}

map<ll, int> cs;

void add(ll x, Node* rt, int bt) {
	if (bt == -1) {
		rt->cnt++;
		return;
	}
	if ((1ll << bt) & x) {
		if (!rt->r) rt->r = new_node();
		add(x, rt->r, bt - 1);
		rt->cnt++;
	}
	else {
		if (!rt->l) rt->l = new_node();
		add(x, rt->l, bt - 1);
		rt->cnt++;
	}
}

int gct(Node* a) {
	if (!a) return 0;
	return a->cnt;
}

ll get_mx(ll x, Node* rt, int bt, ll res) {
	if (bt == -1) {
		return res;
	}
	bool lft = true;
	if ((1ll << bt) & x) {
		if (gct(rt->l) == 0) {
			lft = false;
		}
	}
	else {
		if (gct(rt->r) > 0) lft = false;
	}
	if (lft) return get_mx(x, rt->l, bt - 1, res);
	else return get_mx(x, rt->r, bt - 1, res + (1ll << bt));
}

void SOLVE() {
	cin >> n;
	g.resize(n);
	int x, y;
	ll c;
	for (int i = 0; i < n - 1; i++) {
		cin >> x >> y >> c;
		x--; y--;
		g[x].pb(mp(y, c));
		g[y].pb(mp(x, c));
	}
	d[0] = 0;
	dfs(0, -1);
	for (int i = 0; i < n; i++) {
		add(d[i], rt, B);
		cs[d[i]] = i;
	}
	ll ans = 0;
	int a1 = 0, a2 = 0;
	for (int i = 0; i < n; i++) {
		int y = get_mx(d[i], rt, B, 0);
		if (ans < (y ^ d[i])) {
			ans = y ^ d[i];
			a1 = cs[y];
			a2 = i;
		}
	}
	cout << a1 + 1 << pp << a2 + 1 << nn;
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