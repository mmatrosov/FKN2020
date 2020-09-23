#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <bitset>
#include <thread>
#include <random>
#include <queue>
#include <deque>
#include <ctime>
#include <cmath>
#include <stack>
#include <set>
#include <map>

using namespace std;

//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

bool c, d;

void norm(string &s){
    if(c)
        return;
    for(int i = 0; i<s.size(); i++)
        if('A'<=s[i]&&s[i]<='Z')
            s[i] += 'a'-'A';
    return;
}

bool num(string s){
    for(int i = 0; i<s.size(); i++)
        if(s[i]<'0'||'9'<s[i])
            return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(s[0]=='y')
        c = true;
    else
        c = false;
    cin >> s;
    if(s[0]=='y')
        d = true;
    else
        d = false;
    set<string> q;
    for(int i = 0; i<n; i++){
        cin >> s;
        norm(s);
        q.insert(s);
    }
    map<string, int> jij, jiji;
    int kek = 0;
    while(cin >> s){
        string s1 = "";
        for(int i = 0; i<s.size(); i++){
            char c = s[i];
            if(c=='_'||('0'<=c&&c<='9')||('a'<=c&&c<='z')||('A'<=c&&c<='Z')){
                s1.push_back(c);
                continue;
            }
            norm(s1);
            if(num(s1)){
                s1 = "";
                continue;
            }
            //cout << s1 << '\n';
            if(q.find(s1)!=q.end()){
                s1 = "";
                continue;
            }
            if(s1!=""&&!d&&'0'<=s1[0]&&s1[0]<='9'){
                s1 = "";
                continue;
            }
            if(jij[s1]==0)
                jiji[s1] = kek++;
            jij[s1]++;
            s1 = "";
        }
        norm(s1);
        if(num(s1)){
            s1 = "";
            continue;
        }
        //cout << s1 << '\n';
        if(q.find(s1)!=q.end()){
            s1 = "";
            continue;
        }
        if(s1!=""&&!d&&'0'<=s1[0]&&s1[0]<='9'){
            s1 = "";
            continue;
        }
        if(jij[s1]==0)
            jiji[s1] = kek++;
        jij[s1]++;
        s1 = "";
    }
    string ans = "";
    int cnt = 0, pl = 228337;
    for(auto it = jij.begin(); it!=jij.end(); it++){
        //cout << (it->first) << ' ' << (it->second) << endl;
        if(cnt<(it->second)||(cnt==(it->second)&&pl>jiji[it->first])){
            ans = (it->first);
            cnt = (it->second);
            pl = jiji[it->first];
        }
    }
    cout << ans;

    return 0;
}
