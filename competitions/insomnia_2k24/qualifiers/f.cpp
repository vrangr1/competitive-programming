/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Mar 16 23:32:59 IST 2024
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
	TEST1;
#ifdef LOCAL
    cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

class node{
public:
    map<ll,ll> ct;
    ll mex;
    node():mex(1ll){}
};

void solve(){
    ll n, q; cin >> n >> q;
    vector<ll> v(n);
    map<ll,node> mp;
    auto get = [](ll val) -> pair<ll,ll> {
        ll r = __builtin_ctzll(val);
        rep(i,r) val>>=1ll;
        r++;
        return {val,r};
    };
    multiset<ll> mexs;
    rep(i,n){
        cin >> v[i];
        auto [val, r] = get(v[i]);
        while(true){
            if (mp.find(val) != mp.end())
                mp[val];
            node &nd = mp[val];
            nd.ct[r]++;
            while(nd.ct[nd.mex] > 0)
                nd.mex++;
            mexs.insert(nd.mex);
            r--;
            val<<=1ll;
            if (r == 0) break;
        }
    }
    while(q--){
        ll t, y; cin >> t >> y;
        auto [val, r] = get(y);
        if (t == 1ll){
            while(true){
                node &nd = mp[val];
                assert(nd.ct[r] > 0);
                nd.ct[r]--;
                if (nd.ct[r] == 0ll && nd.mex > r){
                    mexs.erase(mexs.find(nd.mex));
                    nd.mex = r;
                    mexs.insert(nd.mex);
                }
                r--;
                val<<=1ll;
                if (r == 0ll) break;
            }
        }
        else{
            while(true){
                node &nd = mp[val];
                nd.ct[r]++;
                mexs.erase(mexs.find(nd.mex));
                while(nd.ct[nd.mex] > 0)
                    nd.mex++;
                mexs.insert(nd.mex);
                r--;
                val<<=1ll;
                if (r == 0ll) break;
            }
        }
        if (!mexs.empty()) cout << (max(*mexs.rbegin(),1ll))-1ll << endl;
        else cout << "0\n";
    }
}