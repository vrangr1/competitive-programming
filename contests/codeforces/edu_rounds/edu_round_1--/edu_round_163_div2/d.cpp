/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Fri Mar 15 20:30:21 IST 2024
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
#ifndef RANDOM_SNIPPET
#define RANDOM_SNIPPET
#include <random>
#include <chrono>
std::mt19937 rng((unsigned int)std::chrono::steady_clock::now().time_since_epoch().count());
unsigned long long int grng(const unsigned long long int maxval){return rng()%maxval;}
#endif
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
    string s; cin >> s;
    int n = sz(s);
    vector<int> lps(n);
    auto lpscomp = [&](int ind) -> void {
        lps[ind] = 0;
        int i = ind+1, len = 0;
        while(i < n){
            if (s[i] == s[len+ind] || s[i] == '?' || s[len+ind] == '?'){
                lps[i++] = ++len;
            }
            else{
                if (len == 0)
                    lps[i++] = len;
                else len = lps[len-1+ind];
            }
        }
    };
    auto tandem = [&](int i, int j) -> bool {
        int len = lps[j], tn = j-i+1;
        tn>>=1;
        while(len >= tn){
            if (len == tn) return true;
            len = lps[i+len-1];
        }
        return false;
    };
    int len = 0;
    for (int i = 0; i < n; ++i){
        lpscomp(i);
        debug(i,lps);
        for (int j = i+1; j < n; ++j){
            if ((j-i+1)%2) continue;
            if (tandem(i,j)) len = max(len,j-i+1);
        }
    }
    cout << len << endl;
}

const vector<ll> mods = {(ll)1e9+7ll,(ll)1e9+123ll,998244353ll};
vector<ll> bases;
const ll maxbasect = 3ll;
int basect;
const int maxn = 2501ll;
vector<vector<vector<ll>>> basepwrs(maxbasect+1,vector<vector<ll>>(maxn,vector<ll>(3)));

void init(){
    static bool init = false;
    if (init) return;
    init = true;
    basect = (int)grng(maxbasect)+2;
    rep(i,basect) bases.push_back(grng(mods[grng(sz(mods))]-100000000ll)+2ll);
    rep(i,basect){
        rep(j,(int)maxn){
            rep(k,3){
                if (j == 0){
                    basepwrs[i][j][k] = 1ll;
                    continue;
                }
                basepwrs[i][j][k] = (basepwrs[i][j-1][k]*bases[i])%mods[k];
            }
        }
    }
}

void solve(){
    init();
    string s; cin >> s;
    ll n = sz(s);
    auto inv = [](ll a, ll ind) -> ll {
        ll n = mods[ind]-2ll;
        assert(n>0ll);
        ll sol = 1ll;
        while(n > 1){
            if (n%2ll)
                sol = (sol*a)%mods[ind];
            a = (a*a)%mods[ind];
            n/=2ll;
        }
        return (sol*a)%mods[ind];
    };
    auto get = [&](ll ind, ll n, ll bind, ll mind) -> ll {
        return (basepwrs[bind][n][mind]*s[ind])%mods[mind];
    };
    auto get_hash = [&](ll st, ll end, ll bind, ll mind) -> ll {
        ll hash = 0ll;
        hash += (ll)s[st];
        rep(i,st+1ll,end,1ll) {
            hash += (basepwrs[bind][i-st][mind]*s[i])%mods[mind];
            hash%=mods[mind];
        };
        return hash;
    };

    ll sol = 0ll;
    ll bind = 0, mind = 0;
    rep(i,n){
        ll last = n-1ll, len = last-i+1ll;
        if (last%2ll){
            last--;
            len--;
        }
        ll lhash = get_hash(i,i+(len/2ll) -1ll,bind,mind), rhash = get_hash(i+len/2ll, last, bind,mind);
        ll mid = i+(len/2ll)-1ll;
        if (lhash == rhash) sol = max(sol,len);
        --mid;
        while(mid >= i){
            lhash = (lhash + mods[mind] - get(mid+1ll,mid+1ll-i,bind,mind))%mods[mind];
            rhash = (rhash + mods[mind] - get(i+len-1ll,i+len-1ll-mid-1ll,bind,mind))%mods[mind];
            rhash *= bases[bind];
            rhash %= mods[mind];
            rhash = (rhash + s[mid+1ll])%mods[mind];
            len-=2ll;
            if (lhash == rhash) sol = max(sol,len);
            --mid;
        }
    }
    cout << sol << endl;
}

/*


4
zaabaabz
?????
code?????s
codeforces


*/