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

int main(){
	fastIO;
	TEST1;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

int get_sum(const string &s, int st, int end){
    if (st < 0 || end >= (int)s.size() || st > end) return 0;
    int sum = 0;
    rep(i,st,end,1)
        sum += (int)(s[i]-'0');
    return sum;
}

void solve(){
    int n; cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    sort(all(s),[](const string &a, const string &b){
        return a.size() < b.size();
    });
    vector<unordered_map<int,ll>> cts(6);
    ll ct = 0, hf, st, fhalf, lhalf;
    rep(i,n){
        st = min((s[i].size()%2?5:4),(int)s[i].size());
        debug(i,s[i],st,endl);
        rep(len,st,1,-2){
            hf = (len+(ll)(s[i].size()))/2ll;
            assert(hf < 6);
            assert(hf <= (ll)s[i].size());
            lhalf = get_sum(s[i], s[i].size()-hf, s[i].size()-1);
            fhalf = get_sum(s[i], 0, s[i].size()-hf-1);
            debug(len,hf,lhalf,fhalf);
            if (fhalf < lhalf){
                debug(cts[len][lhalf-fhalf],ct);
                ct += cts[len][lhalf-fhalf];
            }
            fhalf = get_sum(s[i],0,hf-1);
            lhalf = get_sum(s[i],hf,s[i].size()-1);
            if (fhalf > lhalf){
                ct += cts[len][fhalf-lhalf];
            }
            debug(ct,endl);
        }
        cts[s[i].size()][get_sum(s[i],0,s[i].size()-1)]++;
        ct++;
        debug(ct,endl);
    }
    cout << ct << endl;
}