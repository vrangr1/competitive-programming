/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed Aug  7 21:21:33 IST 2024
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

// Incorrect Solution. Forgot to account for the fact that the center for the 'star' patterned
// graph can be **any** node.
void solve1() {
    ll n, m; cin >> n >> m;
    vector<vector<ll>> chains(n,vector<ll>(m));
    rep(i,n) {
        rep(j,m) cin >> chains[i][j];
    }
    vector<array<ll,2>> vals;
    ll chdia = 0;
    rep(i,n) {
        ll sum = 0ll, total = accumulate(all(chains[i]),0ll);
        chdia = max(chdia,total);
        array<ll,3> ar = {0ll,chains[i][0],total};
        rep(j,m) {
            sum += chains[i][j];
            ll other = total-sum+chains[i][j];
            auto [_,pl,pr] = ar;
            if (max(pl,pr) > max(other,sum)) 
                ar = {j,sum,other};
        }
        auto [node,lt,rt] = ar;
        node = chains[i][node];
        vals.push_back({node,(ll)max(lt-node,rt-node)});
    }
    sort(all(vals),[](const array<ll,2> &a, const array<ll,2> &b) {
        auto [an,am] = a;
        auto [bn,bm] = b;
        return an+am < bn+bm;
    });
    if (n == 2)
        return void(cout << max(chdia,vals[0][0]+vals[0][1]+vals[1][0]+vals[1][1]) << endl);
    ll sol = LLONG_MAX;
    debug(vals);
    rep(i,n) {
        ll cur = 0;
        if (i == n-1) cur = vals[i][0]+vals[i][1]+vals[i-1][0]+vals[i-1][1];
        else cur = vals[i][0]+vals[i][1]+vals[n-1][0]+vals[n-1][1];
        ll i1 = n-2, i2 = n-1;
        if (i == n-1) i2 = n-3;
        else if (i == n-2) i1 = n-3;
        cur = max(cur,vals[i][0]+vals[i1][0]+vals[i1][1]+vals[i2][0]+vals[i2][1]);
        debug(endl,vals[i],cur);
        sol = min(sol,cur);
    }
    cout << max(chdia,sol) << endl;
}

// Correct solution based on editorial.
void solve() {
    ll n, m; cin >> n >> m;
    vector<vector<ll>> a(n,vector<ll>(m));
    rep(i,n) rep(j,m) cin >> a[i][j];
    vector<vector<ll>> mx(n,vector<ll>(m));
    vector<ll> mn(n, LLONG_MAX);
    ll mxdia = 0ll, sol = LLONG_MAX;
    rep(i,n) {
        ll sum = accumulate(all(a[i]),0ll), cur = 0ll;
        mxdia = max(mxdia,sum);
        rep(j,m) {
            cur += a[i][j];
            mx[i][j] = max(cur,sum);
            sum-=a[i][j];
            mn[i] = min(mn[i],mx[i][j]);
        }
    }
    multiset<ll> mst(all(mn));
    rep(i,n) {
        mst.erase(mst.find(mn[i]));
        rep(j,m) {
            ll m1 = 0, m2 = 0;
            m1 = *mst.rbegin();
            if (sz(mst) > 1) m2 = *next(mst.rbegin());
            ll cur = max(mx[i][j]+m1,m1+m2+a[i][j]);
            sol = min(sol,cur);
        }
        mst.insert(mn[i]);
    }
    cout << max(sol,mxdia) << endl;
}