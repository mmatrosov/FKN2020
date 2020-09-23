#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <deque>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <ctime>
#include <iterator>
#include <bitset>
#include <numeric>
#include <list>
#include <iomanip>
#include <cassert>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <random>
using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define div div228
#define prev prev228
#define free free228
#define close close228
#define int long long
typedef long double ld;
const int BINF = 9e18, LINF = 2e9, mod = 1e9 + 7, P = 179, Q = 1791791791;
typedef long long ll;
string a, b;
set<string> keys;
string f(string s) {
	if (a == "no")
		for (int i = 0; i < s.size(); ++i)
			if ('A' <= s[i] && s[i] <= 'Z') {
				s[i] += 'a';
				s[i] -= 'A';
			}
	return s;
}
bool valid(string s) {
	if (s.size() == 1 && '0' <= s[0] && s[0] <= '9')
		return 0;
	if ('0' <= s[0] && s[0] <= '9' && b == "no")
		return 0;
	return !keys.count(s);
}
void solve() {
    int n;
    cin >> n;
    set<char> c;
    cin >> a >> b;
    c.insert('_');
    for (int i = 0; i < 26; ++i)
    	c.insert('a' + i), c.insert('A' + i);
    for (int i = 0; i < 10; ++i)
    	c.insert('0' + i);
    for (int i = 0; i < n; ++i) {
    	string s;
    	cin >> s;
    	keys.insert(f(s));
    }
    string now = "";
    map<string, int> cnt;
    map<string, int> first;
    int i = 0;
    char ch;
    while (cin.get(ch)) {
    	++i;
    	if (c.count(ch)) {
    		now += ch;
    	} else {
    		if (now.size()) {
    			now = f(now);
    			if (!first.count(now))
    				first[now] = i;
    			cnt[now]++;
    			now = "";
    		}
    	}
    }
    if (now.size()) {
		now = f(now);
		if (!first.count(now))
			first[now] = i;
		cnt[now]++;
		now = "";
	}
	pair<pair<int, int>, string> ans = {{-1, -1}, ""};
	for (auto p : cnt)
		if (valid(p.x))
			ans = max(ans, {{p.y, -first[p.x]}, p.x});
	cout << ans.y << "\n";
    return;
}
signed main() {
    //freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    //cout.precision(40);

    int t = 1;
    //cin >> t;
    for (int i = 0; i < t; ++i)
        solve();

    return 0;
}
