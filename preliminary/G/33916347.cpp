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
const int INF = 1e9, MOD = 1e9 + 7, P = 31, N = 1e5 + 10, K = 1e4, L = 18;
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

vector<pair<int, long long>> g[N];
vector<int> ord;
long long rt_xor[N];

void dfs_precalc(int v, int p, long long p_w) {
	rt_xor[v] = rt_xor[p] ^ p_w;
	ord.push_back(v);

	for (auto [u, w] : g[v]) {
		if (u != p) {
			dfs_precalc(u, v, w);
		}
	}
}

struct node {
	node* c[2] = { nullptr, nullptr };
	int vrt_id = 0;
};

node mem_t[N * 33];
int mem_t_ptr = 0;
node* new_node() {
	assert(mem_t_ptr < N * 33);
	return mem_t + mem_t_ptr++;
}

void add_val(node* root, long long val, int vrt_id) {
	for (long long i = 32; i >= 0; i--) {
		long long bt = (val & (1u << i)) >> i;
		if (root->c[bt] == nullptr) {
			root->c[bt] = new_node();
		}
		root = root->c[bt];
	}

	root->vrt_id = vrt_id;
}

pair<int, long long> get_max_vrt(node* root, long long val) {
	long long res = 0;
	
	for (long long i = 32; i >= 0; i--) {
		long long bt = (val & (1u << i)) >> i;

		if (root->c[1 - bt] != nullptr) {
			res += (1u << i);
			root = root->c[1 - bt];
		} else if (root->c[bt] != nullptr) {
			root = root->c[bt];
		} else {
			return { 0, 0 };
		}
	}

	return { root->vrt_id, res };
}

int main() {
	int n;
	cin >> n;

	for (int i = 1, v, u; i < n; i++) {
		long long w;
		cin >> v >> u >> w;
		g[v].push_back({ u, w });
		g[u].push_back({ v, w });
	}

	dfs_precalc(1, 0, 0);

	node* root = new_node();
	pair<int, int> ans;
	long long ans_val = 0;

	for (auto v : ord) {
		auto p = get_max_vrt(root, rt_xor[v]);
		if (p.second > ans_val) {
			ans = { v, p.first };
			ans_val = p.second;
		}

		add_val(root, rt_xor[v], v);
	}

	if (n == 1 || ans_val == 0) {
		cout << "1 1\n";
	} else {
		cout << ans.first << ' ' << ans.second << '\n';
	}
}