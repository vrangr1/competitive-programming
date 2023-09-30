#if 0
    me=`basename $0 .cpp`
    rm -f $me $me.out
    g++ -std=c++20 -DLOCAL $me.cpp -o $me
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
#include <assert.h>
#define debug(...)
#ifdef LOCAL
    #undef debug
    #include <algo/debug.hpp>
    const bool DEBUG = false;
#else
    const bool DEBUG = false;
#endif

using namespace std;

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
typedef long long int ll;
typedef unsigned long long int ull;
void solve();

int main(){
	fastIO;
	TEST;
	return 0;
}

void pfac(ll num, unordered_map<ll,ll> &umap){
    ll fac = 2ll, count = 1ll;
    while(num%fac == 0ll){
        count++;
        num/=fac;
    }
    umap[fac]=count-1ll;
    repll(i,3ll,sqrt(num),2ll){
        count = 1ll;
        while(num%i == 0){
            count++;
            num/=i;
        }
        umap[i]=count-1ll;
        if (num == 1ll) break;
    }
    if (num>1ll) umap[num]++;
}

bool check(unordered_map<ll,ll> &npfac, unordered_map<ll,ll> &xpfac){
    unordered_map<ll,ll> dnpfac;
    ll dn = 1ll;
    for (auto &it : xpfac)
        npfac[it.first]+=it.second;
    for (auto &it : npfac)
        dn *= (it.second+1ll);
    pfac(dn,dnpfac);
    for (auto &it : dnpfac)
        if (npfac[it.first] < it.second) return false;
    return true;
}

void solve(){
    ll n, q; cin >> n >> q;
    unordered_map<ll,ll> npfac, tpfac, xpfac;
    pfac(n,npfac);
    tpfac.insert(all(npfac));
    while(q--){
        ll k, x;
        cin >> k;
        if (k == 2){
            tpfac.clear();
            tpfac.insert(all(npfac));
            continue;
        }
        cin >> x;
        xpfac.clear();
        pfac(x, xpfac);
        debug(tpfac, xpfac);
        if (check(tpfac, xpfac))
            cout << yes;
        else cout << no;
    }
    cout<<endl;
}