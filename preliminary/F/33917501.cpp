#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <set>
#include <cmath>
#include <vector>
#include <bitset>
#include <iomanip>


using namespace std;

typedef long long ll;
typedef long double ld;

const ld INF = 1e9;

int main() {
    int n, k, x;
    cin >> n >> k;
    int nn = n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    vector<vector<pair<int, int>>> p(n + 1, vector<pair<int, int>>(k + 1, {-1, -1}));
    //for (int i = 0; i <= n; i++) cout << a[i] << ' ';
    //cout << endl;
    for (int j = 1; j <= k; j++) {
        for (int i = 1; i <= n; i++) {
            for (int l = 1; l <= i; l++) {
                if (dp[i][j] < dp[l - 1][j - 1] + (i - l + 1) * a[l]) {
                    dp[i][j] = dp[l - 1][j - 1] + (i - l + 1) * a[l];
                    p[i][j] = {l - 1, a[l]};
                }
            }
        }
    }
    /*for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            cout << p[i][j].second << ' ';
        }
        cout << endl;
    }
     for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            cout << p[i][j].first << ' ';
        }
        cout << endl;
    }*/
    int k1 = 0;
    for (int i = 1; i <= k; i++) {
        if (dp[n][k1] < dp[n][i]) k1 = i;
    }
    vector<int> ans;
    while (k1 != 0) {
        ans.push_back(p[n][k1].second);
        n = p[n][k1].first;
        k1--;
    }
    sort(ans.begin(), ans.end());
    int kk = ans.size();
    for (auto i : ans) cout << i << ' ';
    if (kk < k) {
        int xx = a[nn] + 1;
        for (int i = k - kk; i > 0; i--) {
            cout << xx << ' ';
            xx++;
        }
    }

}
