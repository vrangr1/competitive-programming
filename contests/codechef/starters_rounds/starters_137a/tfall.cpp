/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed Jun  5 20:30:11 IST 2024
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
    vector<ll> x(n), p(n);
    rep(i,n) cin >> x[i];
    rep(i,n) cin >> p[i];
    auto get_ind = [&](ll ind, ll dir) -> int {
        ll sol = ind;
        if (dir) {
            while(sol < n) {
                if (sol == n-1) return n-1;
                if (x[sol] + p[sol] < x[sol+1]) return sol;
                sol++;
            }
            return sol;
        }
        while(sol < n) {
            if (sol == n-1) return sol;
            if (x[sol+1]-p[sol+1] > x[sol]) return sol;
            sol++;
        }
        return sol;
    };
    ll ind1 = get_ind(0,1);
    if (ind1 == n-1) return void(cout << yes);
    ll ind2 = get_ind(ind1+1,1);
    if (ind2 == n-1) return void(cout << yes);
    ind2 = get_ind(ind1+1,0);
    if (ind2 == n-1) return void(cout << yes);
    ind1 = get_ind(0,0);
    if (ind1 == n-1) return void(cout << yes);
    ind2 = get_ind(ind1+1,1);
    if (ind2 == n-1) return void(cout << yes);
    ind2 = get_ind(ind1+1,0);
    if (ind2 == n-1) return void(cout << yes);
    cout << no;
}