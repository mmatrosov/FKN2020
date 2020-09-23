#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector <int> ar(n);
    for (int i = 0; i < n; i++)
        cin >> ar[i];

    sort(ar.begin(), ar.end());

    vector <int> a;

    a.push_back(ar[0]);

    for (int i = 1; i < n; i++)
    {
        if (ar[i] != ar[i - 1])
        {
            a.push_back(ar[i]);
        }
    }

    n = a.size();

    /*for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }*/

    int k = 0;
    cin >> k;

    for (int i = 0; i < k; i++)
    {
        int tmp = 0;
        cin >> tmp;

        if (tmp <= ar[0])
        {
            cout << 0 << "\n";
        } else
        {
            auto x = lower_bound(a.begin(), a.end(), tmp);
            cout << x - a.begin() << "\n";
        }
    }


    return 0;
}
