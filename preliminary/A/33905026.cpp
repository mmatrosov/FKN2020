#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
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
	int n;
	cin >> n;
	if (n % 4 == 0 || n == 1) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}