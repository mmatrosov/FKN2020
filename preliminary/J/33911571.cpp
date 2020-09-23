#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<char> > ans(n, vector<char>(m));
    int it = 1;
    int x = 0, y = 0;
    char c = 'B';
    int jij = n*m;
    int sm = 0;
    bool kek = false;
    while(true){
        sm++;
        if((c-'A')&1)
            c--;
        else
            c++;
        if(kek||((y&1)&&x<it)||(((y&1)==0)&&(m-x)<it)){
            c += 2;
            kek = false;
        }
        if(c>'Z')
            c -= 26;
        for(int i = 0; i<it; i++){
            ans[y][x] = c;
            if(y&1){
                x--;
                if(x==-1){
                    x = 0;
                    y++;
                    kek = true;
                }
            }
            else{
                x++;
                if(x==m){
                    x = m-1;
                    y++;
                    kek = true;
                }
            }
        }
        jij -= it;
        it++;
        if(jij<it){
            for(int i = 0; i<jij; i++){
                ans[y][x] = c;
                if(y&1){
                    x--;
                    if(x==-1){
                        x = 0;
                        y++;
                    }
                }
                else{
                    x++;
                    if(x==m){
                        x = m-1;
                        y++;
                    }
                }
            }
            break;
        }
    }
    cout << sm << '\n';
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++)
            cout << ans[i][j];
        cout << '\n';
    }

    return 0;
}
