/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed May 29 04:42:41 IST 2024
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
#define mt make_tuple
#define space " "
#define yes "YES\n"
#define no "NO\n"
#define pass ((void)0)
template<typename type>inline void print_vec(const vector<type> &v){rep(i,sz(v))cout<<v[i]<<" \n"[i==sz(v)-1];}
void solve();

// IMPORT SNIPPETS HERE
#ifndef HASH_MAP_SNIPPET
#define HASH_MAP_SNIPPET
#include <type_traits>
#include <unordered_set>
#include <unordered_map>
#include <chrono>
typedef long long int ll;

// Source: Neal Wu (codeforces handle: neal)
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

template <typename type>
using hash_set = conditional_t <is_same<type,int>::value || is_same<type,ll>::value, unordered_set<type, custom_hash>, unordered_set<type>>;

template<typename t1, typename t2>
using hash_map = conditional_t<is_same<t1,ll>::value || is_same<t1,int>::value, unordered_map<t1, t2, custom_hash>, unordered_map<t1,t2>>;

template <typename type>
using hash_multiset = conditional_t<is_same<type,int>::value || is_same<type,ll>::value, unordered_multiset<type, custom_hash>, unordered_multiset<type>>;

template<typename t1, typename t2>
using hash_multimap = conditional_t<is_same<t1,int>::value || is_same<t2,ll>::value, unordered_multimap<t1, t2, custom_hash>, unordered_multimap<t1,t2>>;

#endif // IMPORT_HASH_SET_SNIPPET
// END OF SNIPPETS

int main(){
	fastIO;
	TEST1;
#ifdef LOCAL
    cout << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

class segtree {
public:
    int n;
    vector<int> tree;
    segtree(int gn) {
        n = gn;
        gn<<=1;
        if (__builtin_popcount(gn) != 1)
            gn = (1<<(32-__builtin_clz(gn)));
        tree.assign(gn,0);
    }

    void update(int ind) {
        for(tree[ind+=n]++;ind>1;ind>>=1)
            tree[ind>>1] = tree[ind]+tree[ind^1];
    }

    int query(int l, int r) {
        int res = 0;
        for(l+=n,r+=n; l<r; l>>=1,r>>=1) {
            if (l&1) res += tree[l++];
            if (r&1) res += tree[--r];
        }
        return res;
    }
};

void solve(){
    int n; cin >> n;
    vector<int> a(n), fl(n), fr(n);
    rep(i,n) cin >> a[i];
    hash_map<int,int> mp;
    rep(i,n) {
        fl[i] = mp[a[i]];
        mp[a[i]]++;
    }
    mp.clear();
    rep(i,n-1,0,-1) {
        fr[i] = mp[a[i]];
        mp[a[i]]++;
    }
    ll sol = 0;
    segtree st(n);
    rep(i,n-1,0,-1) {
        sol += (ll)st.query(0,fl[i]);
        st.update(fr[i]);
    }
    cout << sol << endl;
}