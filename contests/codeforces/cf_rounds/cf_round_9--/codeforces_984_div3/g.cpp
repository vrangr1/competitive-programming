/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sat Nov  2 21:19:44 IST 2024
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

void solve1() {
    ll n; cin >> n;
    if (n == -1) exit(0);
    auto ask = [&](ll l, ll r) -> ll {
        assert(l >= 1 && l <= r && r <= n);
        cout << "xor " << l << " " << r << endl;
        cout.flush();
        ll x; cin >> x;
        if (x == -1) exit(0);
        return x;
    };
    auto ans = [&](ll a, ll b, ll c) -> void {
        assert(a >= 1 && a <= n);
        assert(b >= 1 && b <= n);
        assert(c >= 1 && c <= n);
        cout << "ans " << a << " " << b << " " << c << endl;
        cout.flush();
    };
    set<ll> sol;
    auto bsch = [&](auto &&self, ll low, ll high) -> ll {
        assert(low <= high);
        if (low == high) {
            sol.insert(low);
            return low;
        }
        if (sz(sol) == 3) return -1;
        assert(sz(sol) < 3);
        assert(high > low+1ll);
        ll mid = low + ((high-low)/2ll);
        ll v = ask(mid,high), ct = 0, st = -1;
        if (sz(sol) == 2) {
            sol.insert(v);
            return v;
        }
        if (!v) {
            --mid;
            if (low == mid) {
                sol.insert(low);
                return low;
            } else if (low+1ll == mid) {
                v = ask(low,mid);
                if (v == (low^mid)) {
                    sol.insert(low);
                    sol.insert(mid);
                } else if (v == low) {
                    sol.insert(low);
                } else sol.insert(mid);
                return -1;
            } else {
                assert(low+1ll != mid);
                return self(self,low,mid);
            }
            return -2;
        }
        if (high-mid+1ll == 2ll) {
            if (v == (mid^high)) {
                sol.insert(mid);
                sol.insert(high);
                ct+=2;
            } else if (v == mid) {
                sol.insert(mid);
                ct++;
            } else {
                sol.insert(high);
                ct++;
            }
        } else {
            assert(mid+1ll != high);
            ll r = self(self,mid,high);
            if (r > 0){
                ct++;
                st = r;
            }
            else if (r == -1) ct+=2;
        }
        if (sz(sol) == 3) return -1;
        if (ct == 1 && st == v) return v;
        assert(sz(sol) < 3);
        v = ask(low,mid-1ll);
        if (!v) return -2;
        --mid;
        if (sz(sol) == 2) {
            sol.insert(v);
            return v;
        }
        if (low == mid) {
            sol.insert(low);
            ct++;
            st = low;
        } else if (low+1ll == mid) {
            if (v == (low^mid)) {
                sol.insert(low);
                sol.insert(mid);
                ct+=2;
            } else if (v == low) {
                sol.insert(low);
                ct++;
                st = low;
            } else {
                sol.insert(mid);
                ct++;
                st = mid;
            }
        } else {
            ll r = self(self,low,mid);
            if (r > 0){
                ct++;
                st = r;
            }
            else if (r == -1) ct+=2;
        }
        if (ct == 0) return -2;
        if (ct == 1) return st;
        return -1;
    };
    bsch(bsch,1,n);
    assert(sz(sol) == 3);
    vector<ll> vals(all(sol));
    ans(vals[0],vals[1],vals[2]);
}

void solve2() {
    ll n; cin >> n;
    if (n == -1) exit(0);
    auto ask = [&](ll l, ll r) -> ll {
        assert(l >= 1 && l <= r && r <= n);
        cout << "xor " << l << " " << r << endl;
        cout.flush();
        ll x; cin >> x;
        if (x == -1) exit(0);
        return x;
    };
    auto ans = [&](ll a, ll b, ll c) -> void {
        assert(a >= 1 && a <= n);
        assert(b >= 1 && b <= n);
        assert(c >= 1 && c <= n);
        cout << "ans " << a << " " << b << " " << c << endl;
        cout.flush();
    };
    set<ll> st;
    auto sch = [&](auto &&self, ll low, ll high, ll cur) -> void {
        assert(low + 1ll < high);
        if (sz(st) == 3) return;
        assert(sz(st) < 3);
        ll mx = (low^high);
        if (low <= cur && cur <= high && mx < low) {
            st.insert(cur);
            return;
        }
        ll mid = low + (high-low+1ll)/2ll;
        ll v = ask(mid,high);
        if (v && mid+1ll == high) {
            if (v == (mid^high)) {
                st.insert(mid);
                st.insert(high);
            } else if (v == mid) {
                st.insert(mid);
            } else {
                st.insert(high);
            }
            if (v == cur) return;
        } else if (v) {
            self(self,mid,high,v);
            if (v == cur) return;
        }
        --mid;
        if (cur == 0 && v == 0) {
            assert(mid-low+1ll >= 3);
            self(self,low,mid,0);
            return;
        }
        v ^= cur;
        assert(v > 0);
        assert(sz(st) < 3);
        if (low == mid) {
            st.insert(low);
            assert(v == low);
            return;
        } else if (low+1ll == mid) {
            if (v == (low^mid)) {
                st.insert(low);
                st.insert(mid);
            } else if (v == low) {
                st.insert(low);
            } else {
                assert(v == mid);
                st.insert(mid);
            }
            return;
        } else {
            self(self,low,mid,v);
        }
    };
    sch(sch,1,n,ask(1,n));
    assert(sz(st) == 3);
    vector<ll> vals(all(st));
    ans(vals[0],vals[1],vals[2]);
}

