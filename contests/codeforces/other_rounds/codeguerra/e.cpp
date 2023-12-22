/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Fri Dec 22 20:18:57 IST 2023
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

class node{
public:
    ll val;
    node *next, *prev;
    node(ll v){
        val = v;
        next = nullptr;
        prev = nullptr;
    }
};

void solve(){
    ll n; cin >> n;
    vector<ll> a(n),b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    auto compute = [&](const ll ind) -> ll {
        ll ct = 0, csum = 0;
        node *cur = new node(0), *nd = nullptr;
        if (ind == 0) nd = cur;
        rep(i,1,n-1ll,1){
            cur->next = new node(i);
            cur->next->prev = cur;
            cur = cur->next;
            if (i == ind) nd = cur;
        }
        while(true){
            ll cind = nd->val;
            if (!nd->next && !nd->prev){
                if (a[cind] + csum >= b[cind]) return ct;
                else return ct+b[cind]-a[cind]-csum;
            }
            if (a[cind] + csum < b[cind]){
                ct += b[cind]-a[cind]-csum;
                csum += b[cind]-csum;
            }
            else csum += a[cind];
            if (nd->next && nd->prev){
                if (b[nd->next->val]-csum-a[nd->next->val] <= b[nd->prev->val]-csum-a[nd->prev->val]){
                    if (nd->prev) nd->prev->next = nd->next;
                    nd->next->prev = nd->prev;
                    nd = nd->next;
                }
                else{
                    if (nd->next) nd->next->prev = nd->prev;
                    nd->prev->next = nd->next;
                    nd = nd->prev;
                }
            }
            else if (nd->next){
                if (nd->prev) nd->prev->next = nd->next;
                nd->next->prev = nd->prev;
                nd = nd->next;
            }
            else{
                assert(nd->prev);
                if (nd->next) nd->next->prev = nd->prev;
                nd->prev->next = nd->next;
                nd = nd->prev;
            }
        }
        return ct;
    };
    rep(i,n)
        cout << compute(i) << " \n"[i==n-1];
}