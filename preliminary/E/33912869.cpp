#include <iostream>
#include <set>
#include <map>

using namespace std;

bool inter(char c) {
	return ('0' <= c && c <= '9')
		|| ('A' <= c && c <= 'Z')
		|| ('a' <= c && c <= 'z')
		|| c == '_'; 
}

string read() {
	char c = getchar();
	while (!inter(c) && c != EOF) {
		c = getchar();
	}
	if (c == EOF) return "";
	string rez = "";
	while (inter(c)) {
		rez += c;
		c = getchar();
	}
	return rez;
}

signed main() {
	// freopen("test.in", "r", stdin);
	int n = stoi(read());
	bool Sense = (read() == "yes");
	bool dStart = (read() == "yes");
	auto toStandard = [&](string s) {
		if (!Sense) {
			for (char &c : s) {
				if ('A' <= c && c <= 'Z') {
					c = c - 'A' + 'a';
				}
			}
		}
		return s;
	};
	set<string> key;
	auto valid = [&](string s) {
		bool allDigits = true;
		for (char c : s) {
			if (!('0' <= c && c <= '9')) {
				allDigits = false;
				break;
			}
		}
		if (allDigits) return false;
		if (!dStart && '0' <= s[0] && s[0] <= '9')
			return false;
		if (key.count(s)) return false;
		return true;
	};
	for (int i = 0; i < n; i++) {
		key.insert(toStandard(read()));
	}
	map<string, int> cnt;
	map<string, int> fst;
	int id = 0;
	while (true) {
		string s = toStandard(read());
		if (s.empty()) break;
		if (!valid(s)) continue;
		if (!cnt.count(s)) {
			fst[s] = id++;
		}
		cnt[s]++;
	}
	string rez; int cur = -1e9;
	for (auto p : cnt) {
		if (make_pair(p.second, -fst[p.first]) > make_pair(cur, -fst[rez])) {
			cur = p.second;
			rez = p.first;
		}
	}
	// cout << cur << endl;
	cout << rez;
}