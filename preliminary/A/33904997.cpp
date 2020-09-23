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
    
    int x;
    cin >> x;
    if (x == 1)
    {
        cout << "YES" << endl;
        return 0;
    }
    for (int i = 1; i <= x; ++i)
        if (4 * i - 4 == x)
        {
            cout << "YES" << endl;
            return 0;
        }
    cout << "NO" << endl;
}