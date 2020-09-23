#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <cassert>
#include <random>
#include <cstring>
#include <numeric>

using namespace std;

#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;

#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
#define debug(x) cerr << #x << " = " << (x) << endl
#else
#define debug(x) 0
#endif

template<typename T = int>
T input() {
    T res;
    cin >> res;
    return res;
}

constexpr int N = 105;
constexpr int INF = 2e18;
pii dp[N][N];


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

	int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int &i : arr) {
        cin >> i;
    }
    sort(arr.rbegin(), arr.rend());
    // for (int i = 0; i <= n; ++i) {
    //     for (int j = 0; j <= k; ++j) {
    //         dp[i][j].first = INF;
    //     }
    // }
    dp[0][0] = {0, -1};
    pii ans = {0, 0};

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            int sum = 0;
            for (int c = i - 1; c >= 0; --c) {
                sum += 1;
                dp[i][j] = max(dp[i][j], {dp[c][j - 1].first + arr[i - 1] * sum, c});
            }
            ans = max(ans, {dp[i][j].first, i});
        }
    }
    vector<int> answer;
    for (int i = ans.second, j = k; i > 0; i = dp[i][j].second, --j) {
        if (arr[i - 1]) {
            answer.emplace_back(arr[i - 1]);
        }
    }
    sort(all(answer));
    answer.erase(unique(all(answer)), answer.end());
    int big = 1e9 - 6;
    while (sz(answer) < k) {
        answer.emplace_back(big--);
    }
    sort(all(answer));
    for (int i : answer) {
        cout << i << ' ';
    }
    cout << endl;
}
