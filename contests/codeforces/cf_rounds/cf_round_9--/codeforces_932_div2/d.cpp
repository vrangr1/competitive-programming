/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Tue Mar  5 21:08:58 IST 2024
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

void solve(){
    ll n, c; cin >> n >> c;
    vector<ll> s(n);
    ll hf = 0ll;
    vector<ll> ct(2);
    rep(i,n){
        cin >> s[i];
        hf += (s[i]/2ll);
        ct[s[i]%2ll]++;
    }
    hf += n;
    ll sol = c+1ll;
    sol += ((c/2ll)*(c/2ll + 1ll));
    if (c%2ll == 0ll) sol -= c/2ll;
    sol -= hf;
    auto get = [c](ll l, ll r, ll par) -> ll {
        par = par%2ll;
        if (l > r) return 0ll;
        assert(l <= (2ll*c));
        assert(r <= (2ll*c));
        if (l%2ll == par && r%2ll == par){
            return (r-l)/2ll + 1ll;
        }
        if (l%2ll == par){
            return (r-l-1ll)/2ll + 1ll;
        }
        if (r%2ll == par){
            return (r-l+1ll)/2ll + 1ll;
        }
        return (r-1ll-(l+1ll))/2ll + 1ll;
    };
    rep(i,n){
        ct[s[i]%2ll]--;
        sol -= get(s[i]+1ll,c,s[i]) - ct[s[i]%2ll];
    }
    assert(sol >= 0ll);
    // auto get2 = [c](ll r) -> ll {
    //     ll sol = (1ll+c)*(r+1ll);
    //     sol -= ((r/2ll)*(r/2ll+1ll));
    //     if (r%2ll == 0ll)
    //         sol += r/2ll;
    //     return sol;
    // };
    // sol += get2(2ll*c) - get2(c);
    auto get2 = [](ll r) -> ll {
        ll sol = (r/2ll)*(r/2ll + 1ll);
        if (r%2ll == 0ll) sol -= r/2ll;
        return sol;
    };
    sol += ((c+1ll)*c);
    sol += get2(c) - get2(2ll*c);
    rep(i,n){
        sol -= get(c+1ll,s[i]+c,s[i]);
    }
    cout << sol << endl;
}