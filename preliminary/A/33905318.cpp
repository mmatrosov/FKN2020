#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <bitset>

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
	
	long long k;
	cin >> k;
	if (((k % 4) || (k <= 0)) && (k != 1))
		cout << "NO";
	else
		cout << "YES";



	return 0;
}