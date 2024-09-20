/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Fri Sep 20 21:53:26 IST 2024
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
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    if (n == 1ll) return void(cout << a[0] << endl);
    vector<ll> lt(n,0ll), rt(n,0ll);
    rep(i,n) {
        if (i == 0) continue;
        lt[i] = gcd(lt[i-1ll],a[i-1ll]);
    }
    rep(i,n-2ll,0ll,-1ll)
        rt[i] = gcd(rt[i+1ll],a[i+1ll]);
    vector<ll> v(n);
    ll ov = gcd(lt.back(),a.back());
    rep(i,n) {
        ll g;
        if (!i) g = rt[i];
        else if (i == n-1ll) g = lt[i];
        else g = gcd(lt[i],rt[i]);
        if (g < ov) {
            debug(ov,g,a,lt,rt,i);
            exit(0);
        }
        assert(g >= ov);
        assert(g%ov == 0ll);
        v[i] = g/ov;
    }
    vector<ll> order(n);
    iota(all(order),0ll);
    sort(all(order),[&](const ll &i, const ll &j) {
        return v[i] > v[j];
    });
    ll sum = 0ll, cur = 0ll;
    rep(i,n) {
        ll ind = order[i];
        cur = gcd(cur,a[ind]);
        sum += cur;
    }
    cout << sum << endl;
}