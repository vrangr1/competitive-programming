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
#define forn(i, n) for (int i = 0; i < n; i++)
#define fornll(i, n) for (ll i = 0ll; i < n; i++)
#define forsn(i, st, end, d) for(int i = st; (d>0?i<=end:i>=end); i+=d)
#define forsnll(i, st, end, d) for(ll i = st; (d>0?i<=end:i>=end); i+=(ll)d)
#define all(x) (x).begin(), (x).end()
#define pass (void)0
#define space " "
#define yes "YES\n"
#define no "NO\n"
void solve(int T);

int main(){
	fastIO;
	int T;cin>>T;
    rep(t,T)solve(t+1);
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

void solve(int T){
    cout << "Case #" << T << ": ";
    ll n; cin >> n;
    vector<ll> a(2ll*n);
    rep(i,2*n) cin >> a[i];
    ll tn = 2ll*n, hn = n/2ll;
    ll cur_ind, match_ind, rev_ind;
    unordered_map<ll,ll> counts1, counts2;
    rep(i,n)
        counts1[a[i]]++;
    rep(i,n,tn-1ll,1)
        counts2[a[i]]++;
    repll(i,tn){
        if (i != 0ll){
            counts1[a[i-1]]--;
            if (counts1[a[i-1]] == 0) counts1.erase(a[i-1]);
            counts1[a[(i+n)%tn]]++;
            counts2[a[(i+n)%tn]]--;
            if (counts2[a[(i+n)%tn]] == 0) counts2.erase(a[(i+n)%tn]);
            counts2[a[i-1]]++;
            if (counts1.size() != counts2.size()) continue;
        }
        bool found = true;
        repll(j,hn){
            cur_ind = (i+j)%tn;
            match_ind = ((i-j-1ll)+tn)%(tn);
            rev_ind = (((i+n-1)%tn)-j+tn)%tn;
            rev_ind = (rev_ind+tn)%tn;
            // if (rev_ind < 0 || rev_ind >= tn){
            //     debug(rev_ind);
            // }
            // assert(cur_ind >= 0 && cur_ind < tn);
            // assert(match_ind >= 0 && match_ind < tn);
            // assert(rev_ind >= 0 && rev_ind < tn);
            if (a[cur_ind] != a[match_ind] || a[cur_ind] >= a[rev_ind]){
                found = false;
                break;
            }
        }
        if(!found) continue;
        if (n%2 == 1){
            cur_ind = (i+hn)%tn;
            match_ind = ((i-hn-1+tn)%tn);
            // assert(cur_ind >= 0 && cur_ind < tn);
            // assert(match_ind >= 0 && match_ind < tn);
            if (a[cur_ind] != a[match_ind]) continue;
        }
        return void(cout << i << endl);
    }
    cout << "-1\n";
}