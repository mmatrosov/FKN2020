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
	cout << "30 531\n";
	for (int i = 2; i <= 58; i += 2) {
		cout << i << '\n';
	}
	cout << 101<<"\n";
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