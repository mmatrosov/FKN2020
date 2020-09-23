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
const int MAXN = 107;
ll a[MAXN], dp[MAXN][MAXN];
int calced[MAXN][MAXN], parent[MAXN][MAXN];
int n, k;
void solve() {
	cin >> n >> k;
	int requiredAnswSize = k;
	if(k > n) k = n;
	for(int i = 0; i < n; ++i) cin >> a[i];
	sort(a, a + n);
	calced[0][0] = 1;
	for(int j = 0; j < k; ++j) {
		for(int i = 0; i < n; ++i) {
			if(!calced[i][j]) continue;
			for(int i2 = i + 1; i2 <= n; ++i2) {
				ll value = dp[i][j] + (i2 - i) * a[i];
				if(calced[i2][j + 1]) {
					if(value > dp[i2][j + 1]) {
						dp[i2][j + 1] = value;
						parent[i2][j + 1] = i;
					}
				} else {
					dp[i2][j + 1] = value;
					parent[i2][j + 1] = i;
				}
				calced[i2][j + 1] = 1;
			}
			if(calced[i + 1][j]) {
				if(dp[i][j] > dp[i + 1][j]) {
					dp[i + 1][j] = dp[i][j];
					parent[i + 1][j] = NIL;
				}
			} else {
				dp[i + 1][j] = dp[i][j];
				parent[i + 1][j] = NIL;
			}
			calced[i + 1][j] = 1;
		}
	}
	assert(calced[n][k]);
	vector<ll> answ;
	int i = n, j = k;
	DBG(i); DBG(j);
	while(i || j) {
		int p = parent[i][j];
		if(p == NIL) {
			--i;
		} else {
			answ.emplace_back(a[p]);
			i = p, --j;
		}
		DBG(i); DBG(j);
	}
	sort(answ.begin(), answ.end());
	ll veryBig = a[n - 1] + 1;
	while(len(answ) < requiredAnswSize) {
		answ.emplace_back(veryBig++);
	}
	cout << answ << '\n';
	DBG(dp[n][k]);
}

int main() {
	fast_io();
	solve();

	return 0;
}
