#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n;
vector<int> vect;

void build_vect() {
	cin >> n;
	set<int> st;
	st.insert(-1);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		st.insert(x);
	}
	for (int x : st)
		vect.push_back(x);
}

int BinSearch(int x) {
	int L = 0, R = vect.size();
	while (R - L > 1) {
		int mid = (L + R) / 2;
		if (vect[mid] >= x)
			R = mid;
		else
			L = mid;
	}
	return L;
}

int main() {
	build_vect();
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		cout << BinSearch(x) << "\n";
	}
	return 0;
}
