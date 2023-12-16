/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Dec 16 20:28:15 IST 2023
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

// END OF SNIPPETS

int main(){
	fastIO;
	TEST;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    deque<pair<char,bool>> dq;
    int ind = (int)(max_element(all(s)) - s.begin());
    string rest = s.substr(0,ind);
    if (!is_sorted(all(rest))) return void(cout << "-1\n");
    vector<int> inds;
    string maxstr;
    rep(i,n){
        if (inds.empty()){
            inds.push_back(i);
            maxstr.push_back(s[i]);
            continue;
        }
        while(!inds.empty() && s[inds.back()] < s[i]){
            inds.pop_back();
            maxstr.pop_back();
        }
        inds.push_back(i);
        maxstr.push_back(s[i]);
    }
    rep(i,sz(inds)){
        if (dq.empty()){
            assert(i == 0);
            // dq.emplace_back(s[inds[i]],true);
            dq.push_back(make_pair(s[inds[i]],true));
            continue;
        }
        rep(j,inds[i-1]+1,inds[i]-1,1)
            dq.push_back(make_pair(s[j],false));
        dq.push_back(make_pair(s[inds[i]],true));
    }
    debug(dq);
    auto get_sz = [](string &rem) -> ll {
        if (rem.empty()) return 0ll;
        ll cur = 0ll;
        while(rem.front() != rem.back()){
            cur++;
            rem.pop_back();
        }
        return cur;
    };
    // string popped;
    ll ct = 0;
    while(!dq.empty()){
        if (dq.back().second) dq.back().first = maxstr.back();
        debug(dq,rest,maxstr);
        assert(dq.front().second);
        if (dq.back().first == dq.front().first){
            while(!dq.empty()){
                if (!dq.back().second) return void(cout << "-1\n");
                dq.pop_back();
            }
            cout << ct + get_sz(maxstr) << endl;
            return;
        }
        ct++;
        if (rest.empty()){
            rest.push_back(dq.back().first);
            if (dq.back().second){
                dq.pop_back();
                maxstr.pop_back();
            }
            assert(!dq.empty());
            dq.pop_front();
        }
        else{
            if (rest.back() > dq.back().first) return void(cout << "-1\n");
            if (dq.back().second){
                dq.pop_back();
                maxstr.pop_back();
            }
            assert(!dq.empty());
            dq.pop_front();
        }
        if (dq.empty()){
            ct += get_sz(maxstr);
            return void(cout << ct << endl);
        }
        while(!dq.empty() && !dq.front().second){
            if (rest.back() > dq.front().first) return void(cout << "-1\n");
            rest.push_back(dq.front().first);
            dq.pop_front();
        }
    }
    cout << ct + get_sz(maxstr) << endl;

    // while(!dq.empty()){
    //     if (maxstr.front() == maxstr.back()) return void(cout << ct << endl);
    //     ct++;
    //     assert(dq.front().second);
    //     if (dq.back().second) dq.back().first = maxstr.back();
    //     if (rest.empty()){
    //         rest.push_back(dq.back().first);
    //         dq.pop_back();
    //         maxstr.pop_back();
    //         if (dq.empty()){
    //             // ct--;
    //             break;
    //         }
    //         // char save = dq.front().first;
    //         dq.pop_front();
    //         while(!dq.empty() && !dq.front().second){
    //             if (rest.back() > dq.front().first) return void(cout << "-1a\n");
    //             rest.push_back(dq.front().first);
    //             dq.pop_front();
    //         }
    //         if(dq.empty()) break;
    //         if(!dq.back().second){
    //             maxstr.push_back(dq.back().first);
    //         }
    //         continue;
    //     }
    //     debug('n',dq);
    //     if (rest.back() > dq.back().first) return void(cout << "-1b\n");
    //     rest.push_back(dq.back().first);
    //     dq.pop_back();
    //     maxstr.pop_back();
    //     if (dq.empty()){
    //         // ct--;
    //         break;
    //     }
    //     // char save = dq.front().first;
    //     dq.pop_front();
    //     while(!dq.empty() && !dq.front().second){
    //         if (rest.back() > dq.front().first) return void(cout << "-1c\n");
    //         rest.push_back(dq.front().first);
    //         dq.pop_front();
    //     }
    //     if (dq.empty()) break;
    //     if(!dq.back().second){
    //         maxstr.push_back(dq.back().first);
    //     }
    //     // dq.emplace_front(save,true);
    //     // if (popped.empty() || popped.back() != save) popped.push_back(save);
    // }
    // cout << ct + get_sz(maxstr) << endl;
}

/*

1
3
acb

1
4
zbca

1
15
czddeneeeemigec


*/