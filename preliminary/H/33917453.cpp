#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(aaa) aaa.begin(), aaa.end()

const int MAX = 1e6;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 30, x = MAX - 1;

	vector<int> v = {x};

	for (int i = 1; i < 30; i++) {
		v.push_back(50000);
	}

	cout << v.size() << " " << x << "\n";
	for (int x : v)
		cout << x << " ";


	return 0;
}