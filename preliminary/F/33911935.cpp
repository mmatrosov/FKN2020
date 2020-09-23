#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define f first
#define s second

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector <int> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x != 0)
            a.push_back(x);
    }
    sort(a.begin(), a.end());
    n = int(a.size());
    if (n == 0) {
        for (int i = 0; i < k; i++)
            cout << i + 1 << " ";
        return 0;
    }
    vector <vector <int> > dp(n, vector <int> (k + 1, -1));
    vector <vector <int> > p(n, vector <int> (k + 1, -1));
    dp[0][1] = a[0];
    for (int i = 1; i < n; i++) {
        dp[i][1] = a[i];
        for (int j = 0; j < i; j++) {
            for (int z = 1; z <= k; z++) {
                if (dp[j][z] != -1) {
                    if (z != k && dp[i][z + 1] < dp[j][z] + a[i]) {
                        dp[i][z + 1] = dp[j][z] + a[i];
                        p[i][z + 1] = j;
                    }
                    dp[j][z] += a[j];
                }
            }
        }
    }
    int ans = 0;
    int f = min(n, k);
    vector <int> answer(k, -1);
    for (int i = 0; i < n; i++) {
        if (dp[ans][f] < dp[i][f])
            ans = i;
    }
    while (f != 0) {
        answer[f - 1] = a[ans];
        ans = p[ans][f];
        f--;
    }
    for (int i = 0; i < k; i++) {
        if (answer[i] == -1)
            answer[i] = answer[i - 1] + 1;
        cout << answer[i] << " ";
    }
}
