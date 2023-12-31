/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Dec 30 20:51:47 IST 2023
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
#include <bit>
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
typedef __int128_t i128;
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
    vector<int> p(n), deg(n,0);
    p[0] = -1;
    rep(i,n-1){
        cin >> p[i+1];
        --p[i+1];
        deg[i+1]++;
        deg[p[i+1]]++;
    }
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    if (n == 1) return void(cout << "1\n");
    if (n == 2){
        if (set<int>(all(a)).size() == 1) return void(cout << "1\n");
        cout << "2\n";
        return;
    }
    vector<vector<int>> fmax(n),smax(n);
    auto add = [&](int node, int ct, int child) -> bool {
        if (fmax[node].empty()){
            fmax[node] = {ct,child};
            return true;
        }
        if (child == fmax[node][1]){
            if (fmax[node][0] > ct) return false;
            fmax[node][0] = max(fmax[node][0],ct);
            return true;
        }
        if (fmax[node][0] < ct){
            // swap(fmax[node],smax[node]);
            smax[node] = fmax[node];
            fmax[node] = {ct,child};
            return true;
        }
        if (smax[node].empty() || smax[node][0] < ct){
            smax[node] = {ct,child};
            return true;
        }
        if (smax[node][0] > ct || smax[node][1] == child){
            return smax[node][0] == ct;
            // return true;
        }
        return true; // Works???    
    };
    auto process = [&](int node){
        set<int> st = {a[node]};
        add(node,sz(st),-1);
        int prev = node;
        node = p[node];
        while(node != -1){
            st.insert(a[node]);
            bool upd = add(node,sz(st),prev);
            if (!upd) return;
            assert(node != p[node]);
            prev = node;
            node = p[node];
        }
    };
    rep(i,1,n-1,1){
        if (deg[i] != 1) continue;
        process(i);
        debug(i,fmax,smax);
    }
    ll mx = -1;
    rep(i,n){
        if (fmax[i].empty()) continue;
        if (smax[i].empty()){
            mx = max((ll)fmax[i][0],mx);
            continue;
        }
        assert(!fmax[i].empty());
        ll v1 = fmax[i][0], v2 = smax[i][0];
        mx = max(mx,v1*v2);
    }
    cout << mx << endl;
}

/*


4

1
2
1
1 2

1
7
1 1 2 2 3 3
6 5 2 3 6 5 6

13
1 1 1 2 2 2 3 3 4 5 6 6
2 2 2 1 4 9 7 2 5 2 1 11 2
12
1 1 1 2 2 3 4 4 7 7 6
11 2 1 11 12 8 5 8 8 5 11 7



*/