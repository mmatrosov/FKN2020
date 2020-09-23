#include<bits/stdc++.h>

using namespace std;

using ll = long long int;
using vi = vector<int>;
#define f(n) for(int i = 0; i < n; i++)
#define fj(n) for(int j = 0; j < n; j++)
#define fk(n) for(int k = 0; k < n; k++)
#define ci(n) cin >> n;
#define ic(n) int n; cin >> n;
#define lc(n) int n; cin >> n;
#define all(a) a.begin(), a.end()
#define pri(a, n) for(int i = 0; i < n; i++) cout << a[i] << " "; cout << "\n";
#define sc second
#define scl(a, n) ll a[n] = {0}; for(int i = 0; i < n; i++) cin >> a[i];
#define pb push_back
#define eb emplace_back
#define pii pair<int, int>
#define ft first
#define int long long
const int inf = 1e9, maxn = 1e6, mod = 1e9 + 7;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


bool ok(char c)
{
    return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '_';
}
bool nd(char c)
{
    return c < '0' || c > '9';
}
bool nds(string s)
{
    bool res = false;
    for(char c : s) if(nd(c)) res = true;
    return res;
}
signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ic(n)
    map<string, bool> key;
    map<string, int> am, id;
    bool c, d;
    string t;
    cin >> t;
    c = (t[0] == 'n');
    cin >> t;
    d = (t[0] == 'y');
    f(n)
    {
        string s;
        cin >> s;
        if(c) fj(s.size()) s[j] = tolower(s[j]);
        key[s] = 1;
    }
    int ls = 0;
    while(cin >> t)
    {
        t += ' ';
        if(c) fj(t.size()) t[j] = tolower(t[j]);
        string cw;
        for(char ch : t)
        {
            if(ok(ch)) cw += ch;
            else
            {
                if(!key[cw] && nds(cw) && (d || nd(cw[0])))
                {
                    if(am[cw] == 0) id[cw] = ls;
                    am[cw]++;
                    ls++;
                }
                cw = "";
            }
        }
    }
    string ans;
    int aam = 0, ai = inf;
    for(pair<string, int> p : am)
    {
        if(p.sc > aam || (p.sc == aam && id[p.ft] < ai))
        {
            ans = p.ft;
            aam = p.sc;
            ai = id[p.ft];
        }
    }
    //cout << am["d"] << ' ' << am["int"];
    cout << ans;
}
