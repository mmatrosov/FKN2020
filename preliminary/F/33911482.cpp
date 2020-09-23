#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 101;
const int inf = 1e9;

int dp[N][N][N], go[N][N][N];

int main()
{
    int n, k;
    std::cin >> n >> k;
    std::vector<int> v;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        if (x)
            v.push_back(x);
    }
    n = v.size();
    if (!n) {
        for (int i = 0; i < k; ++i)
            std::cout << i + 1 << ' ';
        return 0;
    }
    sort(v.begin(), v.end());
    for (int pref = 0; pref < n; ++pref) {
        for (int cnt = 0; cnt <= pref + 1; ++cnt) {
            for (int last = 0; last <= pref; ++last) {
                if (!cnt)
                    dp[pref][cnt][last] = 0;
                else if (!pref)
                    dp[pref][cnt][last] = cnt == 1 ? v[last] : -inf;
                else if (last < pref)
                    dp[pref][cnt][last] = dp[pref-1][cnt][last] + v[last];
                else if (cnt == 1)
                    dp[pref][cnt][last] = v[last];
                else {
                    dp[pref][cnt][last] = -1;
                    for (int prevlast = 0; prevlast < last; ++prevlast)
                        if (dp[pref-1][cnt-1][prevlast] + v[last] > dp[pref][cnt][last])
                            dp[pref][cnt][last] = dp[pref-1][cnt-1][prevlast] + v[last], go[pref][cnt][last] = prevlast;
                }
                //std::cout << "dp[" << pref << "][" << cnt << "][" << last << "] = " << dp[pref][cnt][last] << '\n';
            }
        }
    }
    int oldk = k;
    k = std::min(oldk, n);
    int pref = n - 1, cnt = k, last = 0;
    for (int i = 1; i < n; ++i)
        if (dp[pref][cnt][i] > dp[pref][cnt][last])
            last = i;
    std::vector<int> ans;
    while (pref >= 0) {
        /*std::cout << "pref " << pref << " cnt " << cnt << " last " << last << " ans ";
        for (int x: ans)
            std::cout << x << ' ';
        std::cout << "| value " << dp[pref][cnt][last] << "\n";*/
        if (!cnt)
            break;
        if (!pref) {
            ans.push_back(v[last]);
            break;
        }
        if (last < pref)
            pref--;
        else if (cnt == 1) {
            ans.push_back(v[last]);
            break;
        }
        else {
            ans.push_back(v[last]);
            last = go[pref--][cnt--][last];
        }
    }
    for (int i = k; i < oldk; ++i)
        ans.push_back(inf - i);
    std::sort(ans.begin(), ans.end());
    for (int x: ans)
        std::cout << x << ' ';
    return 0;
}
