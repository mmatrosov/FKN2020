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

int n;
vector<int> a1;
vector<int> a;
int k;
vector<int> b;

void init() {
    ///ifstream cin("task.in"); ofstream cout("task.out");
    ///fast_IO();
    cin >> n;
    a1.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a1[i];
    }
    sort(all(a1));
    a.push_back(a1[0]);
    for (int i = 1; i < n; ++i) {
        if (a1[i - 1] != a1[i]) {
            a.push_back(a1[i]);
        }
    }
    n = a.size();

    cin >> k;
    b.resize(k);
    for (int i = 0; i < k; ++i) {
        cin >> b[i];
    }
    /// cin.close(); cout.close();
}



signed main()
{
    ///ifstream cin("task.in"); ofstream cout("task.out");
    ///fast_IO();
    init();
    for (int i = 0; i < k; ++i) {
        int l = -1;
        int r = n;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (a[m] < b[i]) {
                l = m;
            }
            else {
                r = m;
            }
        }
        cout << l + 1 << endl;
    }

    ///cin.close(); cout.close();
    return 0;
}
