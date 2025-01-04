/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sat Jan  4 20:12:24 IST 2025
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

void solve() {
    ll l, r; cin >> l >> r;
    assert(r > l+1ll);
    ll com = 0;
    auto msb = [](ll n) -> ll {
        return (1ll << (63ll-__builtin_clzll(n)));
    };
    while(msb(l) == msb(r)) {
        ll cur = msb(l);
        com += cur;
        l-=cur;
        r-=cur;
        assert(l >= 0);
        assert(r >= 0);
    }
    ll a = com, b = com, c = com;
    debug(l,r);
    if (DEBUG) {
        debug(bitset<10>(l).to_string());
        debug(bitset<10>(r).to_string());
    }
    if (msb(r) > 2 && (msb(r)>>1ll)-1ll >= l) {
        ll cur = msb(r);
        a |= cur;
        b |= (cur-1ll);
        c |= ((cur>>1ll)-1ll);
        cout << a << " " << b << " " << c << endl;
    }
    else {
        assert(r-l>=2ll);
        ll cur = msb(r);
        a |= cur;
        b |= (cur-1ll);
        assert(cur-1ll >= l);
        ll p = msb(cur-1ll);
        while(p > 0) {
            if (((cur-1ll)^p) >= l) break;
            p>>=1ll;
        }
        if (p) {
            c |= ((cur-1ll)^p);
        } else {
            c = a+1;
        }
        cout << a << " " << b << " " << c << endl;
    }
    
    if (DEBUG) {
        [[maybe_unused]] auto comp = [](ll p, ll q, ll v) -> ll {
            return (p^q) + (q^v) + (v^p);
        };
        debug(comp(a,b,c));
        // debug(comp(8,7,1));
        // debug(comp(1,2,3));
        // debug(comp(7,16,11));
        // debug(comp(132,134,137));
        // debug(comp(98,85,76));
        // debug(comp(123,121, 118));
        debug(comp(965321865,375544086,12551794));
    }
}