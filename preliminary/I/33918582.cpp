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
const ll  LL_INF  = (ll)(1e18);

const int NIL = -1;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T> inline T fetch() { T ret; cin >> ret; return ret; }
template<typename T> inline vector<T> fetch_vec(int sz) { vector<T> ret(sz); for(auto& elem: ret) cin >> elem; return ret; }
template<typename T> inline void makeUnique(vector<T>& v) { sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end()); }
const int MAXN = (int)2e5 + 7777;
int n, m, k;
vector<pair<int, ll>> G[MAXN];
ll smoke[MAXN], dp[MAXN];
void dijkstra1() {
	set<pair<ll, int>> setik;
	for(int i = 0; i < n; ++i) {
		if(smoke[i] < LL_INF) {
			setik.emplace(smoke[i], i);
		}
	}
	while(!setik.empty()) {
		auto iter = setik.begin();
		int v = iter->second;
		setik.erase(iter);
		for(auto& [u, w]: G[v]) {
			if(smoke[v] + w < smoke[u]) {
				iter = setik.find(make_pair(smoke[u], u));
				if(iter != setik.end()) setik.erase(iter);
				smoke[u] = smoke[v] + w;
				setik.emplace(smoke[u], u);
			}
		}
	}
}
void dijkstra2() {
	set<pair<ll, int>> setik;
	for(int i = 0; i < n; ++i) {
		if(dp[i] < LL_INF) {
			setik.emplace(dp[i], i);
		}
	}
	while(!setik.empty()) {
		auto iter = setik.begin();
		int v = iter->second;
		setik.erase(iter);
		for(auto& [u, w]: G[v]) {
			ll value = dp[v] + w;
			if(value < smoke[u] && value < dp[u]) {
				iter = setik.find(make_pair(dp[u], u));
				if(iter != setik.end()) setik.erase(iter);
				dp[u] = value;
				setik.emplace(dp[u], u);
			}
		}
	}
}
void solve() {
	cin >> n >> m >> k;
	for(int i = 0; i < n; ++i) smoke[i] = dp[i] = LL_INF;
	for(int i = 0; i < k; ++i) {
		int v = fetch<int>() - 1;
		smoke[v] = 0;
	}
	for(int i = 0; i < m; ++i) {
		int v = fetch<int>() - 1;
		int u = fetch<int>() - 1;
		ll w = fetch<ll>();
		G[v].emplace_back(u, w);
		G[u].emplace_back(v, w);
	}
	int s = fetch<int>() - 1;
	int f = fetch<int>() - 1;
	if(smoke[s] > 0) {
		dp[s] = 0;
	}
	dijkstra1();
	dijkstra2();
	cout << (dp[f] < LL_INF ? dp[f] : NIL) << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}
