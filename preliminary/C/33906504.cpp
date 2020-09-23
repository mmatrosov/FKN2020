#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<iomanip>
using namespace std;
typedef long long ll;

void solve() {
	int n; cin >> n;
	set<int>a;
	for (int i = 0; i < n; i++) {
		int m; cin >> m;
		a.insert(m);
	}
	vector<int>mas;
	for (int i : a) {
		mas.push_back(i);
	}
	int k; cin >> k;
	for (int i = 0; i < k; i++) {
		int m; cin >> m;
		cout << lower_bound(mas.begin(), mas.end(), m) - mas.begin()<<'\n';
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	solve();
	return 0;
}