/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Tue Aug  6 20:21:16 IST 2024
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

const int mxp = 14;
vector<int> tpr = {1};
void init() {
    static bool init = false;
    if (init) return;
    init = true;
    while (sz(tpr) < mxp+1)
        tpr.push_back(tpr.back()*3);
}

const ld tr = logl(3);

void solve() {
    init();
    auto get = [](ld val) -> int {
        int low = 0, high = mxp;
        while(low < high) {
            int mid = (low+high+1)/2;
            if (tpr[mid] <= val) low = mid;
            else high = mid-1;
        }
        return low+1;
        // return 1+(int)floorl(logl(val)/tr);
    };
    auto mx = [&](int len) -> int {
        return tpr[len]-1;
    };
    auto mn = [&](int len) -> int {
        return tpr[len-1];
    };
    int l, r; cin >> l >> r;
    int bl = get(l), br = get(r);
    int sol = bl;
    debug(l,r,bl,br);
    if (bl == br) sol += (r-l+1)*bl;
    else {
        assert(bl < br);
        debug(mx(bl),mn(br));
        sol += (mx(bl)-l+1)*bl + (r-mn(br)+1)*br;
        rep(i,bl+1,br-1,1)
            sol += (mx(i)-mn(i)+1)*i;
    }
    cout << sol << endl;
}