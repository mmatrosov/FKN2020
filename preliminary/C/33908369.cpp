#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back

const int MAXN = 1e4 + 10;
set <int> s;
vector <int> v;

int main()
{
    int n, k, p;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        s.insert(k);
    }
    for (auto i : s)
        v.pb(i);
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> p;
        cout << upper_bound(v.begin(), v.end(), p - 1) - v.begin() << endl;
    }
    return 0;
}

