

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <bitset>
#include <iomanip>

using namespace std;

typedef map<int, int> mp;
typedef vector<mp> vc;
typedef vector<int> vi;
typedef vector<unsigned long long> vll;
typedef long long ull;
typedef long long ll;


#define pb  push_back
#define ff  first
#define ss  second
#define sz	size()


int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);
	
	int k1, b1, k2, b2;
	cin >> k1 >> b1 >> k2 >> b2;
	if (k1 == k2) {
		if (b1 == b2)
			cout << "coincide";
		else
			cout << "parallel";
		exit(0);
	}
	double ans = b2 - b1;
	ans /= k1 - k2;
	cout << "intersect\n" << fixed << setprecision(6) << ans << ' ' << k1 * ans + b1;

	system("pause");

	return 0;
}