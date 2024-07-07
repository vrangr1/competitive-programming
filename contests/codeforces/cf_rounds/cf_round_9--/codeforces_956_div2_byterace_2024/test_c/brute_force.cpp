/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sun Jul  7 20:52:06 IST 2024
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
    vector<ll> a(n), b(n), c(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    rep(i,n) cin >> c[i];
    vector<ll> pa(n), pb(n),pc(n);
    partial_sum(all(a),pa.begin());
    partial_sum(all(b),pb.begin());
    partial_sum(all(c),pc.begin());
    ll tot = pa.back();
    assert(tot == pb.back());
    assert(tot == pc.back());
    tot = (tot+2ll)/3ll;
    auto inrange = [&](ll v) -> bool {
        return v >= 0ll && v < n;
    };
    auto notints = [](ll la, ll ra, ll lb, ll rb) -> bool {
        assert(la <= ra);
        assert(lb <= rb);
        bool ints = (la <= lb && lb <= ra) || (lb <= la && la <= rb);
        return !ints;
    };
    auto check = [&](ll la, ll ra, ll lb, ll rb, ll lc, ll rc) -> bool {
        assert(notints(la,ra,lb,rb));
        assert(notints(la,ra,lc,rc));
        assert(notints(lc,rc,lb,rb));
        assert(inrange(la));
        assert(inrange(ra));
        assert(inrange(lb));
        assert(inrange(rb));
        assert(inrange(lc));
        assert(inrange(rc));
        ll s = ra-la+1ll + rb-lb+1ll + rc-lc+1ll;
        assert(s == n);
        ll sa = pa[ra], sb = pb[rb], sc = pc[rc];
        if (la) sa -= pa[la-1ll];
        if (lb) sb -= pb[lb-1ll];
        if (lc) sc -= pc[lc-1ll];
        return sa >= tot && sb >= tot && sc >= tot;
    };
    auto ans = [&](ll la, ll ra, ll lb, ll rb, ll lc, ll rc) {
        la++;
        ra++;
        lb++;
        rb++;
        lc++;
        rc++;
        cout << la << " " << ra << " " << lb << " " << rb << " " << lc << " " << rc << endl;
        return;
    };
    rep(la,n) {
        if (la) {
            rep(ra, la, n-1ll, 1ll) {
                if (ra == n-1ll) {
                    if (la == 1ll) continue;
                    rep(rb,la-1ll) {
                        ll lb = 0ll;
                        ll lc = rb+1ll, rc = la-1ll;
                        if (check(la,ra,lb,rb,lc,rc)) {
                            ans(la,ra,lb,rb,lc,rc);
                            return;
                        }
                    }
                    rep(rc,la-1ll) {
                        ll lc = 0ll, lb = rc+1ll, rb = la-1ll;
                        if (check(la,ra,lb,rb,lc,rc)) {
                            ans(la,ra,lb,rb,lc,rc);
                            return;
                        }
                    }
                }
                else {
                    ll lb = 0ll, rb = la-1ll, lc = ra+1ll, rc = n-1ll;
                    if (check(la,ra,lb,rb,lc,rc)) {
                        ans(la,ra,lb,rb,lc,rc);
                        return;
                    }
                    lb = ra+1ll;
                    rb = n-1ll;
                    lc = 0ll;
                    rc = la-1ll;
                    if (check(la,ra,lb,rb,lc,rc)) {
                        ans(la,ra,lb,rb,lc,rc);
                        return;
                    }
                }
            }
        }
        else {
            rep(ra, la, n-3ll, 1ll) {
                ll lb = ra+1ll;
                rep(rb, lb, n-2ll, 1ll) {
                    ll lc = rb+1ll, rc = n-1ll;
                    if (check(la,ra,lb,rb,lc,rc)) {
                        ans(la,ra,lb,rb,lc,rc);
                        return;
                    }
                }
                ll lc = ra+1ll;
                rep(rc, lc, n-2ll, 1ll) {
                    lb = rc+1ll;
                    ll rb = n-1ll;
                    if (check(la,ra,lb,rb,lc,rc)) {
                        ans(la,ra,lb,rb,lc,rc);
                        return;
                    }
                }
            }
        }
    }
    cout << "-1\n";
}