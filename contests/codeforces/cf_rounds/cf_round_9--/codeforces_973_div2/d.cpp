/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Fri Sep 20 20:31:58 IST 2024
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
// #ifndef ATCODER_INTERNAL_BITOP_HPP
// #define ATCODER_INTERNAL_BITOP_HPP 1

// #ifdef _MSC_VER
// #include <intrin.h>
// #endif

// #if __cplusplus >= 202002L
// #include <bit>
// #endif

// namespace atcoder {

// namespace internal {

// #if __cplusplus >= 202002L

// using std::bit_ceil;

// #else

// // @return same with std::bit::bit_ceil
// unsigned int bit_ceil(unsigned int n) {
//     unsigned int x = 1;
//     while (x < (unsigned int)(n)) x *= 2;
//     return x;
// }

// #endif

// // @param n `1 <= n`
// // @return same with std::bit::countr_zero
// int countr_zero(unsigned int n) {
// #ifdef _MSC_VER
//     unsigned long index;
//     _BitScanForward(&index, n);
//     return index;
// #else
//     return __builtin_ctz(n);
// #endif
// }

// // @param n `1 <= n`
// // @return same with std::bit::countr_zero
// constexpr int countr_zero_constexpr(unsigned int n) {
//     int x = 0;
//     while (!(n & (1 << x))) x++;
//     return x;
// }

// }  // namespace internal

// }  // namespace atcoder

// #endif  // ATCODER_INTERNAL_BITOP_HPP

// #ifndef ATCODER_LAZYSEGTREE_HPP
// #define ATCODER_LAZYSEGTREE_HPP 1

// #include <algorithm>
// #include <cassert>
// #include <functional>
// #include <vector>

// // #include "atcoder/internal_bit"

// namespace atcoder {

// #if __cplusplus >= 201703L

// template <class S,
//           auto op,
//           auto e,
//           class F,
//           auto mapping,
//           auto composition,
//           auto id>
// struct lazy_segtree {
//     static_assert(std::is_convertible_v<decltype(op), std::function<S(S, S)>>,
//                   "op must work as S(S, S)");
//     static_assert(std::is_convertible_v<decltype(e), std::function<S()>>,
//                   "e must work as S()");
//     static_assert(
//         std::is_convertible_v<decltype(mapping), std::function<S(F, S)>>,
//         "mapping must work as S(F, S)");
//     static_assert(
//         std::is_convertible_v<decltype(composition), std::function<F(F, F)>>,
//         "composition must work as F(F, F)");
//     static_assert(std::is_convertible_v<decltype(id), std::function<F()>>,
//                   "id must work as F()");

// #else

// template <class S,
//           S (*op)(S, S),
//           S (*e)(),
//           class F,
//           S (*mapping)(F, S),
//           F (*composition)(F, F),
//           F (*id)()>
// struct lazy_segtree {

// #endif

//   public:
//     lazy_segtree() : lazy_segtree(0) {}
//     explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
//     explicit lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) {
//         size = (int)internal::bit_ceil((unsigned int)(_n));
//         log = internal::countr_zero((unsigned int)size);
//         d = std::vector<S>(2 * size, e());
//         lz = std::vector<F>(size, id());
//         for (int i = 0; i < _n; i++) d[size + i] = v[i];
//         for (int i = size - 1; i >= 1; i--) {
//             update(i);
//         }
//     }

//     void set(int p, S x) {
//         assert(0 <= p && p < _n);
//         p += size;
//         for (int i = log; i >= 1; i--) push(p >> i);
//         d[p] = x;
//         for (int i = 1; i <= log; i++) update(p >> i);
//     }

//     S get(int p) {
//         assert(0 <= p && p < _n);
//         p += size;
//         for (int i = log; i >= 1; i--) push(p >> i);
//         return d[p];
//     }

//     S prod(int l, int r) {
//         assert(0 <= l && l <= r && r <= _n);
//         if (l == r) return e();

//         l += size;
//         r += size;

//         for (int i = log; i >= 1; i--) {
//             if (((l >> i) << i) != l) push(l >> i);
//             if (((r >> i) << i) != r) push((r - 1) >> i);
//         }

//         S sml = e(), smr = e();
//         while (l < r) {
//             if (l & 1) sml = op(sml, d[l++]);
//             if (r & 1) smr = op(d[--r], smr);
//             l >>= 1;
//             r >>= 1;
//         }

//         return op(sml, smr);
//     }

