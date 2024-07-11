/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Thu Jul 11 22:07:58 IST 2024
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
#ifndef SQRT_SNIPPET
#define SQRT_SNIPPET
#include <iostream>
// Babylonian Method
template <typename type, typename = typename std::enable_if<std::is_integral<type>::value>::type>
type bsqrt(type x){
    const type one = 1, two = 2;
    type a = x, b = (x + one) / two;
    while (a > b){
        a = b;
        b = (b + x / b) / two;
    }
    return a;
}
#endif
// END OF SNIPPETS

int main() {
	fastIO;
	TEST;
#ifdef LOCAL
    cout << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

const ll mx = (ll)1e6;

class segtree {
public:
    ll n;
    vector<ll> tree;
    segtree(const vector<ll> a) {
        n = sz(a);
        ll gn = (n<<1ll);
        if (__builtin_popcountll(gn) != 1) 
            gn = (1ll << (64ll-__builtin_clzll(gn)));
        tree.assign(gn,1);
        rep(i,n)
            tree[i+n] = a[i];
        rep(i,n-1,1ll,-1ll) {
            if (tree[i<<1ll] == mx || tree[i<<1ll|1ll] == mx)
                tree[i] = mx;
            else tree[i] = tree[i<<1ll]*tree[i<<1ll|1ll];
            tree[i] = min(tree[i],mx);
        }
    }

    ll query(ll l, ll r) {
        ll res = 1ll;
        for(l+=n,r+=n;l<r;l>>=1ll,r>>=1ll) {
            if (l&1ll) {
                if (tree[l] == mx) res = mx;
                else res *= tree[l];
                l++;
            }
            if (r&1ll) {
                --r;
                if (tree[r] == mx || res == mx) res = mx;
                else res *= tree[r];
            }
            res = min(res,mx);
            if (res == mx) return res;
        }
        return min(res,mx);
    }
};

// Misunderstood the problem. The following is the solution to a different problem in which a segment is considered bad if there isn't a subsegment whose product is x.
void solve1() {
    ll n, x; cin >> n >> x;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    segtree seg(a);
    auto lbd = [&](auto &&self, ll low, ll high, const ll st) -> ll {
        if (low == high) {
            if (seg.query(st,low+1ll) != x) return -1;
            return low;
        }
        ll mid = (low+high)/2ll, v = seg.query(st,mid+1ll);
        if (v < x) return self(self, mid+1ll, high, st);
        return self(self, low, mid, st);
    };
    auto ubd = [&](auto &&self, ll low, ll high, const ll st) -> ll {
        if (low == high) {
            if (seg.query(st,high+1ll) != x) return -1ll;
            return high;
        }
        ll mid = (low+high+1ll)/2ll, v = seg.query(st, mid+1ll);
        if (v > x) return self(self, low, mid-1ll, st);
        return self(self, mid, high, st);
    };
    vector<tuple<ll,ll>> ints;
    vector<vector<ll>> ops(n), cls(n);
    ll ct = 0ll;
    rep(i,n) {
        if (a[i] > x || seg.query(i,n) < x) continue;
        ll l = lbd(lbd, i, n-1ll, i);
        if (l == -1ll) continue;
        ll r = ubd(ubd, i, n-1ll, i);
        assert(r != -1ll);
        assert(i != l);
        ints.emplace_back(i,l);
        ops[i].push_back(ct);
        cls[l].push_back(ct++);
    }
    debug(ints);
    set<ll> seen;
    ll sol = 0ll;
    rep(i,n) {
        bool sp = false;
        for (ll &f : cls[i]) {
            if (seen.find(f) == seen.end()) continue;
            sp = true;
            seen.erase(f);
        }
        sol+=sp;
        for (ll &s : ops[i])
            seen.insert(s);
    }
    cout << sol+1ll << endl;
}

// Based on tourist's solution
void solve() {
    int n, x; cin >> n >> x;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> factors;
    {
        factors.push_back(1);
        int sq = bsqrt(x);
        rep(f,2,sq,1)
            if (x%f == 0) {
                factors.push_back(f);
                if (f != x/f)
                factors.push_back(x/f);
            }
        sort(all(factors));
    }
    vector<bool> seen(x+1,false);
    int sol = 0;
    for (int &v : a) {
        if (x%v) continue;
        for (int i = sz(factors)-1; i >= 0; --i)
            if (seen[factors[i]] && x%(factors[i]*v) == 0) {
                seen[factors[i]*v] = true;
                if (factors[i]*v == x) break;
            }
        seen[v] = true;
        if (!seen[x]) continue;
        sol++;
        seen[x] = false;
        for (int &f : factors)
            seen[f] = false;
        seen[v] = true;
    }
    cout << sol+1 << endl;
}