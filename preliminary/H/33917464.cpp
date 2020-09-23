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

    vector <int> arr = {100000,100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 50041, 50067, 50034, 50000, 50069, 50024, 50078, 50058, 50062, 50064, 50005, 50045, 50081, 50027, 50061, 50091, 50095, 50042, 50027, 50036};
    cout << 30 << " " << 1000000 << endl;
    show(arr);
    

}