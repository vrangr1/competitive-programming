/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Tue Aug 20 21:10:25 IST 2024
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
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> sol;
    auto save = [&](vector<ll> &b) {
        if (sz(sol) < sz(b)) {
            sol = b;
            return;
        }
        if (sz(sol) > sz(b)) return;
        ll m = sz(sol);
        rep(i,m) {
            if (b[i] == sol[i]) continue;
            if (i%2) {
                if (b[i] < sol[i]) {
                    sol = b;
                    return;
                }
                return;
            }
            if (b[i] > sol[i]) {
                sol = b;
            }
            return;
        }
    };
    auto rec = [&](auto &&self, ll i, vector<ll> &b, set<ll> &seen) -> void {
        if (i == n) {
            save(b);
            return;
        }
        self(self,i+1,b,seen);
        if (seen.find(a[i]) != seen.end()) {
            return;
        }
        b.push_back(a[i]);
        seen.insert(a[i]);
        self(self,i+1,b,seen);
        b.pop_back();
        seen.erase(a[i]);
    };
    vector<ll> b;
    set<ll> seen;
    rec(rec,0,b,seen);
    cout << sz(sol) << endl;
    print_vec(sol);
}