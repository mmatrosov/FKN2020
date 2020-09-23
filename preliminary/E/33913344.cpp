#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <bitset>
#include <iomanip>

using namespace std;

typedef map<int, int> mp;
typedef vector<mp> vc;
typedef vector<int> vi;
typedef vector<unsigned long long> vll;
typedef long long ull;
typedef long long ll;


#define pb  push_back
#define ff  first
#define ss  second
#define sz	size()

bool isGood(char c) {
	if ((c >= 'a') && (c <= 'z'))
		return true;
	if ((c >= 'A') && (c <= 'Z'))
		return true;
	if ((c >= '0') && (c <= '9'))
		return true;
	if (c == '_')
		return true;
	return false;
}

bool isGood2(char c) {
	if ((c >= 'a') && (c <= 'z'))
		return true;
	if ((c >= 'A') && (c <= 'Z'))
		return true;
	if (c == '_')
		return true;
	return false;
}

int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);
	
	set<string> keyWords;
	bool isRegister = false, canStartNumber = false;
	int numK;
	cin >> numK;
	string s;
	cin >> s;
	if (s == "yes")
		isRegister = true;
	cin >> s;
	if (s == "yes")
		canStartNumber = true;
	for (int j = 0; j < numK; ++j) {
		cin >> s;
		if (!isRegister) {
			for (int i = 0; i < s.size(); ++i) {
				if ((s[i] >= 'A') && (s[i] <= 'Z'))
					s[i] += 32;
			}
		}
		keyWords.insert(s);
	}
	map<string, int> firstIn, cnt;
	int ind = 0;
	while (cin >> s) {
		++ind;



		if (!isRegister) {
			for (int i = 0; i < s.size(); ++i) {
				if ((s[i] >= 'A') && (s[i] <= 'Z'))
					s[i] += 32;
			}
		}

		int iter = 0;
		while (iter < s.size()) {
			string s1 = "";
			while ((iter < s.size()) && isGood(s[iter])) {
				s1 += s[iter];
				++iter;
			}
			while ((iter < s.size()) && !isGood(s[iter])) {
				++iter;
			}


			if (keyWords.find(s1) != keyWords.end())
				continue;
			if (!canStartNumber) {
				if ((s1[0] >= '0') && (s1[0] <= '9'))
					continue;
			}
			bool isCandidat = false;
			for (int i = 0; i < s1.size(); ++i) {
				if (isGood2(s1[i])) {
					isCandidat = true;
					break;
				}
			}
			if (!isCandidat)
				continue;
			++cnt[s1];
			if (cnt[s1] == 1)
				firstIn[s1] = ind;

		}
		

	}

	string ans = "";
	int fIn = 1000 * 1000 * 1000;
	int am = 0;
	for (auto pr : cnt) {
		if (pr.ss == am) {
			if (firstIn[pr.ff] < fIn) {
				fIn = firstIn[pr.ff];
				ans = pr.ff;
			}
		}
		else if ((ans == "") || (pr.ss > am)) {
			am = pr.ss;
			fIn = firstIn[pr.ff];
			ans = pr.ff;
		}
	}

	cout << ans;

	system("pause");

	return 0;
}