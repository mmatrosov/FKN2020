#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> arr;
set<int> v;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		v.insert(k);
	}
	for (auto el: v) {
		arr.push_back(el);
	}
	sort(arr.begin(), arr.end());
	/*for (auto el: arr) {cout << el << " ";}
	cout << endl;*/
	int k;
	cin >> k;
	while (k --> 0) {
		int L = -1;
		int R = arr.size();
		int p;
		cin >> p;
		while (R - L > 1) {
			int med = (R + L) / 2;
			if (arr[med] >= p) {
				R = med;
			} else {
				L = med;
			}
		}
		cout << L + 1 << '\n';
	}
	// your code goes here
	return 0;
}