//     S all_prod() { return d[1]; }

//     void apply(int p, F f) {
//         assert(0 <= p && p < _n);
//         p += size;
//         for (int i = log; i >= 1; i--) push(p >> i);
//         d[p] = mapping(f, d[p]);
//         for (int i = 1; i <= log; i++) update(p >> i);
//     }
//     void apply(int l, int r, F f) {
//         assert(0 <= l && l <= r && r <= _n);
//         if (l == r) return;

//         l += size;
//         r += size;

//         for (int i = log; i >= 1; i--) {
//             if (((l >> i) << i) != l) push(l >> i);
//             if (((r >> i) << i) != r) push((r - 1) >> i);
//         }

//         {
//             int l2 = l, r2 = r;
//             while (l < r) {
//                 if (l & 1) all_apply(l++, f);
//                 if (r & 1) all_apply(--r, f);
//                 l >>= 1;
//                 r >>= 1;
//             }
//             l = l2;
//             r = r2;
//         }

//         for (int i = 1; i <= log; i++) {
//             if (((l >> i) << i) != l) update(l >> i);
//             if (((r >> i) << i) != r) update((r - 1) >> i);
//         }
//     }

//     template <bool (*g)(S)> int max_right(int l) {
//         return max_right(l, [](S x) { return g(x); });
//     }
//     template <class G> int max_right(int l, G g) {
//         assert(0 <= l && l <= _n);
//         assert(g(e()));
//         if (l == _n) return _n;
//         l += size;
//         for (int i = log; i >= 1; i--) push(l >> i);
//         S sm = e();
//         do {
//             while (l % 2 == 0) l >>= 1;
//             if (!g(op(sm, d[l]))) {
//                 while (l < size) {
//                     push(l);
//                     l = (2 * l);
//                     if (g(op(sm, d[l]))) {
//                         sm = op(sm, d[l]);
//                         l++;
//                     }
//                 }
//                 return l - size;
//             }
//             sm = op(sm, d[l]);
//             l++;
//         } while ((l & -l) != l);
//         return _n;
//     }

//     template <bool (*g)(S)> int min_left(int r) {
//         return min_left(r, [](S x) { return g(x); });
//     }
//     template <class G> int min_left(int r, G g) {
//         assert(0 <= r && r <= _n);
//         assert(g(e()));
//         if (r == 0) return 0;
//         r += size;
//         for (int i = log; i >= 1; i--) push((r - 1) >> i);
//         S sm = e();
//         do {
//             r--;
//             while (r > 1 && (r % 2)) r >>= 1;
//             if (!g(op(d[r], sm))) {
//                 while (r < size) {
//                     push(r);
//                     r = (2 * r + 1);
//                     if (g(op(d[r], sm))) {
//                         sm = op(d[r], sm);
//                         r--;
//                     }
//                 }
//                 return r + 1 - size;
//             }
//             sm = op(d[r], sm);
//         } while ((r & -r) != r);
//         return 0;
//     }

//   private:
//     int _n, size, log;
//     std::vector<S> d;
//     std::vector<F> lz;

//     void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
//     void all_apply(int k, F f) {
//         d[k] = mapping(f, d[k]);
//         if (k < size) lz[k] = composition(f, lz[k]);
//     }
//     void push(int k) {
//         all_apply(2 * k, lz[k]);
//         all_apply(2 * k + 1, lz[k]);
//         lz[k] = id();
//     }
// };

// }  // namespace atcoder

// #endif  // ATCODER_LAZYSEGTREE_HPP

