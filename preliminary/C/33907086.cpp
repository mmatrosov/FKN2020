#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <string>
#define int long long

using namespace std;

typedef pair<int, int> pa;
typedef long long ll;
typedef long double ld;

const int LG = 20, N = (1 << LG);

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i : a) cin >> i;
	sort(a.begin(), a.end());
	a.resize(unique(a.begin(), a.end()) - a.begin());
	int k;
	cin >> k;
	for (int i = 0; i < k; ++i){
		int x;
		cin >> x;
		cout << lower_bound(a.begin(), a.end(), x) - a.begin() << '\n';
	}
}