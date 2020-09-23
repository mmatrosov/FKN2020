#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define int long long

using namespace std;
const int N = 207702;
int n, k, m;
int a[N];
set <int> st;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n ; i++){
        cin >> a[i];
        st.insert(a[i]);
    }
    m = 0;
    for (auto it = st.begin(); it != st.end(); it++){
        m++;
        a[m] = *it;
    }
    cin >> k;
    for (int i = 1; i <= k; i++){
        int x;
        cin >> x;
        int l = 0;
        int r = m + 1;
        while (r - l > 1){
            int mid = (l + r) / 2;
            if (a[mid] < x){
                l = mid;
            }
            else {
                r = mid;
            }
        }
        cout << l << endl;
    }

}
