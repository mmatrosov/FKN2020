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
	ld k1, b1, k2, b2;
	cin >> k1 >> b1 >> k2 >> b2;
	if (k1 == k2) {
		cout << (b1 == b2 ? "coincide" : "parallel");
	}
	else {
		ld x = (b2 - b1) / (k1 - k2);
		ld y = k1 * x + b1;
		cout << "intersect\n";
		cout << fixed << setprecision(10) << x << " " << y;
	}
}