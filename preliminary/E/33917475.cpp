#include <bits/stdc++.h>

using namespace std;

#define all(a) a.begin(),a.end()

bool ra;
bool na;

map<string, int> mp;

vector<string> kek;

void add_word(string &w) {
    bool nd = false;
    for (char &a:w) {
        if (!ra)
            a = tolower(a);
        if (!isdigit(a))
            nd = true;
    }
    if (!na && isdigit(w[0]))
        return;
    if (nd) {
        mp[w] += 1;
        if (mp[w] == 1)
            kek.push_back(w);
    }
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string ras, nas;
    cin >> ras >> nas;
    ra = ras[0] == 'y';
    na = nas[0] == 'y';

    string cur;
    vector<string> al;
    for (int i = 0; i < n; ++i) {
        string t;
        cin >> t;

        al.push_back(t);
    }

    std::istreambuf_iterator<char> begin(std::cin), end;
    string buf(begin, end);
    for (char a:buf) {
        if (isdigit(a)) {
            cur.push_back(a);
            continue;
        }
        if (('a' <= a && a <= 'z') || ('A' <= a && a <= 'Z') || a == '_') {
            cur.push_back(a);
            continue;
        }
        if (!cur.empty()) {
            add_word(cur);
        }
        cur.clear();
    }
    if (!cur.empty()) {
        add_word(cur);
    }
    for (string &t: al) {
        if(!ra){
            for (int i = 0; i < t.size(); ++i) {
                t[i]=tolower(t[i]);
            }
        }
        mp[t] = 0;
    }
    int mx = 0;
    string mxa;
    for (const auto &i:kek) {

        if (mp[i] > mx) {
            mx = mp[i];
            mxa = i;
        }
    }
    cout << mxa << endl;
    return 0;
}
