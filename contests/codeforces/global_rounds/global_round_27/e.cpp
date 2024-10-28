/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sun Oct 27 22:02:32 IST 2024
****************************************************/
#include <bits/stdc++.h>

#define debug(...) (void)42
#ifdef LOCAL
    #undef debug
    #include <algo/debug.hpp>
    const bool DEBUG = false;
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
    ll x, y, z, k; cin >> x >> y >> z >> k;
    ll base = 0ll;
    auto cost = [&](ll d) -> ll {
        assert(d > 0ll);
        return max(d-base,0ll)*x + ((z+d-1)/d)*y;
    };
    auto best = [&](ll rt) -> ll {
        assert(rt >= 0ll);
        ll bd = rt, bt = LLONG_MAX;
        rep(d,max({rt-1000000,base,1ll}),(ll)min(rt+5,z),1ll) {
            ll cur = cost(d);
            if (cur < bt) {
                bt = cur;
                bd = d;
            }
        }
        return bd;
    };
    ll sol = 0ll;
    debug(x,y,k);
    while(z > 0) {
        debug(endl,z,base);
        if (z <= base) {
            sol += y;
            break;
        }
        ld t = ld(z*y) / ld(x);
        debug(t);
        t = sqrtl(t);
        debug(t);
        ll rt = ll(t);
        debug(rt);
        rt = best(rt);
        assert(rt > 0);
        debug(rt);
        if (base >= rt) {
            assert(base > 0ll);
            sol += ((z+base-1)/base)*y;
            break;
        }
        if (rt-base <= k) {
            sol += cost(rt);
            break;
        }
        base += k;
        sol += k*x + y;
        debug(z,base);
        // if (z <= base) exit(0);
        assert(z > base);
        z-=base;
    }
    cout << sol << endl;
}