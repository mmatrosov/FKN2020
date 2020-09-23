#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    long long k;
    cin >> k;
    if (k < 1)
    {
        cout << "NO\n";
        return 0;
    }
    if (k == 1)
    {
        cout << "YES\n";
        return 0;
    }

    if ((k + 4) % 4 == 0)
    {
        cout << "YES\n";
    } else
    {
        cout << "NO\n";
    }

    return 0;
}
