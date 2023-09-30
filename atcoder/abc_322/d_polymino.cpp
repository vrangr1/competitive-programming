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
#define yes "Yes\n"
#define no "No\n"
void solve();

int main(){
	fastIO;
	TEST1;
	return 0;
}

// bool fill(const vector<vector<pair<int,int>>> &polys, vector<vector<bool>> &covered, int si, int sj, int ind){
//     assert(!covered[si][sj]);
//     vector<vector<bool>> og = covered;
//     int x, y;
//     rep(i,polys[ind].size()){
//         x = si+polys[ind][i].first;
//         y = sj+polys[ind][i].second;
//         if (x < 0 || x >= 4 || y < 0 || y >= 4){
//             covered = og;
//             return false;
//         }
//         if (covered[x][y]){
//             covered = og;
//             return false;
//         }
//         covered[x][y] = true;
//     }
//     return true;
// }

bool fill(const vector<vector<vector<pair<int,int>>>> &polys, vector<vector<bool>> &covered, int si, int sj, int ind, int rot){
    assert(!covered[si][sj]);
    vector<vector<bool>> og = covered;
    int x, y;
    rep(i,polys[ind][rot].size()){
        x = si+polys[ind][rot][i].first;
        y = sj+polys[ind][rot][i].second;
        if (x < 0 || x >= 4 || y < 0 || y >= 4){
            covered = og;
            return false;
        }
        if (covered[x][y]){
            covered = og;
            return false;
        }
        covered[x][y] = true;
    }
    // if (ind == 1 && rot == 0) debug(polys[ind][rot],covered);
    return true;
}

void unfill(const vector<vector<vector<pair<int,int>>>> &polys, vector<vector<bool>> &covered, int si, int sj, int ind, int rot){
    assert(covered[si][sj]);
    int x, y;
    rep(i,polys[ind].size()){
        x = si+polys[ind][rot][i].first;
        y = sj+polys[ind][rot][i].second;
        assert(x>=0 && x < 4 && y >= 0 && y < 4);
        if (!covered[x][y]){
            debug(ind, rot, covered, si, sj, x, y, i);
        }
        assert(covered[x][y]);
        covered[x][y] = false;
    }
}

void get_source_indices(const vector<vector<bool>> &covered, int &si, int &sj, const bool dir){
    si = INT_MAX;
    sj = INT_MAX;
    if(dir){
        rep(i,4)
            rep(j,4)
                if(!covered[i][j]){
                    si = i;
                    sj = j;
                    return;
                }
        return;
    }
    rep(j,4){
        rep(i,4){
            if(!covered[i][j]){
                si = i;
                sj = j;
                return;
            }
        }
    }
}

inline bool all_ones(const vector<vector<bool>> &covered){
    debug(covered);
    rep(i, 4) rep(j,4) if (!covered[i][j]) return false;
    return true;
}

