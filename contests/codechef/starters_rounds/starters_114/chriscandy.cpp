/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed Dec 27 20:00:59 IST 2023
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
#ifndef FENWICK_TREE_SNIPPET
#define FENWICK_TREE_SNIPPET
#include <iostream>
#include <vector>
#include <assert.h>
template <typename type>
class fenwick_tree{
private:
    size_t n;
    std::vector<type> arr, psum;
    
    size_t get_lsetbit(int val){
        return val&(-val);
    }
public:
    fenwick_tree(int n){
        this->n = n;
        this->arr.assign(n,0);
        this->psum.assign(n+1,0);
    }
    
    void update(size_t index, type val, bool by_increment = false){
        assert(index < this->n);
        if (!by_increment)
            val -= this->arr[index];
        arr[index] += val;
        index++;
        while(index <= n){
            this->psum[index] += val;
            index += get_lsetbit(index);
        }
    }

    fenwick_tree(const std::vector<type> &arr){
        static_assert(std::is_arithmetic<type>::value,
            "Fenwick Tree type must be an arithmetic type");
        this->n = arr.size();
        this->arr.resize(arr.size());
        this->psum.assign(arr.size()+1, static_cast<type>(0));
        for(size_t i = 0; i < this->n; ++i)
            this->update(i, arr[i]);
    }

    size_t size(){
        return this->n;
    }

    type get_sum(size_t index){
        type sum = 0;
        index++;
        while (index > ((size_t)0)){
            sum += this->psum[index];
            index -= get_lsetbit(index);
        }
        return sum;
    }
};
#endif
// END OF SNIPPETS

int main(){
	fastIO;
	TEST;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}


class fentree{
private:
    int n;
    vector<int> tree;

    int query(int ind){
        int res = 0;
        for(; ind > 0; ind -= (ind & (-ind)))
            res += tree[ind];
        return res;
    }
public:
    fentree(int gn){
        n = gn;
        gn++;
        tree.assign(gn,0);
    };

    void update(int ind){
        for(;ind <= n; ind += (ind&(-ind)))
            tree[ind]++;
    }

    int query(int l, int r){
        r = min(r,n);
        if (l > r) return 0;
        return query(r)-query(l-1);
    }
};

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int ct = 0;
    fentree st(n);
    rep(i,n){
        if (st.query(a[i]+1,n) > 0) ct++;
        st.update(a[i]);
    }
    cout << ct << endl;
}