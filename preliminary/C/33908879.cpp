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

	map<int, int> cnt;
	map<int, int> prefix;
	set<int> st;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		st.insert(x);
		cnt[x] = 1;
	}
	int cn = 0;
	for (auto ptr : cnt) {
		cn += ptr.ss;
		prefix[ptr.ff] = cn;
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int x;
		cin >> x;
		auto it = st.lower_bound(x);
		if (it == st.begin()) {
			cout << "0\n";
			continue;
		}
		--it;
		cout << prefix[*it] << '\n';
	}

	system("pause");

	return 0;
}