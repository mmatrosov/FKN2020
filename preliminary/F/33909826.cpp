#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <bitset>
#include <queue>
#include <deque>
#include <ctime>
#include <cmath>
#include <stack>
#include <set>
#include <map>

using namespace std;

/*/#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")*/

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i<n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    vector<vector<int> > d(n+1, vector<int>(k+1, 0));
    vector<vector<int> > pr(n+1, vector<int>(k+1, -1));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<k; j++){
            for(int y = 0; y<=i; y++){
                if(d[i+1][j+1]<d[y][j]+(a[y])*(i-y+1)){
                    d[i+1][j+1] = d[y][j]+(a[y])*(i-y+1);
                    pr[i+1][j+1] = y;
                }
            }
            //cout << d[i][j] << ' ';
        }
        //cout << '\n';
    }
    vector<int> ans;
    int x = n, y = k;
    while(x>0&&y>0){
        x = pr[x][y];
        if(x==-1)
            break;
        ans.push_back(a[x]);
        y--;
    }
    while(!ans.empty()&&ans.back()==0)
        ans.pop_back();
    reverse(ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end())-ans.begin());
    int it = a.back()+1;
    while(ans.size()<k)
        ans.push_back(it++);
    for(int i = 0; i<ans.size(); i++)
        cout << ans[i] << ' ';

    return 0;
}
