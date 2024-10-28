/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Mon Oct 28 20:18:13 IST 2024
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
    // if (n == 1ll) return void(cout << "1\n");
    ll sol = 1ll;
    if (n%2 == 0ll) {
        rep(i,0,n-1ll,2) {
            sol = max(sol,a[i+1]-a[i]);
        }
    } else {
        vector<ll> lt(n), rt(n);
        lt[0] = rt[n-1] = 0;
        sol = LLONG_MAX;
        rep(i,2,n-1ll,2ll)
            lt[i] = max(lt[i-2],a[i-1]-a[i-2]);
        rep(i,n-3,0ll,-2)
            rt[i] = max(rt[i+2],a[i+2]-a[i+1]);
        rep(i,0,n-1ll,2ll) {
            ll cur = max(lt[i],rt[i]);
            ll mn = a[i];
            rep(j,i-1ll,0ll,-1ll) {
                if (a[i]-a[j] > i-j) {
                    mn = a[i] - (a[j+1]-1);
                    break;
                }
            }
            rep(j,i+1,n-1ll,1ll) {
                if (a[j]-a[i] > j-i) {
                    mn = min(mn,a[j-1]+1-a[i]);
                    break;
                }
            }
            if (i == 0 || i == n-1ll) mn = 1;
            cur = max(cur,mn);
            sol = min(sol,cur);
        }
    }
    cout << sol << endl;
}