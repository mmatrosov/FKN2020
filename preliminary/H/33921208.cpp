#include <vector>
#include <cstdio>
#include <algorithm>
#include <iostream>

static constexpr int MAX = 2000000;

std::vector<int> items;
std::vector<int> sufSum;
int stepsCounter;

using namespace  std;

bool good = false;

void RunKnapsack(int n, int X, int sum, int i) {
    if (good) return;
    ++stepsCounter;
    if (stepsCounter >= MAX) {
        cout << 30 << ' ' << X << endl;
        for (int i = 0; i < 30; i++) cout << items[i] << ' ';
        cout << endl;
        //printf("NO\n");
        exit(0);
    }
    if (sum == X) {
        //cout << stepsCounter << endl;
        good = true;
        return;
    }
    if ((i == n) || (sum > X) || (sum + sufSum[i] < X))
        return;
    RunKnapsack(n, X, sum, i + 1);
    RunKnapsack(n, X, sum + items[i], i + 1);
}

int prime(int x) {
    for (int d = 2; d * d <= x; d++) if (x % d== 0) return false;
    return true;
}

int main() {
    while (1) {
        stepsCounter = 0, good = false;
        int n = 30, X;
        items.clear();
        sufSum.clear();
        for (int i = 3000; items.size() < 30;i++) if (prime(i) && items.size() < 30) items.push_back(i);
        int c = rand() % 15 + 15;
        X = 0;
        random_shuffle(items.begin(), items.end());
        for (int i = 0; i < c; i++) X += items[i];
        items.resize(n);
        sufSum.resize(n);
        sort(items.begin(), items.end());
        reverse(items.begin(), items.end());
        for (int i = n - 1; i >= 0; --i) {
            if (i == n - 1)
                sufSum[i] = items[i];
            else
                sufSum[i] = sufSum[i + 1] + items[i];
        }
        RunKnapsack(n, X, 0, 0);
    }
}