bool check(const vector<vector<vector<pair<int,int>>>> &polys, vector<vector<bool>> &covered, int b, int c, bool dir, const int a, const int rota){
    int si, sj;
    debug(a,b,c);
    get_source_indices(covered, si, sj, dir);
    int osi, osj;
    osi = si;
    osj = sj;
    bool ans = false;

    rep(rotb, 4){
        // if (a == 1 && rota == 0 && b == 0 && rotb == 3 && dir){
        //     debug('h', covered, polys[b][rotb], si, sj);
        // }
        if (!fill(polys,covered,si,sj,b,rotb)) continue;
        if (b == 1 && rotb == 0) debug(si, sj, polys[b][rotb], covered);
        get_source_indices(covered, si, sj, true);
        rep(rotc, 4)
            if (fill(polys,covered,si,sj,c,rotc)){
                ans = all_ones(covered);
                if(ans) return true;
                // debug(a, rota, b, rotb, dir, c, rotc, true);
                unfill(polys,covered,si,sj,c,rotc);
            }
        get_source_indices(covered,si,sj,false);
        if (b == 1 && rotb == 0) debug(covered);
        rep(rotc, 4)
            if (fill(polys,covered,si,sj,c,rotc)){
                ans = all_ones(covered);
                if(ans) return true;
                // debug(a, rota, b, rotb, dir, c, rotc, false);
                unfill(polys,covered,si,sj,c,rotc);
            }
        si = osi;
        sj = osj;
        if (b == 1) debug('h', a, rota, rotb, si, sj);
        unfill(polys, covered, si, sj, b, rotb);
    }
    swap(b,c);
    rep(rotb, 4){
        if (!fill(polys,covered,si,sj,b,rotb)) continue;
        get_source_indices(covered, si, sj, false);
        rep(rotc, 4)
            if (fill(polys,covered,si,sj,c,rotc)){
                ans = all_ones(covered);
                if(ans) return true;
                // debug(a, rota, b, rotb, dir, c, rotc, true);
                unfill(polys,covered,si,sj,c,rotc);
            }
        get_source_indices(covered,si,sj,false);
        rep(rotc, 4)
            if (fill(polys,covered,si,sj,c,rotc)){
                ans = all_ones(covered);
                if(ans) return true;
                // debug(a, rota, b, rotb, dir, c, rotc, false);
                unfill(polys,covered,si,sj,c,rotc);
            }
        si = osi;
        sj = osj;
        unfill(polys, covered, si, sj, b, rotb);
    }
    return false;
}

bool check(const vector<vector<vector<pair<int,int>>>> &polys, int a, int b, int c){
    vector<vector<bool>> covered(4,vector<bool>(4,false));
    rep(rota, 4){
        if (!fill(polys,covered,0,0,a,rota)) continue;
        if (a == 1 && rota == 0) debug('a',polys[a][rota],covered);
        if (check(polys, covered, b, c, true, a, rota)) return true;
        if (check(polys, covered, b, c, false, a, rota)) return true;
        unfill(polys, covered, 0, 0, a, rota);
    }
    return false;
}

void transform(int rot, int &roti, int &rotj, int i, int j){
    switch(rot){
        case 0:
            roti = i;
            rotj = j;
            return;
        case 1:
            // roti = 4-j-1;
            // rotj = i;
            roti = j;
            rotj = 4-i-1;
            return;
        case 2:
            roti = 4-i-1;
            rotj = 4-j-1;
            // roti = 4-i-1;
            // rotj = 4-j-1;
            return;
        case 3:
            roti = 4-j-1;
            rotj = i;
            // roti = j;
            // rotj = 4-i-1;
            return;
    }

}

void solve(){
    int p = 3, n = 4;
    // vector<vector<pair<int,int>>> polys(3);
    vector<vector<vector<pair<int,int>>>> polys(3,vector<vector<pair<int,int>>>(4));
    char ch;
    vector<vector<string>> inp(3, vector<string>(4));
    rep(i,3){
        rep(j,4)
            cin >> inp[i][j];
    }
    int roti, rotj;
    rep(rot,4){
        rep(i,3){
            bool first = true;
            int si, sj;
            rep(j,4){
                rep(k,4){
                    transform(rot, roti, rotj, j, k);
                    ch = inp[i][roti][rotj];
                    if (ch == '.') continue;
                    if (first){
                        si = j;
                        sj = k;
                        // if (i == 0 && rot == 1)
                        //     debug(si, sj);
                        // polys[i][rot].push_back(make_pair(0,0));
                        first = false;
                    }
                    // if (i == 0 && rot == 1){
                    //     debug(roti, rotj);
                    // }
                    // polys[i][rot].push_back(make_pair(roti-si,rotj-sj));
                    polys[i][rot].push_back(make_pair(j-si,k-sj));
                }
            }
        }
    }
    
    // if (check(polys, 0,1,2) || check(polys, 0,2,1) || check(polys, 1,0,2) || check(polys, 1,2,0) || check(polys, 2,0,1) || check(polys, 2,1,0)) cout << yes;
    // debug(polys);
    if (check(polys,0,1,2) || check(polys,1,0,2) || check(polys,2,0,1)) cout << yes;
    else cout << no;
}