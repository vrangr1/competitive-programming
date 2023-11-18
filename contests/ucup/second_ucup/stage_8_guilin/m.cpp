#if 0
    me=`basename $0 .cpp`
    rm -f $me $me.out
    only_compile=${1:-0}
    if [ $only_compile == compile ]; then
        g++ -std=c++20 $me.cpp -o $me -Wall -O2 -Wextra -Wno-sign-conversion -Wshadow
        exit
    fi
    if [ $only_compile == debug ]; then
        g++ -std=c++20 -DLOCAL $me.cpp -o $me -Wall -O2 -Wextra -Wno-sign-conversion -Wshadow
        exit
    fi
    g++ -std=c++20 -DLOCAL $me.cpp -o $me -Wall -O2 -Wextra -Wno-sign-conversion -Wshadow
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
	TEST1;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

void insert_stabilize(int val, multiset<int> &fhf, multiset<int> &lhf, const size_t fhfsz, const size_t n){
    if (fhf.empty() && lhf.empty())
        fhf.insert(val);
    else if (fhf.empty()){
        if (*lhf.begin() < val)
            lhf.insert(val);
        else fhf.insert(val);
    }
    else if (lhf.empty())
        fhf.insert(val);
    else{
        if (val <= *lhf.begin())
            fhf.insert(val);
        else lhf.insert(val);
    }
    if (fhf.size() < fhfsz){
        assert(!lhf.empty());
        fhf.insert(*lhf.begin());
        lhf.erase(lhf.begin());
    }
    else if (fhf.size() > fhfsz){
        lhf.insert(*fhf.rbegin());
        fhf.erase(prev(fhf.end()));
    }
    assert(fhf.size() == fhfsz);
    assert(fhf.size() + lhf.size() == n);
}

int get_median(const vector<int> &a, const vector<int> &b, const size_t n, const size_t fhfsz, multiset<int> &fhf, multiset<int> &lhf, int ind = -1){
    if (ind == -1){
        assert(fhf.empty());
        assert(lhf.empty());
        rep(i,n){
            fhf.insert(a[i]);
            if (fhf.size() > fhfsz){
                lhf.insert(*fhf.rbegin());
                fhf.erase(prev(fhf.end()));
            }
        }
        assert(fhf.size() + lhf.size() == n);
        assert(fhf.size() == fhfsz);
        return *fhf.rbegin();
    }
    int curmed = *fhf.rbegin();
    // debug(a[ind],ind,curmed);
    if (a[ind] <= curmed)
        fhf.erase(fhf.find(a[ind]));
    else lhf.erase(lhf.find(a[ind]));
    // debug(fhf,lhf);
    insert_stabilize(b[ind], fhf, lhf, fhfsz, n);
    return *fhf.rbegin();
}

void revert(const vector<int> &a, const vector<int> &b, const size_t n, const size_t fhfsz, multiset<int> &fhf, multiset<int> &lhf, int ind){
    int curmed = *fhf.rbegin();
    if (b[ind] <= curmed) fhf.erase(fhf.find(b[ind]));
    else lhf.erase(lhf.find(b[ind]));
    insert_stabilize(a[ind], fhf, lhf, fhfsz, n);
}

void solve(){
    int n; cin >> n;
    vector<int> a(n),b(n);
    rep(i,n) cin >> a[i] >> b[i];
    // debug('h');
    multiset<int> fhf, lhf;
    const size_t fhfsz = (n+1)/2;
    int med, maxmed;
    maxmed = med = get_median(a, b, n, fhfsz, fhf, lhf);
    // int ogmed = med;
    debug(a,b,n,med);
    int cl = -1, cr = -1, ct = 0;
    rep(i,n){
        debug(i,cl,cr,med,maxmed,fhf,lhf,ct,endl);
        if (cl != -1){
            if (a[i] == b[i]) pass;
            else if (a[i] > b[i]) ct--;
            // else if (a[i] <= med && b[i] >= med){
            //     ct++;
            // }
            else ct++;
            if (ct <= 0){
                rep(j,cl,cr,1)
                    revert(a,b,n,fhfsz,fhf,lhf,j);
                cl = cr = -1;
                ct = 0;
                debug(med,maxmed,ct,fhf,lhf,endl,endl);
                continue;
            }
            cr = i;
            med = get_median(a, b, n, fhfsz, fhf, lhf, cr);
            // if (med < ogmed){
            //     rep(j,cl,cr,1)
            //         revert(a, b, n, fhfsz, fhf, lhf, j);
            //     cl = cr = -1;
            //     continue;
            // }
            maxmed = max(maxmed, med);
            debug(med,maxmed,ct,fhf,lhf,endl,endl);
            continue;
        }
        else if (b[i] <= a[i]) continue;
        cl = i;
        cr = i;
        ct = 1;
        med = get_median(a, b, n, fhfsz, fhf, lhf, cr);
        // debug(lhf,fhf);
        maxmed = max(maxmed, med);
        debug(med,maxmed,ct,fhf,lhf,endl,endl);
    }
    cout << maxmed << endl;
}

/*

5
3 6
5 2
4 7
6 4
2 8

6

a: [ 3 5 4 6 2 ]
b: [ 6 2 7 4 8 ]

5

2 2   4   6 6


3
3 4
6 3
2 8

6

a: [3 6 2]
b: [4 3 8]

2 3 6

3


5
9 9
4 1
4 6
7 6
1 8

7

a: [ 9 4 4 7 1 ]
b: [ 9 1 6 6 8 ]

1 4 4 7 9
8 1 6 6 9

8 1 4 7 9

1 4 7 8 9


5
1 2
8 6
1 7
1 4
8 3

7

a: [ 1 8 1 1 8 ]
b: [ 2 6 7 4 3 ]

1 1 1 8 8
2 4 7 3 6

2 1 7 8 6


*/