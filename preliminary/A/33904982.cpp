
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <set>
#include <math.h>
#define ll long long
#define ld long double

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ll k;
	cin >> k;
	if (k == 1) {
		cout << "YES\n";
		return 0;
	}
	if (k % 4 == 0) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}
}
//*/