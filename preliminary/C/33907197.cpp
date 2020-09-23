#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <set>
#include <math.h>
#define ll long long
#define ld long double

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<int> arr2(n);
	for (int i = 0; i < n; i++) {
		cin >> arr2[i];
	}
	sort(arr2.begin(), arr2.end());
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		if (i == 0 || arr2[i] != arr2[i - 1]) {
			arr.push_back(arr2[i]);
		}
	}
	n = arr.size();
	reverse(arr.begin(), arr.end());
	//for (auto elem : arr)
	//	cerr << elem << ", ";
	//cerr << endl;
	int k;
	cin >> k;
	vector<int> ans(k);
	vector<pair<int, int> > p(k);
	for (int i = 0; i < k; i++) {
		cin >> p[i].first;
		p[i].second = i;
	}
	sort(p.begin(), p.end());
	reverse(p.begin(), p.end());
	//for (auto elem : p)
	//	cerr << elem.first << "/" << elem.second << " ";
	//cerr << endl;
	int pt = 0;
	for (int i = 0; i < k; i++) {
		//cerr << arr[pt] << " " << p[i].first << endl;
		while (pt != n && arr[pt] >= p[i].first) {
			//cerr << i << "/" << p[i].first << "/" << arr[pt] << endl;
			pt++;
		}
		//cerr << i << ": " << pt << endl;
		//cerr << p[i].first << endl;
		ans[p[i].second] = n - pt;
	}
	for (int i = 0; i < k; i++) {
		cout << ans[i] << "\n";
	}
}
//*/