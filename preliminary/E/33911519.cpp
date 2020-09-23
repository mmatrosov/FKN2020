#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <bitset>
#include <fstream>
#include <unordered_set>
#include <unordered_map>


using namespace std;


#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")

#define int long long
#define eb emplace_back
#define pb push_back
#define ld long double
#define f first
#define s second
#define deb(a) cerr << #a << " = " << a << '\n';
#define fast() { \
    ios_base::sync_with_stdio(0); \
    cin.tie(0); \
    cout << fixed << setprecision(20); \
    cerr << fixed << setprecision(11); \
}



const int INF = 1e9 + 7;
const ld EPS = 1e-10;
const int MAXI = 20000;
const int MOD = 998244353;
const int MAXST = 2000000;
const int P = 62;
const ld PI = 3.14159265358979323;

ostream &operator<<(ostream &stream, const pair <int, int> &p) {
    stream << p.first << ' ' << p.second << ' ';
    return stream;
}


set < string > was;
map < string, int > kol, f;
int top = 0;

signed main() {
    /* freopen("cipher.in", "r", stdin);
     freopen("cipher.out", "w", stdout);*/
    fast();
    int n;
    cin >> n;
    string c, d;
    cin >> c >> d;
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        if (c == "no")
            for (int j = 0; j < s.length(); j++)
                s[j] = tolower(s[j]);
        was.insert(s);
    }
    string s;
    for (; getline(cin, s); ){
        string ans = "";
        for (int i = 0; i < s.length(); i++){
            if (c == "no")
                s[i] = tolower(s[i]);
            if (s[i] >= '0' && s[i] <= '9')
                ans += s[i];
            else if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z' || s[i] == '_')
                ans += s[i];
            else {
                bool z = false;
                for (auto j: ans)
                    if (j < '0' || j > '9')
                        z = true;
                if (ans.size() > 0 && ans[0] >= '0' && ans[0] <= '9' && d == "no")
                    z = false;
                if (was.find(ans) != was.end())
                    z = false;
                if (z){
                    if (f.find(ans) == f.end())
                        f[ans] = top;
                    top++;
                    kol[ans]++;
                }
                ans = "";
            }
        }
       /* if (s == "+")
            break;*/
        bool z = false;
        for (auto j: ans)
            if (j < '0' || j > '9')
                z = true;
        if (ans.size() > 0 && ans[0] >= '0' && ans[0] <= '9' && d == "no")
            z = false;
        if (was.find(ans) != was.end())
            z = false;
        if (z){
            if (f.find(ans) == f.end())
                f[ans] = top;
            top++;
            kol[ans]++;
        }
        ans = "";
    }
    string ans = "";
    int mx = 0;
    for (auto i: kol){
       // cout << i.f << ' ' << i.s << ' ' << f[i.f] << ' ' << f[ans] << endl;
        if (i.s > mx){
            ans = i.f;
            mx = i.s;
        }
        else if (i.s == mx && f[i.f] < f[ans]) {
         //   cout << i.f << ' ' << ans << ' ' << f[i.f] << ' ' << f[ans] << endl;
            ans = i.f;
            mx = i.s;
        }
    }
    cout << ans;
    return 0;
}