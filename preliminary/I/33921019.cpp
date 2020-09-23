#pragma region Include
#include<algorithm>
#include<assert.h>
//#include<bitset>
//#include<complex>
#include<ctime>
#include<cmath>
#include<fstream>
//#include <functional>
#include<iostream>
//#include<iterator>
#include<map>
//#include<queue>
#include<random>
//#include<stack>
#include<set>
#include<string>
#include<tuple>
#include<utility>
//#include<unordered_map>
//#include<unordered_set>
#include<vector>
using namespace std;
#pragma endregion
#pragma region Constant
const long long llINF = 1e18 + 1, llMOD = 1e9 + 7;
const int INF = 1e9, MOD = 1e9 + 7, P = 31, N = 2e5 + 10, K = 1e4, L = 18;
const long double EPS = 1e-8, ldINF = 1e18, PI = acos(-1);
#pragma endregion
#pragma region Utill
template<typename T>
inline void sort_uniq(vector<T>& v) {
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
}

template<typename T>
bool rel_min(T& rel_val, T const& n_val) {
	if (rel_val > n_val) {
		rel_val = n_val;
		return true;
	}

	return false;
}
#pragma endregion
#pragma region IO
const char sep[] = " ";

template <typename T, typename P>
istream& operator >> (istream &in, pair<T, P> &p) {
	in >> p.first >> p.second;
	return in;
}

template<typename T>
void in_seg(istream &in, T *dst_begin, T *dst_end) {
	while (dst_begin != dst_end) {
		in >> (*dst_begin);
		++dst_begin;
	}
}

template <typename T>
istream& operator >> (istream &in, vector<T> &v) {
	for (T& i : v) {
		in >> i;
	}
	return in;
}

template<typename T, typename P>
ostream& operator << (ostream &out, pair<T, P> const& p) {
	out << p.first << ' ' << p.second;
	return out;
}

template <typename T>
ostream& operator << (ostream &out, vector<T> const& v) {
	for (T const& i : v) {
		out << i << sep;
	}
	
	if (!v.empty()) {
		out << '\n';
	}

	return out;
}

template <typename T>
ostream& operator << (ostream& out, vector<vector<T>> const& v) {
	for (vector<T> const& i : v) {
		out << i;
	}

	return out;
}

void set_precision(ostream &out, int val) {
	out.setf(out.fixed, out.floatfield);
	out.precision(val);
}
#pragma endregion

vector<pair<int, int>> g[N];

int main() {
	int n, m, k, s, f;
	cin >> n >> m >> k;

	set<pair<int, int>> q;
	vector<long long> dst_a(n + 1, llINF);

	for (int i = 0, v; i < k; i++) {
		cin >> v;
		q.insert({ 0, v });
		dst_a[v] = 0;
	}

	for (int i = 0, v, u, w; i < m; i++) {
		cin >> v >> u >> w;
		g[v].push_back({ u, w });
		g[u].push_back({ v, w });
	}

	cin >> s >> f;

	while (!q.empty()) {
		int v = q.begin()->second;
		q.erase(q.begin());

		for (auto[u, w] : g[v]) {
			if (dst_a[u] > dst_a[v] + w) {
				q.erase({ dst_a[u], u });
				dst_a[u] = dst_a[v] + w;
				q.insert({ dst_a[u], u });
			}
		}
	}

	vector<long long> dst_b(n + 1, llINF);
	dst_b[s] = 0;
	q.insert({ 0, s });

	while (!q.empty()) {
		int v = q.begin()->second;
		q.erase(q.begin());

		for (auto[u, w] : g[v]) {
			if (dst_b[u] > dst_b[v] + w && dst_a[u] > dst_b[v] + w) {
				q.erase({ dst_b[u], u });
				dst_b[u] = dst_b[v] + w;
				q.insert({ dst_b[u], u });
			}
		}
	}

	if (dst_b[f] == llINF) {
		cout << "-1\n";
	} else {
		cout << dst_b[f] << '\n';
	}
}