// Win32Project116.cpp: определяет точку входа для консольного приложения.
//

//#include "stdafx.h"
#include<iomanip>
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int k;
	cin >> k;
	if (k == 1 || k % 4 == 0) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	//system("pause");
    return 0;
}

