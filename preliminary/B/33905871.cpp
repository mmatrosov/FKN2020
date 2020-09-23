#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <set>
#define all(a) a.begin(), a.end()
///#pragma GCC optimize("Ofast")
#define int long double
#define ft first
#define sd second

/*

СТРОИМ КОММУНИЗМ РАБОТЯГИ!

                                    ╦═╩═╦═╩═█
                          ████▄▄▄═╦═╩═╦═╩═╦═█
                  ████████████████▄▄╦═╩═╦═╩═█
█═╦═╩═╦▄████████████████▀▀▀▀█████████▄╦═╩═╦═█
█═╩═╦═████████████████████▄═╦▀█████████═╦═╩═█
█═╦═▄██████████▀╩═╦═╩▄██████▄═╦▀████████▄═╦═█
█═╩═█████████▀╩═╦═╩═█████████▄╩═╦████████═╩═█
█═╦█████████▄═╦═╩═╦═▀█████████╦═╩═████████╦═█
█═╩███████████▄▄██▄═╦═▀████████═╦═████████╩═█
█═██████████████████▄═╦═▀█████▀═╩═█████████═█
█═████████████████████▄═╦═▀███╩═╦═█████████═█
█═╦████████████▀╩▀██████▄═╦═▀═╦═╩█████████╦═█
█═╩█████████▀═╩═╦═╩▀▀███▀▀╩═╦═╩═██████████╩═█
█═╦═██████▀═╦═▄▄█▄▄═╩═╦═╩═╦═╩═╦═╩▀███████═╦═█
█═╩═▀████═╩═▄█████████▄▄▄▄████▄═╦═╩█████▀═╩═█
█═╦═╩═██████████████████████████▄═▄████═╩═╦═█
█═╩═╦═╩▀█████████████████████████████▀╩═╦═╩═█
█═╦═╩═╦═╩▀▀███████████████████████▀▀╩═╦═╩═╦═█
█═╩═╦═╩═╦═╩═▀▀▀███████████████▀▀▀═╩═╦═╩═╦═╩═█
█═╦═╩═╦═╩═╦═╩═╦═╩═▀▀▀▀▀▀▀▀▀═╩═╦═╩═╦═╩═╦═╩═╦═█
█═╩═╦═╩═╦═╩═╦═╩═╦═╩═╦═╩═╦═╩═╦═╩═╦═╩═╦═╩═╦═╩═█
█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█

*/

using namespace std;

void fast_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

const int INF = 1e18;
const int DEBUG = 1;

int k1, b1, k2, b2;

void init() {
    ///ifstream cin("task.in"); ofstream cout("task.out");
    ///fast_IO();
    cin >> k1 >> b1;
    cin >> k2 >> b2;
    /// cin.close(); cout.close();
}



signed main()
{
    ///ifstream cin("task.in"); ofstream cout("task.out");
    ///fast_IO();
    init();
    if (k1 == k2 && b1 == b2) {
        cout << "coincide";
        return 0;
    }
    if (k1 == k2) {
        cout << "parallel";
        return 0;
    }
    cout << "intersect\n";
    int x = (b2 - b1) / (k1 - k2);
    int y = k1 * x + b1;
    cout.precision(100);
    cout << x << " " << y << endl;

    ///cin.close(); cout.close();
    return 0;
}
