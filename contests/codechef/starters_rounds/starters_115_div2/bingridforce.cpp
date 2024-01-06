/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed Jan  3 21:38:56 IST 2024
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

const ll mod = (ll)1e9+7ll;

void solve(){
    ll n, m; cin >> n >> m;
    vector<string> l(n);
    rep(i,n) cin >> l[i];
    string p = l.back();
    string z = l.back();
    rep(i,n-2ll,0ll,-1){
        if (count(all(l[i+1]),'1') <= 1){
            p = l[i];
            z = l[i];
            continue;
        }
        string pn = l[i], zn = l[i];
        vector<bool> left(m,false), right(m,false);
        if (m > 1){
            left[1] = (p[0] == '1' && pn[0] == '0');
            right[m-2] = (p.back() == '1' && pn.back() == '0');
        }
        rep(j,2,m-1ll,1)
            left[j] = left[j-1]||(p[j-1]=='1'&&pn[j-1]=='0');
        rep(j,m-3ll,0ll,-1ll)
            right[j] = right[j+1]||(p[j+1]=='1'&&pn[j+1]=='0');
        rep(j,m){
            if (pn[j] == '1' && p[j] == '1' && (left[j] || right[j])){
                zn[j] = '0';
            }
            if (pn[j] == '1' || p[j] == '0') continue;
            pn[j] = '1';
        }
        swap(p,pn);
        swap(z,zn);
    }
    ll ct = count(all(l[0]),'1'), t = 0;
    rep(i,m){
        if (p[i] == '1' && z[i] == '0'){
            ++t;
        }
        if (l[0][i] == '1' && z[i] == '1') --ct;
    }
    assert(ct >= 0);
    assert(t>=0);
    assert(ct <= t);
    auto inv = [](auto &&self, ll n) -> ll {
        if (n <= 1) return 1ll;
        return ((mod - mod/n)*self(self,mod%n))%mod;
    };
    auto fac = [](ll n){
        if (n <= 1) return 1ll;
        ll f = 1ll;
        rep(i,1ll,n,1ll){
            f *= i;
            f%=mod;
        }
        return f;
    };
    ll sol = fac(t);
    sol *= inv(inv,fac(ct));
    sol %= mod;
    sol *= inv(inv,fac(t-ct));
    sol %= mod;
    cout << sol << endl;
}