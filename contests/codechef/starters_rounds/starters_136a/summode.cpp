/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed May 29 20:00:33 IST 2024
****************************************************/
#include <bits/stdc++.h>

#define debug(...) (void)42
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
    cout << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

void solve(){
    ll n; cin >> n;
    string s; cin >> s;
    ll sol = ((n*(n-1ll))/2ll) + n;
    vector<ll> psum(n,0);
    psum[0] = (s[0] == '1'?1:-1);
    map<ll,ll> mp;
    auto get = [&](ll i) -> ll {
        ll cur = 0ll;
        if (!psum[i]) cur++;
        cur += mp[psum[i]];
        return cur;
    };
    debug(sol);
    mp[psum[0]]++;
    rep(i,n) {
        if (!i) continue;
        psum[i] = psum[i-1] + (s[i] == '1'?1ll:-1ll);
        debug(i,mp,get(i));
        sol += get(i);
        mp[psum[i]]++;
    }
    debug(psum);
    cout << sol << endl;
}