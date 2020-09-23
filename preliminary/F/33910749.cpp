// Win32Project116.cpp: определяет точку входа для консольного приложения.
//

//#include "stdafx.h"
#include<iomanip>
#include<iostream>
#include<cmath>
#include<set>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
long long c0 = 0;
vector<long long> a(101);
long long scal(long long x, long long y, long long x2, long long y2) {
	return x*y2 - x2*y;
}
double dist(long long x, long long y, long long x2, long long y2) {
	return sqrt((x - x2)*(x - x2) + (y - y2)*(y - y2));
}
double cos(long long x1, long long y1, long long x2, long long y2) {
	return (x1*x2 + y1*y2) / (dist(x1, y1, c0, c0)*dist(x2, y2, c0, c0));
}
void show(vector<vector<long long>> &dp, int x, int y) {
	if (x == 0) {
		return;
	}
	if (dp[x][y] == dp[x - 1][y]) {
		cout << "1 ";
		show(dp, x - 1, y);
		return;
	}
	long long c1 = 1;
	cout << max(a[y], c1) << " ";
	for (int i = y; i < dp[0].size(); ++i) {
		if (dp[x][y] == a[y] * (i - y + 1) + dp[x - 1][i + 1]) {
			show(dp, x - 1, i + 1);
			return;
		}
	}
	return;
}
int main()
{
	int k, n;
	cin >> n >> k;
	a.resize(n + 1);
	a[0] = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i + 1];
	}
	++n;
	stable_sort(a.begin(), a.end());
	vector<vector<long long>> dp(k + 1, vector<long long>(n + 1, 0));
	for (int i = 1; i < k + 1; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = j; k < n; ++k) {
				dp[i][j] = max(dp[i][j], a[j] * (k - j + 1) + dp[i - 1][k + 1]);
			}
		}
	}
	long long mx = 0;
	int it = 0;
	for (int i = 0; i < dp[k].size(); ++i) {
		if (dp[k][i] > dp[k][it]) {
			it = i;
		}
	}
	show(dp, k, it);
	//system("pause");
    return 0;
}

