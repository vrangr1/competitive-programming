/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Mar 23 18:51:46 IST 2024
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
// #include <bit>
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
// typedef __int128_t i128;
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
    ll n; cin >> n;
    string s, t; cin >> s >> t;
    vector<vector<ll>> inds(26);
    rep(i,sz(s)){
        inds[s[i]-'a'].push_back(i);
    }
    auto get_ct = [&](ll ind, char ch) -> ll {
        auto it = lower_bound(all(inds[ch-'a']), ind);
        return (ll)(inds[ch-'a'].end() - it);
    };

    auto get_ind = [&](ll ind, char ch, ll need) -> ll {
        vector<ll> &cur = inds[ch-'a'];
        auto it = lower_bound(all(cur), ind);
        assert(it != cur.end());
        it += (need-1ll);
        assert(it != cur.end());
        return *it;
    };
    auto pos = [&](ll k) -> bool {
        debug(k);
        if (k == 0ll) return true;
        ll ct = 0ll, ind = 0ll;
        for(char ch : t){
            debug(ch,ct,ind);
            ll need = k;
            ll cct = sz(inds[ch-'a']);
            if (need >= cct){
                ct += (need/cct)-1ll;
                ll rem = get_ct(ind,ch);
                ll cn = cct;
                if (rem < cct){
                    ct++;
                    cn-=rem;
                    ind = 0;
                }
                ind = get_ind(ind,ch,cn);
                if (ind == n-1){
                    ct++;
                    ind=0;
                }
                else ind++;
                need%=cct;
            }
            if (need == 0) continue;
            ll rem = get_ct(ind,ch);
            if (need >= rem){
                need-=rem;
                ct++;
                ind=0;
                rem = get_ct(ind,ch);
            }
            assert(need <= rem);
            ind = get_ind(ind,ch,need);
            if (ind == n-1ll){
                ct++;
                ind = 0ll;
            }
            else ind++;
        }
        debug(ind,ct,endl);
        if (ind) ct++;
        return ct <= n;
    };
    auto bsch = [&](auto &&self, ll low, ll high) -> ll {
        if (low == high) return low;
        ll mid = (low+high+1ll)/2ll;
        if (pos(mid)) return self(self,mid,high);
        else return self(self,low,mid-1ll);
    };
    ll mx = (n*((ll)sz(s)))/((ll)sz(t));
    cout << bsch(bsch,0ll,mx) << endl;
}