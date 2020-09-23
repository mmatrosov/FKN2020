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

ld k1, k2, b1, b2;

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
	cin >> k1 >> b1 >> k2 >> b2;
	if (k1 == k2 && b1 == b2)
	{
		cout << "coincide";
		return 0;
	}
	if (k1 == k2)
	{
		cout << "parallel";
		return 0;
	}
	cout << "intersect\n";
	ld x = (b2 - b1) / (k1 - k2);
	ld y = k1 * x + b1;
	cout << fixed << setprecision(10) << x << ' ' << y;
	return 0;
}