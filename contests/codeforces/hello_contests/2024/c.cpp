/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Jan  6 20:13:18 IST 2024
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

// Attempt 1, incorrect
void solve1(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> vals, inds, p(n,-1);
    rep(i,n){
        if (vals.empty() || vals.back() >= a[i]){
            vals.push_back(a[i]);
            if (inds.empty()) p[i] = -1;
            else p[i] = inds.back();
            // if (inds.empty()) p.push_back(-1);
            // else p.push_back(inds.back());
            inds.push_back(i);
            continue;
        }
        auto iter = partition_point(all(vals),[&](const int &val){
            return val >= a[i];
        });
        assert(iter != vals.end());
        int curind = (int)(iter-vals.begin());
        vals[curind] = a[i];
        inds[curind] = i;
        if (curind) p[i] = inds[curind-1];
    }
    vector<bool> vis(n,false);
    debug(vals.size(),inds,p);
    int ind = inds.back();
    vis[ind] = true;
    while(p[ind] != -1){
        ind = p[ind];
        vis[ind] = true;
    }
    debug(vis);
    int ct = 0, last = INT_MAX;
    rep(i,n){
        if (vis[i]) continue;
        if (last < a[i]) ct++;
        last = a[i];
    }
    cout << ct << endl;
}

// Attempt 2, incorrect
void solve2(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> s,t;
    auto compute = [](const vector<int> &a){
        int ct = 0, n = sz(a), last = INT_MAX;
        rep(i,n){
            if (last < a[i]) ct++;
            last = a[i];
        }
        return ct;
    };
    int sol = 0;
    rep(i,n){
        if ((t.empty() && !s.empty()) || (!t.empty() && !s.empty() && t.back() > s.back())){
            swap(t,s);
        }
        if (t.empty() || t.back() >= a[i]){
            t.push_back(a[i]);
            continue;
        }
        if (s.empty() || s.back() >= a[i]){
            s.push_back(a[i]);
            continue;
        }
        t.push_back(a[i]);
        sol++;
    }
    cout << compute(s) + compute(t) << endl;
    cout << sol << endl;
    // debug(s,t);
}


class segtree{
private:
    int n;
    vector<int> tree, ft, lt;
public:
    segtree(const vector<int> &arr){
        int gn = sz(arr);
        gn *= 2;
        if (gn - (gn&(-gn)) != 0)
            gn = 1<<bit_width((uint)gn);
        tree.assign(gn,0);
        ft.resize(gn);
        lt.resize(gn);
        n = sz(arr);
        // a = arr;
        rep(i,n,2*n-1,1)
            ft[i] = lt[i] = arr[i-n];
        rep(i,n-1,1,-1){
            tree[i] = tree[i<<1] + tree[i<<1|1];
            ft[i] = ft[i<<1];
            lt[i] = lt[i<<1|1];
            if (lt[i<<1] < ft[i<<1|1]) tree[i]++;
        }
        // debug(n,arr,ft,lt,tree);
    }

    int query(int l, int r){
        int res = 0;
        for(l+=n,r+=n;l < r; l>>=1,r>>=1){
            if (l&1){
                res += tree[l];
                if (l+1 < r && lt[l] < ft[l+1]) res++;
                l++;
            }
            if (r&1){
                --r;
                res += tree[r];
                if (r > 1 && lt[r-1] < ft[r]) res++;
            }
        }
        return res;
    }
};

class segtree2{
private:
    int n;
    vector<int> tree;
public:
    segtree2(int gn){
        n = gn;
        gn*=2;
        if (gn - (gn&(-gn)) != 0)
            gn = 1<<bit_width((uint)gn);
        tree.assign(gn,-1);
    }

    void update(int ind, int val){
        for(tree[val+=n] = ind; val > 1 && tree[val>>1] == -1; val>>=1){
            tree[val>>1] = ind;
        }
    }

    int query(int l, int r){
        int res = -1;
        for (l+=n,r+=n; l < r; l>>=1,r>>=1){
            if (l&1){
                res = max(res,tree[l++]);
            }
            if (r&1)
                res = max(res,tree[--r]);
        }
        return res;
    }
};

// Attempt 3, incorrect, though can be fixed
void solve3(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    segtree st(a);
    segtree2 st2(n);
    segtree2 st3(n);
    int last = 0;
    rep(i,1,n-1,1){
        if (a[i] <= a[i-1]){
            // st3.update(i-1,a[i-1]);
            continue;
        }
        int ind = st2.query(a[i],n);
        debug(a,i,a[i],ind,last,endl);
        if (st2.query(1,n) != -1) last++;
        int ind2 = st3.query(a[i],n);
        int temp = INT_MAX;
        if (ind2 != -1){
            assert(ind2 > 0);
            temp = st.query(0,ind2) + st.query(ind2+1,i);
            if (ind2 < i-1 && a[ind2-1] < a[ind2+1]) temp++;
        }
        st2.update(i-1,a[i-1]);
        st3.update(i,a[i]);
        // int ind2 = st3.query(a[i],n);
        if (ind == -1) continue;
        assert(a[ind] >= a[i]);
        assert(ind+1 < i && a[ind+1] > a[ind]);
        last = min(last, st.query(0,ind+1) + st.query(ind+1,i));
        last = min(last,temp);
    }
    cout << last << endl;
}

// Attempt 4, AC: Greedy Approach
// Observation is king.... 
void solve4(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int x = INT_MAX, y = INT_MAX;
    int sol = 0;
    rep(i,n){
        if (x > y) swap(x,y);
        if (x >= a[i]) x = a[i];
        else if (y >= a[i]) y = a[i];
        else x = a[i], sol++;
    }
    cout << sol << endl;
}

// Attempt 5: DP, Segment Tree
void solve(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    
}


/*

5

1
5
1 2 3 4 5

1
8
8 2 3 1 1 7 4 3

5
3 3 3 3 3
1
1

1
2
2 1




3 3 3 3 8 9 3 3 8 3 3

3 3 3 3 8 9 3 3 8 3 3

*/