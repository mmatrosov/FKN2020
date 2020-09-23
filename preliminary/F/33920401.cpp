#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#define all(a) a.begin(), a.end()
#define int long long

using namespace std;

void fast_IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

const int INF = 1e18;
const int DEBUG = 1;

int n, k;
vector<int> a1;
vector<int> a;
vector<int> cnt;

vector<vector<int>> dp;
vector<vector<int>> pr;

void init() {
    cin >> n >> k;
    a1.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a1[i];
    }
    sort(all(a1));

    a.push_back(a1[0]);
    cnt.push_back(1);
    for (int i = 1; i < n; ++i) {
        if (a1[i - 1] == a1[i]) {
            cnt[cnt.size() - 1]++;
        }
        else {
            a.push_back(a1[i]);
            cnt.push_back(1);
        }
    }
    n = a.size();

    reverse(all(a));
    reverse(all(cnt));

    if (a[n - 1] == 0) {
        a.pop_back();
        cnt.pop_back();
        n--;
    }

    dp.resize(n + 1);
    for (int i = 0; i <= n; ++i) {
        dp[i].resize(k + 1, 0);
    }

    pr.resize(n + 1);
    for (int i = 0; i <= n; ++i) {
        pr[i].resize(k + 1, 0);
    }
}



signed main()
{
    fast_IO();
    init();

    if (k >= n) {
        reverse(all(a));
        int lst = 0;
        for (int i = 0; i < k; ++i) {
            if (i >= n) {
                lst++;
                cout << lst << " ";
            }
            else {
                cout << a[i] << " ";
                lst = a[i];
            }
        }
        return 0;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= min(i, k); ++j) {
            int sum = 0;
            for (int p = i - 1; p >= 0; --p) {
                sum += cnt[p];
                if (dp[p][j - 1] + sum * a[i - 1] > dp[i][j]) {
                    dp[i][j] = dp[p][j - 1] + sum * a[i - 1];
                    pr[i][j] = p;
                }
            }
        }
    }

    int ans = 0;
    int x = 0;
    for (int i = 0; i <= n; ++i) {
        if (dp[i][k] > ans) {
            ans = dp[i][k];
            x = i;
        }
    }
    for (int i = 0; i < k; ++i) {
        cout << a[x - 1] << " ";
        if (i < k - 1) {
            x = pr[x][k - i];
        }
    }
    return 0;
}
