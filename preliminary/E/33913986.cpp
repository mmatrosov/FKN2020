#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(aaa) aaa.begin(), aaa.end()

bool check(char c) {
	return isalpha(c) || c == '_' || isdigit(c);
}

void to_lower_c(string &s) {
	for (char &c : s) {
		if (c >= 'A' && c <= 'Z') {
			c = 'a' + c - 'A';
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	bool case_sens;
	bool start_dig;

	cin >> n;

	string s;
	cin >> s;

	case_sens = (s[0] == 'y');

	cin >> s;
	start_dig = (s[0] == 'y');

	set<string> keywords;

	for (int i = 0; i < n; i++) {
		string g;
		cin >> g;
		if (!case_sens)
			to_lower_c(g);
		keywords.insert(g);
	}

	string t, anime;

	while (getline(cin, anime)) {
		t += anime;
		t += "\n";
	}

	if (!case_sens) {
		to_lower_c(t);
	}

	map<string, int> mp;

	int len = t.size();

	for (int i = 0; i < len; ) {
		/*if (!start_dig && isdigit(t[i])) {
			i++;
		}
		else */{
			int x = i;

			bool letter = false;
			while (x < len && check(t[x])) {
				if (!isdigit(t[x]))
					letter = true;
				x++;
			}
			

			if (letter && x != i) {
				string g = t.substr(i, x - i);
				if (start_dig || !isdigit(g[0]))
					if (!keywords.count(g))
					mp[g]++;
			}
			i = x + 1;
		}
	}

	int mx = 0;
	for (const auto &p : mp) {
		mx = max(mx, p.second);
	}

	for (int i = 0; i < len; ) {
		// if (!start_dig && isdigit(t[i])) {
		// 	i++;
		// }
		 {
			int x = i;
			bool letter = false;
			while (x < len && check(t[x])) {
				if (!isdigit(t[x]))
					letter = true;
				x++;
			}

			string g = t.substr(i, x - i);
			if (start_dig || !isdigit(g[0]))
			if (letter && !keywords.count(g) && mp[g] == mx) {
				cout << g << "\n";
				return 0;
			}
			i = x + 1;
		}
	}
	

	return 0;
}