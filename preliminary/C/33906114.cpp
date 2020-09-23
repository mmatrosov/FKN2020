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
	set<int> s;
	vi ar;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		s.insert(x);
	}
	for (auto x : s) ar.pb(x);
	int k;
	cin >> k;
	while (k--) {
		int p;
		cin >> p;
		cout << (lower_bound(all(ar), p) - ar.begin()) << endl;
	}
	return 0;
}