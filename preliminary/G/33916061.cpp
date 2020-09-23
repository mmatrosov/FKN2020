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
const int MAXN = (int)1e5 + 777;
vector<pair<int, ll>> G[MAXN];
int n;
ll a[MAXN];
void dfs(int v, int p) {
	for(auto& [u, w]: G[v]) {
		if(u == p) continue;
		a[u] = a[v] ^ w;
		dfs(u, v);
	}
}
pair<vector<int>, vector<int>> split(const vector<int>& idx, ll mask) {
	vector<int> idx0, idx1;
	for(auto& i: idx) {
		if(a[i] & mask) {
			idx1.emplace_back(i);
		} else {
			idx0.emplace_back(i);
		}
	}
	return {idx0, idx1};
}
pair<ll, pii> inc(pair<ll, pii> x, ll d) {
	x.first += d;
	return x;
}
pair<ll, pii> calc(const vector<int>& lhs, const vector<int>& rhs, ll mask) {
	if(lhs.empty() || rhs.empty()) return {-LL_INF, {NIL, NIL}};
	if(mask == 0) return {0, {lhs.front(), rhs.front()}};
	if(len(lhs) <= 20 || len(rhs) <= 20) {
		pair<ll, pii> answ = {-LL_INF, {NIL, NIL}};
		for(auto& i: lhs) {
			for(auto& j: rhs) {
				pair<ll, pii> loc = {(a[i] ^ a[j]) & (2LL * mask - 1LL), {i, j}};
				if(loc > answ) answ = loc;
			}
		}
		return answ;
	}
	int canSkip = 1;
	for(auto& i: lhs) {
		if(a[i] & mask) {
			canSkip = 0;
			break;
		}
	}
	for(auto& i: rhs) {
		if(a[i] & mask) {
			canSkip = 0;
			break;
		}
	}
	if(canSkip) {
		return calc(lhs, rhs, mask >> 1LL);
	}
	const auto [lhs0, lhs1] = split(lhs, mask);
	const auto [rhs0, rhs1] = split(rhs, mask);
	if((!lhs0.empty() && !rhs1.empty()) || (!lhs1.empty() && !rhs0.empty())) {
		const auto answ01 = inc(calc(lhs0, rhs1, mask >> 1LL), mask);
		const auto answ10 = inc(calc(lhs1, rhs0, mask >> 1LL), mask);
		return max(answ01, answ10);
	}
	const auto answ00 = calc(lhs0, rhs0, mask >> 1LL);
	const auto answ11 = calc(lhs1, rhs1, mask >> 1LL);
	return max(answ00, answ11);
}
void stress(int n) {
	for(int i = 0; i < n; ++i) {
		a[i] = randint(0, (1LL << 4LL) - 1LL);
	}
	vector<int> idx(n);
	for(int i = 0; i < n; ++i) idx[i] = i;
	const auto [bestValue, vu] = calc(idx, idx, 1LL << 32LL);
	ll trueAnsw = -LL_INF;
	pii trueAnswPos;
	for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) {
		ll loc = a[i] ^ a[j];
		if(loc > trueAnsw) {
			trueAnsw = loc;
			trueAnswPos = {i, j};
		}
	}
	if(trueAnsw == bestValue) {
		cout << "OK\n";
	} else {
		cout << "NOT OK\n";
		DBG(trueAnsw);
		DBG(trueAnswPos);
		DBG(bestValue);
		DBG(vu);
		DBG(n);
		for(int i = 0; i < n; ++i) {
			cout << a[i] << ' ';
		}
		cout << '\n';
		exit(-1);
	}
}
void solve() {
	cin >> n;
	for(int i = 0; i < n - 1; ++i) {
		int v = fetch<int>() - 1;
		int u = fetch<int>() - 1;
		ll w = fetch<ll>();
		G[v].emplace_back(u, w);
		G[u].emplace_back(v, w);
	}
	dfs(0, NIL);
	vector<int> idx(n);
	for(int i = 0; i < n; ++i) idx[i] = i;
	const auto [bestValue, vu] = calc(idx, idx, 1LL << 32LL);
	cout << vu.first + 1 << ' ' << vu.second + 1 << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}
