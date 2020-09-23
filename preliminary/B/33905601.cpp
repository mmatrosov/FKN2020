// Win32Project116.cpp: определяет точку входа для консольного приложения.
//

//#include "stdafx.h"
#include<iomanip>
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	long long k1, b1, k2, b2;
	cin >> k1 >> b1 >> k2 >> b2;
	if (k1 == k2 && b1 == b2) {
		cout << "coincide";
	}
	else if (k1 == k2) {
		cout << "parallel";
	}
	else {
		cout << "intersect\n";
		double x;
		x = 1.0*(b2 - b1) / (k1 - k2);
		cout << fixed << setprecision(6) << x << " " << k1*x + b1;
	}
	//system("pause");
    return 0;
}

