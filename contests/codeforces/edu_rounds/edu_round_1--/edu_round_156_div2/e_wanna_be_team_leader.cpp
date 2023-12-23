#if 0
    me=`basename $0 .cpp`
    rm -f $me $me.out
    only_compile=${1:-0}
    if [ $only_compile == compile ]; then
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
	TEST1;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}


bool process(int tid, double task, vector<vector<int>> &assigns, set<pair<int,int>> &rem){
    if (rem.size() == 0) return false;
    debug(tid, task, rem);
    set<pair<int,int>>::iterator iter, ft;
    iter = rem.lower_bound(make_pair(task,-1));
    debug(iter==rem.end());
    if (iter != rem.end()){
        assigns[tid].push_back(iter->second);
        rem.erase(iter);
        return true;
    }
    ft = iter;
    iter = prev(iter);
    // set<pair<int,int>>::iterator high = iter;
    double ct = 1;
    double mn = iter->first;
    bool found = false;
    while(true){
        debug(mn,ct);
        if (task/ct <= mn){
            found = true;
            break;
        }
        if (iter == rem.begin()) break;
        ct += 1.0;
        iter = prev(iter);
        mn = iter->first;
    }
    if (!found){
        if (ft == rem.end()) return false;
        assigns[tid].push_back(ft->second);
        rem.erase(ft);
        return true;
    }
    debug(ct,*iter,rem);
    while(iter != rem.begin() && task/ct <= iter->first)
        iter--;
    debug(task/ct, *iter);
    if (task/ct > iter->first) iter = next(iter);
    ft = iter;
    rep(_,ct){
        assert(iter!=rem.end());
        assigns[tid].push_back(iter->second);
        iter = next(iter);
    }
    rem.erase(ft,iter);
    return true;
}

void solve1(){
    double n, m; cin >> n >> m;
    vector<double> a(n), b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    // return;
    vector<int> ordera(n), orderb(m);
    // iota(all(ordera), 0);
    iota(all(orderb),0);
    // sort(all(ordera), [&a](const int &i, const int &j){
    //     return a[i] < a[j];
    // });
    sort(all(orderb), [&b](const int &i, const int &j){
        return b[i] < b[j];
    });
    // int ind = 0;
    // double ct = 0, val;
    vector<vector<int>> assigns(m);
    // auto comp = [](const pair<int,int> &a, const pair<int,int> &b){
    //     if (a.first != b.first) return a.first < b.first;
    //     return a.second < b.second;
    // };
    // set<pair<int,int>, decltype(comp)> p(comp);
    // debug(a,b);
    set<pair<int,int>> p;
    rep(i,n)
        p.insert(make_pair(a[i],i));
    debug(p);
    for (int i = m-1; i >= 0; --i){
        debug(i);
        if (!process(orderb[i], b[orderb[i]], assigns, p))
            return void(cout << no);
        // if (ind == n) return void(cout << no);
        // ct = 1.0;
        // val = a[ordera[ind]];
        // assigns[orderb[i]].push_back(ordera[ind]);
        // ind++;
        // while(ind < n && b[orderb[i]]/ct > val){
        //     ct += 1.0;
        //     assigns[orderb[i]].push_back(ordera[ind]);
        //     ind++;
        // }
        // if (b[orderb[i]]/ct > val) return void(cout << no);
    }
    cout << yes;
    // while(!p.empty()){
    //     assigns[0].push_back(p.begin()->second);
    //     p.erase(p.begin());
    // }
    rep(i,m){
        cout << assigns[i].size() << " ";
        rep(j,(int)assigns[i].size())
            cout << assigns[i][j]+1 << " \n"[j == (int)assigns[i].size()-1];
    }
}


void solve(){
    double n, m; cin >> n >> m;
    vector<double> prog(n), b(m);
    rep(i,n) cin >> prog[i];
    rep(i,m) cin >> b[i];
    vector<vector<int>> assigns(m);
    vector<int> progord(n), bord(m);
    iota(all(progord),0);
    iota(all(bord),0);
    sort(all(progord),[&prog](const int &i, const int &j){
        return prog[i] < prog[j];
    });
    sort(all(bord),[&b](const int &i, const int &j){
        return b[i] < b[j];
    });
    double last = 0ll, sum = 0ll;
    vector<int> indices;
    set<pair<int,int>> tasks;
    rep(i,m)
        tasks.insert(make_pair(b[i],i));
    set<pair<int,int>>::iterator iter;
    debug(tasks);
    rep(i,n){
        debug(i);
        if (last == 0ll) last = prog[progord[i]];
        sum += last;
        debug(sum);
        indices.push_back(progord[i]);
        iter = tasks.lower_bound(make_pair(sum,-1));
        
        // if (iter != tasks.end()) debug(*iter);
        if (iter == tasks.end()) iter--;
        while(iter != tasks.begin() && iter->first > sum)
            iter--;
        if (iter == tasks.begin() && iter->first > sum) continue;
        // if (iter == tasks.end()) return void(cout << no);
        // debug(*iter, sum);
        // iter--;
        
        debug(*iter);
        debug(sum);
        assigns[iter->second].insert(assigns[iter->second].end(), all(indices));
        indices.clear();
        last = 0ll;
        sum = 0ll;
        tasks.erase(iter);
    }
    if (tasks.size()){
        debug(tasks, assigns);
        return void(cout << no);
    }
    cout << yes;
    rep(i,m){
        cout << assigns[i].size() << " ";
        rep(j,(int)assigns[i].size())
            cout << assigns[i][j]+1 << " \n"[j == (int)assigns[i].size()-1];
    }
}