int main() {
	fastIO;
	TEST;
#ifdef LOCAL
    cout << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

// class S {
// public:
//     ll val;
//     S() : val(0ll) {}
//     S(ll v) {
//         val = v;
//     }
// };

// S op(S a, S b) {
//     return S(a.val+b.val);
// }

// S e() {
//     return S();
// }

// class F {
// public:
//     ll val;
//     F() : val(LLONG_MIN){}
//     F(ll v) : val(v){}
// };

// S mapping(F f, S x) {
//     if (f.val == LLONG_MIN) return x;
//     return S(f.val);
// }

// F composition(F f, F g) {
//     if (f.val == LLONG_MIN) return g;
//     if (g.val == LLONG_MIN) return f;
//     return f;
// }

// F id() {
//     return F();
// }


// Based on https://codeforces.com/blog/entry/18051
class segtree {
public:
    ll n, h;
    vector<ll> tree, d;
    segtree(ll gn) {
        if (__builtin_popcountll(gn) != 1ll)
            gn = (1ll << (64ll-__builtin_clzll(gn)));
        n = gn;
        gn<<=1ll;
        tree.assign(gn,0ll);
        d.assign(gn,LLONG_MIN);
        h = 64ll-__builtin_clzll(gn);
    }

    void calc(ll p, ll k) {
        if (d[p] == 0) tree[p] = tree[p<<1ll] + tree[p<<1|1];
        else tree[p] = d[p] * k;
    }

    void apply(ll p, ll value, ll k) {
        tree[p] = value * k;
        if (p < n) d[p] = value;
    }

    void build(ll l, ll r) {
        ll k = 2;
        for (l += n, r += n-1ll; l > 1ll; k <<= 1ll) {
            l >>= 1ll, r >>= 1ll;
            for (ll i = r; i >= l; --i) calc(i, k);
        }
    }

    void push(ll l, ll r) {
        ll s = h, k = 1 << (h-1);
        for (l += n, r += n-1; s > 0; --s, k >>= 1ll)
            for (ll i = l >> s; i <= r >> s; ++i) if (d[i] != 0) {
                apply(i<<1, d[i], k);
                apply(i<<1|1, d[i], k);
                d[i] = 0;
            }
    }

    void modify(ll l, ll r, ll value) {
        if (value == 0) return;
        push(l, l + 1);
        push(r - 1, r);
        ll l0 = l, r0 = r, k = 1;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1, k <<= 1) {
            if (l&1) apply(l++, value, k);
            if (r&1) apply(--r, value, k);
        }
        build(l0, l0 + 1);
        build(r0 - 1, r0);
    }

    ll query(ll l, ll r) {
        push(l, l + 1);
        push(r - 1, r);
        ll res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) res += tree[l++];
            if (r&1) res += tree[--r];
        }
        return res;
    }
};

void solve() {
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    // vector<S> vec(n);
    // atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(vec);
    segtree seg(n);
    rep(i,n) {
        debug(endl,i);
        // if (i == 0 || seg.get(i-1).val <= a[i]) {
        if (i == 0 || seg.query(i-1,i) <= a[i]) {
            // seg.apply(i,F(a[i]));
            seg.modify(i,i+1,a[i]);
            continue;
        }
        ll low = 0ll, high = i-1ll;
        while(low < high) {
            ll mid = (low+high)/2ll;
            // ll sum = seg.prod(mid,i).val;
            ll sum = seg.query(mid,i);
            // if ((sum+a[i])/(i-mid+1ll) <= seg.get(mid).val)
            if ((sum+a[i])/(i-mid+1ll) <= seg.query(mid,mid+1ll))
                high = mid;
            else low = mid+1ll;
        }
        assert(high < i);
        if (i == 3 && DEBUG) {
            rep(j,n) {
                // debug(j,seg.prod(j,j+1).val);
                debug(j,seg.query(j,j+1));
            }
            // debug(seg.get(0).val);
            // debug(seg.get(1).val);
            // debug(seg.get(2).val);
            // debug(seg.get(3).val);
            // debug(seg.prod(0,2).val);
            // debug(seg.prod(1,3).val);
            // debug(seg.prod(2,4).val);
            // debug(seg.prod(0,3).val);
            // debug(seg.all_prod().val);
        }
        // ll sum = (seg.prod(high,i).val + a[i]), ct = i-high+1ll;
        ll sum = seg.query(high,i)+a[i], ct = i-high+1ll;
        ll rem = sum%ct, avg = sum/ct;
        debug(high,sum,ct,rem,avg);
        // seg.apply(high,high+ct-rem,F(avg));
        seg.modify(high,high+ct-rem,avg);
        if (rem) {
            // seg.apply(high+ct-rem,i+1ll,F(avg+1ll));
            seg.modify(high+ct-rem,i+1ll,avg+1ll);
            assert(i+1ll-(high+ct-rem) == rem);
        }
        // if (high) assert(seg.get(high-1ll).val <= seg.get(high).val);
        if (high) assert(seg.query(high-1ll,high) <= seg.query(high,high+1ll));
    }
    if (DEBUG) {
        debug(endl);
        rep(i,n) {
            // debug(i,seg.get(i).val);
            debug(i,seg.query(i,i+1ll));
        }
    }
    // cout << seg.get(n-1ll).val - seg.get(0ll).val << endl;
    cout << seg.query(n-1ll,n) - seg.query(0,1) << endl;
}