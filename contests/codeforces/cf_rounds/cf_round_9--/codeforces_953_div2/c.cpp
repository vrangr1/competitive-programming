/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sun Jun 16 14:55:58 IST 2024
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
    ll n, k; cin >> n >> k;
    if (k == 0) {
        cout << "Yes\n";
        rep(i,n) cout << i+1 << " \n"[i==n-1];
        return;
    }
    if (k%2) return void(cout << "No\n");
    ll mx = 0;
    rep(i,n) mx += llabs(n-i-(i+1ll));
    if (k > mx) return void(cout << "No\n");
    vector<int> p(n);
    iota(all(p),1);
    k/=2ll;
    ll limit = n;
    for(ll i = 1; i <= n && k > 0; i++) {
        assert(i < limit);
        if (limit-i <= k) {
            swap(p[i-1],p[limit-1]);
            k-=(limit-i);
            limit--;
            continue;
        }
        assert(i+k <= limit);
        swap(p[i-1],p[i+k-1]);
        k = 0;
        break;
    }
    assert(k == 0);
    cout << "Yes\n";
    print_vec(p);
}