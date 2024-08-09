/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Fri Aug  9 05:23:35 IST 2024
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
    ll n; cin >> n;
    if (((n*(n+1ll))/2ll)%2ll) return void(cout << "NO\n");
    ll t = ((n*(n+1ll))/4ll);
    vector<bool> sel(n+1ll,false);
    ll ct = 0ll, cur = n;
    while(t) {
        if (t > cur) {
            t-=cur;
            sel[cur] = true;
            ct++;
            cur--;
            continue;
        }
        sel[t] = true;
        ct++;
        t = 0ll;
        break;
    }
    cout << "YES\n";
    cout << ct << endl;
    vector<ll> vals;
    rep(i,1,n,1) {
        if (sel[i]) {
            cout << i << " \n"[ct==1];
            ct--;
        }
        else vals.push_back(i);
    }
    cout << sz(vals) << endl;
    print_vec(vals);
}