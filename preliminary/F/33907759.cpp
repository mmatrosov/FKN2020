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
 
const int INF = 1e9 + 1;
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
    
    int n, k;
    cin >> n >> k;
    vector <vector <int>> dp(n + 1, vector <int>(k + 1)), pred(n + 1, vector <int>(k + 1));
    vector <int> seq(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> seq[i];
    sort(seq.B(), seq.E());
    seq.push_back(1e9);
    for (int j = 1; j <= k; ++j)
        for (int i = 1; i <= n; ++i)
        {
            for (int t = i; t >= 0; --t)
                if (dp[i][j] < dp[t][j - 1] + (i - t) * seq[t + 1])
                {
                    dp[i][j] = dp[t][j - 1] + (i - t) * seq[t + 1];
                    pred[i][j] = t;
                }
        }

    //show(dp);
    int ind = n;
    vector <int> res;
    for (int i = 0; i < k; ++i)
    {
        res.push_back(seq[pred[ind][k - i] + 1]);
        ind = pred[ind][k - i];
    }
    sort(res.B(), res.E());
    show(res);

}