/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sun Aug 11 22:24:00 IST 2024
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
    vector<pair<ll,ll>> stk;
    rep(i,n) {
        ll ct, col; cin >> ct >> col;
        debug(endl,endl,ct,col,stk);
        if (stk.empty()) {
            stk.emplace_back(ct,col);
            cout << ct << " \n"[i==n-1];
            continue;
        }
        ll last = 0ll;
        while(!stk.empty()) {
            auto [lct, lcol] = stk.back();
            if (lcol != col) {
                if (lct <= ct) {
                    last = lct;
                    stk.pop_back();
                    continue;
                }
                break;
            }
            stk.pop_back();
            ct = lct-last+ct;
        }
        stk.emplace_back(ct,col);
        cout << stk.front().first << " \n"[i==n-1];
    }
}