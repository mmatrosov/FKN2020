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
const int INF = 1e9, MOD = 1e9 + 7, P = 31, N = 1e2 + 1, K = 1e4, L = 18;
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

int dp[N][N][N];
int p[N][N][N];

int main() {
	int n, k_cnt;
	cin >> n >> k_cnt;
	vector<int> c(n);
	cin >> c;

	if (k_cnt >= n) {
		sort(c.begin(), c.end());
		while (c.size() < k_cnt) {
			c.push_back(c.back() + 1);
		}
		cout << c << '\n';
		return 0;
	}

	c.push_back(0);
	sort(c.begin(), c.end());

	for (int i = 1; i <= n; i++) {
		for (int k = 0; k < min(i, k_cnt + 1); k++) {
			for (int prv = 0; prv < i; prv++) {
				if (k != 0) {
					dp[i][k][prv] = dp[i - 1][k][prv] + c[prv];
				}

				if (k + 1 <= k_cnt && dp[i][k + 1][i] < dp[i - 1][k][prv] + c[i]) {
					dp[i][k + 1][i] = dp[i - 1][k][prv] + c[i];
					p[i][k + 1][i] = prv;
				}
			}
		}
	}

	int max_pos = 0, pos = n;

	for (int i = 1; i <= n; i++) {
		if (dp[n][k_cnt][i] > dp[n][k_cnt][max_pos]) {
			max_pos = i;
		}
	}

	vector<int> ans;

	while (pos > 0) {
		if (p[pos][k_cnt][max_pos] != 0) {
			ans.push_back(c[max_pos]);
			max_pos = p[pos][k_cnt][max_pos];
			--pos;
			--k_cnt;
		} else {
			--pos;
		}
	}

	ans.push_back(c[max_pos]);
	--k_cnt;

	sort(ans.begin(), ans.end());

	while (k_cnt > 0) {
		ans.push_back(ans.back() + 1);
		--k_cnt;
	}

	cout << ans << '\n';
}