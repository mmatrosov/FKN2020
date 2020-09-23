#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

string c, d;

bool not_number(string & a){
    for (auto i : a){
        if (i < '0' || i > '9'){
            return 1;
        }
    }
    return 0;
}

string read_one(){
    string sup;
    if (cin >> sup){
        if (c == "no"){
            for (int i = 0; i < sup.size(); i++){
                if ('A' <= sup[i] && sup[i] <= 'Z' ){
                    sup[i] = (sup[i] - 'A') + 'a';
                }
            }
        }
        return sup;
    }
    return "";
}

vector<string> keywords;

bool is_keyword(string & a){
    for (auto i : keywords){
        if (a == i){
            return 1;
        }
    }
    return 0;
}

vector<string> cut(string & a){
    vector<string> ans;
    string cur = "";
    for (auto i : a){
        if (('0' <= i && i <= '9') || ('a' <= i && i <= 'z') || ('A' <= i && i <= 'Z') || i == '_'){
            cur += i;
        }else{
            if (cur != ""){
                ans.push_back(cur);
                cur = "";
            }
        }
    }
    if (cur != ""){
        ans.push_back(cur);
    }
    return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n >> c >> d;
    keywords.resize(n);
    for (int i = 0; i < n; i++){
        keywords[i] = read_one();
    }
    map<string, int> res;
    map<string, int> ind;
    string sup;
    while (true){
        sup = read_one();
        if (sup == ""){
            break;
        }
        vector<string> a = cut(sup);
        for (auto now  : a){
            if (!is_keyword(now) && not_number(now)){
                if (d == "no"){
                    if ('0' > now[0] || now[0] > '9' ){
                        res[now]++;
                        if (ind[now] == 0){
                            ind[now] = res.size();
                        }
                    }
                }else{
                    res[now]++;
                    if (ind[now] == 0){
                        ind[now] = res.size();
                    }
                }
            }
        }
    }
    string ans = "";
    for (auto i : res){
        /*if (ans != ""){
            cout << ans << ' ' << i.first << ' '  << res[ans] << ' ' << res[i.first] << ' ' << ind[ans] << ' ' << ind[i.first] << endl;
        }*/
        if (ans == "" || res[ans] < i.second || (res[ans] == i.second && ind[i.first] < ind[ans])){
            ans = i.first;
        }
    }
    cout << ans << endl;
    return 0;
}
