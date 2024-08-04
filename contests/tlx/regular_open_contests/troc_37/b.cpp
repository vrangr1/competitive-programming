/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Aug  3 19:52:39 IST 2024
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
	TEST1;
#ifdef LOCAL
    cout << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

void solve() {
    ll n, k; cin >> n >> k;
    vector<pair<ll,ll>> vals(n);
    ll sum = 0ll;
    rep(i,n) {
        cin >> vals[i].first;
        sum += vals[i].first;
    }
    rep(i,n) cin >> vals[i].second;
    if (sum <= k) return void(cout << "1\n");
    auto sat = [&](ll p) -> bool {
        ll a = 0, b = 0, rem = 0;
        rep(i,n) {
            auto [w,s] = vals[i];
            if (rem >= s) {
                rem -=s;
                continue;
            }
            s-=rem;
            rem = 0ll;
            if ((s%p) == 0) {
                if (w <= s/p) a+=w;
                else b += s;
                continue;
            }
            if (w < (s+p-1)/p) a += w;
            else {
                ll cur = ((s+p-1)/p)*p;
                rem = cur-s;
                b += cur;
            }
        }
        assert((b%p)==0);
        ll req = (b+p-1)/p;
        return (a+req) <= k;
    };
    auto bsch = [&](auto &&self, ll low, ll high) -> ll {
        if (low == high) {
            assert(sat(high));
            return high;
        }
        ll mid = (low+high)/2ll;
        if (sat(mid)) return self(self,low,mid);
        else return self(self,mid+1ll,high);
    };
    cout << bsch(bsch,2,ll(1e6)+3ll) << endl;
}