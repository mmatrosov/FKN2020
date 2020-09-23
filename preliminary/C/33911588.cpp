#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> diego;

vector<long long> collect;


int main() {
    long long n, m, input;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input;
        diego.push_back(input);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> input;
        collect.push_back(input);
    }
    sort(begin(diego), end(diego));
    auto it = unique(begin(diego), end(diego));
    diego.resize(distance(diego.begin(), it));

    for (auto item : collect) {
        cout << distance(begin(diego), lower_bound(begin(diego), end(diego), item)) << endl;
    }
}
