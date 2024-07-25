/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed Jul 24 21:09:29 IST 2024
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
    ll n, l, r; cin >> n >> l >> r;
    vector<ll> p(n);
    iota(all(p),1ll);
    vector<vector<ll>> t = {p};
    auto comp = [&]() -> ll {
        ll sol = 0ll, sum = 0ll;
        rep(i,n) {
            sum += p[i];
            sol += (sum <= r && sum >= l);
        }
        return sol;
    };
    ll sol = comp();
    do {
        ll cur = comp();
        if (cur < sol) {
            sol = cur;
            t = {p};
        }
        else if (cur == sol) {
            t.push_back(p);
        }
    } while(next_permutation(all(p)));
    debug(sol);
    if (DEBUG) {
        for (auto &q : t)
            print_vec(q);
    }
    print_vec(t[0]);
}