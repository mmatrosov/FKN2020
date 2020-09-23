#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back
#define pf push_front
#define ft first
#define sc second
#define all(v) v.begin(), v.end()
using namespace std;
const int maxn = 100000, inf = 1e18;
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    string c, d;
    cin >> c >> d;
    map<string, int> mp;
    map<string, int> mp1;
    map<string, int> tm;
    for (int d = 0; d < n; d++) {
        string s;
        cin >> s;
        if (c == "no") {
            for (int i = 0; i < s.size(); i++) {
                if (s[i] >= 'A' && s[i] <= 'Z') {
                    s[i] -= 'A' - 'a';
                }
            }
        }
        mp[s] = 1;
    }
    char ch;
    string tek = "";
    int cnt = 0;
    string s;
    bool check = 1;
    while (cin>>s && check) {
        s.pb(' ');
        for (int i1 = 0; i1 < s.size(); i1++) {
            ch = s[i1];
//            if (ch == '.') {
//                check = 0;
//                break;
//            }
            //cout << ch;
            cnt++;
            if (c == "no" && ch >= 'A' && ch <= 'Z') {
                ch -= 'A' - 'a';
            }
            if ((ch > 'z' || ch < 'a') && (ch > 'Z' || ch < 'A') && (ch > '9' || ch < '0') && ch != '_') {
                if (tek != "") {
                    if (mp[tek] == 0) {
                        if (d == "no" && tek[0] >= '0' && tek[0] <= '9') {

                        } else {
                            bool check1 = 0;
                            for (int d = 0; d < tek.size() && !check1; d++) {
                                if (tek[d] < '0' || tek[d] > '9') {
                                    check1 = 1;
                                }
                            }
                            //cout << tek << "\n";
                            if (check1) {
                                if (mp1[tek] == 0) {
                                    mp1[tek] = 1;
                                    tm[tek] = cnt;
                                } else {
                                    mp1[tek]++;
                                }
                            }
                        }
                    }
                }
                tek = "";
            } else {
                tek.pb(ch);
            }
        }
    }
    int max1 = 0;
    string rem = "";
    for (map<string, int>::iterator it = mp1.begin(); it != mp1.end(); it++) {
        //cout << (*it).ft << " " << (*it).sc << " " << tm[(*it).ft] << "\n";
        if (it->sc > max1) {
            max1 = it->sc;
            rem = it->ft;
        } else if ((*it).sc == max1 && tm[(*it).ft] < tm[rem]) {
            max1 = (*it).sc;
            rem = (*it).ft;
        }
    }
    cout << rem;
}
