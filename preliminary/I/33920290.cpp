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

int s, f;
int n, m, k, a[N];
LL die[N], dist[N];
vector <pair<int, int>> gr[N];

void calc_die() {
	fill(die, die + n, LINF);
	set <pair<LL, int>> st;
	for (int i = 0; i < k; i++) {
		die[a[i]] = 0;
		st.insert(mp(0, a[i]));
	}
	while (size(st) > 0) {
		int u = (*st.begin()).second;
		st.erase(st.begin());
		for (auto it : gr[u]) {
			int v, len;
			tie(v, len) = it;
			if (die[v] > die[u] + len) {
				st.erase(mp(die[v], v));
				die[v] = die[u] + len;
				st.insert(mp(die[v], v));
			}
		}
	}
}

void get_ans() {
	fill(dist, dist + n, LINF);
	dist[s] = 0;
	set <pair<LL, int>> st = { mp(0, s) };
	while (size(st) > 0) {
		int u = (*st.begin()).second;
		st.erase(st.begin());
		for (auto it : gr[u]) {
			int v, len;
			tie(v, len) = it;
			if (dist[v] > dist[u] + len && die[v] > dist[u] + len) {
				st.erase(mp(dist[v], v));
				dist[v] = dist[u] + len;
				st.insert(mp(dist[v], v));
			}
		}
	}
	cout << (dist[f] == LINF ? -1 : dist[f]);
}

void solve() {
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		cin >> a[i];
		a[i]--;
	}
	for (int i = 0; i < m; i++) {
		int u, v, l;
		cin >> u >> v >> l;
		u--, v--;
		gr[u].push_back(mp(v, l));
		gr[v].push_back(mp(u, l));
	}
	cin >> s >> f;
	s--, f--;
	calc_die();
	get_ans();
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