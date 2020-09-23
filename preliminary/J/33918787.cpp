#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef string str;

#define pb push_back
#define ppp pop_back
#define pii pair<int,int>
#define fi first
#define se second
#define stie std::tie
#define vec vector
#define	forn(i, l, r) for (int i=l; i<=r; i++)
#define emp empty
#define beg begin
#define ins insert
#define cle clear
#define era erase
#define que queue
#define pque priority_queue
#define mset multiset
#define deq deque
#define sta stack
#define con const
#define rsz resize
#define ass assign
#define lowb lower_bound
#define uppb upper_bound

template<class T> void mini(T& a, T b) { a = min(a, b); }
template<class T> void maxi(T& a, T b) { a = max(a, b); }
template<class T1, class T2> ostream& operator<<(ostream &out, pair<T1, T2> a) { return out << a.first << " " << a.second; }
template<class T> ostream& operator<<(ostream& out, vector<T> a) { for (auto& i : a) out << i << " "; return out; }
template<class T> ostream& operator<<(ostream& out, set<T> a) { for (auto& i : a) out << i << " "; return out; }
template<class T> ostream& operator<<(ostream& out, multiset<T> a) { for (auto& i : a) out << i << " "; return out; }
template<class T1, class T2> ostream& operator<<(ostream& out, map<T1, T2> a) { for (auto& i : a) out << i << "\n"; return out; }
template<class T1, class T2> ostream& operator<<(ostream& out, unordered_map<T1, T2> a) { for (auto& i : a) out << i << "\n"; return out; }
template<class T> ostream& operator<<(ostream& out, queue<T> a) { while (!a.empty()) { cout << a.front() << " "; a.pop(); } return out; }
template<class T> ostream& operator<<(ostream& out, deque<T> a) { while (!a.empty()) { cout << a.front() << " "; a.pop_front(); } return out; }
template<class T> ostream& operator<<(ostream& out, priority_queue<T> a) { while (!a.empty()) { cout << a.top() << "\n"; a.pop(); } return out; }
template<class T> void out(T a) { cout << a << endl; }
template<class T1, class T2> void out(T1 a, T2 b) { cout << a << " " << b << endl; }
template<class T1, class T2, class T3> void out(T1 a, T2 b, T3 c) { cout << a << " " << b << " " << c << endl; }
template<class T1, class T2, class T3, class T4> void out(T1 a, T2 b, T3 c, T4 d) { cout << a << " " << b << " " << c << " " << d << endl; }
template<class T> void out(vector<vector<T>> a) { for (vector<T> i : a) out(i); }
void out() { cout << "OK" << endl; }
template<class T> void sort(vector<T>& a) { sort(a.begin(), a.end()); }
template<class T> void uniq(vector<T>& a) { sort(a); a.erase(unique(a.begin(), a.end()), a.end()); }
template<class T> vector<T> set_int(vector<T> a, vector<T> b) { sort(a); sort(b); vector<T> res; set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(res)); return res; }
clock_t start_time; double get_time() { return (double)(clock() - start_time) / CLOCKS_PER_SEC; }
#if __SIZEOF_INT128__ >= 16
typedef __int128 LL;
istream& operator>>(istream& in, __int128& a) { int64_t b; cin >> b; a = b; return in; }
ostream& operator<<(ostream& out, const __int128 a) {
    unsigned __int128 b = a < 0 ? -a : a; char buf[128]; char* c = end(buf); do { --c; *c = "0123456789"[b % 10]; b /= 10; } while (b);
    if (a < 0) { --c; *c = '-'; } int len = end(buf) - c; out.rdbuf()->sputn(c, len); return out;
}
#endif

con int N = 1005;

char a[N][N];
vec<pii> b;

void Solve() {
	forn(i, 0, N-1) {
		forn(j, 0, N-1) {
			a[i][j] = '.';
		}
	}
	int n, m;
	cin >> n >> m;
	forn(i, 1, n) {
		if (i & 1) {
			forn(j, 1, m) {
				b.pb({i, j});
			}
		}
		else {
			for (int j=m; j>=1; j--) {
				b.pb({i, j});
			}
		}
	}
	int left = n * m;
	int ptr = 0;
	int ans = 0;
	for (int tar = 1; ; tar++) {
		if (tar + tar + 1 > left) {
			tar = left;
		}
		vec<pii> lol;
		forn(kek, 1, min(left, tar)) {
			pii cur = b[ptr++];
			lol.pb(cur);
		}
		set<char> kek;
		for (pii cur : lol) {
			int i = cur.fi;
			int j = cur.se;
			kek.ins(a[i-1][j]);
			kek.ins(a[i+1][j]);
			kek.ins(a[i][j-1]);
			kek.ins(a[i][j+1]);
		}
		char x = '.';
		for (char c='A'; c<='Z'; c++) {
			if (!kek.count(c)) {
				x = c;
				break;
			}
		}
		assert(x != '.');
		for (pii cur : lol) {
			int i = cur.fi;
			int j = cur.se;
			a[i][j] = x;
		}
		left -= min(tar, left);
		ans++;
		if (!left) break;
	}
	cout << ans << "\n";
	forn(i, 1, n) {
		forn(j, 1, m) {
			cout << a[i][j];
		}
		cout << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
	start_time = clock();
	Solve();
	return 0;
}
