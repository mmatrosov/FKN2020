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

const int maxLog = 32;

struct node{
    int ind;
    node * go[2];
    node(int ind = -1){
        this->ind = ind;
        go[0] = nullptr;
        go[1] = nullptr;
    }
};

typedef node * pnode;

vector<int> getBin(int x){
    vector<int> ans;
    for(int i = 0; i < maxLog; i++){
        ans.push_back(x % 2);
        x /= 2;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

struct trie{
    pnode root;
    trie(){
        root = new node();
    }
    void add(int x, int ind){
        vector<int> a = getBin(x);
        pnode v = root;
        for(auto i : a){
            if(!v->go[i])v->go[i] = new node();
            v = v->go[i];
        }
        v->ind = ind;
    }
    void print(pnode v){
        if(v->ind > -1)cout << v->ind << " ";
        if(v->go[0])print(v->go[0]);
        if(v->go[1])print(v->go[1]);
    }
    int getMaxXor(int x){
        vector<int> a = getBin(x);
        pnode v = root;
        for(auto i : a){
            if(v->go[i ^ 1])v = v->go[i ^ 1];
            else v = v->go[i];
        }
        return v->ind;
    }
};

int n;
vector<vector<pair<int, int>>> g;
vector<int> pxor;

void dfs(int v, int p = -1, int d = 0){
    pxor[v] = d;
    for(auto t : g[v]){
        int to = t.first, w = t.second;
        if(to == p)continue;
        dfs(to, v, d ^ w);
    }
}

signed main(){
    cin >> n;
    g.resize(n);
    pxor.resize(n);
    for(int i = 1; i < n; i++){
        int a, b, w; cin >> a >> b >> w; a--; b--;
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }
    dfs(0);
    trie t; t.add(pxor[0], 0);
    int ans = 0, a = 0, b = 0;
    for(int i = 1; i < n; i++){
        int ind = t.getMaxXor(pxor[i]);
        if((pxor[ind] ^ pxor[i]) >= ans){
            ans = pxor[ind] ^ pxor[i];
            a = ind;
            b = i;
        }
        t.add(pxor[i], i);
    }
    cout << a + 1 << " " << b + 1 << "\n";
    return 0;
}

