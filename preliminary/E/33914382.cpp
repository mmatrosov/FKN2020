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
vector<string> a;
bool reg; ///
bool num;
map<string, int> d;
int ans;
vector<string> allstr;

void init() {
    ///ifstream cin("task.in"); ofstream cout("task.out");
    ///fast_IO();
    cin >> n;
    string s1;
    cin >> s1;
    if (s1 == "yes") {
        reg = 0;
    }
    else {
        reg = 1;
    }
    cin >> s1;
    if (s1 == "yes") {
        num = 1;
    }
    else {
        num = 0;
    }

    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (reg) {
        for (int i = 0; i < n; ++i) {
            string st = "";
            for (char ch: a[i]) {
                if ('A' <= ch && ch <= 'Z') {
                    st += (ch - ('A' - 'a'));
                }
                else {
                    st += ch;
                }
            }
            a[i] = st;
        }
    }

    ans = 0;
    /// cin.close(); cout.close();
}

bool good(string st) {
    if (st == "") {
        return 0;
    }
    bool isch = 0;
    for (char ch: st) {
        if ('a' <= ch && ch <= 'z') {
            isch = 1;
            break;
        }
        if ('A' <= ch && ch <= 'Z') {
            isch = 1;
            break;
        }
        if (ch == '_') {
            isch = 1;
            break;
        }
    }
    if (!isch) {
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] == st) {
            return 0;
        }
    }
    return 1;
}

void solve(string st) {
    if (!good(st)) {
        return;
    }
    if (d.find(st) == d.end()) {
        d[st] = 0;
        allstr.push_back(st);
    }
    d[st]++;
    ans = max(ans, d[st]);
    //cout << "===> " << st << endl;
}

signed main()
{
    ///ifstream cin("task.in"); ofstream cout("task.out");
    ///fast_IO();
    init();
    string s;
    while (cin >> s) {
            /*
        if (s == "stop!!!") {
            break;
        }
            */
            /*
        if ('0' <= s[0] && s[0] <= '9' && num == 0) {
            break;
        }
            */
        string st = "";
        bool fbad = 0;
        for (char ch: s) {
            if (num == 0 && st == "" && '0' <= ch && ch <= '9') {
                fbad = 1;
            }
            if (fbad) {
                if ((ch < 'a' || 'z' < ch) && (ch < 'A' || 'Z' < ch) && (ch < '0' || '9' < ch) && (ch != '_')) {
                    fbad = 0;
                }
                else {
                    continue;
                }
            }

            if ('a'<= ch && ch <= 'z') {
                st += ch;
            }
            else if ('A' <= ch && ch <= 'Z') {
                if (reg) {
                    st += (ch - ('A' - 'a'));
                }
                else {
                    st += ch;
                }
            }
            else if (ch == '_') {
                st += ch;
            }
            else if ('0' <= ch && ch <= '9') {
                if ((st.size() == 0 && num == 1) || (st.size() > 0)) {
                    st += ch;
                }
            }
            else {
                solve(st);
                st = "";
            }
        }
        solve(st);
        st = "";
    }
    for (string st: allstr) {
        if (d[st] == ans) {
            cout << st;
            return 0;
        }
    }
    ///cin.close(); cout.close();
    return 0;
}
