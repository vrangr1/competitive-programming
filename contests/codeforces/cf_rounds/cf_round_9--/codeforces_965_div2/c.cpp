/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Aug 10 20:17:42 IST 2024
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

void solve1() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> b(n);
    rep(i,n) cin >> b[i];
    vector<ll> order(n);
    iota(all(order),0ll);
    sort(all(order),[&](const ll &i, const ll &j) {
        return a[i] < a[j];
    });
    vector<ll> nxtz(n), prvo(n), prvz(n);
    ll nxt = n;
    debug(order);
    rep(i,n-1,0ll,-1) {
        nxtz[i] = nxt;
        if (!b[order[i]]) nxt = i;
    }
    ll prv = -1, pz = -1;
    rep(i,n) {
        if (b[order[i]]) prv = i;
        // else pz = i;
        prvo[i] = prv;
        prvz[i] = pz;
        if (!b[order[i]]) pz = i;
    }
    vector<ll> psum(n);
    rep(i,n) {
        psum[i] = a[order[i]];
        if (i) psum[i] += psum[i-1];
    }
    auto get = [&](ll l, ll r) -> ll {
        assert(l <= r);
        return psum[r] - (l?psum[l-1]:0ll);
    };
    auto cost = [&](ll med, ll i, ll t) -> ll {
        if (med == t) return 0ll;
        ll ct = (t-med), red = 0;
        if (i > med && i < t) {
            ct--;
            red = a[order[i]];
        }
        if (prvz[t] > med) {
            // ll sol = 0ll;

        }
        // if (ct == 0ll) {
        //     debug(med,i,t);
        //     exit(0);
        // }
        assert(ct > 0ll);
        return (ct*a[order[t]] - get(med,t-1) + red);
    };
    ll sol = 0ll;
    debug(nxtz,prvo,psum);
    rep(i,n) {
        ll med = (n-2ll)/2ll;
        if (i <= med) med++;
        ll am = prvo[med];
        debug(endl,i);
        if (am == -1) {
            sol = max(sol,a[order[i]] + a[order[med]]);
            continue;
        }
        ll req = a[order[med]] - a[order[am]];
        if (req > k) {
            sol = max(sol,a[order[i]] + a[order[med]]);
            continue;
        }
        debug(med,req);



        // ll mxind = nxtz[med];
        // if (mxind == i)
        //     mxind = nxtz[i];
        ll low = med, high = n-1ll;
        debug(low,high);
        while(low < high) {
            ll mid = (low+high+1ll)/2ll;
            if (cost(med,i,mid)+req <= k) low = mid;
            else high = mid-1;
        }
        req += cost(med,i,low);
        assert(req <= k);
        ll cur = a[order[low]];
        // if (low == mxind-1ll) {
        //     ll ct = (low-med+1ll);
        //     cur += (k-req)/ct;
        // }




        // if (mxind != n) cur = min(cur,a[order[mxind]]);
        debug(a[order[i]],cur);
        sol = max(sol,a[order[i]] + cur);
    }
    cout << sol << endl;
}

const ll inf = (ll)1e16;

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> b(n);
    rep(i,n) cin >> b[i];
    vector<ll> order(n);
    iota(all(order),0ll);
    sort(all(order),[&](const ll &i, const ll &j) {
        return a[i] < a[j];
    });
    vector<ll> zct(n), osum(n,0ll);
    rep(i,n) {
        if (i) osum[i] = osum[i-1ll];
        if (b[order[i]]) osum[i] += a[order[i]];
        zct[i] = (b[order[i]] == 0);
        if (i) zct[i] += zct[i-1];
    }
    auto get_zeros = [&](ll l, ll r) -> ll {
        assert(l <= r);
        return zct[r] - (l?zct[l-1ll]:0ll);
    };
    auto get_osum = [&](ll l, ll r) -> ll {
        assert(l <= r);
        return osum[r] - (l?osum[l-1ll]:0ll);
    };
    map<ll,vector<ll>> mp, mpind;
    {
        rep(med,(n-2ll)/2ll,(n-2ll)/2ll +1ll,1ll) {
            ll ct = 0ll, sum = 0ll;
            mp[med].resize(n);
            mpind[med].resize(n);
            auto &v = mp[med];
            auto &vind = mpind[med];
            rep(i,med-1,0ll,-1ll) {
                if (b[order[i]] == 0) continue;
                ct++;
                sum += a[order[i]];
                v[ct] = sum;
                vind[ct] = i;
            }
        }
    }

    auto cost = [&](ll med, ll i, ll t) -> ll {
        if (med == t) return 0ll;
        if (t == med+1ll) return a[order[t]] - a[order[med]];
        ll ctz = get_zeros(med+1ll,t-1ll);
        ll ct = (t-med);
        assert(i != t);
        assert(i != med);
        ll sum = get_osum(med+1ll,t-1ll) + a[order[med]];
        if (i > med && i < t) {
            ct--;
            if (b[order[i]]) sum -= a[order[i]];
        }
        assert(!mp[med].empty());
        auto &v = mp[med];
        auto &vind = mpind[med];
        assert(!vind.empty());
        if (b[order[med]]) {
            // sum += v[ctz];
            if (i < med && b[order[i]] && vind[ctz] <= i) {
                sum += v[ctz+1ll] - a[order[i]];
            }
            else sum += v[ctz];
        }
        else {
            if (i < med && b[order[i]] && vind[ctz+1ll] <= i) {
                sum += v[ctz+2ll]-a[order[i]] - v[1];
            }
            else sum += v[ctz+1ll] - v[1];
        }
        return ct*a[order[t]] - sum;
    };

    vector<ll> nxtz(n), prvo(n), prvz(n);
    ll nxt = n;
    rep(i,n-1,0ll,-1) {
        nxtz[i] = nxt;
        if (!b[order[i]]) nxt = i;
    }
    ll prv = -1, pz = -1;
    rep(i,n) {
        if (b[order[i]]) prv = i;
        prvo[i] = prv;
        prvz[i] = pz;
        if (!b[order[i]]) pz = i;
    }
    debug(order);
    ll sol = 0ll;
    rep(i,n) {
        ll med = (n-2ll)/2ll;
        if (i <= med) med++;
        if (b[order[i]])
        sol = max(a[order[i]]+k+a[order[med]],sol);
        ll am = prvo[med];
        debug(endl,i,med);
        if (am == -1) {
            sol = max(sol,a[order[i]] + a[order[med]]);
            continue;
        }
        ll req = a[order[med]] - a[order[am]];
        if (req > k) {
            sol = max(sol,a[order[i]] + a[order[med]]);
            continue;
        }
        assert(med != i);
        ll low = med, high = n-1ll;
        debug(req,low,high);
        while(low < high) {
            ll mid = (low+high+1ll)/2ll;
            if (mid == i) {
                if (mid == high) {
                    high--;
                    continue;
                }
                mid++;
            }
            if (cost(med,i,mid)+req <= k) low = mid;
            else high = mid-1ll;
        }
        req+=cost(med,i,low);
        assert(req <= k);
        debug(low,req);
        ll cur = a[order[low]];
        if (low == n-1ll || (i == n-1ll && low == n-2ll)) {
            ll ct = (low-med)+1ll;
            if (i > med && i < low) ct--;
            cur += (k-req)/ct;
            req += (k-req)/ct;
        }
        else {
            // cur += (a[order[low+1ll]]-a[order[low]])
        }
        debug(cur);
        assert(req <= k);
        sol = max(sol,cur+a[order[i]]+(b[order[i]]?k-req:0ll));
    }
    cout << sol << endl;
}