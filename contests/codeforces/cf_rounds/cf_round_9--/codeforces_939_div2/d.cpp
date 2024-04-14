/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Apr 13 21:11:59 IST 2024
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
#define mt make_tuple
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
	TEST1;
#ifdef LOCAL
    cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    auto get_mex = [](vector<int> a) -> int {
        sort(all(a));
        int mex = 0;
        for(int v : a){
            if (v < mex) continue;
            if (mex == v)
                mex++;
            else break;
        }
        return mex;
    };
    vector<pair<int,int>> ops;
    auto proc = [&get_mex](vector<int> &a) -> array<int,4> {
        int mex = get_mex(a), n = sz(a);
        if (mex == 0) return {-1,-1,-1,-1};
        int sl = -1, sr = -1, sinc = 0, smex = -1;
        rep(i,n){
            set<int> st;
            int cur = 0, sum = 0;
            rep(j,i,n-1,1){
                sum += a[j];
                st.insert(a[j]);
                while(st.find(cur) != st.end()) cur++;
                int temp = (cur*(j-i+1)) - sum;
                if (temp < 0) continue;
                if (sl == -1 || temp > sinc){
                    sinc = temp;
                    sl = i;
                    sr = j;
                    smex = cur;
                    continue;
                }
                if (temp == sinc && (j-i+1) < (sr-sl+1)){
                    sl = i;
                    sr = j;
                    smex = cur;
                }
            }
        }
        if (sl == -1) return {-1,-1,-1,-1};
        return {sl,sr,smex,sinc};
    };
    auto upd = [&proc](vector<int> &a, int &gl, int &gr, int &gmex, int &ginc, int temp = -1) -> bool {
        auto [l,r,mex,inc] = proc(a);
        if (temp != -1 && inc <= temp) return false;
        if (gl == -1){
            gl = l;
            gr = r;
            gmex = mex;
            ginc = inc;
            return l != -1;
        }
        if (l == -1) return false;
        if (inc > ginc){
            gl = l;
            gr = r;
            gmex = mex;
            ginc = inc;
            return true;
        }
        if (inc < ginc) return false;
        if ((r-l+1) >= (gr-gl+1)) return false;
        gl = l;
        gr = r;
        gmex = mex;
        ginc = inc;
        return true;
    };
    // int ct = 0;
    while(true){
        // ct++;
        // if (ct > 4) break;
        debug(a);
        int l = -1, r = -1, mex = -1, inc = -1;
        upd(a,l,r,mex,inc);
        bool one = false;
        int ind = -1;
        rep(i,n){
            int temp = a[i];
            a[i] = 0;
            if (upd(a,l,r,mex,inc,temp)){
                one = true;
                ind = i;
            }
            a[i] = temp;
        }
        if (l == -1) break;
        if (one){
            ops.emplace_back(ind,ind);
            a[ind] = 0;
            ops.emplace_back(l,r);
            rep(i,l,r,1)
                a[i] = mex;
            continue;
        }
        ops.emplace_back(l,r);
        rep(i,l,r,1) a[i] = mex;
    }
    cout << accumulate(all(a),0) << " " << sz(ops) << endl;
    for (auto [l,r] : ops)
        cout << l+1 << " " << r+1 << endl;
}