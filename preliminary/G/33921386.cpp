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
#pragma GCC optimize("Ofast,no-stack-protector")*/
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

struct Node{

    int_fast32_t v, x = 0;
    Node* nx[2];

    Node(){
        nx[0] = nullptr;
        nx[1] = nullptr;
    }

    Node(int_fast32_t v): v(v){
        nx[0] = nullptr;
        nx[1] = nullptr;
    }

    void rev(int_fast32_t it){
        if(x&(1u<<it))
            swap(nx[0], nx[1]);
        if(nx[0]!=nullptr)
            nx[0]->x ^= x;
        if(nx[1]!=nullptr)
            nx[1]->x ^= x;
        x = 0;
    }

};

struct Bor{

    int_fast32_t sz = 0;
    Node *rt = nullptr;

    Bor(){
        rt = new Node();
    }

    void add(int_fast32_t a, int_fast32_t V){
        Node *v = rt;
        for(int_fast32_t i = 31; i>=0; i--){
            v->rev(i);
            if((v->nx[(a&(1u<<i))>>i])==nullptr){
                v->nx[(a&(1u<<i))>>i] = new Node(V);
                if(i==0)
                    sz++;
            }
            v = v->nx[(a&(1u<<i))>>i];
        }
    }

    pair<int_fast32_t, int_fast32_t> get(int_fast32_t a){
        Node *v = rt;
        int_fast32_t ans = 0;
        for(int_fast32_t i = 31; i>=0; i--){
            v->rev(i);
            if((v->nx[((a&(1u<<i))>>i)^1])!=nullptr){
                ans |= (1u<<i);
                v = v->nx[((a&(1u<<i))>>i)^1];
            }
            else
                v = v->nx[(a&(1u<<i))>>i];
        }
        return {ans, v->v};
    }

};

int_fast32_t ans = 0;
int_fast32_t v1 = 0, v2 = 0;
vector<vector<pair<int_fast32_t, int_fast32_t> > > g;

void calc(Node *v, Bor *b, int_fast32_t kek, int_fast32_t d){
    if(v==nullptr)
        return;
    if(d==-1){
        pair<int_fast32_t, int_fast32_t> jij = b->get(kek);
        if(jij.first>ans){
            ans = jij.first;
            v1 = jij.second;
            v2 = v->v;
        }
        return;
    }
    v->rev(d);
    calc(v->nx[0], b, kek, d-1);
    calc(v->nx[1], b, kek+(1u<<d), d-1);
}

Node* mer(Node *a, Node *b, int d){
    if(a==nullptr)
        return b;
    if(b==nullptr)
        return a;
    a->rev(d);
    b->rev(d);
    b->nx[0] = mer(a->nx[0], b->nx[0], d-1);
    b->nx[1] = mer(a->nx[1], b->nx[1], d-1);
    return b;
}

Bor* dfs(int_fast32_t v, int_fast32_t pr = -1){
    Bor *b = new Bor();
    bool kek = true;
    for(int_fast32_t i = 0; i<g[v].size(); i++){
        if(g[v][i].first==pr)
            continue;
        Bor *b1 = dfs(g[v][i].first, v);
        if(b1->sz!=0){
            pair<int_fast32_t, int_fast32_t> jij = b1->get(g[v][i].second);
            //cout << jij.first << '/' << ans << endl;
            if(jij.first>ans){
                ans = jij.first;
                v1 = jij.second;
                v2 = v;
            }
        }
        b1->rt->x ^= g[v][i].second;
        b1->add(g[v][i].second, g[v][i].first);
        if(g[v][i].second>ans){
            ans = g[v][i].second;
            v1 = v;
            v2 = g[v][i].first;
        }
        if(kek){
            kek = false;
            b = b1;
            continue;
        }
        if((b1->sz)>(b->sz))
            swap(b, b1);
        //cout << (b1->sz) << ':' << (b->sz) << endl;
        calc(b1->rt, b, 0, 31);
        b->rt = mer(b1->rt, b->rt, 31);
    }
    return b;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int_fast32_t n;
    cin >> n;
    g.resize(n);
    for(int_fast32_t i = 1; i<n; i++){
        int_fast32_t a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    dfs(0);
    cout << v1+1 << ' ' << v2+1;

    return 0;
}
/*
3
1 2 4294967294
2 3 1
*/
