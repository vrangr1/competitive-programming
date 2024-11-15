/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Fri Nov 15 18:25:06 IST 2024
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

// class mxseg {
// public:
//     int n;
//     vector<pair<int,int>> tree;
//     mxseg(const vector<int> &a) {
//         n = sz(a);
//         int gn = (n<<1);
//         if (__builtin_popcount(gn) != 1)
//             gn = (1<<(32-__builtin_clz(gn)));
//         tree.assign(gn,{INT_MIN,INT_MIN});
//         rep(i,n)
//             tree[i+n] = {a[i],i};
//         rep(i,n,1,-1) {
//             tree[i] = max(tree[i<<1],tree[i<<1|1]);
//             // auto [lval, lind] = tree[i<<1];
//             // auto [rval, rind] = tree[i<<1|1];
//         }       
//     }

//     pair<int,int> query(int l, int r) {
//         pair<int,int> res = {INT_MIN,-1};
//         for (l+=n,r+=n;l<r;l>>=1,r>>=1) {
//             if (l&1) res = max(res,tree[l++]);
//             if (r&1) res = max(res,tree[--r]);
//         }
//         return res;
//     }
// };

// class mnseg {
// public:
//     int n;
//     vector<pair<int,int>> tree;
//     mnseg(const vector<int> &a) {
//         n = sz(a);
//         int gn = (n<<1);
//         if (__builtin_popcount(gn) != 1)
//             gn = (1<<(32-__builtin_clz(gn)));
//         tree.assign(gn,{INT_MAX,INT_MAX});
//         rep(i,n)
//             tree[i+n] = {a[i],i};
//         rep(i,n,1,-1)
//             tree[i] = min(tree[i<<1],tree[i<<1|1]);
//     }

//     pair<int,int> query(int l, int r) {
//         pair<int,int> res = {INT_MAX,INT_MAX};
//         for (l+=n,r+=n;l<r;l>>=1,r>>=1) {
//             if (l&1) res = min(res,tree[l++]);
//             if (r&1) res = min(res,tree[--r]);
//         }
//         return res;
//     }
// };

// void solve() {
//     int n; cin >> n;
//     vector<int> a(n);
//     rep(i,n) cin >> a[i];
//     vector<int> sol(n,-1);
//     int mxind = int(max_element(all(a))-a.begin());
//     rep(i,mxind,n-1,1)
//         sol[i] = a[mxind];
//     int mn = *min_element(mxind+all(a));
//     rep(i,mxind)
//         if (a[i] > mn) sol[i] = a[mxind];
//     if (a[0] > mn) {
//         fill(all(sol),a[mxind]);
//         print_vec(sol);
//         return;
//     }


//     rep(i,mxind) {
//         if (sol[i] != -1) {
//             mn = min(mn,a[i]);
//             continue;
//         }
        
//     }
// }

class segtree {
public:
    int n;
    vector<pair<int,int>> tree;
    segtree(const vector<int> &a) {
        n = sz(a);
        int gn = (n<<1);
        if (__builtin_popcount(gn) != 1)
            gn = (1<<(32-__builtin_clz(gn)));
        tree.assign(gn,{INT_MAX,INT_MIN});
        rep(i,n)
            tree[i+n] = {i,a[i]};
        rep(i,n-1,1,-1) {
            auto [lind, lval] = tree[i<<1];
            auto [rind, rval] = tree[i<<1|1];
            if (lval > rval || (lval == rval && lind < rind)) tree[i] = tree[i<<1];
            else tree[i] = tree[i<<1|1];
        }
        debug(tree[1]);
    }

    pair<int,int> query(int l, int r) {
        pair<int,int> res = {INT_MAX, INT_MIN};
        for (l+=n,r+=n; l < r; l>>=1,r>>=1) {
            if (l&1) {
                auto [ind, val] = tree[l];
                if (val > res.second || (val == res.second && ind < res.first)) res = tree[l];
                ++l;
            }
            if (r&1) {
                --r;
                auto [ind,val] = tree[r];
                if (val > res.second || (val == res.second && ind < res.first)) res = tree[r];
            }
        }
        return res;
    }
};

class mnseg {
public:
    int n;
    vector<int> tree;
    mnseg(const vector<int> &a) {
        n = sz(a);
        int gn = (n<<1);
        if (__builtin_popcount(gn) != 1)
            gn = (1<<(32-__builtin_clz(gn)));
        tree.assign(gn,INT_MAX);
        rep(i,n)
            tree[i+n] = a[i];
        rep(i,n-1,1,-1)
            tree[i] = min(tree[i<<1],tree[i<<1|1]);
    }

    int query(int l, int r) {
        int res = INT_MAX;
        for (l += n, r+=n; l < r; l>>=1,r>>=1) {
            if (l&1) res = min(res,tree[l++]);
            if (r&1) res = min(res, tree[--r]);
        }
        return res;
    }
};

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> sol(n,-1);
    vector<bool> mxvals(n,false);
    segtree seg(a);
    mnseg mseg(a);
    int last = n;
    int mnval = INT_MAX, lastmx = INT_MIN;
    debug(seg.query(0,n));
    while(last != 0) {
        auto [mxind, mxval] = seg.query(0,last); // first ind with max val in rng [0,ind)
        if (mxval > mnval) {
            mxval = lastmx;
        } else {
            lastmx = mxval;
        }
        debug(endl,last,mxind,mxval);
        fill(sol.begin() + mxind, sol.begin() + last, mxval);
        mnval = min(mnval, mseg.query(mxind,last));
        mxvals[mxind] = true;
        last = mxind;
    }
    print_vec(sol);
}