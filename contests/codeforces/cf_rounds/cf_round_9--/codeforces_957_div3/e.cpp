/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Thu Jul 11 20:57:44 IST 2024
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
    auto pwr = [](auto &&self, ll a, ll n) -> ll {
        assert(n>=0ll);
        if (n == 0ll) return 1ll;
        if (n%2ll) return a*self(self,a*a,n/2ll);
        return self(self,a*a,n/2ll);
    };
    ll n; cin >> n;
    ll sol = 0ll;
    vector<tuple<ll,ll>> sols;
    string s = to_string(n);
    rep(a,1,(int)1e4,1) {
        ll len = a*sz(s);
        ll na = n*a;
        ll t = sz(to_string(na));
        rep(b,len-t,len,1) {
            if (b > na) break;
            if (b == 0) continue;
            ll p = na-b, q;
            if (len - b == 0ll) {
                q = 0ll;
                break;
            }
            else if (len - b <= sz(s)) {
                q = n;
                while(sz(to_string(q)) != len-b)
                    q/=10ll;
            }
            else {
                if (len-b > 12ll) continue;
                q = n;
                while(len - b - sz(to_string(q)) > sz(s)) {
                    q*=pwr(pwr,10ll,sz(s));
                    q+=n;
                }
                ll v = len-b-sz(to_string(q));
                q*=pwr(pwr,10ll,v);
                q+=(n/pwr(pwr,10ll,sz(s)-v));
            }
            if (p!=q) continue;
            sol++;
            sols.emplace_back(a,b);
        }
    }
    cout << sol << endl;
    for (auto [a,b] : sols)
        cout << a << " " << b << endl;
}