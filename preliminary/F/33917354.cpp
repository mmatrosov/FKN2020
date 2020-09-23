#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second

using namespace std;
const int N = 107;
int n, k;
int a[N];
int dp[N][N][N];
int bp[N][N][N];
pair <pair <int, int>, pair <int, int> > pr1[N][N][N];
pair <pair <int, int>, pair <int, int> > pr2[N][N][N];
set <int> st;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    /*for (int i = 1; i <= n; i++){
        cout << a[i] << " ";
    }
    cout << endl;*/
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= k; j++){
            for (int r = 1; r <= i; r++){
                dp[i][j][r] = max(bp[i - 1][j - 1][r - 1] + a[r], dp[i - 1][j][r] + a[r]);
                if (bp[i - 1][j - 1][r - 1] + a[r] >= dp[i - 1][j][r] + a[r]){
                    pr1[i][j][r] = {{2, i - 1}, {j - 1, r - 1}};
                }
                else {
                    pr1[i][j][r] = {{1, i - 1}, {j, r}};
                }
                bp[i][j][r] = max(bp[i][j - 1][r], max(bp[i][j][r - 1], dp[i][j][r]));
                if (bp[i][j - 1][r] >= max(bp[i][j][r - 1], dp[i][j][r])){
                    pr2[i][j][r] = {{2, i}, {j - 1, r}};
                }
                else
                if (bp[i][j][r - 1] >= max(bp[i][j - 1][r], dp[i][j][r])){
                    pr2[i][j][r] = {{2, i}, {j, r - 1}};
                }
                else {
                    pr2[i][j][r] = {{1, i}, {j, r}};
                }
                /*cout << "fuck you" << endl;
                cout << dp[i - 1][j - 1][r - 1] + a[r] << endl;
                cout << dp[i - 1][j][r] + a[r] << endl;
                cout << dp[i][j][r - 1] << endl;
                cout << dp[i][j - 1][r] << endl;
                cout << "end" <<endl;*/
            }
        }
        //cout << dp[i][1][i] << endl;
    }

    //cout << bp[n][k][n] << endl;

    int tp = 2;
    int i = n;
    int j = k;
    int r = n;

    while (i > 0){
        //cout << tp << " " << i << " " << j << " " << r << endl;
        if (tp == 1){
            st.insert(a[r]);
            int i1, j1, r1, t1;
            t1 = pr1[i][j][r].fi.fi;
            i1 = pr1[i][j][r].fi.se;
            j1 = pr1[i][j][r].se.fi;
            r1 = pr1[i][j][r].se.se;
            i = i1, j = j1, r = r1, tp = t1;
        }
        else {
            int i1, j1, r1, t1;
            t1 = pr2[i][j][r].fi.fi;
            i1 = pr2[i][j][r].fi.se;
            j1 = pr2[i][j][r].se.fi;
            r1 = pr2[i][j][r].se.se;
            i = i1, j = j1, r = r1, tp = t1;
        }
    }


    for (int i = 300; i <= 500; i++){
        if (st.size() < k){
            st.insert(i);
        }
    }

    for (auto it = st.begin(); it != st.end(); it++){
        cout << *it << " ";
    }
}
