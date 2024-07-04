/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed Jul  3 20:20:43 IST 2024
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
    vector<ll> p(n); rep(i,n) cin >> p[i];
    if (n == 1ll) return void(cout << "1\n");
    set<ll> st;
    st.insert(p[0]);
    vector<ll> op(n,-1ll);
    ll sol = 1ll;
    rep(i,1ll,n-1ll,1ll) {
        if (*st.rbegin() == i) {
            op[i-1ll] = 1;
            sol++;
            st.insert(p[i]);
            continue;
        }
        st.erase(p[i-1]);
        st.insert(p[i]);
        if (*st.rbegin() == i) {
            op[i-1] = 2;
        }
        st.insert(p[i-1]);
    }
    op.back() = 1;
    vector<ll> psum(n), mn(n), mnind(n),oct(n),mx(n);
    psum[0] = (op[0] == 1ll);
    psum[1] = (op[0] == 2ll) + (op[1] == 1ll);
    mn[0] = psum[0];
    // mn[1] = min(psum[1],0ll);
    mn[1] = psum[1];
    if (mn[1] == psum[1]) mnind[1] = 1ll;
    else mnind[1] = -1ll;
    if (mn[0] == psum[0]) mnind[0] = 0;
    else mnind[0] = -1ll;
    debug(sol);
    oct[0] = (op[0] == 1ll);
    rep(i,1,n-1ll,1)
        oct[i] = oct[i-1]+(ll)(op[i]==1ll);
    mx[0] = oct[0] - psum[0];
    mx[1] = oct[1] - psum[1];
    sol = max(sol,psum[1]+oct.back()-oct[1]);
    rep(i,2,n-1ll,1) {
        psum[i] = psum[i-2] + (ll)(op[i-1ll]==2ll) + (ll)(op[i] == 1ll);
        mn[i] = mn[i-2];
        mnind[i] = mnind[i-2ll];
        mx[i] = mx[i-2];
        // ll v = 0ll;
        // if (mnind[i] >= 0ll) v = oct[mnind[i]];
        sol = max(sol,psum[i]+oct.back()-oct[i]+mx[i]);
        sol = max(sol,psum[i]+oct.back()-oct[i]);
        // if (sol == 3) debug(i);
        // if (mn[i] >= psum[i]) {
        //     mn[i] = psum[i];
        //     mnind[i] = i;
        // }
        mx[i] = max(mx[i],oct[i]-psum[i]);
    }
    debug(op,psum,mx,oct);
    cout << sol << endl;
}