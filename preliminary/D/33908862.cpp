#pragma region Include
#include<algorithm>
#include<assert.h>
#include<bitset>
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
//#include<set>
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

struct pt {
	long long x;
	long long y;

	long long dst_sq() const {
		return x * x + y * y;
	}
};

long long operator % (pt const& lhs, pt const& rhs) {
	return lhs.x * rhs.y - lhs.y * rhs.x;
}

long long operator * (pt const& lhs, pt const& rhs) {
	return lhs.x * rhs.x + lhs.y * rhs.y;
}

istream& operator >> (istream& in, pt& p) {
	in >> p.x >> p.y;
	return in;
}

bool eq(long double x, long double y) {
	return abs(x - y) < EPS;
}

int main() {
	pt a, b;
	cin >> a >> b;
	
	set_precision(cout, 16);
	long double ans = sqrt((long double)(a.dst_sq())) + sqrt((long double)(b.dst_sq()));

 	if (a.dst_sq() == b.dst_sq()) {
		long double ang = atan2((long double)(a % b),(long double)(a * b));
		if (ang < 0) {
			ang = atan2((long double)(b % a), (long double)(b * a));
		}

		ans = min(ans, sqrt((long double)a.dst_sq()) * ang);
	} else if (a.dst_sq() > b.dst_sq()) {
		long double ang = atan2((long double)(a % b), (long double)(a * b));
		if (ang < 0) {
			ang = atan2((long double)(b % a), (long double)(b * a));
		}

		ans = min(ans, sqrt((long double)a.dst_sq()) - sqrt((long double)b.dst_sq()) + sqrt((long double)(b.dst_sq())) * ang);
	} else {
		long double ang = atan2((long double)(a % b), (long double)(a * b));
		if (ang < 0) {
			ang = atan2((long double)(b % a), (long double)(b * a));
		}

		ans = min(ans, sqrt((long double)b.dst_sq()) - sqrt((long double)a.dst_sq()) + sqrt((long double)(a.dst_sq())) * ang);
	}

	cout << ans << '\n';
}