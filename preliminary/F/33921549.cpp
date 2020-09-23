#include <iostream>
#include <vector>
#include <algorithm>

#define int long long

using namespace std;

signed main()
{
    freopen("input.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<vector<int> > dp(n + 1, vector<int>(k + 1, 0));
    vector<vector<int> > p(n + 1, vector<int > (k + 1, -1));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= k; j++){
            dp[i][j] = dp[i][j - 1];
            p[i][j] = i;
            for (int t = 0; t < i; t++){
                int cur = dp[t][j - 1] + a[t] * (i - t);
                if (cur > dp[i][j]){
                    p[i][j] = t;
                    dp[i][j] = cur;
                }
            }
        }
    }
    vector<int> ans;
    int x = n;
    int y = k;
    while (x > 0 && y > 0){
        if (p[x][y] == x){
            y--;
        }else{
            if (p[x][y] == -1 || p[x][y] == n){
                cout << -1 << endl;
                return 0;
            }
            ans.push_back(a[p[x][y]]);
            x = p[x][y];
            y--;
        }
    }
    if (ans.size() == 0){
        ans.push_back(1);
    }
    sort(ans.begin(), ans.end());
    while (ans.size() < k){
        int sup = ans[ans.size() - 1] + 1;
        ans.push_back(sup);
    }
    for (auto i : ans){
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}
