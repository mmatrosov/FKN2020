#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back

const int MAXN = 1e4 + 10;
set <string> m;
map <string, int> k;
vector <string> v;
int n, maxx;
bool reg = false, num = false;

void check(string s) {
    if (!reg) {
            for (int j = 0; j < s.length(); j++) {
                s[j] = tolower(s[j]);
            }
        }
    bool fl = false;
    for (int j = 0; j < s.length(); j++) {
        if (s[j] < '0' || s[j] > '9')
            fl = true;
    }
    if (m.count(s) == 0 && fl) {
        if (s[0] >= '0' && s[0] <= '9') {
            if (num){
                if (k[s] == 0) {
                    v.pb(s);
                }
                k[s]++;
                if (k[s] > maxx) {
                    maxx = k[s];
                }
            }
        }
        else {
            if (k[s] == 0) {
                v.pb(s);
            }
            k[s]++;
            if (k[s] > maxx) {
                maxx = k[s];
            }
        }
    }
}

int main()
{

    string s1, s;
    cin >> n >> s1 >> s;
    if (s1[0] == 'y') reg = true; //чувствительны к регистру
    if (s[0] == 'y') num = true; //могут начинаться с цифры
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (!reg) {
            for (int j = 0; j < s.length(); j++) {
                s[j] = tolower(s[j]);
            }
        }
        m.insert(s);
    }
    maxx = 0;
    while (cin >> s1) {
        s = "";
        for (int i = 0; i < s1.length(); i++)
        {
            if (isalpha(s1[i]) || (s1[i] >= '0' && s1[i] <= '9') || s1[i] == '_') {
                s += s1[i];
            }
            else if (s != "") {
                check(s);
                s = "";
            }
        }
        if (s != "") {
            check(s);
        }
    }
    for (auto i : v) {
        if (k[i] == maxx) {
            cout << i;
            return 0;
        }
    }
    return 0;
}

