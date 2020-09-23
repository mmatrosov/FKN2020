#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    vector <int> v;
    v.push_back(a[0]);
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1])
            v.push_back(a[i]);
    }
    n = int(v.size());
    int k;
    cin >> k;
    vector <pair <int, int> > g(k);
    for (int i = 0; i < k; i++) {
        cin >> g[i].first;
        g[i].second = i;
    }
    sort(g.begin(), g.end());
    vector <int> ans(k, 0);
    int j = 0, i = 0;
    while (i < k && g[i].first < v[j]) i++;
    for (i; i < k; i++) {
        while (j < n && v[j] < g[i].first) j++;
        ans[g[i].second] = j;
        if (j == n) break;
    }
    for (i; i < k; i++)
        ans[g[i].second] = j;
    for (int i = 0; i < k; i++)
        cout << ans[i] << endl;
}


