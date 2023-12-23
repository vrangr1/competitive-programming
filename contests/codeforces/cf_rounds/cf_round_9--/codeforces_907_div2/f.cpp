#if 0
    me=`basename $0 .cpp`
    rm -f $me $me.out
    only_compile=${1:-0}
    if [ $only_compile == compile ]; then
        g++ -std=c++20 $me.cpp -o $me -Wall -O2 -Wextra -Wno-sign-conversion -Wshadow
        exit
    fi
    g++ -std=c++20 -DLOCAL $me.cpp -o $me -Wall -O2 -Wextra -Wno-sign-conversion -Wshadow
    if test -f $me; then
	    ./$me > $me.out
        echo "\noutput begins now:"
        cat $me.out
    	rm $me $me.out
    fi
    exit
#endif
/***************************************************
* AUTHOR : Anav Prasad
* Nick   : vrangr
****************************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <ctype.h>
#include <unordered_set>
#include <set>
#include <stdlib.h>
#include <map>
#include <iterator>
#include <iomanip>
#include <algorithm>
#include <climits>
#include <numeric>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <forward_list>
#include <unordered_map>
#include <bit>
#include <bitset>
#include <random>
#include <assert.h>
#define debug(...)
#ifdef LOCAL
    #undef debug
    #include <algo/debug.hpp>
    const bool DEBUG = true;
#endif

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0)
#define TEST int T;cin>>T;while(T--)solve();
#define TEST1 solve();
#define GET_MACRO(_1,_2,_3,_4,NAME,...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, forsn, qwe, forn)(__VA_ARGS__)
#define repll(...) GET_MACRO(__VA_ARGS__, forsnll, qwe, fornll)(__VA_ARGS__)
#define qwe(r,t,y)
#define forn(i, n) for (int i = 0; i < n; i++)
#define fornll(i, n) for (ll i = 0ll; i < n; i++)
#define forsn(i, st, end, d) for(int i = st; (d>0?i<=end:i>=end); i+=d)
#define forsnll(i, st, end, d) for(ll i = st; (d>0?i<=end:i>=end); i+=(ll)d)
#define all(x) (x).begin(), (x).end()
#define pass (void)0
#define space " "
#define yes "YES\n"
#define no "NO\n"
void solve();

int main(){
	fastIO;
	TEST;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

class node{
public:
    ll ind, fval, vsum;
    ll cts;
    set<pair<ll,ll>> vals;
    vector<node*> children;
    node(ll ind, ll cts):fval(0),vsum(0){
        this->ind = ind;
        this->children.clear();
        this->vals.clear();
        this->cts = cts;
    }
};

void dfs(node *cur, set<pair<ll,ll>> &add, ll vsum){
    set<pair<ll,ll>>::iterator it;
    for(it = add.begin(); it != add.end(); ++it){
        if (it->first < cur->cts) vsum -= it->second;
        else break;
    }
    vsum += cur->vsum;
    cur->fval = vsum;
    if (it != add.end())
        cur->vals.insert(it,add.end());
    for(auto child : cur->children)
        dfs(child, cur->vals, vsum);
}

void solve(){
    ll q; cin >> q;
    ll sz = 1;
    node *root = new node(1,0);
    vector<node*> nodes;
    nodes.push_back(root);
    rep(ts,q){
        ll t; cin >> t;
        if (t == 1){
            ll v; cin >> v; v--;
            sz++;
            node *child = new node(sz,ts);
            nodes.push_back(child);
            nodes[v]->children.push_back(child);
            continue;
        }
        assert(t==2);
        ll v, x; cin >> v >> x; v--;
        nodes[v]->vals.insert(make_pair(ts,x));
        nodes[v]->vsum += x;
    }
    set<pair<ll,ll>> st;
    dfs(nodes[0], st, 0);
    repll(i,sz) cout << nodes[i]->fval << " \n"[i==sz-1];
}