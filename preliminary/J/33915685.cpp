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

const int maxn = 1009;
char a[maxn][maxn];

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    int cnt = n * m;
    int cur = 1;
    int x = 0, y = 0;
    int ans = 0;
    while (cnt)
    {
        ans++;
        if (cnt - cur < cur + 1)
            cur = cnt;
        int t = cur;
        set<char> s;
        int i = x, e = y;
        while (t)
        {
            if (i)
                s.insert(a[i - 1][e]);
            if (e)
                s.insert(a[i][e - 1]);
            if (e != m - 1)
                s.insert(a[i][e + 1]);
            if (i % 2 == 0)
            {
                if (e == m - 1)
                    i++;
                else
                    e++;
            }
            else
            {
                if (e == 0)
                    i++;
                else
                    e--;
            }
            t--;
        }
        char c = 'A';
        while (s.find(c) != s.end())
            c++;
        t = cur;
        while (t)
        {
            a[x][y] = c;
            if (x % 2 == 0)
            {
                if (y == m - 1)
                    x++;
                else
                    y++;
            }
            else
            {
                if (y == 0)
                    x++;
                else
                    y--;
            }
            t--;
        }
        cnt -= cur;
        cur++;
    }
    cout << ans << "\n";
    for (int i = 0; i < n; i++)
    {
        for (int e = 0; e < m; e++)
            cout << a[i][e];
        cout << "\n";
    }
}
