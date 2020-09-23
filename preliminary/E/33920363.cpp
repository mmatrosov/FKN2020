#include <bits/stdc++.h>
 
using namespace std;

//#define int long long
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

void norm(string &s, string &c) {
	if (c[0] == 'y') {
		return;
	}
	for (int i = 0; i < (int)s.length(); ++i) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			s[i] = 'a' + s[i] - 'A';
		}
	}
}

bool good(char c) {
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '_');
}

bool digit(char c){
	return (c >= '0' && c <= '9');
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//cout.setf(ios::fixed);
	//cout.precision(20);

	int n;
	string c, d;
	cin >> n >> c >> d;
	unordered_set<string> setik;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		norm(s, c);
		setik.insert(s);
	}
	unordered_map<string, int> mapa, cnt;
	int cur = 0;
	string s;
	while (cin >> s) {
		norm(s, c);
		s += '-';
		bool in = false, nd = false, st = false;
		string res = "";
		for (char ch : s) {
			if (!in && good(ch)) {
				in = true;
				nd = !digit(ch);
				st = digit(ch);
				res += ch;
			}
			else if (in) {
				if (good(ch)) {
					nd |= !digit(ch);
					res += ch;
				}
				else {
					in = false;
					if (st && d[0] == 'n' || !nd) {
						res = "";
					}
					else {
						if (setik.count(res)) {
							res = "";
						}
						else {
							if (!mapa.count(res)) {
								mapa[res] = cur;
							}
							cnt[res]++;
							cur++;
							res = "";
						}
					}
				}
			}
		}
	}
	int mx = 0;
	string ans = "";
	for (auto it : cnt) {
		if (it.second > mx || (it.second == mx && mapa[it.first] < mapa[ans])) {
			mx = it.second;
			ans = it.first;
		}
	}
	cout << ans << '\n';
}