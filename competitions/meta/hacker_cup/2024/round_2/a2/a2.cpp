/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sat Oct 19 22:45:55 IST 2024
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
void solve(int test_case);

int main() {
	fastIO;
	int T;cin>>T;rep(t,T)solve(t+1);
#ifdef LOCAL
    cout << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

void solve1(int test_case) {
    cout << "Case #" << test_case << ": ";
    //testing
    vector<vector<ll>> dp(9,vector<ll>(9));
    rep(v,1,8,1)
        dp[8][v] = 8-v+1;
    ll sum = 36;
    rep(p,7,1,-1) {
        ll cur = 0ll;
        dp[p][1] = sum;
        cur = sum;
        rep(v,2,8,1) {
            dp[p][v] = dp[p][v-1]-dp[p+1][v-1];
            cur += dp[p][v];
        }
        swap(cur,sum);
    }
    debug(dp);
}

void solve(int test_case) {
    cout << "Case #" << test_case << ": ";
    ll a, b, m; cin >> a >> b >> m;
    ll sol = 0ll;
    auto rec = [&](auto &&self, ll lval, ll rval, ll lastl, ll lastr, ll pwr, ll mid) -> void {
        ll curval = lval*pwr*10ll + mid*pwr + rval;
        if (curval > b) return;
        if (curval >= a && curval%m == 0ll) {
            sol++;
        }
        rep(vl,lastl,mid-1ll,1) {
            rep(vr,lastr,mid-1ll,1) {
                self(self,lval*10ll + vl, vr*pwr+rval, vl, vr, pwr*10ll, mid);
            }
        }
    };
    rep(mid,1,9,1)
        rec(rec,0ll,0ll,1,1,1,mid);
    cout << sol << endl;
}