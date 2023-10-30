#if 0
    me=`basename $0 .cpp`
    rm -f $me $me.out
    only_compile=${1:-0}
    if [ $only_compile == compile ]; then
        g++ -std=c++20 $me.cpp -o $me -Wall -O2 -Wextra -Wno-sign-conversion -Wshadow
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
#define GET_MACRO(_1,_2,_3,_4,NAME,...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, forsn, qwe, forn)(__VA_ARGS__)
#define repll(...) GET_MACRO(__VA_ARGS__, forsnll, qwe, fornll)(__VA_ARGS__)
#define qwe(r,t,y)
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define fornll(i, n) for (ll i = 0ll; i < (ll)n; i++)
#define forsn(i, st, end, d) for(int i = st; (d>0?i<=(int)end:i>=(int)end); i+=d)
#define forsnll(i, st, end, d) for(ll i = st; (d>0?i<=(ll)end:i>=(ll)end); i+=(ll)d)
#define all(x) (x).begin(), (x).end()
#define pass (void)0
#define space " "
#define yes "YES\n"
#define no "NO\n"
void solve();

typedef long double ld;

int main(){
	fastIO;
	TEST;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

class DSU{
public:
    vector<ld> parent, rank;
    unordered_map<ld,ld> sums, inds;

    DSU(ld n, const vector<ld> &a):parent(n,-1),rank(n,0){
        for (ld i = 0; i < n; ++i){
            inds[i] = i+1;
            sums[i+1] = a[i];
        }
    }

    ld find(ld x){
        assert(x < parent.size());
        if (parent[x] == -1) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(ld x, ld y){
        ld px = find(x), py = find(y);
        if (px == py) return;
        assert(inds.find(px) != inds.end());
        assert(inds.find(py) != inds.end());
        assert(sums.find(inds[px]) != sums.end());
        assert(sums.find(inds[py]) != sums.end());
        assert(px >= 0 && px < rank.size());
        assert(py >= 0 && py < rank.size());
        ld mnind = min(inds[px],inds[py]);
        ld sum = sums[inds[px]] + sums[inds[py]];
        if (rank[px] < rank[py]){
            rank[px] = rank[py];
            parent[px] = py;
            inds[py] = mnind;
            sums[inds[py]] = sum;
        }
        else if (rank[px] > rank[py]){
            rank[py] = rank[px];
            parent[py] = px;
            inds[px] = mnind;
            sums[inds[px]] = sum;
        }
        else{
            rank[px] = ++rank[py];
            parent[px] = py;
            inds[py] = mnind;
            sums[inds[py]] = sum;
        }
    }

    ld get_ind(ld x){
        return inds[x];
    }

    ld get_sum(ld x){
        return sums[inds[x]];
    }

    ld get_ratio(ld x){
        return sums[inds[x]]/inds[x];
    }
};

void solve(){
    ld n, c; cin >> n >> c;
    vector<ld> a(n);
    rep(i,n){
        cin >> a[i];
        a[i]/=c;
    }
    c=1;
    set<pair<ld,ld>> vals;
    DSU dsu(n,a);
    for(ld i = 1; i <= n; ++i){
        vals.insert(make_pair(a[i-1]/i,i-1));
    }
    // cout << "here\n";
    ld v1, v2, i1, i2;
    set<pair<ld,ld>>::reverse_iterator iter;
    debug(vals);
    while((int)vals.size() > 1){
        iter = vals.rbegin();
        v1 = iter->first;
        i1 = iter->second;
        ++iter;
        // assert(iter != vals.rend());
        v2 = iter->first;
        i2 = iter->second;
        // debug(v1,v2,i1,i2,dsu.get_ind())
        if ((v1 + v2) >= (c*dsu.get_ind(i1)*dsu.get_ind(i2))){
            dsu.unite(i1,i2);
            vals.erase(make_pair(v1,i1));
            vals.erase(make_pair(v2,i2));
            i1 = dsu.find(i1);
            // vals.insert(make_pair(dsu.get_ratio(i1),i1));
            
        }
        else break;
    }
    debug(vals);
    if (vals.size() == 1) cout << yes;
    else cout << no;
}