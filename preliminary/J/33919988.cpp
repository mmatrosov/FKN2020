#include <iostream>
#include <iomanip>
#include <random>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <sstream>
#include <bitset>
#include <cassert>
#include <fstream>
#include <queue>

#define len(X) ((int)(X).size())

#ifdef __LOCAL
	#define DEBUG_OUTPUT_ENABLED 1
	#define DBG(X) dout << #X << "=" << (X) << '\n';
	#define SAY(X) dout << (X) << '\n';
#else
	#define DEBUG_OUTPUT_ENABLED 0
	#define DBG(X) 42;
	#define SAY(X) 42;
#endif

#define dout   ___debug::instance

using namespace std;
using ll = long long int;
using ull = unsigned long long int;
using ld  = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const set<T>& v) { for(auto el: v) cout << el << " "; return os; }
template<typename T, typename S> inline ostream& operator<<(ostream& os, const map<T, S>& v) { for(auto el: v) cout << el << " "; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const multiset<T>& v) { for(auto el: v) cout << el << " "; return os; }
namespace ___debug {
	struct DebugStream {
		private:
			bool is_first;
		public:
			DebugStream(bool _is_first): is_first(_is_first) {}
			template<typename T> DebugStream operator<<(const T& value) const {
				assert(DEBUG_OUTPUT_ENABLED);
				if(is_first) cout << "[DBG] ";
				cout << value;
				return DebugStream(false);
			};

			template<typename T> DebugStream printArray(T* l, T* r) {
				assert(DEBUG_OUTPUT_ENABLED);
				if(is_first) cout << "[DBG] ";
				while(l != r) {
					cout << (*l);
					++l;
					if(l == r) {
						cout << '\n';
					} else {
						cout << ' ';
					}
				}
				return DebugStream(false);
			}
	};
	DebugStream instance(true);
};

const int INT_INF = (int)(2e9);
const ll  LL_INF  = (ll)(2e18);

const int NIL = -1;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T> inline T fetch() { T ret; cin >> ret; return ret; }
template<typename T> inline vector<T> fetch_vec(int sz) { vector<T> ret(sz); for(auto& elem: ret) cin >> elem; return ret; }
template<typename T> inline void makeUnique(vector<T>& v) { sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end()); }
const int MAXN = 1007;
const int MAXK = (int)1e5;
int A[MAXN][MAXN];
vector<int> G[MAXK];
int color[MAXK];
void solve() {
	int n = fetch<int>();
	int m = fetch<int>();
	vector<pii> ord;
	for(int i = 0; i < n; ++i) {
		if(i & 1) {
			for(int j = m - 1; j >= 0; --j) {
				ord.emplace_back(i, j);
			}
		} else {
			for(int j = 0; j < m; ++j) {
				ord.emplace_back(i, j);
			}
		}
	}
	int k = 0;
	int sz = 1;
	while(len(ord) >= sz) {
		DBG(sz);
		for(int idx = 0; idx < sz; ++idx) {
			auto [i, j] = ord.back(); ord.pop_back();
			A[i][j] = k;
		}
		++k;
		++sz;
	}
	while(!ord.empty()) {
		auto [i, j] = ord.back(); ord.pop_back();
		A[i][j] = k - 1;
	}
	for(int i = 0; i < n - 1; ++i) {
		for(int j = 0; j < m; ++j) {
			int a = A[i][j];
			int b = A[i + 1][j];
			if(a != b) {
				G[a].emplace_back(b);
				G[b].emplace_back(a);
			}
		}
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m - 1; ++j) {
			int a = A[i][j];
			int b = A[i][j + 1];
			if(a != b) {
				G[a].emplace_back(b);
				G[b].emplace_back(a);
			}
		}
	}
	vector<pii> vOrd(k);
	for(int i = 0; i < k; ++i) {
		makeUnique(G[i]);
		DBG(len(G[i]));
		color[i] = NIL;
		vOrd[i] = make_pair(len(G[i]), i);
	}
	sort(vOrd.begin(), vOrd.end());
	for(auto& [_, i]: vOrd) {
		DBG(i);
		set<int> badColors;
		for(auto& j: G[i]) {
			if(color[j] >= 0) {
				badColors.insert(color[j]);
			}
		}
		color[i] = 0;
		while(badColors.count(color[i])) {
			++color[i];
		}
		DBG(color[i]);
	}
	cout << k << '\n';
	for(int i = 0; i < n; ++i) {
		string S(m, '%');
		for(int j = 0; j < m; ++j) {
			int c = color[A[i][j]];
			assert(c < 26 && c >= 0);
			S[j] = 'A' + c;
		}
		cout << S << '\n';
	}
}

int main() {
	fast_io();
	solve();

	return 0;
}
