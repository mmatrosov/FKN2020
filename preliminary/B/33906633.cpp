#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <string>

using namespace std;

typedef pair<int, int> pa;
typedef long long ll;
typedef long double ld;

const int LG = 20, N = (1 << LG);

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int k1, b1;
	int k2, b2;
	cin >> k1 >> b1 >> k2 >> b2;
	if (k1 == k2){
		if (b1 != b2){
			cout << "parallel";
		} else {
			cout << "coincide";
		}
	} else {
		cout << "intersect" << '\n';
		cout.precision(6);
		cout << fixed;
		ld x = (ld)(b1 - b2) / (k2 - k1);
		ld y = k1 * x + b1;
		cout << x << " " << y;
	}
}