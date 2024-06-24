/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sun Jun 23 21:23:47 IST 2024
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
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    map<ll,ll> mp;
    map<ll,vector<ll>> vals;
    for (ll v : a) {
        mp[v%k]++;
        vals[v%k].push_back(v);
    }
    ll oct = 0;
    for (auto [f, ct] : mp) {
        oct += (ct%2ll);
    }
    if (oct > 1) return void(cout << "-1\n");
    if (oct == 1 && (n%2ll == 0)) return void(cout << "0\n");
    if (n%2ll == 0) {
        ll sol = 0;
        for (auto [f, vec] : vals) {
            sort(all(vec));
            assert(sz(vec)%2 == 0);
            rep(i,0,sz(vec)-1,2) {
                sol += (vec[i+1]-vec[i])/k;
            }
        }
        cout << sol << endl;
        return;
    }
    ll sol = 0;
    for (auto [f,vec] : vals) {
        sort(all(vec));
        debug(f,vec);
        if (sz(vec)%2) {
            ll cur = LLONG_MAX;
            rep(i,sz(vec)) {
                ll sum = 0ll;
                rep(j,1ll,i-1ll,2ll) {
                    sum += (vec[j]-vec[j-1ll])/k;
                }
                ll st = i+1ll;
                if (i%2ll) {
                    if (i == sz(vec)-1ll) {
                        st = sz(vec);
                    }
                    else {
                        sum += (vec[i+1ll]-vec[i-1ll])/k;
                        st = i+2ll;
                    }
                }
                rep(j,(int)st,sz(vec)-1,2ll)
                    sum += (vec[j+1]-vec[j])/k;
                cur = min(cur,sum);
            }
            assert(cur != LLONG_MAX);
            sol += cur;
            continue;
        }
        rep(i,0,sz(vec)-1,2) {
            sol += (vec[i+1]-vec[i])/k;
        }
    }
    cout << sol << endl;
}