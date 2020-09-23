#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <string>
#include <iostream>
#include <complex>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <stack>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <random>
#include <set>
#include <vector>
#include <unordered_map>
#include <bitset>
#include <unordered_set>
#include <array>
#include <forward_list>
#include <chrono>
#include <iomanip>
#include <utility>
#include <assert.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("sse")

#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

mt19937 gen(34);

int n;
string C, D, s;
bool c, d;
set <string> words;
map <string, int> pos;
map <int, int> m;

void lower_register(string& s)
{
	for (int i = 0; i < s.length(); i++)
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] = s[i] - 'A' + 'a';
}

bool letter(char c)
{
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

void obr(string& s)
{
	bool is_letter = false;
	for (int i = 0; i < s.length(); i++)
		is_letter |= (letter(s[i]) || s[i] == '_');
	if (!is_letter || s.length() == 0)
		return;
	if ((!d && s[0] >= '0' && s[0] <= '9') || words.find(s) != words.end())
		return;
	if (pos.find(s) == pos.end())
		pos[s] = m.size();
	m[pos[s]]++;

}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("memory.in", "r", stdin);
	//freopen("memory.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	cin >> C >> D;
	c = (C == "yes");
	d = (D == "yes");
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		if (!c)
			lower_register(s);
		words.insert(s);
	}
	s = "";
	string ss;
	while (cin >> ss)
	{
		if (!c)
			lower_register(ss);
		for (int i = 0; i < ss.length(); i++)
		{
			if ((ss[i] >= '0' && ss[i] <= '9') || letter(ss[i]) || ss[i] == '_')
				s += ss[i];
			else
			{
				obr(s);
				s = "";
			}
		}
		obr(s);
		s = "";
	}
	string ans;
	int cnt = 0, num = -1;
	for (auto it = m.begin(); it != m.end(); it++)
		if (it->second > cnt)
		{
			cnt = it->second;
			num = it->first;
		}
	for (auto it = pos.begin(); it != pos.end(); it++)
		if (it->second == num)
		{
			cout << it->first;
			return 0;
		}
	return 0;
}