/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sun Feb 18 18:17:41 IST 2024
****************************************************/
#include <iostream>
#include <vector>
#include <string.h>
#include <ctype.h>
#include <set>
#include <stdlib.h>
#include <map>
#include <iterator>
#include <iomanip>
#include <algorithm>
#include <climits>
#include <numeric>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <forward_list>
#include <bit>
#include <bitset>
#include <array>
#include <assert.h>
#define debug(...) 42
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
#define mt make_tuple
#define space " "
#define yes "YES\n"
#define no "NO\n"
#define pass ((void)0)
template<typename type>inline void print_vec(const vector<type> &v){rep(i,sz(v))cout<<v[i]<<" \n"[i==sz(v)-1];}
void solve();

// IMPORT SNIPPETS HERE

// END OF SNIPPETS

int main(){
	fastIO;
	TEST;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

void solve1(){
    int n; cin >> n;
    string val; cin >> val;
    ll sol = 0;
    vector<ll> dp(n+1ll,0ll);
    dp[1] = 1ll;
    rep(i,2ll,n,1ll){
        dp[i] = 10ll*dp[i-1ll]+1ll;
    }
    reverse(all(val));
    rep(i,n){
        ll ind = i+1l;
        sol += (val[i]-'0')*dp[ind];
    }
    cout << sol << endl;
}

// vector<string> dp((int)4e5+1,"");

void solve2(){
    int n; cin >> n;
    string val; cin >> val;
    auto add = [](auto &&self, string &a, string &b) -> void {
        if (sz(a) >= sz(b)){
            int carry = 0, ca, cb, s, ia = sz(a)-1, ib = sz(b)-1;
            for(; ib >= 0; --ia,--ib){
                ca = a[ia]-'0';
                cb = b[ib]-'0';
                s = ca+cb+carry;
                carry=s/10;
                assert(carry<10);
                s%=10;
                a[ia] = (s+'0');
            }
            while(ia >= 0 && carry > 0){
                ca = a[ia]-'0';
                s = ca+carry;
                carry=s/10;
                assert(carry<10);
                s%=10;
                a[ia] = (s+'0');
                --ia;
            }
            if (ia == -1 && carry > 0){
                a = to_string(carry) + a;
            }
            return;
        }
        string temp = b;
        swap(a,b);
        self(self,a,b);
        b = temp;
    };
    auto mult = [](string &a, int m) -> void {
        assert(m >= 1 && m < 10);
        if (m == 1) return;
        int carry = 0, c;
        rep(i,sz(a)-1,0,-1){
            c = a[i]-'0';
            c *= m;
            c += carry;
            carry = c/10;
            assert(carry < 10);
            a[i] = (c%10)+'0';
        }
        if (carry > 0) a = to_string(carry) + a;
    };
    // auto init = [&]() -> void {
    //     string one = "1";
    //     rep(i,1,n,1){
    //         if (dp[i] != "") continue;
    //         dp[i] = dp[i-1];
    //         dp[i].push_back('0');
    //         add(add,dp[i],one);
    //     }
    // };
    // init();
    string sol = "0";
    reverse(all(val));
    string dp = "", one = "1";
    rep(i,n){
        dp.push_back('0');
        add(add,dp,one);
        if (val[i] == '0') continue;
        ll ind = i+1l;
        string cur = dp;
        mult(cur,(val[i]-'0'));
        add(add,sol,cur);
    }
    cout << sol << endl;
}


#ifndef ATCODER_INTERNAL_BITOP_HPP
#define ATCODER_INTERNAL_BITOP_HPP 1

#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace atcoder {

namespace internal {

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

}  // namespace internal

}  // namespace atcoder

#endif  // ATCODER_INTERNAL_BITOP_HPP


#ifndef ATCODER_LAZYSEGTREE_HPP
#define ATCODER_LAZYSEGTREE_HPP 1

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
namespace atcoder {

template <class S,
          S (*op)(S, S),
          S (*e)(),
          class F,
          S (*mapping)(F, S),
          F (*composition)(F, F),
          F (*id)()>
struct lazy_segtree {
  public:
    lazy_segtree() : lazy_segtree(0) {}
    lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
    lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        lz = std::vector<F>(size, id());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return e();

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push(r >> i);
        }

        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    void apply(int p, F f) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = mapping(f, d[p]);
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return;

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    template <bool (*g)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return g(x); });
    }
    template <class G> int max_right(int l, G g) {
        assert(0 <= l && l <= _n);
        assert(g(e()));
        if (l == _n) return _n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(op(sm, d[l]))) {
                while (l < size) {
                    push(l);
                    l = (2 * l);
                    if (g(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*g)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return g(x); });
    }
    template <class G> int min_left(int r, G g) {
        assert(0 <= r && r <= _n);
        assert(g(e()));
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(op(d[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if (g(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;
    std::vector<F> lz;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, F f) {
        d[k] = mapping(f, d[k]);
        if (k < size) lz[k] = composition(f, lz[k]);
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
};

}  // namespace atcoder

#endif  // ATCODER_LAZYSEGTREE_HPP

struct S{
    ll v;
    S(){
        v = 0;
    }
    S(ll vgn){
        v = vgn;
    }
};

S op(S a, S b){
    return S(a.v+b.v);
}

S e(){
    return S(0);
}

struct F{
    ll inc;
};
S mapping(F f, S x){
    return S(x.v+f.inc);
}
F comp(F f, F g){
    return F{f.inc+g.inc};
}
F id(){
    return F{0ll};
}

void solve(){
    int n; cin >> n;
    string val; cin >> val;
    vector<S> a(n);
    atcoder::lazy_segtree<S,op,e,F,mapping,comp,id> seg(a);
    rep(i,n){
        seg.apply(i,n,F{val[i]-'0'});
    }
    string sol;
    ll carry = 0ll;
    rep(i,n-1,0,-1){
        ll cur = seg.get(i).v;
        cur += carry;
        carry = cur/10ll;
        sol.push_back((cur%10ll) + '0');
    }
    while(carry > 0ll){
        sol.push_back((carry%10ll)+'0');
        carry/=10ll;
    }
    while(!sol.empty() && sol.back() == '0')
        sol.pop_back();
    reverse(all(sol));
    cout << sol << endl;
}

/*


*/