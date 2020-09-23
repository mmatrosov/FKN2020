#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())
#define ld long double

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    string s1, s2;
    cin >> n >> s1 >> s2;
    bool t1 = (s1[0] == 'y');
    bool t2 = (s2[0] == 'y');
    set<string> used;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        if (!t1)
        {
            for (int e = 0; e < (int)s.size(); e++)
            {
                if (s[e] >= 'A' && s[e] <= 'Z')
                    s[e] = char(s[e] - 'A' + 'a');
            }
        }
        used.insert(s);
    }
    map<string, pii> cnt;
    int t = 0;
    while (cin >> s)
    {
        s += " ";
        int sz = s.size();
        string cur = "";
        for (int i = 0; i < sz; i++)
        {
            t++;
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9') || (s[i] == '_'))
            {
                if (!t1 && s[i] >= 'A' && s[i] <='Z')
                    cur += char(s[i] - 'A' + 'a');
                else
                    cur += s[i];
            }
            else
            {
                bool fl = 0;
                for (int e = 0; e < (int)cur.size(); e++)
                {
                    if (cur[e] < '0' || cur[e] > '9')
                        fl = 1;
                }
                if (!fl || used.find(cur) != used.end())
                {
                    cur = "";
                    continue;
                }
                if (!cur.empty() && (t2 || cur[0] < '0' || cur[0] > '9'))
                {
                    if (cnt.find(cur) == cnt.end())
                        cnt[cur] = mp(1, -t);
                    else
                        cnt[cur].ff++;
                }
                cur = "";
            }
        }
    }
    string opt;
    pii ma(0, 0);
    for (auto u : cnt)
    {
        if (u.ss > ma)
        {
            ma = u.ss;
            opt = u.ff;
        }
    }
    cout << opt;
}
