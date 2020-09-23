//#pragma optimization_level 3
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <math.h>
#include <cmath>
#include <string>
#include <random>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <string.h>
#include <stack>
#include <assert.h>
#include <list>
#include <time.h>
#include <memory>
#include <chrono>
using namespace std;
//
#define fast cin.tie(0);cout.tie(0);cin.sync_with_stdio(0);cout.sync_with_stdio(0);
//#define cin in
//#define cout out
#define ll long long
#define db double
#define ld long double
#define uset unordered_set
#define umap unordered_map
#define ms multiset
#define pb push_back
#define pq priority_queue
#define umap unordered_map
#define uset unordered_set
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<ld, ld>
#define pnn pair<Node*, Node*>
#define uid uniform_int_distribution
#define PI acos(-1.0)
//#define sort(a, b) sort(a.begin(), a.end(), b())
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ifstream in("input.txt");
ofstream out("output.txt");

static constexpr int MAX = 2000000;



std::vector<int> items;
std::vector<int> sufSum;
int stepsCounter;
int n, X;
bool ans = 0;
bool fin = 0;

void RunKnapsack(int sum, int i) {
    if (fin) return;

    ++stepsCounter;
    if (stepsCounter >= MAX) {
        ans = 0;
        fin = 1;
        //printf("NO\n");
        //exit(0);
    }
    if (sum == X) {
        ans = 1;
        fin = 1;
        //printf("YES\n");
        //exit(0);
    }
    if ((i == n) || (sum > X) || (sum + sufSum[i] < X))
        return;
    RunKnapsack(sum, i + 1);
    RunKnapsack(sum + items[i], i + 1);
}

bool prog() {
    //scanf("%d%d", &n, &X);
    //items.resize(n);
    sufSum.resize(n);
    //for (int i = 0; i < n; ++i) {
    //    scanf("%d", &items[i]);
    //}
    sort(items.begin(), items.end());
    reverse(items.begin(), items.end());
    for (int i = n - 1; i >= 0; --i) {
        if (i == n - 1)
            sufSum[i] = items[i];
        else
            sufSum[i] = sufSum[i + 1] + items[i];
    }
    RunKnapsack(0, 0);
    //printf("NO\n");
    return (fin ? ans : 0);
}

int dp[31][100000];

void rand_gen() {
    memset(dp, 0, sizeof(dp));
    n = 30;
    X = (rand() % (int)900) + 1;
    ans = fin = 0;

    stepsCounter = 0;
    items.resize(n);
    for (int& x : items)
        x = (rand() % (int)30) + 1;
}


bool calc_dp() {
    for (int i = 0; i < n; i++) {
        dp[i][0] = 1;

        for (int w = 1; w <= X; w++) {
            if (i == 0 && w == items[i])
                dp[i][w] = 1;

            if (i > 0) {
                dp[i][w] |= dp[i - 1][w];
                if (w >= items[i])
                    dp[i][w] |= dp[i - 1][w - items[i]];
            }
        }
    }
    return dp[n - 1][X];
}

int main() {
    /*
    srand(time(0));

    for (int cnt = 1;; ++cnt) {
        if (cnt % 100 == 0) cout << '=';
        rand_gen();

        bool real = calc_dp();
        bool pr = prog();

        if (real != pr) {
            cout << '\n';
            cout << pr << '\n';
            cout << n << ' ' << X << '\n';
            for (int x : items) cout << x << ' ';
            return 0;
        }
    }
    */

    cout << 30 << ' ' << 41 << '\n';
    cout << 3 << '\n';
    for (int i = 0; i < 29; i++)
        cout << 2 << '\n';
}