void solve() {
    ll n; cin >> n;
    if (n == -1) exit(0);
    auto ask = [&](ll l, ll r) -> ll {
        assert(l >= 1 && l <= r && r <= n);
        cout << "xor " << l << " " << r << endl;
        cout.flush();
        ll x; cin >> x;
        if (x == -1) exit(0);
        return x;
    };
    auto ans = [&](ll a, ll b, ll c) -> void {
        assert(a >= 1 && a <= n);
        assert(b >= 1 && b <= n);
        assert(c >= 1 && c <= n);
        cout << "ans " << a << " " << b << " " << c << endl;
        cout.flush();
    };
    vector<ll> vals;
    auto find2 = [&](auto &&self, ll mask, ll xr) -> void {
        assert((xr&mask) == 0);
        assert(sz(vals) == 1);
        ll lsb = (mask&(-mask));
        ll bit = (lsb>>1ll), r = lsb-1ll;
        ll v = ((bit|mask) <= n ? ask((bit|mask),min(n,(r|mask))) : 0);
        while(v == 0) {
            r = bit-1ll;
            bit>>=1ll;
            v = ((bit|mask) <= n ? ask((bit|mask),min(n,(r|mask))) : 0);
        }
        if (v == xr) {
            self(self,(mask|bit),xr);
        } else {
            vals.push_back(v);
            vals.push_back(xr^v);
        }
        assert(sz(vals) == 3);
    };
    auto find3 = [&](auto &&self, ll mask, ll xr) -> void {
        assert((mask&xr) != 0ll);
        assert(sz(vals) == 0);
        ll r = (mask&(-mask))-1ll, bit = ((r+1ll)>>1ll);
        ll v = ((bit|mask) <= n ? ask((bit|mask),min(n,(r|mask))) : 0);
        while(v == 0) {
            r = bit-1ll;
            bit>>=1ll;
            v = ((bit|mask) <= n ? ask((bit|mask),min(n,(r|mask))) : 0);
        }
        if (v == xr) {
            self(self,mask|bit,xr);
        } else if ((bit&v)) {
            vals.push_back(v);
            xr^=v;
            r = bit-1ll;
            bit>>=1ll;
            v = ask((bit|mask),(r|mask));
            while(v == 0) {
                r = bit-1ll;
                bit>>=1ll;
                v = ask((bit|mask),(r|mask));
            }
            if (v != xr) {
                vals.push_back(v);
                vals.push_back(v^xr);
            } else {
                find2(find2,mask|bit,xr);
            }
        } else {
            vals.push_back(v^xr);
            find2(find2,mask|bit,v);
        }
    };
    ll ov = ask(1,n);
    ll bit = (1ll << (63ll-__builtin_clzll(n)));
    assert(bit <= n);
    ll v = ask(bit,n);
    while(v == 0) {
        ll r = bit-1ll;
        bit>>=1ll;
        v = ask(bit,r);
    }
    assert(v);
    if (v != ov && (v&bit)) { // 1
        vals.push_back(v);
        ov ^= v;
        // TODO Find rest two
        assert(bit > 1);
        ll r = bit-1ll;
        bit>>=1ll;
        v = ask(bit,r);
        while(v == 0) {
            r = bit-1ll;
            bit>>=1ll;
            v = ask(bit,r);
        }
        if (v == ov) {
            find2(find2,bit,v);
        } else {
            vals.push_back(v);
            vals.push_back(ov^v);
        }
    } else if (v == ov) {
        assert((v&bit));
        // TODO Find all three
        ll mask = bit;
        find3(find3,mask,ov);
    } else { // 2
        vals.push_back(v^ov); // Found 3rd val
        // TODO Find the rest 2 here
        find2(find2,bit,v);
    }
    assert(sz(vals)==3);
    ans(vals[0],vals[1],vals[2]);
}