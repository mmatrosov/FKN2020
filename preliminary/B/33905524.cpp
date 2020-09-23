#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <iomanip>
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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int k1, b1, k2, b2;
	cin >> k1 >> b1 >> k2 >> b2;
	if (k1 == k2 && b1 == b2) return cout << "coincide" << endl, 0;
	if (k1 == k2) return cout << "parallel" << endl, 0;
	cout << "intersect" << endl;
	double x = (double)(b2 - b1) / (double)(k1 - k2);
	double y = (double)k1 * x + (double) b1;
	cout << fixed << setprecision(10) << x << ' ' << y << endl;
	return 0;
}