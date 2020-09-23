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

void dfs(long long v, vector<vector<pair<long long, long long>>> &g, vector<long long> &s, long long way, int pred = -1) {
	s[v] = way;
	for (int i = 0; i < g[v].size(); ++i) {
		if (g[v][i].first == pred) {
			continue;
		}
		dfs(g[v][i].first, g, s, (way^g[v][i].second), v);
	}
}
long double dist(long long a, long long b) {
	return sqrtl(a*a + b*b);
}
int main()
{
	long long x1, y1;
	cin >> x1 >> y1;
	long long x2, y2;
	cin >> x2 >> y2;
	long double sinn = x1*y2 - x2*y1, coss = x1*x2 + y1*y2;
	long double angle = atan2(sinn, coss);
	if (angle < 0) {
		angle *= -1;
	}
	cout << fixed << setprecision(7) << min(dist(x1, y1) + dist(x2, y2),
		angle*min(dist(x1, y1), dist(x2, y2)) + abs(dist(x1, y1) - dist(x2, y2)));
	//system("pause");
    return 0;
}

