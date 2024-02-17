/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Feb 17 18:01:03 IST 2024
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
#include <atcoder/lazysegtree>
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
#define yes "Yes\n"
#define no "No\n"
#define pass ((void)0)
template<typename type>inline void print_vec(const vector<type> &v){rep(i,sz(v))cout<<v[i]<<" \n"[i==sz(v)-1];}
void solve();

// IMPORT SNIPPETS HERE

// END OF SNIPPETS

int main(){
	fastIO;
	TEST1;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

void solve(){
    int n, q; cin >> n >> q;
    string s; cin >> s;
    struct S{
        char left, right;
        bool alt;
        S(){
            left = '.';
            right = '.';
            alt = true;
        }
        S(char l, char r, bool a){
            left = l;
            right = r;
            alt = a;
        }
    };
    vector<S> a(n);
    rep(i,n){
        a[i] = S(s[i],s[i],true);
    }
    auto op = [](S l, S r) -> S {
        if (!l.alt || !r.alt) return S(l.left,r.right,false);
        if (l.right != r.left) return S(l.left,r.right,true);
        return S(l.left,r.right,false);
    };
    auto e = []() -> S {
        return S('.','.',true);
    };
    struct F{
        bool flip;
    };
    auto mapping = [](F l, S r) -> S {
        auto fix = [](char ch, bool f) -> char {
            if (!f) return ch;
            switch(ch){
                case '0': return '1';
                case '1': return '0';
                case '.': return '.';
                default: assert(false);
            }
            assert(false);
            return '.';
        };
        r.left = fix(r.left,l.flip);
        r.right = fix(r.right,l.flip);
        return r;
    };

    auto comp = [](F l, F r) -> F {
        if (!l.flip && !r.flip) return l;
        if (!l.flip || !r.flip) return F{true};
        return F{false};
    };

    auto id = []() -> F {
        return F{false};
    };
    
    atcoder::lazy_segtree<S,op,e,F,mapping,comp,id> seg(a);
    while(q--){
        int t, l, r; cin >> t >> l >> r;
        --l;
        if (t == 1){
            seg.apply(l,r,F{true});
        }
        else{
            if (seg.prod(l,r).alt) cout << yes;
            else cout << no;
        }
    }
}