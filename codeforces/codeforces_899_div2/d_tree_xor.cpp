#if 0
    me=`basename $0 .cpp`
    rm -f $me $me.out
    g++ -std=c++20 -DLOCAL $me.cpp -o $me
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
#include <assert.h>
#define debug(...)
#ifdef LOCAL
    #undef debug
    #include <algo/debug.hpp>
    const bool DEBUG = false;
#else
    const bool DEBUG = false;
#endif

using namespace std;

#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0)
#define TEST int T;cin>>T;while(T--)solve();
#define TEST1 solve();
#define GET_MACRO(_1,_2,_3,_4,NAME,...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, forsn, qwe, forn)(__VA_ARGS__)
#define qwe(r,t,y)
#define forn(i, n) for (int i = 0; i < n; i++)
#define forsn(i, st, end, d) for(int i = st; (d>0?i<=end:i>=end); i+=d)
#define all(x) (x).begin(), (x).end()
#define pass (void)0
#define space " "
#define yes "YES\n"
#define no "NO\n"
typedef long long int ll;
typedef unsigned long long int ull;
void solve();

int main(){
	fastIO;
	TEST;
	return 0;
}

// bitset<(int)2e5> vis;

void process(int node, int parent, const vector<int> &a, const vector<vector<int>> &edges, vector<unordered_map<int, vector<vector<ll>>>> &dp, vector<unordered_map<int,ll>> &sizes, vector<ll> &answers){
    if (parent == -1 && answers[node] != LLONG_MAX) return;
    if (dp[node].find(parent) != dp[node].end()) return;
    // if (subtree_answers[node].find(parent) != subtree_answers[node].end())
    //     return;
    sizes[node][parent] = 1;
    dp[node][parent] = vector<vector<ll>>(20, vector<ll>(2,0ll));
    if (edges[node].size() == 0){
        answers[node] = 0ll;
        return;
    }
    ll num;
    // subtree_answers[node][parent] = 1;
    if (edges[node].size() == 1 && parent != -1){
        assert(edges[node][0] == parent);
        rep(bit, 20){
            num = (ll)(1<<bit);
            dp[node][parent][bit][(a[node]&num)>0] = 0;
            dp[node][parent][bit][(a[node]&num)==0] = num;
        }
        return;
    }
    for (int neighbor : edges[node]){
        if (neighbor == parent) continue;
        process(neighbor, node, a, edges, dp, sizes, answers);
        sizes[node][parent] += sizes[neighbor][node];
    }
    for (int neighbor : edges[node]){
        if (neighbor == parent) continue;
        rep(bit, 20){
            num = (ll)(1<<bit);
            if (a[node]&num){
                dp[node][parent][bit][0] += dp[neighbor][node][bit][1];
                dp[node][parent][bit][1] += dp[neighbor][node][bit][1];
            }
            else{
                dp[node][parent][bit][0] += dp[neighbor][node][bit][0];
                dp[node][parent][bit][1] += dp[neighbor][node][bit][0];
            }
        }
    }
    rep(bit,20){
        num = (ll)(1<<bit);
        if (a[node]&num)
            dp[node][parent][bit][0] += sizes[node][parent]*(num);
        else
            dp[node][parent][bit][1] += sizes[node][parent]*(num);
    }
    if (parent == -1){
        answers[node] = 0ll;
        debug(node, dp[node][parent],endl);
        rep(bit, 20)
            answers[node] += min(dp[node][parent][bit][0], dp[node][parent][bit][1]);
    }
}

vector<vector<int>> edges(2e5);
vector<unordered_map<int, vector<vector<ll>>>> dp(2e5);
vector<unordered_map<int, ll>> sizes(2e5);
vector<ll> answers(2e5);

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    // vector<vector<int>> edges(n);
    rep(i,n){
        edges[i].clear();
        dp[i].clear();
        answers[i] = LLONG_MAX;
    }
    // vector<unordered_map<int, vector<vector<ll>>>> dp(n);
    // vector<unordered_map<int, ll>> subtree_answers(n);
    // vector<unordered_map<int, ll>> sizes(n);
    // vector<ll> answers(n, LLONG_MAX);
    
    // vis.reset();
    rep(i,n){
        cin >> a[i];
        edges[i].clear();
        dp[i].clear();
    }
    if (n == 1) return void(cout << "0\n");
    // fill(answers.begin(), answers.begin() + n, LLONG_MAX);
    int u, v;
    rep(i,n-1){
        cin >> u >> v;
        u--; v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    rep(i,n)
        process(i,-1,a,edges,dp, sizes, answers);
    rep(i,n)
        cout << answers[i] << " \n"[i==n-1];
}