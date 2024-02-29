/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Tue Feb 27 20:13:13 IST 2024
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
	TEST;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

void solve1(){
    ll a, b, l; cin >> a >> b >> l;
    map<pair<ll,ll>, ll> mp;
    auto pr = [&mp](auto &&self, ll a, ll n) -> ll {
        if (mp.find({a,n}) != mp.end()) return mp[{a,n}];
        if (n == 0ll) return mp[{a,n}] = 1ll;
        if (n%2ll) return mp[{a,n}] = a*self(self,a*a,n/2ll);
        return mp[{a,n}] = self(self,a*a,n/2ll);
    };
    auto bsch = [&pr](auto &&self, ll low, ll high, ll a, ll k) -> ll {
        if (low == high){
            ll p = pr(pr,a,low);
            assert(p <= k);
            return low;
        }
        ll mid = (low+high+1ll)/2ll;
        ll p = pr(pr,a,mid);
        if (p > k) return self(self, low, mid-1ll,a,k);
        if (p == k) return mid;
        return self(self, mid, high, a, k);
    };
    auto comp = [](ll l, ll b) -> ll {
        ll v = 1ll, sol = 0ll;
        while(l%v == 0ll){
            sol++;
            v*=b;
        }
        return sol;
    };
    ll amx = 7, bmx = 7;
    while(pr(pr,a,amx) < l) amx++;
    while(pr(pr,b,bmx) < l) bmx++;
    if (a%b &&  b%a){
        ll sol = 0;
        ll v = 1ll;
        while(l%v == 0ll){
            sol += comp(l/v,b);
            v*=a;
        }
        cout << sol << endl;
        return;
    }
    if (a > b) swap(a,b);
    cout << comp(l,a) << endl;
}

void solve(){
    ll a, b, l; cin >> a >> b >> l;
    set<ll> k;
    ll va = 1ll, vb = 1ll;
    while(l%va == 0ll){
        ll lb = l/va;
        vb = 1ll;
        while(lb%vb == 0ll){
            k.insert(lb/vb);
            vb *= b;
        }
        va *= a;
    }
    cout << sz(k) << endl;
}