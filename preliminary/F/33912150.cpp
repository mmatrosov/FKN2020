#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<map>
#include<set>
#include<random>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<deque>
#include<bitset>
#include<cstdio>
#include<cassert>
#include<sstream>
#include<set>

#define int long long int

using namespace std;

signed main(){
    int n, k; cin >> n >> k;
    unordered_map<int, int> cnt;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x > 0)cnt[x]++;
    }
    vector<pair<int, int>> a;
    for(auto i : cnt)a.push_back(i);
    sort(a.rbegin(), a.rend());
    if(a.size() < k){
        int last = 0;
        while(!a.empty()){
            cout << a.back().first << " ";
            last = a.back().first;
            a.pop_back();
            k--;
        }
        for(int i = 0; i < k; i++)cout << (last++) + 1 << " ";
        cout << "\n";
        return 0;
    }
    n = a.size();
    a.insert(a.begin(), {-1, -1});
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1e15));
    vector<vector<pair<int, int>>> prev(n + 1, vector<pair<int, int>>(k + 1, {-1, -1}));
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            int summ = 0;
            for(int w = i; w >= 1; w--){
                summ += a[w].second;
                if(dp[i][j] < dp[w - 1][j - 1] + summ * a[i].first){
                    dp[i][j] = dp[w - 1][j - 1] + summ * a[i].first;
                    prev[i][j] = {w - 1, j - 1};
                }
            }
        }
    }
    int ans = -1e15, ind = -1;
    for(int i = 1; i <= n; i++){
        if(dp[i][k] > ans){
            ans = dp[i][k];
            ind = i;
        }
    }
    vector<int> res;
    while(ind > 0){
        res.push_back(a[ind].first);
        ind = prev[ind][k].first;
        k--;
    }
    sort(res.begin(), res.end());
    for(auto i : res)cout << i << " ";
    return 0;
}

