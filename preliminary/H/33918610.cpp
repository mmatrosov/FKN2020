#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define F first
#define S second
#define pb push_back
mt19937 rnd;

const int N = 35;
const int W = 1e6 + 10;
int a[N];
bitset<W> dp;

bool solve(int n, int tar) {
    dp.reset();
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        dp |= (dp << a[i]);
    }
    return dp[tar];
}

static constexpr int MAX = 2000000;

int items[N], sufSum[N];
int stepsCounter;

bool RunKnapsack(int n, int X, int sum, int i) {
    ++stepsCounter;
    if (stepsCounter >= MAX) {
        return 0;
    }
    if (sum == X) {
        return 1;
    }
    if ((i == n) || (sum > X) || (sum + sufSum[i] < X))
        return 0;
    if (RunKnapsack(n, X, sum, i + 1)) {
        return 1;
    }
    if (RunKnapsack(n, X, sum + items[i], i + 1)) {
        return 1;
    }
    return 0;
}

bool wrong(int n, int X) {
    stepsCounter = 0;
    for (int i = 0; i < n; i++) {
        items[i] = a[i + 1];
    }
    sort(items, items + n);
    reverse(items, items + n);
    for (int i = n - 1; i >= 0; --i) {
        if (i == n - 1)
            sufSum[i] = items[i];
        else
            sufSum[i] = sufSum[i + 1] + items[i];
    }
    return RunKnapsack(n, X, 0, 0);
}

void stress() {
    while (1) {
        int n = rnd() % 30 + 1;
        int tar = rnd() % 1000000 + 1;
        for (int i = 1; i <= n; i++) {
            a[i] = rnd() % 1000000 + 1;
        }
        if (solve(n, tar) && !wrong(n, tar)) {
            cout << n << " " << tar << endl;
            for (int i = 1; i <= n; i++) {
                cout << a[i] << " ";
            }
            cout << endl;
            break;
        }
        else {
            cout << "OK" << endl;
        }
    }
    exit(0);
}

void kek() {
    while (1) {
        int n = 30;
        int p = rnd() % 999999 + 2;
        int q = rnd() % (p - 1) + 1;
        int k = rnd() % n + 1;
        if (k == 1 || k == n) {
            continue;
        }
        for (int i = 1; i <= k; i++) {
            a[i] = p;
        }
        for (int i = k + 1; i <= n; i++) {
            a[i] = q;
        }
        int cp = rnd() % (k + 1);
        int cq = rnd() % (n - k + 1);
        int tar = cp * p + cq * q;
        if (tar > 1000000) {
            continue;
        }
        bool cur = wrong(n, tar);
        if (stepsCounter >= 400000) {
            cout << n << " " << tar << "\n";
            for (int i = 1; i <= n; i++) {
                cout << a[i] << " ";
            }
            cout << "\n";
            cout << stepsCounter << "\n";
            exit(0);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int n = 30, tar = 796662;
    for (int i = 1; i <= 17; i++) {
        a[i] = 64104;
    }
    for (int i = 18; i <= n; i++) {
        a[i] = 45759;
    }
    cout << n << " " << tar << "\n";
    for (int i = 1; i <= n; i++) {
        cout << a[i] << "\n";
    }

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
