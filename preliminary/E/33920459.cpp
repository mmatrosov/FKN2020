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
int readBoolean() {
	return fetch<string>() == "yes";
}
template<typename FuncS, typename Func>
vector<string> split(const string& text, FuncS predicateStart, Func predicate) {
	const int n = len(text);
	vector<string> words;
	int i = 0;
	while(i < n) {
		if(!predicate(text[i])) {
			++i;
		} else {
			int j = i;
			string word;
			while(j < n && predicate(text[j])) {
				word.push_back(text[j++]);
			}
			words.emplace_back(word);
			i = j;
		}
	}
	return words;
}
char toLower(char ch) {
	return (ch >= 'A' && ch <= 'Z' ? ch - 'A' + 'a' : ch);
}
string toLower(string s) {
	for(auto& ch: s) ch = toLower(ch);
	return s;
}
void solve() {
	//for(char ch = 0; ch >= 0; ++ch) if(isalpha(ch)) cout << ch;
	const int numKeywords = fetch<int>();
	const int caseSensitive = readBoolean();
	const int canBeginWithDigit = readBoolean();
	const auto keywords = fetch_vec<string>(numKeywords);
	string sourceCode;
	while(true) {
		char ch = cin.get();
		if(ch >= 0) sourceCode.push_back(ch);
		if(cin.eof()) {
			break;
		}
	}
	const auto pStart = [&](char ch) -> int {
		if(canBeginWithDigit) {
			return isalnum(ch) || ch == '_';
		} else {
			return isalpha(ch) || ch == '_';
		}
	};
	const auto p = [&](char ch) -> int {
		return isalnum(ch) || ch == '_';
	};
	const auto words = split(sourceCode, pStart, p);
	const auto isIdentifier = [&](const string& word) -> int {
		const int n = len(word);
		if(isdigit(word[0]) && !canBeginWithDigit) {
			return 0;
		}
		int onlyDigits = 1;
		for(auto& ch: word) {
			if(!isdigit(ch)) {
				onlyDigits = 0;
				break;
			}
		}
		if(onlyDigits) {
			return 0;
		}
		for(auto& keyword: keywords) {
			if(len(keyword) == n) {
				int same = 1;
				for(int i = 0; i < n; ++i) {
					if(caseSensitive) {
						if(keyword[i] != word[i]) {
							same = 0;
							break;
						}
					} else {
						if(toLower(keyword[i]) != toLower(word[i])) {
							same = 0;
							break;
						}
					}
				}
				if(same) {
					return 0;
				}
			}
		}
		return 1;
	};
	map<string, int> frequency;
	string answ;
	int answFreq = 0;
	DBG(words);
	for(auto& word: words) {
		if(isIdentifier(word)) {
			++frequency[caseSensitive ? word : toLower(word)];
		}
	}
	for(auto& word: words) {
		if(isIdentifier(word)) {
			int wordFreq = frequency[caseSensitive ? word : toLower(word)];
			if(wordFreq > answFreq) {
				tie(answ, answFreq) = tie(word, wordFreq);
			}
		}
	}
	cout << (caseSensitive ? answ : toLower(answ)) << '\n';
	DBG(answFreq);
}

int main() {
	fast_io();
	solve();

	return 0;
}
