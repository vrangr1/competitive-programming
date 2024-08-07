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

void solve() {
    ll n, m; cin >> n >> m;
    vector<vector<ll>> chains(n,vector<ll>(m));
    rep(i,n) {
        rep(j,m) cin >> chains[i][j];
    }
    vector<array<ll,2>> vals;
    ll sol = 0ll, nsum = 0ll;
    rep(i,n) {
        ll sum = 0ll, total = accumulate(all(chains[i]),0ll);
        sol = max(sol,total);
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
        nsum += node;
    }
    sol = max(sol,nsum);
    sort(all(vals),[](const array<ll,2> &a, const array<ll,2> &b) {
        auto [an,am] = a;
        auto [bn,bm] = b;
        return am < bm;
    });
    ll lt = 0, rt = 0, ch = 0;
    while(!vals.empty()) {
        if (sz(vals) == 1) {
            auto [cn,cm] = vals.back();
            vals.pop_back();
            sol = max(sol,min(lt,rt)+cn+cm);
            break;
        }
        auto [bn,bm] = vals.back();
        vals.pop_back();
        auto [sn,sm] = vals.back();
        vals.pop_back();
        sol = max(sol,bn+bm+sn+sm+ch);
        ch+=sn+bn;
        if (max(bn+bm+rt,sn+sm+lt) <= max(bn+bm+lt,sn+sm+rt)) {
            sol = max(sol,max(bn+bm+rt,sn+sm+lt));
            rt+=bn;
            lt+=sn;
        }
        else {
            sol = max(sol,max(bn+bm+lt,sn+sm+rt));
            rt+=sn;
            lt+=bn;
        }
    }
    cout << sol << endl;
}