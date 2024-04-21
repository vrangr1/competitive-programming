/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Thu Apr 18 21:32:14 IST 2024
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
	TEST1;
#ifdef LOCAL
    cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

void solve(){
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<vector<ll>> g(n);
    rep(i,n){
        ll p; cin >> p;
        if (p == -1) assert(i==0);
        else {
            g[i].push_back(p);
            g[p].push_back(i);
        }
    }
    if (n == 1){
        cout << max(a.front(),0ll) << endl;
        return;
    }
    ll sol = 0;
    auto dfs = [&](auto &&self, ll node, ll parent, vector<ll> &vals) -> void {
        vals.push_back(a[node]);
        if (sz(g[node]) == 1 && g[node][0] == parent){
            assert(parent != -1);
            if (sz(vals) < k) {
                vals.pop_back();
                return;
            }
            ll sum = 0, m = sz(vals), ct = 0;
            rep(i,m){
                sum = 0;
                rep(j,i,m-1ll,1){
                    sum += vals[j];
                    if (j-i+1ll >= k) sol = max(sol,sum);
                }
            }
            // rep(i,m){
            //     sum += vals[m-i-1];
            //     ct++;
            //     if (ct >= k) sol = max(sol,sum);
            //     if (sum < 0){
            //         sum = 0;
            //         ct = 0;
            //     }
            // }
            
            // sum = 0ll;
            // rep(i,k) sum += vals[m-i-1];
            // if (k > 0) sol = max(sol,sum);
            // rep(i,k,m-1ll,1) {
            //     sum += vals[m-i-1ll];
            //     sol = max(sol,sum);
            // }

            // sum = 0ll;
            // rep(i,k) sum += vals[i];
            // if (k > 0) sol = max(sol,sum);
            // rep(i,k,m-1ll,1) {
            //     sum += vals[i];
            //     sol = max(sol,sum);
            // }
            
            vals.pop_back();
            return;
        }
        bool leaf = true;
        for (ll v : g[node]){
            if (v == parent) continue;
            self(self,v,node,vals);
            leaf = false;
        }
        assert(!leaf);
        vals.pop_back();
    };
    vector<ll> vals;
    dfs(dfs,0,-1,vals);
    assert(vals.empty());
    cout << sol << endl;

}