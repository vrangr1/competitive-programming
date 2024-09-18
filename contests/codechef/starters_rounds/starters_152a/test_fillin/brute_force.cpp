/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Wed Sep 18 21:21:19 IST 2024
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
template<typename type>inline void print_vec(const vector<type> &v){rep(i,sz(v))cout<<v[i]<<" \n"[i==sz(v)-1];}
void solve();

int main() {
	fastIO;
	TEST;
#ifdef LOCAL
    cout << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

const ll mod = 998244353ll;

void solve() {
    ll n; cin >> n;
    ll n2 = n*2ll;
    vector<ll> p(n2);
    rep(i,n2) cin >> p[i];
    vector<bool> miss(n2+1,true);
    rep(i,n2) miss[p[i]] = false;
    vector<ll> rem;
    rep(i,1,n2,1) if (miss[i]) rem.push_back(i);
    ll mx = 0ll;
    auto get = [&](auto &cp) -> ll {
        ll sol = 0ll;
        rep(i,n)
            sol += llabs(cp[2ll*i]-cp[2ll*i+1ll]);
        return sol;
    };
    do {
        auto cp = p;
        ll j = 0ll;
        rep(i,n2) 
            if (!cp[i]) cp[i] = rem[j++];
        mx = max(mx,get(cp));
    } while(next_permutation(all(rem)));
    ll sol = 0ll;
    sort(all(rem));
    do {
        auto cp = p;
        ll j = 0ll;
        rep(i,n2) 
            if (!cp[i]) cp[i] = rem[j++];
        if (get(cp) == mx) sol++;
    } while(next_permutation(all(rem)));
    cout << sol << endl;
}