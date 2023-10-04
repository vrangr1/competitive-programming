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
    const bool DEBUG = true;
#else
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

const ll HPRIME = (1ll<<30ll)+1ll;

inline ll get_hash(ll a, ll b){
    return a*HPRIME + b;
}

// inline void insert_or_skip(ll a, ll b, unordered_map<ll,bool> &vis, queue<pair<ll,ll>> &q){
inline void insert_or_skip(ll a, ll b, unordered_set<ll> &vis, queue<pair<ll,ll>> &q){
    ll hh = get_hash(a,b);
    if (vis.find(hh) == vis.end()){
    // if(!vis[hh]){
        vis.insert(hh);
        // vis[hh] = true;
        q.push(make_pair(a,b));
    }
}

inline bool check_match(ll a, ll b, ll c, ll d){
    return (a==c) && (b==d);
}

bool check_exclusive(ll num, const ll oa, const ll ob, const ll target){
    ll bit;
    ll decide = -1;
    for(;num > 0; num -= (num&(-num))){
        bit = (num&(-num));
        if ((num&bit) == 0) continue;
        if ((oa&bit) > 0 || (ob&bit) > 0) continue;
        if (decide == -1){
            decide = ((target&bit) > 0);
            continue;
        }
        if (decide != ((target&bit)>0)) return true;
    }
    return false;
}

bool check_exclusive(ll num, const ll target){
    ll bit;
    ll decide = -1;
    for(;num > 0; num -= (num&(-num))){
        bit = (num&(-num));
        if ((num&bit) == 0) continue;
        if (decide == -1){
            decide = ((target&bit) > 0);
            continue;
        }
        if (decide != ((target&bit)>0)) return true;
    }
    return false;
}

bool precheck(const ll a, const ll b, const ll c, const ll d, const ll m){
    ll tc = c, td = d, bit;
    while(tc > 0){
        bit = (tc&(-tc));
        if ((a&bit) == 0 && (b&bit) == 0 && (m&bit) == 0) return true;
        tc -= bit;
    }
    while(td > 0){
        bit = (td&(-td));
        if ((a&bit) == 0 && (b&bit) == 0 && (m&bit) == 0) return true;
        td -= bit;
    }
    if (check_exclusive(a, b, m, c)) return true;
    if (check_exclusive(b, a, m, c)) return true;
    if (check_exclusive(m, b, a, c)) return true;
    if (check_exclusive(a, b, m, d)) return true;
    if (check_exclusive(b, a, m, d)) return true;
    if (check_exclusive(m, b, a, d)) return true;
    if (check_exclusive((a&b&m), c)) return true;
    if (check_exclusive((a&b&m), d)) return true;
    if (check_exclusive((a&b)&((a&b)^m), c)) return true;
    if (check_exclusive((m&b)&((m&b)^a), c)) return true;
    if (check_exclusive((a&m)&((a&m)^b), c)) return true;
    if (check_exclusive((a&b)&((a&b)^m), d)) return true;
    if (check_exclusive((m&b)&((m&b)^a), d)) return true;
    if (check_exclusive((a&m)&((a&m)^b), d)) return true;
    return false;
}

void solve(){
    ll a, b, c, d, m; cin >> a >> b >> c >> d >> m;
    if (check_match(a,b,c,d)) return void(cout << "0\n");
    if (precheck(a,b,c,d,m)) return void(cout << "-1\n");
    // unordered_map<ll,bool> vis;
    unordered_set<ll> vis;
    queue<pair<ll,ll>> q;
    q.push(make_pair(a,b));
    vis.insert(get_hash(a,b));
    // vis[get_hash(a,b)]=true;
    pair<ll,ll> cur;
    ll ca, cb, cc, cd, hh;
    int dist = 0, len;
    ll count = 0;
    while(q.size()){
        len = q.size();
        dist++;
        rep(i,len){
            cur = q.front();
            q.pop();
            ca = cur.first;
            cb = cur.second;
            // debug(ca, cb,dist);
            count++;
            if (count > 16384ll) break;
            // if (dist > 3) break;
            cc = (ca|cb);
            cd = cb;
            if (check_match(cc,cd,c,d)) return void(cout << dist << endl);
            insert_or_skip(cc ,cd, vis, q);
            
            cc = (ca&cb);
            cd = cb;
            if (check_match(cc,cd,c,d)) return void(cout << dist << endl);
            insert_or_skip(cc, cd, vis, q);

            cc = ca;
            cd = ca^cb;
            if (check_match(cc,cd,c,d)) return void(cout << dist << endl);
            insert_or_skip(cc, cd, vis, q);

            cc = ca;
            cd = cb^m;
            if (check_match(cc,cd,c,d)) return void(cout << dist << endl);
            insert_or_skip(cc, cd, vis, q);
        }
        if (count > 16384ll) break;
    }
    cout << "-1\n";
}


// 1
// 1 6 0 7 1

/*

11
54108139 513508182 0 0 516490787
678878676 252558896 0 10 348495665
888801156 175664702 16781376 0 979881357
141434083 967576761 33645060 33645060 745575833
935021940 937715891 0 0 192077657
956993884 680722197 0 106954880 787624092
435499220 560029393 0 101351722 636723995
354966359 189151475 545325064 1082368 37277364
121776023 225796688 813694984 814258216 189332788
1042269640 462507557 0 6303762 896056471
92946584 666049497 134258688 0 681224705

*/