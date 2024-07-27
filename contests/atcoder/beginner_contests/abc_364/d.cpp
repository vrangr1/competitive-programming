/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Jul 27 17:45:37 IST 2024
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
    ll n, q; cin >> n >> q;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(all(a));
    auto comp = [&](const ll ind, const ll b, const ll k, const ll left, const ll right) -> ll {
        assert(left + right == k);
        if (n-ind < right || ind < left) return LLONG_MAX;
        return max(a[ind+right-1ll]-b, b-a[ind-left]);
    };
    auto bsch = [&](auto &&self, ll low, ll high, const ll k, const ll b, const ll ind) -> ll {
        if (b == 2) {
            debug(low,high);
        }
        if (low == high)
            return comp(ind,b,k,k-low,low);
        if (low+1ll == high)
            return min(comp(ind,b,k,k-low,low), comp(ind,b,k,k-high,high));
        ll mid = (low+high)/2ll;
        if (n-ind < mid) return self(self,low,mid-1ll,k,b,ind);
        if ((k-mid) > ind) return self(self,mid+1ll,high,k,b,ind);
        ll lv = comp(ind,b,k,k-low,low), mv = comp(ind,b,k,k-mid,mid), hv = comp(ind,b,k,k-high,high);
        if (mid == low+1ll && mid == high-1ll) return min({mv,lv,hv});
        if (mid == low+1ll) return min({lv,hv,mv,self(self,mid+1ll,high-1ll,k,b,ind)});
        if (mid == high-1ll) return min({lv,hv,mv,self(self,low+1ll,mid-1ll,k,b,ind)});
        ll rd = a[ind+mid-1ll]-b, ldist = b-a[ind-(k-mid)];
        if (rd >= ldist) return min(max(ldist,rd), self(self,low,mid-1ll,k,b,ind));
        return min(max(ldist,rd),self(self,mid+1ll,high,k,b,ind));
    };
    debug(a);
    while(q--) {
        ll b, k; cin >> b >> k;
        auto it = lower_bound(all(a),b);
        ll ind = ll(it-a.begin());
        debug(endl,b,k,ind);
        if (ind == n) {
            cout << b-a[n-k] << endl;
            continue;
        }
        if (ind == 0) {
            cout << a[k-1ll] - b << endl;
            continue;
        }
        cout << bsch(bsch,0,k,k,b,ind) << endl;
    }
}