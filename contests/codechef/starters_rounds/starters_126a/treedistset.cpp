/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed Mar 20 20:22:39 IST 2024
****************************************************/
#include <iostream>
#include <vector>
#include <string.h>
#include <ctype.h>
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
// #include <bit>
#include <bitset>
#include <array>
#include <assert.h>
#define debug(...) 42
#ifdef LOCAL
    #undef debug
    #include <algo/debug.hpp>
    const bool DEBUG = true;
#else
    [[maybe_unused]] const bool DEBUG = false;
#endif

using namespace std;

typedef unsigned int uint;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
// typedef __int128_t i128;
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0)
#define TEST int T;cin>>T;while(T--)solve();
#define TEST1 solve();
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(v) ((int)(v).size())
#define GET_MACRO(_1,_2,_3,_4,NAME,...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, forsn, debug, forn)(__VA_ARGS__)
#define forn(i, n) for (__typeof(n) i = 0; i < n; i++)
#define forsn(i, st, end, d) for(__typeof(end) i = st; (d>0?i<=end:i>=end); i+=((__typeof(end))d))
#define mt make_tuple
#define space " "
#define yes "YES\n"
#define no "NO\n"
#define pass ((void)0)
template<typename type>inline void print_vec(const vector<type> &v){rep(i,sz(v))cout<<v[i]<<" \n"[i==sz(v)-1];}
void solve();

// IMPORT SNIPPETS HERE

// END OF SNIPPETS

int main(){
	fastIO;
	TEST;
#ifdef LOCAL
    cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

void solve(){
    int n; cin >> n;
    vector<vector<int>> adj(n);
    rep(i,n-1){
        int u,v; cin >> u >> v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }
    int mxdist = 0, mxnode = 0, root = 0;
    vector<int> marked(n,false);
    vector<int> diam;
    auto dfs = [&](auto &&self, int node, int parent, int d, bool flag = false) -> bool {
        if (d > mxdist){
            mxdist = d;
            mxnode = node;
        }
        if (sz(adj[node]) == 1 && parent != -1){
            assert(adj[node][0] == parent);
            if (flag && d == mxdist){
                fill(all(marked),false);
                diam.clear();
                diam.push_back(node);
                marked[node] = true;
                return true;
            }
            return false;
        }
        bool mark = false;
        for (int v : adj[node]){
            if (v == parent) continue;
            bool cur = self(self,v,node,d+1,flag);
            if (!flag) assert(!cur);
            mark |= cur;
        }
        if (mark){
            assert(flag);
            marked[node] = true;
            diam.push_back(node);
        }
        return mark;
    };
    dfs(dfs,root,-1,0);
    root = mxnode;
    debug(mxnode,mxdist);
    mxdist = 0;
    mxnode = root;
    dfs(dfs,root,-1,0,true);
    debug(diam,marked);
    int dm = sz(diam);
    assert(dm > 0);
    string color(n,'.');
    reverse(all(diam));
    rep(i,dm/2){
        assert(marked[diam[i]] && marked[diam[dm-i-1]]);
        assert(color[diam[i]] == '.' && color[diam[dm-i-1]] == '.');
        color[diam[i]] = 'R';
        color[diam[dm-i-1]] = 'B';
    }
    int rest = n-dm, ct = 0, t;
    if (dm%2){
        assert(marked[diam[dm/2]]);
        assert(color[diam[dm/2]] == '.');
        color[diam[dm/2]] = 'R';
        if (rest%2)
            t = rest/2;
        else
            t = rest/2 - 1;
    }
    else{
        t = rest/2 - 1;
    }
    debug(rest,t);
    rep(i,n){
        if (marked[i]){
            assert(color[i] != '.');
            continue;
        }
        assert(color[i] == '.');
        color[i] = (ct <= t? 'B': 'R');
        ct++;
    }
    debug(color);
    int rc = (int)count(all(color),'R'), bc = (int)count(all(color),'B');
    if (n%2 == 0) assert(rc == bc);
    else assert(abs(rc-bc) == 1);
    assert(find(all(color), '.') == color.end());
    cout << color << endl;
}