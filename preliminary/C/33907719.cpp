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
	int n;
	cin >> n;
	vector<int> m(n);
	for (int i = 0; i < n; i++) {
		cin >> m[i];
	}
	sort(m.begin(), m.end());
	m.push_back(2e9);
	long long l = 0;
	int k = 0;
	cin >> k;
	vector<long long> nu(n + 1, 0);
	long long last = -1;
	for (int i = 0; i < n; i++) {
		nu[i + 1] = nu[i];
		if (m[i] != last) {
			nu[i + 1]++;
		}
		last = m[i];
	}
	for (int i = 0; i < k; i++) {
		int v;
		cin >> v;
		long long le = -1, re = n;
		while(re-le>1){
			int me = (re + le) / 2;
			if (m[me] < v) {
				le = me;
			}
			else {
				re = me;
			}
		}
		cout << nu[le + 1] << "\n";
	}
	system("pause");
}