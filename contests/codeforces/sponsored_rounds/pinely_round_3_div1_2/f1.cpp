/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Dec 23 21:34:05 IST 2023
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

    type get_sum(size_t in1, size_t in2){
        return get_sum(in2) - get_sum(--in1);
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

const ll mod = 998244353ll;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    if (!is_sorted(all(a))) return void(cout << "0\n");
    vector<ll> nxt(n,-1), prev(n,-1);
    rep(i,n)
        if (a[i] > i+1)
            return void(cout << "0\n");
        else if (a[i] == i+1)
            nxt[i] = i;
    ll last = n-1;
    rep(i,n-2ll,0ll,-1){
        if (nxt[i] == i){
            last = i;
            continue;
        }
        nxt[i] = last;
    }
    last = -1;
    rep(i,n){
        prev[i] = last;
        if (nxt[i] == i) last = i;
    }
    debug(nxt,prev);
    fenwick_tree<ll> ft(n);
    vector<ll> pos(n);
    rep(i,n){
        ll low = prev[i]+1ll;
        ll high = nxt[i];
        if (low == high){
            pos[i] = 1ll;
            continue;
        }
        if ((i == 0 && a[i] == 0)||(a[i] == a[i-1])){
            low = max(low,i+1ll);
        }
        assert(low<=high);
        ll cur = ft.get_sum(low,high);
        pos[i] = high-low+1ll-cur;
        assert(pos[i] >= 1ll);
        ft.update(low,1ll,true);
    }
    debug(pos);
    ll sol = 1ll;
    rep(i,n){
        sol *= pos[i];
        sol %= mod;
    }
    cout << sol << endl;
}

/*

5

1
5
1 2 3 4 5

1
6
0 2 2 2 4 6

6
0 1 3 4 5 5
6
1 2 3 2 4 6
15
0 0 1 1 1 2 3 4 5 6 7 9 11 13 15


*/