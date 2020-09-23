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

int n, k;
ll a[110];
ll dp[110][110];

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
	cin >> n >> k;
	multiset<int> s;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] != 0)
			s.insert(a[i]);
	}
	n = s.size();
	if (n == 0)
	{
		for (int i = 0; i < k; i++)
			cout << i + 1 << ' ';
		return 0;
	}
	int p = 1;
	for (auto it = s.begin(); it != s.end(); it++)
	{
		a[p] = *it;
		p++;
	}
	for(int j = 1; j <= k; j++)
		for (int i = 1; i <= n; i++)
			for (int prev = i - 1; prev >= 0; prev--)
				dp[i][j] = max(dp[i][j], dp[prev][j - 1] + a[prev + 1] * (i - prev));
	//cout << dp[n][k];
	int i = n, j = k;
	set <int> taxes;
	while (i > 0 && j > 0)
	{
		for(int prev = i - 1; prev >= 0; prev--)
			if (dp[i][j] == dp[prev][j - 1] + a[prev + 1] * (i - prev))
			{
				taxes.insert(a[prev + 1]);
				j--;
				i = prev;
				break;
			}
	}
	while (taxes.size() < k)
		taxes.insert(*taxes.rbegin() + 1);
	for (auto it = taxes.begin(); it != taxes.end(); it++)
		cout << *it << ' ';
	return 0;
}