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
        ll v = ask(mid,high), ct = 0, st;
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