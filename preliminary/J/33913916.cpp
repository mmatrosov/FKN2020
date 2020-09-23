#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int cur = n * m;
    int max = 0;
    for (int i = 1;; i++)
    {
        if (cur >= 2 * i + 1)
            cur -= i;
        else
        {
            max = i - 1;
            break;
        }
    }

    int curn = 1;
    int left = 1;
    char curc = 'A';

    if (max == 0)
    {
        curn = 1e9;
        left = 1e9;
        curc = 'X';
    }

    vector<string> ans(n, string(m, '.'));
    string och = "EFGHIJKLMNOPQRSTUVWXYZ";
    int coch = 0;
    for (int i = 0; i < n; i++)
    {
        int start, end, step;
        string ch;
        if (i % 2 == 0)
        {
            start = 0;
            end = m;
            step = 1;
        }
        else
        {
            start = m - 1;
            end = -1;
            step = -1;
        }

        if (i % 2 == 0)
            ch = "AB";
        else
            ch = "CD";

        for (int j = start; j != end; j += step)
        {
            if (left == curn)
            {
                if (abs(end - j) >= curn)
                    curc = ch[1 - curn % 2];
                else
                {
                    curc = och[coch];
                    coch = (coch + 1) % och.size();
                }
            }

            ans[i][j] = curc;
            left--;
            if (left == 0)
            {
                curn++;
                if (curn > max)
                    curn = 1e9;
                left = curn;
            }
        }
    }

    cout << max + 1 << endl;
    for (string s : ans)
        cout << s << endl;

    return 0;
}
