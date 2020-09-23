#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <iomanip>
#include <math.h>
#define pb emplace_back
#define sz(x) (int)x.size()
#define ll long long
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define ve vector
#define fi first
#define se second

using namespace std;
const int INF = 1000000000;

double dist(double x1, double y1, double x2, double y2) {
	double ans = abs(pow(x1 * x1 + y1 * y1, 0.5) - pow(x2 * x2 + y2 * y2, 0.5));
	double ang = abs(atan2(x1 * y2 - x2 * y1, x1 * x2 + y1 * y2));
	ang = min(ang, 2 * M_PI - ang);
	ans += ang * pow(x1 * x1 + y1 * y1, 0.5);
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	double x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	double ans = 100000000000000;

	ans = min(ans, dist(x1, y1, x2, y2));
	ans = min(ans, dist(x2, y2, x1, y1));
	ans = min(ans, pow(x1 * x1 + y1 * y1, 0.5) + pow(x2 * x2 + y2 * y2, 0.5));

	cout << fixed << setprecision(10) << ans << endl;
	return 0;
}