#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    unordered_set<int> s;
    vector<int> num;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        if (s.count(a) == 0)
        {
            s.insert(a);
            num.push_back(a);
        }
    }

    sort(num.begin(), num.end());

    int k;
    cin >> k;

    for (int i = 0; i < k; i++)
    {
        int a;
        cin >> a;

        cout << lower_bound(num.begin(), num.end(), a) - num.begin() << endl;
    }

    return 0;
}
