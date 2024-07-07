/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sun Jul  7 20:25:43 IST 2024
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
    debug(tot);
    auto bsch = [n,tot](auto &&self, ll low, ll high, const ll prev, const vector<ll> &psum) -> ll {
        assert(low <= high);
        if (low == high) {
            assert(psum[high]-prev >= tot);
            return high;
        }
        ll mid = (low+high)/2ll, sum = psum[mid] - prev;
        if (sum >= tot) return self(self, low, mid, prev, psum);
        return self(self, mid+1ll, high, prev, psum);
    };
    auto get = [n,tot,&bsch](const vector<ll> &psum, const vector<ll> &vals, ll st, bool dbg = false) -> ll {
        assert(st < n);
        assert(st >= 0ll);
        ll prev = psum[st]-vals[st];
        if (psum.back()-prev < tot) return -1;
        if (dbg) {
            debug(prev);
        }
        return bsch(bsch, st, n-1, prev, psum);
    };
    ll la = -1, ra = -1, lb = -1, rb = -1, lc = -1, rc = -1;
    auto proc = [&](bool dbg = false) {
        ra = get(pa, a, 0);
        if (dbg) {
            debug(ra);
        }
        if (ra == -1 || ra == n-1) {
            la = ra = lb = rb = lc = rc = -1;
            return;
        }
        la = 0;
        lb = ra+1ll;
        rb = get(pb, b, lb);
        if (dbg) {
            debug(rb);
        }
        if (rb == -1 || rb == n-1) {
            la = ra = lb = rb = lc = rc = -1;
            return;
        }
        lc = rb+1ll;
        rc = get(pc, c, lc);
        if (dbg) {
            debug(rc);
        }
        if (rc == -1) {
            la = ra = lb = rb = lc = rc = -1;
            return;
        }
        rc = n-1;
    };
    auto ans = [&]() {
        la++;
        ra++;
        lb++;
        rb++;
        lc++;
        rc++;
        cout << la << " " << ra << " " << lb << " " << rb << " " << lc << " " << rc << endl;
        return;
    };

    //abc
    proc();
    if (la != -1) {
        ans();
        return;
    }
    
    //acb
    swap(b,c);
    swap(pb,pc);
    proc();
    if (la != -1) {
        swap(lb,lc);
        swap(rb,rc);
        ans();
        return;
    }
    swap(b,c);
    swap(pb,pc);

    //bac
    swap(a,b);
    swap(pa,pb);
    // debug(a,b,c);
    proc();
    // debug(la,ra,lb,rb,lc,rc);
    if (la != -1) {
        swap(la,lb);
        swap(ra,rb);
        ans();
        return;
    }
    
    //bca
    swap(b,c);
    swap(pb,pc);
    proc();
    if (la != -1) {
        swap(lb,lc);
        swap(rb,rc);
        swap(la,lb);
        swap(ra,rb);
        ans();
        return;
    }
    swap(b,c);
    swap(pb,pc);
    swap(a,b);
    swap(pa,pb);

    // cab
    swap(a,b);
    swap(pa,pb);
    swap(a,c);
    swap(pa,pc);
    proc();
    if (la != -1) {
        swap(la,lc);
        swap(ra,rc);
        swap(la,lb);
        swap(ra,rb);
        ans();
        return;
    }

    //cba
    swap(b,c);
    swap(pb,pc);
    proc();
    if (la != -1) {
        swap(la,lc);
        swap(ra,rc);
        ans();
        return;
    }
    cout << "-1\n";
}