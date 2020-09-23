#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second

using namespace std;
const int N = 107;
int n, k;
string s1, s2;
map <string , pair <int, int> > mp;
set <string> st1;
int cur = 0;

bool check(string s){
    int x = s[0];
    if (s[0] == '_' || (x >= 65 && x <= 90) || (x >= 97 && x <= 122) || (x >= 48 && x <= 57)){
        return 1;
    }
    else {
        return 0;
    }
}

void add(string s){
    //cout << s << endl;
    cur++;
    if (s == ""){
        return;
    }
    bool fl = 0;
    for (int i = 0; i < s.size(); i++){
        int x = s[i];
        if (x > 57 || x < 48){
            fl = 1;
            break;
        }
    }
    if (!fl){
        return;
    }
    int x = s[0];
    if (x >= 48 && x <= 57 && s2 == "no"){
        return;
    }
    if (s1 == "no"){
        string s1;
        for (int i = 0; i < s.size(); i++){
            int x = s[i];
            if (x >= 97 && x <= 122){
                x -= 32;
                char c = x;
                s1 += c;
            }
            else {
                s1 += s[i];
            }
        }
        if (mp[s1].fi == 0){
            mp[s1].fi = cur;
            mp[s1].se = 1;
        }
        else {
            mp[s1].se++;
        }
    }
    else {
        if (mp[s].fi == 0){
            mp[s].fi = cur;
            mp[s].se = 1;
        }
        else {
            mp[s].se++;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    cin >> s1 >> s2;
    for (int i = 1; i <= n; i++){
        string s;
        cin >> s;
        string ss;
        if (s1 == "no"){
            for (int i = 0; i < s.size(); i++){
                int x = s[i];
                if (x >= 97 && x <= 122){
                    x -= 32;
                    char c = x;
                    ss += c;
                }
                else {
                    ss += s[i];
                }
            }
            st1.insert(ss);
        }
        else {
            st1.insert(s);
        }
    }
    string s;
    while (cin >> s){
        //cout << s << endl;
        string str = "";
        for (int i = 0; i < s.size(); i++){
            string ss = "";
            ss += s[i];
            if (check(ss)){
                str += s[i];
            }
            else {
                add(str);
                str = "";
            }
        }
        add(str);
    }

    string ans = "";

    int mx = 0;
    int mn = 0;
    for (auto it = mp.begin(); it != mp.end(); it++){
        string s = it->first;
        //cout << s << endl;
        if (st1.find(s) != st1.end()){
            continue;
        }
        int col = it->second.second;
        int frst = it->second.first;
        //cout << col << endl;
        //cout << endl;
        if (col == mx){
            if (frst < mn){
                mn = frst;
                ans = s;
            }
        }
        else
        if (col > mx){
            ans = s;
            mn = frst;
            mx = col;
        }
    }

    cout << ans << endl;
}
