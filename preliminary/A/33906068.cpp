#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define int long long

using namespace std;
const int N = 207702;
int n, m, k, t;
int a[N];


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    if (n == 1){
        cout << "YES" << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++){
        if ((i - 1) * 4 == n){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}
