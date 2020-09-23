/*
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
*/


#include <bits/stdc++.h>


using namespace std;


#define int long long


void warp()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}


bool reg = false;
bool numb = false;


int timer = 0;


bool isLetter(char c)
{
    return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
}

bool isDigit(char c)
{
    return '0' <= c && c <= '9';
}


bool ok(char c)
{
    return c == '_' || isDigit(c) || isLetter(c);
}


char lower(char c)
{
    if ('A' <= c && c <= 'Z')
    {
        c += ('a' - 'A');
    }
    return c;
}


string work(string s)
{
    if (reg == true) return s;
    for (int i = 0; i < s.size(); i++)
    {
        s[i] = lower(s[i]);
    }
    return s;
}


bool in(set<string> &a, string b)
{
    return a.find(b) != a.end();
}


map<string, int> cnt;
map<string, int> first;

set<string> key;

void add(string id)
{
    id = work(id);
    if (in(key, id)) return;
    if (id.size() == 0) return;
    if (numb == false && isDigit(id[0])) return;
    int cn = 0;
    for (int i = 0; i < id.size(); i++)
    {
        if (isDigit(id[i])) continue;
        cn++;
    }
    if (cn == 0) return;
    if (cnt[id] == 0)
    {
        cnt[id] = 1;
        first[id] = timer;
        timer++;
    }
    else cnt[id]++;
}


void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (s == "yes") reg = true;
    cin >> s;
    if (s == "yes") numb = true;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        s = work(s);
        key.insert(s);
    }
    while (cin >> s)
    {
       string cur = "";
       for (int i = 0; i < s.size(); i++)
       {
           if (ok(s[i]))
           {
               cur.push_back(s[i]);
           }
           else
           {
               add(cur);
               cur = "";
           }
       }
       add(cur);
    }
    string ans;
    int p = -1;
    for (map<string, int>::iterator it = cnt.begin(); it != cnt.end(); ++it)
    {
        string cur = it->first;
        int r = it->second;
        if (r > p)
        {
            p = r;
            ans = cur;
        }
        else if (r == p)
        {
            if (first[cur] < first[ans]) ans = cur;
        }
    }
    cout << ans << endl;
}


signed main()
{
    warp();
    solve();
    return 0;
}
