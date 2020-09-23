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
const int INF = 1e9, MOD = 1e9 + 7, P = 31, N = 5e2 + 1, K = 1e4, L = 18;
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
const char sep[] = "\n";

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

bool is_word(string const& s, bool num_start) {
	if (isdigit(s[0]) && !num_start) {
		return false;
	}

	bool has_n_dig = false;

	for (char c : s) {
		has_n_dig |= isalpha(c);
		has_n_dig |= (c == '_');
		
		if (c != '_' && !isdigit(c) && !isalpha(c)) {
			return false;
		}
	}

	return has_n_dig;
}

bool is_valid_c(char c) {
	return (c == '_') || isalpha(c) || isdigit(c);
}

int main() {
	int n;
	cin >> n;
	bool reg_sence = false;
	bool num_start = false;
	string s;

	cin >> s;
	if (s[0] == 'y') {
		reg_sence = true;
	}

	cin >> s;

	if (s[0] == 'y') {
		num_start = true;
	}

	set<string> st;
	map<string, pair<int, int>> cnt;
	int occur_ptr = 0;

	for (int i = 0; i < n; i++) {
		cin >> s;
		if (!reg_sence) {
			for (char& c : s) {
				c = tolower(c);
			}
		}
		st.insert(s);
	}

	while (cin >> s) {
		string s_valid;
		bool new_s = false;

		for (char c : s) {
			if (!reg_sence) {
				c = tolower(c);
			}
			if (is_valid_c(c)) {
				if (new_s) {
					if (is_word(s_valid, num_start) && st.count(s_valid) == 0) {
						if (!cnt.count(s_valid)) {
							cnt[s_valid].first = occur_ptr++;
						}
						++cnt[s_valid].second;
					}

					s_valid.clear();
					new_s = false;
					s_valid += c;
				} else {
					s_valid += c;
				}
			} else {
				new_s = true;
			}
		}

		if (!s_valid.empty()) {
			if (is_word(s_valid, num_start) && st.count(s_valid) == 0) {
				if (!cnt.count(s_valid)) {
					cnt[s_valid].first = occur_ptr++;
				}
				++cnt[s_valid].second;
			}
		}
	}

	string ans;
	int cnt_ans = 0, occ_ans = INF;

	for (auto&[st, st_cnt] : cnt) {
		if (st_cnt.second > cnt_ans || (st_cnt.second == cnt_ans && occ_ans > st_cnt.first)) {
			ans = st;
			cnt_ans = st_cnt.second;
			occ_ans = st_cnt.first;
		}
	}

	cout << ans << '\n';
}