/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sat Oct  5 17:37:33 IST 2024
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
void solve();

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
    ld s, t; cin >> s >> t;
    vector<array<ll,4>> lines(n);
    for (auto &[x1,y1,x2,y2] : lines)
        cin >> x1 >> y1 >> x2 >> y2;
    const ll mx = (1<<n);
    ld sol = (ld)LLONG_MAX;
    auto get = [&](ld x1, ld y1, ld x2, ld y2, ld sp) -> ld {
        return sqrtl((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2))/sp;
    };
    rep(stat,(ll)mx) {
        vector<ll> order(n);
        iota(all(order),0);
        do {
            pair<ll,ll> cur = {0ll,0ll};
            ld time = 0;
            for (ll i : order) {
                ll v = (1ll<<i);
                if (stat == 0b100 && order == vector<ll>{1ll,0ll,2ll}) {
                    debug(endl,i,v,((stat&v) > 0),lines[i], cur);
                }
                if (stat&v) {
                    if (stat == 0b100 && order == vector<ll>{1ll,0ll,2ll}) {
                        debug(get((ld)cur.first,(ld)cur.second,(ld)lines[i][0],(ld)lines[i][1],s),get((ld)lines[i][0],(ld)lines[i][1],(ld)lines[i][2],(ld)lines[i][3],t));
                    }
                    time += get((ld)cur.first,(ld)cur.second,(ld)lines[i][0],(ld)lines[i][1],s);
                    time += get((ld)lines[i][0],(ld)lines[i][1],(ld)lines[i][2],(ld)lines[i][3],t);
                    cur = {lines[i][2],lines[i][3]};
                }
                else {
                    if (stat == 0b100 && order == vector<ll>{1ll,0ll,2ll}) {
                        debug(get((ld)cur.first,(ld)cur.second,(ld)lines[i][2],(ld)lines[i][3],s),get((ld)lines[i][0],(ld)lines[i][1],(ld)lines[i][2],(ld)lines[i][3],t));
                    }
                    time += get((ld)cur.first,(ld)cur.second,(ld)lines[i][2],(ld)lines[i][3],s);
                    time += get((ld)lines[i][0],(ld)lines[i][1],(ld)lines[i][2],(ld)lines[i][3],t);
                    cur = {lines[i][0],lines[i][1]};
                }
            }
            sol = min(sol,time);
            if (DEBUG) {
                if (stat == 0b100 && order == vector<ll>{1ll,0ll,2ll}) {
                    debug(endl,time);
                }
            }
        } while(next_permutation(all(order)));
    }
    cout << setprecision(20) << sol << endl;
}