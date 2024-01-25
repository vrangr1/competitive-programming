/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed Jan 24 21:01:00 IST 2024
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

const ll mod = (ll)(1e9)+7ll;

void solve(){
    int n, k; cin >> n >> k;
    string s; cin >> s;
    string rev = s;
    reverse(all(rev));
    auto comp = [&](string t) -> ll {
        vector<int> lcs(n);
        lcs[0] = 0;
        int len = 0, i = 1;
        while(i < n){
            assert(len < n);
            if (s[i] == s[len])
                lcs[i++] = ++len;
            else{
                if (len != 0)
                    len = lcs[len-1];
                else
                    lcs[i++] = len;
            }
        }
        int j = 0;
        ll ct = 0ll;
        i = 0;
        while(i<sz(t)){
            if (t[i] == s[j]){
                ++i;
                j++;
            }
            if (j == n){
                ct++;
                j = lcs[j-1];
            }
            else if (i < sz(t) && s[j] != t[i]){
                if (j!=0)
                    j = lcs[j-1];
                else i++;
            }
        }
        --ct;
        if (rev == s) ct--;
        return ct;
    };
    auto comppr = [](auto &&self, ll a, ll n) -> ll {
        if (n == 0ll) return 1ll;
        if (n%2ll)
            return (a*self(self,(a*a)%mod,n/2ll))%mod;
        return self(self,(a*a)%mod,n/2ll);
    };
    ll pr = comppr(comppr,2ll,k-1ll);
    ll sol = (pr*comp(s+rev))%mod;
    sol+= ((pr-1ll)*comp(rev+s))%mod;
    sol%=mod;
    sol+= pr;
    sol%=mod;
    if(rev==s) sol +=pr;
    sol%=mod;
    cout << sol << endl;
}