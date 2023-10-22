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
    const bool DEBUG = false;
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
void solve();

int main(){
	fastIO;
	TEST;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

string get_bstr(ll num){
    string str = bitset<64>(num).to_string();
    str = str.substr(__builtin_clzll(num));
    return str.substr(0,str.size()-__builtin_ctzll(num));
}

ll get_hpower(ll num, ll lshifts){
    return 64-__builtin_clzll(num)+lshifts;
}

void balance(string &prev, string &cur){
    if (prev.size() == cur.size()) return;
    while(prev.size() < cur.size()) prev.push_back('0');
    while(prev.size() > cur.size()) cur.push_back('0');
}

void solve(){
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll last = 0;
    ll ops = 0;
    string prev, cur;
    rep(i,1,n-1,1){
        if (last == 0 && a[i] >= a[i-1]) continue;
        // if (a[i] >= a[i-1]){
        //     ll p = get_hpower(a[i-1],last), c = get_hpower(a[i],0);

        // }

        if (last == 0){
            prev = get_bstr(a[i-1]);
            cur = get_bstr(a[i]);
            balance(prev,cur);
            ll pnum = stoi(prev,0,2);
            ll cnum = stoi(cur,0,2);
            ll p = get_hpower(a[i-1],0), c = get_hpower(a[i],0);
            if (pnum != cnum){
                if (pnum < cnum){
                    assert(c < p);
                    ops += p-c;
                    last = p-c;
                    continue;
                }
                assert(pnum > cnum);
                assert(p>=c);
                ops += p+1-c;
                last = p+1-c;
                continue;
            }
            assert(pnum == cnum);
            assert(p>c);
            ops += p-c;
            last = p-c;
            continue;
        }
        prev = get_bstr(a[i-1]);
        cur = get_bstr(a[i]);
        balance(prev,cur);
        ll pnum = stoi(prev,0,2);
        ll cnum = stoi(cur,0,2);
        ll p = get_hpower(a[i-1],last), c = get_hpower(a[i],0);
        debug(last,a[i],a[i-1],pnum,cnum,p,c);
        if (pnum <= cnum){
            if (c >= p){
                assert(a[i] >= a[i-1]);
                last = 0;
                continue;
            }
            assert(c<p);
            ops += p-c;
            last = p-c;
            continue;
        }
        assert(pnum > cnum);
        if (p < c){
            assert(a[i] >= a[i-1]);
            last = 0;
            continue;
        }
        assert(p>=c);
        ops += p+1-c;
        last = p+1-c;
        continue;
    }
    cout << ops << endl;
}

/*

1
6
1 8 2 16 8 16
*/