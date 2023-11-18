#if 0
    me=`basename $0 .cpp`
    rm -f $me $me.out
    only_compile=${1:-0}
    if [ $only_compile == compile ]; then
        g++ -std=c++20 $me.cpp -o $me -Wall -O2 -Wextra -Wno-sign-conversion -Wshadow -Wl,-stack_size -Wl,0x20000000
        exit
    fi
    if [ $only_compile == debug ]; then
        g++ -std=c++20 -DLOCAL $me.cpp -o $me -Wall -O2 -Wextra -Wno-sign-conversion -Wshadow -Wl,-stack_size -Wl,0x20000000
        exit
    fi
    g++ -std=c++20 -DLOCAL $me.cpp -o $me -Wall -O2 -Wextra -Wno-sign-conversion -Wshadow -Wl,-stack_size -Wl,0x20000000
    if test -f $me; then
	    ./$me > $me.out
        echo "\noutput begins now:"
        cat $me.out
    	rm $me $me.out
    fi
    exit
#endif
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
#define debug(...)
#ifdef LOCAL
    #undef debug
    #include <algo/debug.hpp>
    const bool DEBUG = true;
#endif

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0)
#define TEST int T;cin>>T;while(T--)solve();
#define TEST1 solve();
#define all(x) (x).begin(), (x).end()
#define sz(v) ((int)(v).size())
#define GET_MACRO(_1,_2,_3,_4,NAME,...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, forsn, qwe, forn)(__VA_ARGS__)
#define repll(...) GET_MACRO(__VA_ARGS__, forsnll, qwe, fornll)(__VA_ARGS__)
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define fornll(i, n) for (ll i = 0ll; i < (ll)n; i++)
#define forsn(i, st, end, d) for(int i = st; (d>0?i<=(int)end:i>=(int)end); i+=d)
#define forsnll(i, st, end, d) for(ll i = st; (d>0?i<=(ll)end:i>=(ll)end); i+=(ll)d)
#define qwe(r,t,y)
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

class segtree{
private:
    int segsz;
    vector<int> arr;

    void update(int ind){
        // debug(ind);
        assert(ind>= 0);
        assert(ind < (int)arr.size());
        assert(2*ind+1 < (int)arr.size());
        assert(2*ind+2 < (int)arr.size());
        arr[ind] = arr[2*ind+1] + arr[2*ind + 2];
        if (ind == (ind-1)/2) return;
        update((ind-1)/2);
    }

    int get_sum(int l, int r, int cl, int cr, int ind){
        if (ind >= (int)arr.size()) return 0;
        if (l <= cl && r >= cr) return arr[ind];
        if (l >= cr) return 0;
        if (r <= cl) return 0;
        return get_sum(l, r, cl, cr/2, 2*ind+1) + get_sum(l, r, cr/2, cr, 2*ind+2);
    }
public:
    segtree(int n){
        segsz = n;
        if (n - (n&(-n)) != 0)
            segsz = 1<<(32 - __builtin_clz(n));
        arr.assign(2*segsz-1,0);
    }

    void setval(int ind, int val = 1){
        ind += segsz-1;
        assert(ind < (int)arr.size());
        assert(ind >= 0);
        arr[ind] += val;
        // debug('s', ind);
        update((ind-1)/2);
    }

    int get(int val){
        return get_sum(0, val, 0, segsz, 0);
    }

    void dbg(){
        debug(arr);
    }
};

void solve1(){
    debug('h');
    int n; cin >> n;
    vector<int> p(n);
    rep(i,n){
        cin >> p[i];
        --p[i];
    }
    segtree values(n), indices(n);
    rep(i,n){
        values.setval(p[i]);
        if (values.get(p[i]) == 0){
            indices.setval(i);
            continue;
        }
        if (indices.get(i) == i) continue;
        indices.setval(i);
    }
    values.dbg();
    indices.dbg();
    cout << n - indices.get(n) << endl;
}

void solve(){
    int n; cin >> n;
    vector<int> p(n);
    rep(i,n){
        cin >> p[i];
        p[i]--;
    }
    int mn = INT_MAX, wmn = INT_MAX, wins = 0;
    rep(i,n){
        if (p[i] <= mn){
            mn = p[i];
            continue;
        }
        if (wmn <= p[i]) continue;
        wins++;
        wmn = min(wmn, p[i]);
    }
    cout << wins << endl;
}

/*

4

2
3
2 1 3
2
2 1

1
3
1 2 3

1
4
2 1 4 3



*/