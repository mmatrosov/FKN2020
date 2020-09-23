#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector <int> a;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        if (tmp > 0)
        {
            a.push_back(tmp);
        }
    }

    n = a.size();

    if (n == 0)
    {
        for (int i = 0; i < k; i++)
        {
            cout << i + 1 << " ";
        }
        return 0;
    }

    sort(a.begin(), a.end());

    int dif = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] != a[i - 1]) dif++;
    }

    if (k >= dif)
    {
        cout << a[0] << " ";
        for(int i = 1; i < n; i++)
        {
            if (a[i] != a[i - 1]) cout << a[i] << " ";
        }
        for (int i = 0; i < k - dif; i++)
        {
            cout << 10000000 + i << " ";
        }
        return 0;
    }


    long long ar[n + 1][k + 1];
    long long L[n + 1][k + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            ar[i][j] = -10000000;
            L[i][j] = 0;
            if (j == 0)
            {
                ar[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            long long maxv = -10000000;
            long long maxl = 0;
            for (int l = 1; l <= i; l++)
            {
                long long v = ar[i - l][j - 1] + l * a[i - l];
                if (v >= maxv)
                {
                    maxv = v;
                    maxl = l;
                }
            }
            ar[i][j] = maxv;
            L[i][j] = maxl;
        }
    }

    /*for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            cout << ar[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n\n";
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            cout << L[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n\n";*/

    int posx = n, posy = k;

    vector <int> ans;

    while (posy > 0 && posx > 0)
    {
        ans.push_back(a[posx - L[posx][posy]]);
        //cout << a[posx - L[posx][posy]] << " " << L[posx][posy] << "\n";
        posx -= L[posx][posy];
        posy--;
        //cout << posx << " " << posy << "\n\n";
    }

    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i] << " ";
    }

    long long start = a[n - 1] + 10;
    for (int i = ans.size(); i < k; i++)
    {
        cout << start + i - ans.size() << " ";
    }

    return 0;
}
