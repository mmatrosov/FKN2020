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

//static constexpr int MAX = 2000000;
//
//std::vector<int> items;
//std::vector<int> sufSum;
//int stepsCounter;
//
//bool RunKnapsack(int n, int X, int sum, int i) {
//	++stepsCounter;
//	if (stepsCounter >= MAX) {
//		return false;
//	}
//	if (sum == X) {
//		return true;
//	}
//	if ((i == n) || (sum > X) || (sum + sufSum[i] < X))
//		return false;
//	
//	if (RunKnapsack(n, X, sum, i + 1))
//		return true;
//	return RunKnapsack(n, X, sum + items[i], i + 1);
//}
//
//pair<bool, int> solve(vector<int> itm, int n_in, int x_in) {
//	items.clear();
//	sufSum.clear();
//	stepsCounter = 0;
//	//ifstream cin("input.txt");
//	
//	int n, X;
//	//cin >> n >> X;
//	n = n_in;
//	X = x_in;
//	//items.resize(n);
//	items = itm;
//	sufSum.resize(n);
//	
//	//for (int i = 0; i < n; ++i) {
//	//	cin >> items[i];
//	//}
//	
//	sort(items.begin(), items.end());
//	reverse(items.begin(), items.end());
//	
//	for (int i = n - 1; i >= 0; --i) {
//		if (i == n - 1)
//			sufSum[i] = items[i];
//		else
//			sufSum[i] = sufSum[i + 1] + items[i];
//	}
//	
//	auto res = RunKnapsack(n, X, 0, 0);
//	return { res , stepsCounter };
//}

/*

84692










*/

int main() {
	cout << "30 972402\n";
	vector<int> arr = {
		57671,
		69609,
		77117,
		84692,
		88354,
		88704,
		94340,
		101977,
		104892,
		105090,
		107253,
		107561,
		109297,
		126906,
		157404,
		173308,
		187233,
		196153,
		198571,
		201088,
		207223,
		212218,
		226500,
		241574,
		251108,
		251638,
		262687,
		265455,
		274002,
		298111 };

	for (int i : arr) {
		cout << i << '\n';
	}
}