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
#define int long long
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
const string yes = "YES";
const string no = "NO";

int n;

void init() {
    ///ifstream cin("task.in"); ofstream cout("task.out");
    ///fast_IO();
    cin >> n;
    /// cin.close(); cout.close();
}



signed main()
{
    ///ifstream cin("task.in"); ofstream cout("task.out");
    ///fast_IO();
    init();
    if (n == 1) {
        cout << yes;
        return 0;
    }

    if (n % 4 == 0) {
        cout << yes;
    }
    else{
        cout << no;
    }
    ///cin.close(); cout.close();
    return 0;
}
