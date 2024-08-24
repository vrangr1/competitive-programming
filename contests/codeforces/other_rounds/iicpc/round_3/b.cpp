/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sat Aug 24 20:06:45 IST 2024
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
#define yes "YES\n"
#define no "NO\n"
template<typename type>inline void print_vec(const vector<type> &v){rep(i,sz(v))cout<<v[i]<<" \n"[i==sz(v)-1];}
void solve();

// IMPORT SNIPPETS HERE

// END OF SNIPPETS

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
    ll m = (1ll<<n);
    vector<ll> a(m);
    rep(i,m) {
        cin >> a[i];
    }
    if (a[0] != 0) return void(cout << "NO\n");
    rep(b,n) {
        ll val = (1ll<<b);
        set<ll> zeros, ones;
        rep(i,m) {
            if (i&val) {
                // for (ll v : ones) {
                //     ll cur = v^a[i];
                //     if (v == a[i] || cur == a[i]) continue;
                //     if (ones.find(cur) != ones.end()) {
                //         debug(val,b,a[i],ones,zeros);
                //         return void(cout << "NO\n");
                //     }
                // }
                ones.insert(a[i]);
            }
            else {
                zeros.insert(a[i]);
            }
        }
        for (ll o : ones) {
            // if (zeros.find(o) != zeros.end()) return void(cout << "NO\n");
            for (ll z : zeros) {
                // if (ones.find(z) != ones.end()) return void(cout << "NO\n");
                if (ones.find(o^z) == ones.end()) {
                    // debug(ones,zeros);
                    return void(cout << "NO\n");
                }
                // if (zeros.find(o^z) != zeros.end()) return void(cout << "NO\n");
            }
        }
        for (ll z1 : zeros) {
            for (ll z2 : zeros) {
                if (zeros.find(z1^z2) == zeros.end()) return void(cout << "NO\n");
            }
        }
        for (ll o1 : ones) {
            for (ll o2 : ones) {
                if (zeros.find(o1^o2) == zeros.end()) return void(cout << "NO\n");
            }
        }
    }
    cout << "YES\n";
}