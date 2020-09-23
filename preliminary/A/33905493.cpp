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
	int k;
	cin >> k;
	if (k == 1) return cout << "YES", 0;
	cout << (k % 4 == 0 ? "YES" : "NO");

	return 0;
}