#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MAX = 107;

ll dp[MAX][MAX]; // idx:take
int ancIDX[MAX][MAX];
int ancGROUP[MAX][MAX];

ll getAns(vector<ll>& v, int k) {
    set<int> diff;
    ll sum = 0;
    for (int i = 1; i < v.size(); ++i) {
        diff.insert(v[i]);
        sum += v[i];
    }

    if (diff.size() <= k) {
        return sum;
    } else {
        memset(dp, -1, sizeof(dp));
        dp[1][1] = v[1];
        dp[0][0] = 0;
        for (int i = 2; i < v.size(); ++i) {
            for (int j = 1; j <= min(i, k); ++j) {
                for (int first = i; first >= 1; --first) {
                    if (dp[first - 1][j - 1] != -1) {
                        dp[i][j] = max(dp[i][j], dp[first - 1][j - 1] + v[first] * (i - first + 1));
                    }
                }
            }
        }

        return dp[v.size() - 1][k];
    }
}

signed main() {
#ifdef LOCAL
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<ll> v(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    vector<ll> test = v;

    ll ans = 0, size_ans = -1;
    for (int i = 1; i <= n; ++i) {
        ll currAns = getAns(test, k);

        if (size_ans == -1 || ans <= currAns) {
            ans = currAns;
            size_ans = i - 1;
        }

        reverse(test.begin(), test.end());
        test.pop_back();
        reverse(test.begin(), test.end());
    }

    reverse(v.begin(), v.end());
    for (int i = 0; i < size_ans; ++i) {
        v.pop_back();
    }
    reverse(v.begin(), v.end());

    set<ll> diff;
    ll sum = 0;
    for (int i = 1; i < v.size(); ++i) {
        diff.insert(v[i]);
        sum += v[i];
    }

    if (diff.size() <= k) {
        set<ll> ans = diff;
        k -= diff.size();
        for (int i = 1; k; ++i) {
            if (!ans.count(i)) {
                ans.insert(i);
                --k;
            }
        }

        for (const auto& it : ans) {
            cout << it << ' ';
        }
        cout << '\n';
    } else {
        memset(dp, -1, sizeof(dp));
        dp[1][1] = v[1];
        dp[0][0] = 0;
        for (int i = 2; i < v.size(); ++i) {
            for (int j = 1; j <= min(i, k); ++j) {
                for (int first = i; first >= 1; --first) {
                    if (dp[first - 1][j - 1] != -1) {
                        ll relax = dp[first - 1][j - 1] + v[first] * (i - first + 1);

                        if (dp[i][j] < relax) {
                            dp[i][j] = relax;
                            ancIDX[i][j] = first - 1;
                        }
                    }
                }
            }
        }

        set<ll> ans;

        int idx = (int)(v.size()) - 1;

        for (int i = k; i >= 1; --i) {
            idx = ancIDX[idx][i];
            ans.insert(v[idx + 1]);
        }

        for (const auto& it : ans) {
            cout << it << ' ';
        }
        cout << '\n';
    }
}
