#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n == 0){
        int k;
        cin >> k;
        for (int i = 0; i < k; i++){
            cout << 0 << endl;
        }
        return 0;
    }
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> b;
    b.push_back(a[0]);
    for (int i = 1; i < n; i++){
        if (a[i] != a[i - 1]){
            b.push_back(a[i]);
        }
    }
    a = b;
    n = a.size();
    int k;
    cin >> k;
    for (int i = 0; i < k; i++){
        int p;
        cin >> p;
        if (a[0] >= p){
            cout << 0 << endl;
        }else{
            if (a[a.size() - 1] < p){
                cout << a.size() << endl;
            }else{
                int l = 0;
                int r = a.size() - 1;
                while (r - l > 1){
                    int m = (r + l) / 2;
                    if (a[m] >= p){
                        r = m;
                    }else{
                        l = m;
                    }
                }
                cout << l + 1 << endl;
            }
        }
    }
    return 0;
}
