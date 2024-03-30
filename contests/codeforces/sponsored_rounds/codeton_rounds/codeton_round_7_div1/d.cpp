/***************************************************
* AUTHOR : Anav Prasad
* Nick   : vrangr
****************************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <ctype.h>
#include <unordered_set>
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
#include <unordered_map>
#include <bit>
#include <bitset>
#include <random>
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
#define pass (void)0
template<typename type>inline void print_vec(const vector<type> &v){rep(i,sz(v))cout<<v[i]<<" \n"[i==sz(v)-1];}
void solve();

int main(){
	fastIO;
	TEST;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

class ftree{
private:
    vector<int> tree;
    vector<int> arr;
    int n;

    bool bsch(int low, int high, const int req){
        if (low > high) return false;
        if (low == high) return getsum(low) == req;
        int mid = (low+high+1)/2, val = getsum(mid);
        if (val == req) return true;
        if (val < req) return bsch(mid,high,req);
        return bsch(low,mid-1,req);
    }

    int getsum(int i){
        i++;
        int sum = 0;
        while(i > 0){
            assert(i < sz(tree));
            sum += tree[i];
            i -= (i&(-i));
        }
        return sum;
    }
public:
    ftree(const vector<int> &a){
        arr.assign(sz(a),0);
        n = sz(a)+1;
        tree.assign(n,0);
        --n;
        rep(i,n)
            update(i,a[i]);
    }

    void update(int i, int v){
        v -= arr[i];
        if (v == 0) return;
        arr[i]+=v;
        ++i;
        while(i <= n){
            tree[i] += v;
            i += (i&(-i));
        }
    }

    bool query(int s){
        rep(i,n-1,0,-1){
            int cur = getsum(i);
            if (cur == s) return true;
            if (cur < s) break;
            if (bsch(0,i-1,cur-s)) return true;
        }
        return false;
    }
};

class segtree{
private:
    vector<int> tree;
    int n;

    int query(int l, int r){
        int res = 0;
        for (l+=n,r+=n; l < r; l>>=1,r>>=1){
            if (l&1) res += tree[l++];
            if (r&1) res += tree[--r];
        }
        return res;
    }

    bool bsch(int low, int high, const int req){
        if (low > high) return false;
        else if (low == high) return query(0ll,low+1) == req;
        int mid = (low+high+1)/2, val = query(0,mid+1);
        if (val == req) return true;
        else if (val < req) return bsch(mid, high, req);
        return bsch(low,mid-1,req);
    }

public:
    segtree(const vector<int> &a){
        n = sz(a);
        n*=2;
        if (n - (n&(-n)) != 0)
            n = 1<<bit_width((uint)n);
        tree.assign(n,0);
        n = sz(a);
        rep(i,n,2*n-1,1)
            tree[i] = a[i-n];
        rep(i,n-1,1,-1)
            tree[i] = tree[i<<1]+tree[i<<1|1];
    }

    void update(int i, int v){
        for (tree[i+=n]=v; i > 0; i>>=1)
            tree[i>>1] = tree[i] + tree[i^1];
    }

    bool query(int s){
        rep(i,n-1,0,-1){
            int cur = query(0,i+1);
            if (cur == s) return true;
            else if (cur < s) break;
            else if (bsch(0,i,cur-s)) return true;
        }
        return false;
    }
};

// Fenwick/Segment Tree solution = O(nq*log^2(n))
void solve1(){
    int n, q; cin >> n >> q;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    // segtree st(a);
    ftree st(a);
    rep(Q,q){
        int op; cin >> op;
        if (op == 1){
            int s; cin >> s;
            if (st.query(s)) cout << yes;
            else cout << no;
        }
        else{
            int i, v; cin >> i >> v; --i;
            st.update(i,v);
        }
    }
}

// tourist's solution
// OBSERVATION!!!!! Any sum smaller or equal to the sum of the entire array of the same parity as the original sum can 
// always be obtained as a sum of a subarray!!!!!
// Curiosly, as it turns out, this method takes way more memory than even a segment tree. Strange. Didn't know set was 
// that memory consuming. Makes sense, considering a RB tree.
void solve(){
    int n, q; cin >> n >> q;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int total = accumulate(all(a),0);
    set<int> ones;
    rep(i,n) if (a[i] == 1) ones.insert(i);
    auto query = [&](const int s) -> bool {
        if (s > total) return false;
        if (s%2 == total%2) return true;
        if (sz(ones) == 0) return false;
        int ct = min(*ones.begin(),n-1-*ones.rbegin());
        if (total-ct*2 < s) return false;
        return true;
    };
    while(q--){
        int op; cin >> op;
        if (op == 1){
            int s; cin >> s;
            if (query(s)) cout << yes;
            else cout << no;
        }
        else{
            int i, v; cin >> i >> v; --i;
            if (a[i] == v) continue;
            total += v-a[i];
            if (a[i] == 1) ones.erase(i);
            else ones.insert(i);
            a[i] = v;
        }
    }
}