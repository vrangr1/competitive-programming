/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sat Aug 31 20:44:45 IST 2024
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
	TEST1;
#ifdef LOCAL
    cout << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

class Solution {
public:
    long long minDamage(ll pr, vector<int>& damage, vector<int>& hh) {
        ll n = damage.size();
        vector<ll> dmg(n), h(n);
        for (ll i = 0; i < n; ++i) {
            dmg[i] = damage[i];
            h[i] = hh[i];
        }
        vector<ll> order(n);
        iota(all(order),0ll);
        sort(all(order),[&](const ll &i, const ll &j) {
            // return dmg[i]*((h[i]+pr-1ll)/pr) > dmg[j]*((h[j]+pr-1ll)/pr);
            ll s1 = ll((h[i]+pr-1ll)/pr), s2 = ll((h[j]+pr-1ll)/pr);
            // return dmg[i]*s1 > dmg[j]*s2;
            // return dmg[i]*s1 < dmg[j]*s2;
            // return s1 < s2;
            // return s1 > s2;
            // if (dmg[i] != dmg[j]) return dmg[i] > dmg[j];
            // return s1 < s2;
            // if (dmg[i] != dmg[j]) return dmg[i] < dmg[j];
            // return s1 < s2;
            // return s1 > s2;
            ld d1 = (ld(dmg[i]))/((ld)s1), d2 = (ld(dmg[j]))/((ld)s2);
            // return d1 < d2;
            return d1 > d2;
        });
        debug(order);
        ll cur = 0ll, sol = 0ll;
        for (ll &i : order) {
            sol += cur*dmg[i];
            ll s = (h[i]+pr-1ll)/pr;
            ll cd = s*dmg[i];
            sol += cd;
            cur += s;
        }
        return sol;
    }
    
    long long minDamage1([[maybe_unused]] ll pr, vector<int>& damage, vector<int>& hh) {
        ll n = damage.size();
        vector<ll> dmg(n), h(n);
        for (ll i = 0; i < n; ++i) {
            dmg[i] = damage[i];
            h[i] = hh[i];
        }
        return 0ll;
    }
};

/*
62
[80,79]
[86,13]


*/
void solve() {
    Solution sol;
    int n, pr; cin >> n >> pr;
    vector<int> dmg(n), h(n);
    rep(i,n) cin >> dmg[i];
    rep(i,n) cin >> h[i];
    cout << sol.minDamage(pr,dmg,h) << endl;
}