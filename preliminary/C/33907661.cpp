#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#pragma optimizitaion_level 3
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <bitset>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <unordered_map>
#include <tuple>
#include <cmath>
#include <functional>
#include <algorithm>
#include <set>
#include <cassert>
#include <deque>
#include <unordered_set>
#include <numeric>
using namespace std;
#define kekek ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

signed main() {
	kekek;
	int n;
	cin >> n;
	vector<int> kek(n);
	for (auto& i : kek) {
		cin >> i;
	}
	sort(kek.begin(), kek.end());
	kek.resize(unique(kek.begin(), kek.end()) - kek.begin());
	int k;
	cin >> k;
	while (k--) {
		int p;
		cin >> p;
		auto lol = lower_bound(kek.begin(), kek.end(), p) - kek.begin();
		cout << lol << '\n';
	}

	return 0;
}