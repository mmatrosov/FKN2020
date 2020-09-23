#include <iostream>
#include <set>
#include <map>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <deque>
#include <stack>
#include <climits>
#include <math.h>
#include <cassert>
#include <unordered_map>
#include <chrono>
#include <random>
#include <ctime>
#include <complex>
using namespace std;
#pragma warning(disable : 4996)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ld PI = acosl(-1.0);
const ll MOD = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
#ifdef _DEBUG
	freopen("input1.txt", "r", stdin);
	freopen("output2.txt", "w", stdout);
#endif
	srand(time(0));
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	map<int, int> used;
	vector<int> a;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (!used[x])a.push_back(x);
		used[x] = 1;
	}
	sort(a.begin(), a.end());
	int q;
	cin >> q;
	while (q--) {
		int p;
		cin >> p;
		cout << (int)(lower_bound(a.begin(), a.end(), p) - a.begin()) << "\n";
	}
}