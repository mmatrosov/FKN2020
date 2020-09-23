#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<random>
#include<set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int k;
	cin >> k;
	if (k == 1 || k % 4 == 0) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	system("pause");
}