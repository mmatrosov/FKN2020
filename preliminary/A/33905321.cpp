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

const int LG = 20, N = (1 << LG);

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	if (n == 1){
		cout << "YES";
		return 0;
	}

	for (int a = 2; a <= 1e5; ++a){
		if (2 * a + 2 * (a - 2) == n){
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
}