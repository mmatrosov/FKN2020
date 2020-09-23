//#include <vector>
//#include <cstdio>
//#include <algorithm>
//#include <iostream>
//
//static constexpr int MAX = 2000000;
//
//std::vector<int> items;
//std::vector<int> sufSum;
//int stepsCounter;
//
//void RunKnapsack(int n, int X, int sum, int i) {
//    ++stepsCounter;
//    std::cout << stepsCounter;
//    if (stepsCounter >= MAX) {
//        printf("NO\n");
//        exit(0);
//    }
//    if (sum == X) {
//        printf("YES\n");
//        exit(0);
//    }
//    if ((i == n) || (sum > X) || (sum + sufSum[i] < X))
//        return;
//    RunKnapsack(n, X, sum, i + 1);
//    RunKnapsack(n, X, sum + items[i], i + 1);
//}
//
//int main() {
//    int n, X;
//    scanf("%d%d", &n, &X);
//    items.resize(n);
//    sufSum.resize(n);
//    for (int i = 0; i < n; ++i) {
//        scanf("%d", &items[i]);
//    }
//    sort(items.begin(), items.end());
//    reverse(items.begin(), items.end());
//    for (int i = n - 1; i >= 0; --i) {
//        if (i == n - 1)
//            sufSum[i] = items[i];
//        else
//            sufSum[i] = sufSum[i + 1] + items[i];
//    }
//    RunKnapsack(n, X, 0, 0);
//    printf("NO\n");
//}


#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(n + 1, -1000000001)));

    for (int i = 0; i <= n; ++i)
        dp[i][0][0] = 0;

    vector<int> costs(n, 0);
    for (int& c : costs) {
        cin >> c;
        c = -c;
    }

    sort(costs.begin(), costs.end());
    for (int& c : costs) {
        c = -c;
    }

    if (k >= n) {
        for (int i = costs.size() - 1; i >= 0; --i)
            cout << costs[i] << " ";
        for (int i = 1; i <= k - n; ++i)
            cout << costs[0] + i << " ";
        return 0;
    }

    vector<vector<int>> parent(n + 1, vector<int>(k + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int t = 1; t <= k; ++t) {
            for (int j = 0; j < i; ++j) {
                int a = dp[i - 1][t - 1][j] + costs[i - 1] * (i - j);
                if (a > dp[i][t][i]) {
                    dp[i][t][i] = a;
                    parent[i][t] = j;
                }
                int b = dp[i - 1][t][j];
                if (b > dp[i][t][j]) {
                    dp[i][t][j] = b;
//                    parent[i][t] = j;
                }
            }
        }
    }

    int ans = 0;
    int last = -1;
    for (int j = 1; j <= n; ++j) {
        if (dp[n][k][j] > ans) {
            ans = dp[n][k][j];
            last = j;
        }
    }

    for (int t = k; t > 0; --t) {
        cout << costs[last - 1] << " ";
        last = parent[last][t];
    }
}
