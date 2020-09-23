#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve();

signed main()
{
#ifdef _______
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
#else
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
#endif
    // ios_base::sync_with_stdio(0);
    int _ = _ = _ = 1;
    for (_; _; --_)
        solve();
}

const int N = 2e5 + 77, mod = 1e9 + 7;

void solve()
{
    int n, reg, numstr;
    string s1, s2;
    cin >> n >> s1 >> s2;
    reg = s1 == "yes";
    numstr = s2 == "yes";
    set<string> keyword;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (!reg)
        {
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] >= 'A' && s[i] <= 'Z')
                {
                    s[i] = char(s[i] + ('a' - 'A'));
                }
            }
        }
        keyword.insert(s);
    }
    int pos = 0;
    map<string, int> cnt, loc;
    while (cin.peek() != EOF)
    {
        char c = cin.peek();
        if (!(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9' || c == '_'))
        {
            cin.ignore();
            continue;
        }
        string s;
        while ((c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9' || c == '_'))
        {
            s += c;
            cin.ignore();
            c = cin.peek();
        }
        if (!reg)
        {
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] >= 'A' && s[i] <= 'Z')
                {
                    s[i] = char(s[i] + ('a' - 'A'));
                }
            }
        }
        if (s.size() == 1 && s[0] >= '0' && s[0] <= '9')
        {
            continue;
        }
        if (numstr || !(s[0] >= '0' && s[0] <= '9'))
        {
            if (keyword.count(s))
                continue;
            pos++;
            cnt[s]++;
            if (cnt[s] == 1)
                loc[s] = pos;
        }
        cin.ignore();
    }
    int mx = 0;
    for (auto i : cnt)
        mx = max(mx, i.second);
    string ans;
    int posans = 1e18;
    for (auto i : cnt)
    {
        if (i.second == mx && loc[i.first] < posans)
        {
            posans = loc[i.first];
            ans = i.first;
        }
    }
    cout << ans;
}