/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed Dec 20 22:17:33 IST 2023
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

const ll mod = 998244353ll;

void solve(){
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    auto inv = [](auto &&self, ll n) -> ll {
        if (n <= 1ll) return n;
        return ((mod-mod/n)*self(self,mod%n))%mod;
    };
    sort(all(a));
    vector<vector<ll>> prs(n,vector<ll>(8,1ll));
    rep(pr,1,7,1){
        rep(i,n){
            prs[i][pr] = (prs[i][pr-1]*a[i])%mod;
        }
    }
    vector<ll> choose(8,0ll);
    choose[0] = choose[7] = 1ll;
    choose[1] = choose[6] = 7ll;
    choose[2] = choose[5] = 21ll;
    choose[3] = choose[4] = 35ll;
    vector<vector<ll>> psum(n+1ll,vector<ll>(8,0ll)), right(n+1ll,vector<ll>(8,0ll));
    rep(pr,8){
        rep(i,n){
            psum[i+1ll][pr] = psum[i][pr] + prs[i][pr];
        }
    }
    rep(pr,8){
        rep(i,n-1ll,0ll,-1ll){
            right[i][pr] = right[i+1ll][pr] + prs[i+1][pr];
        }
    }
    ll ct = 1ll;
    rep(i,n){
        ct *= 2ll;
        ct %= mod;
    }
    ct--;
    ct+=mod;
    ct%=mod;
    ll sum = 0ll;
    rep(i,n){
        rep(pr,8){
            sum += ct*(choose[pr]*psum[i][pr]*prs[i][pr]);
        }
        rep(pr,8){
            sum -= ct*(choose[pr]*right[i][pr]*prs[i][pr]);
        }
    }
}