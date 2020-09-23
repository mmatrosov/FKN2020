#include <bits/stdc++.h>
 
#define pii pair<int, int>
#define endl "\n"
#define int long long
#define F first
#define S second
#define B begin
#define E end
#define RB rbegin
#define RE rend
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
 
const int INF = 1e18 + 1;
const double EPS = 1e-10;
const ll P = 1e9 + 7;
const int Q = 47;
 
using namespace std;
 
void hello()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}
 
void show(vector<int>& arr)
{
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
}
void show(vector<vector<int>>& arr)
{
    for (auto i : arr)
        show(i);
    cout << endl;
}



signed main()
{
    hello();
    
    int n, m;
    cin >> n >> m;

    int res = 0;
    int i = 0, j = 0, t = 0;
    int cnt = n * m;
    vector <vector <int>> ares(n, vector <int>(m));
    while (cnt >= res + 1)
    {
        // cout << res << endl;
        ++res;
        vector <pii> indxs;
        for (int k = 0; k < res; ++k)
        {
            if (t == 0)
            {
                indxs.push_back({i, j});
                ++j;
                if (j == m)
                {
                    ++i; --j;
                    t = 1;
                }
            }
            else
            {
                indxs.push_back({i, j});
                --j;
                if (j == -1)
                {
                    ++i; ++j;
                    t = 0;
                }
            }
            --cnt;
        }
        if (cnt < res + 1)
        {
            for (int k = 0; k < cnt; ++k)
            {
                if (t == 0)
                {
                    indxs.push_back({i, j});
                    ++j;
                    if (j == m)
                    {
                        ++i; --j;
                        t = 1;
                    }
                }
                else
                {
                    indxs.push_back({i, j});
                    --j;
                    if (j == -1)
                    {
                        ++i; ++j;
                        t = 0;
                    }
                }
            }
        }


        vector <int> lts;
        for (auto val : indxs)
        {
            int i = val.F, j = val.S;
            if (i && ares[i - 1][j])
                lts.push_back(ares[i - 1][j]);
            if (j && ares[i][j - 1])
                lts.push_back(ares[i][j - 1]);
            if (i != n - 1 && ares[i + 1][j])
                lts.push_back(ares[i + 1][j]);
            if (j != m - 1 && ares[i][j + 1])
                lts.push_back(ares[i][j + 1]);
        }
        sort(lts.B(), lts.E());
        // show(lts);
        lts.resize(unique(lts.B(), lts.E()) - lts.B());
        int lt = 0;

        for (int i = 0; i < lts.size(); ++i)
            if (!i && lts[i] != 'A')
            {
                lt = 'A';
                break;
            }
            else if (i && lts[i] != lts[i - 1] + 1)
            {
                lt = lts[i - 1] + 1;
                break;
            }
        if (lt == 0 && lts.size() != 26)
            lt = lts.size() + 'A';
        if (lt == 0)
        {
            // cout << res << endl;
            assert(0);
            return 0;
        }
        for (auto val : indxs)
            ares[val.F][val.S] = lt;
    }
    cout << res << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << (char)ares[i][j];
        }
        cout << endl;
    }

}