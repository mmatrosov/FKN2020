
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <set>
#include <map>
#include <math.h>
#define ll long long
#define ld long double

using namespace std;

bool C = 0, D = 0;

const ll mod1 = 1200720071;
const ll mod2 = 1791791791;
const ll x1 = 137;
const ll x2 = 173;
const int LN = 52;

int get(char c) {
	int code = c - ' ';
	if (!C && code >= 65 && code <= 90) {
		code -= 32;
	}
	return code + 1;
}

bool digit(char c) {
	int code = c - ' ';
	return (code >= 16 && code <= 25);
}

bool good(char c) {
	int code = c - ' ';
	if (code >= 16 && code <= 25)
		return 1;
	if (code >= 33 && code <= 58)
		return 1;
	if (code >= 65 && code <= 90)
		return 1;
	if (code == 63)
		return 1;
	return 0;
}

ll gethash(string &s, ll mod, ll x){
	ll now = 0;
	for (auto elem : s) {
		ll val = get(elem);
		now = (now * x + val) % mod;
	}
	return now;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	string c, d;
	cin >> n >> c >> d;
	if (c == "yes")
		C = 1;
	if (d == "yes")
		D = 1;
	set<pair<ll, ll> > bad;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		//cerr << s << endl;
		bad.insert({ gethash(s, mod1, x1), gethash(s, mod2, x2) });
	}
	string s;
	string T = "";
	while (getline(cin, s)) {
		T += s;
		T += " ";
	}
	map<pair<ll, ll>, pair<int, int> > coun;
	map<pair<ll, ll>, string> real;
	int pt = 0;
	while (pt < T.size()) {
		int st = pt;
		if (!good(T[pt])) {
			pt++;
			continue;
		}
		if (digit(T[pt]) && !D) {
			while (pt < T.size() && good(T[pt])) {
				pt++;
			}
			//pt++;
			continue;
		}
		ll now = 0;
		ll now2 = 0;
		string s1 = "";
		bool flag = 0;
		while (pt < T.size()) {
			if (!good(T[pt]))
				break;
			if (!digit(T[pt]))
				flag = 1;
			s1 += T[pt];
			now = (now * x1 + get(T[pt])) % mod1;
			now2 = (now2 * x2 + get(T[pt])) % mod2;
			pt++;
		}
		if (flag) {
			if (coun.find({ now, now2 }) == coun.end()) {
				coun[{now, now2}] = { 0, st };
				real[{now, now2}] = s1;
			}
			coun[{now, now2}].first += 1;
		}
	}
	//cerr << bad.size() << "!!!" << endl;
	//cerr << real[(*bad.begin())] << "!"<< endl;
	//cerr << C << endl;
	int ans = -1;
	ll ind = 1e18;
	pair<ll, ll> val = { -1, -1 };
	for (auto elem : coun) {
		//cerr << real[elem.first] << ": " << elem.second.first << endl;
		if (bad.find(elem.first) != bad.end())
			continue;
		//cerr << "here" << endl;
		if (elem.second.first > ans || (elem.second.first == ans && elem.second.second < ind)) {
			ans = elem.second.first;
			ind = elem.second.second;
			val = elem.first;
		}
	}
	cout << real[val] << endl;
}
//*/