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
	set <int> s;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		s.insert(x);
	}
	vector <int> a;
	for (auto it = s.begin(); it != s.end(); it++)
		a.push_back(*it);
	int k;
	cin >> k;
	while (k--)
	{
		int x;
		cin >> x;
		auto it = lower_bound(a.begin(), a.end(), x) - a.begin();
		cout << it << '\n';
	}
	return 0;
}