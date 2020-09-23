// Win32Project116.cpp: определяет точку входа для консольного приложения.
//

//#include "stdafx.h"
#include<iomanip>
#include<iostream>
#include<cmath>
#include<set>
#include<vector>
using namespace std;
int main()
{
	int n;
	cin >> n;
	set<int> sp;
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		sp.insert(k);
	}
	vector<int> a;
	for (auto t : sp) {
		a.push_back(t);
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; ++i) {
		int p;
		cin >> p;
		int l = -1, r = a.size();
		while (r - l > 1) {
			int ser = (r + l) / 2;
			if (a[ser] >= p) {
				r = ser;
			}
			else {
				l = ser;
			}
		}
		cout << l + 1 << "\n";
	}
	//system("pause");
    return 0;
}

