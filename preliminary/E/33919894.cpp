#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

string reg(string s) {
    for (int i = 0; i < int(s.size()); i++)
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = char(int(s[i] - 'A') + 'a');
    return s;
}

long long int h(string s) {
    long long int PR = 43, MD = 1e9 + 7;
    int n = int(s.size()), m;
    vector <long long int> pw(n + 1);
    vector <long long int> h(n + 1);
    h[0] = 0;
    pw[0] = 1;
    for (int i = 1; i <= n; i++)
        pw[i] = (pw[i - 1] * PR) % MD;
    for (int i = 1; i <= n; i++)
        h[i] = (h[i - 1] * PR + s[i - 1]) % MD;
    return h[n];
}

int main() {
    int n;
    cin >> n;
    string c, d;
    cin >> c >> d;
    set <long long int> q;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (c == "no") s = reg(s);
        q.insert(h(s));
    }
    string s = "", s1;
    getline(cin, s1);
    while (getline(cin, s1)) {
        if (s != "") s += ' ';
        s += s1;
    }
    string t = "";
    for (int i = 0; i < int(s.size()); i++) {
        if (s[i] == ' ' || s[i] >= 'a' && s[i] <= 'z' ||
            s[i] >= 'A' && s[i] <= 'Z' || s[i] >= '0' && s[i] <= '9'
            || s[i] == '_')
                t += s[i];
        else t += ' ';
    }
    string f = "";
    for (int i = 0; i < int(t.size()); i++) {
        if (t[i] != ' ') f += t[i];
        else if (i + 1 < int(t.size()) && t[i + 1] != ' ') f += ' ';
    }
    if (f[0] == ' ') f.erase(0, 1);
    string now = "";
    map <long long int, int> m;
    map <long long int, int> ind;
    string answer = "";
    int cod = -1, indx = -1;
    f += ' ';
    bool flag = 0;
    for (int i = 0; i < int(f.size()); i++) {
        if (f[i] != ' ') {
            now += f[i];
            if (!(f[i] >= '0' && f[i] <= '9'))
                flag = 1;
        }
        else {
            if (now[0] >= '0' && now[0] <= '9' && d == "no" || !flag) {
                now = "";
                continue;
            }
            if (c == "no")
                now = reg(now);
            long long int num = h(now);
            if (q.find(num) == q.end())
                m[num]++;
            int nowx = m[num];
            if (nowx == 1) ind[num] = i;
            int indnow = ind[num];
            if (nowx > cod || nowx == cod && indnow < indx) {
                cod = nowx;
                answer = now;
                indx = indnow;
            }
            now = "";
            flag = 0;
        }
    }
    cout << answer;
}

