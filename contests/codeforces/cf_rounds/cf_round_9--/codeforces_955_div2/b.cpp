/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Tue Jun 25 20:15:17 IST 2024
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
    ll x, y, k; cin >> x >> y >> k;
    if ((x%y) == 0ll) {
        x++;
        assert(x%y);
        --k;
    }
    vector<ll> ord, lens;
    set<ll> st;
    ll cur = 0ll;
    bool done = false;
    while(k) {
        assert(x%y);
        debug(endl,x);
        if (!done && !ord.empty() && st.find(x) != st.end()) {
            done = true;
            ll ind = (ll)(find(all(ord),x) - ord.begin());
            assert(ind != sz(ord));
            assert(sz(lens) == sz(ord));
            ll len = cur - lens[ind];
            debug(ord,lens,x,ind,len);
            assert(len > 0ll);
            // if (len == 0ll) break;
            k%=len;
        }
        ord.push_back(x);
        st.insert(x);
        lens.push_back(cur);
        ll rem = y-(x%y);
        if (rem > k) {
            x+=k;
            assert(x%y);
            k = 0;
            break;
        }
        x+=rem;
        k-=rem;
        while((x%y) == 0ll)
            x/=y;
        cur += rem;
    }
    cout << x << endl;
}