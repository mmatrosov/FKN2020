#include <bits/stdc++.h>

using namespace std;

#define all(a) a.begin(),a.end()

int ar[100000];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    set<int> st;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        st.insert(t);
    }
    int j=0;
    for(int a : st){
        ar[j++]=a;
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int t;
        cin >> t;
        cout << (lower_bound(ar, ar + j, t) - ar) << endl;
    }
    return 0;
}
