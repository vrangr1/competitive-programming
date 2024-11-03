/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sat Nov  2 21:00:32 IST 2024
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
	TEST;
#ifdef LOCAL
    cout << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

void solve() {
    auto fxor = [](ll n) -> ll {
        switch(n%4ll) {
            case 0ll: return n;
            case 1ll: return 1;
            case 2ll: return n+1ll;
            default: return 0ll;
        }
        assert(false);
        return 0;
    };
    auto rxor = [&](ll l, ll r) -> ll {
        assert(l <= r);
        return fxor(r)^fxor(l-1ll);
    };
    ll l, r, i, k; cin >> l >> r >> i >> k;
    ll sol = rxor(l,r), mask = (1ll<<i)-1ll;
    ll low;
    if ((l&mask) > k) {
        low = ((((l>>i)+1ll)<<i)|k);
    } else {
        low = (((l>>i)<<i)|k);
    }
    if (r < k || low > r) {
        cout << sol << endl;
        return;
    }
    assert(low >= l && low <= r);
    ll high;
    if ((r&mask) >= k) {
        high = (((r>>i)<<i)|k);
    } else {
        high = ((((r>>i)-1ll)<<i)|k);
    }
    assert(low <= high && high <= r);
    ll hl = (low>>i), hr = (high>>i);
    ll t = (rxor(hl,hr))<<i;
    if ((hr-hl+1ll)%2ll) t|=k;
    sol^=t;
    cout << sol << endl;
}