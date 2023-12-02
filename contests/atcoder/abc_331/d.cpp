/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Dec  2 18:21:47 IST 2023
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
#endif

using namespace std;

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
#define pass (void)0
template<typename type>inline void print_vec(const vector<type> &v){rep(i,sz(v))cout<<v[i]<<" \n"[i==sz(v)-1];}
void solve();

// IMPORT SNIPPETS HERE
#ifndef IMPORT_HASH_SET_SNIPPET
#define IMPORT_HASH_SET_SNIPPET
#include <type_traits>
#include <unordered_set>
#include <unordered_map>
#include <chrono>
typedef long long int ll;
using namespace std;

// Source: Neal Wu (codeforces handle: neal)
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

template <typename type>
using hash_set = conditional_t <is_same<type,int>::value || is_same<type,ll>::value, unordered_set<type, custom_hash>, unordered_set<type>>;

template<typename t1, typename t2>
using hash_map = conditional_t<is_same<t1,ll>::value || is_same<t1,int>::value, unordered_map<t1, t2, custom_hash>, unordered_map<t1,t2>>;

template <typename type>
using hash_multiset = conditional_t<is_same<type,int>::value || is_same<type,ll>::value, unordered_multiset<type, custom_hash>, unordered_multiset<type>>;

template<typename t1, typename t2>
using hash_multimap = conditional_t<is_same<t1,int>::value || is_same<t2,ll>::value, unordered_multimap<t1, t2, custom_hash>, unordered_multimap<t1,t2>>;

#endif // IMPORT_HASH_SET_SNIPPET
// END OF SNIPPETS

int main(){
	fastIO;
	TEST1;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

const char black = 'B';

void solve(){
    ll n, q; cin >> n >> q;
    vector<string> p(n);
    rep(i,n) cin >> p[i];
    map<vector<ll>,ll> mp;
    vector<vector<ll>> stx(n,vector<ll>(n,0ll)), sty(n,vector<ll>(n,0ll));
    rep(i,n){
        stx[i][0] = (p[i][0] == black);
        rep(j,1,n-1ll,1ll){
            stx[i][j] = stx[i][j-1] + (p[i][j] == black);
        }
    }
    rep(j,n){
        sty[0][j] = (p[0][j] == black);
        rep(i,1,n-1ll,1ll){
            sty[i][j] = sty[i-1][j] + (p[i][j] == black);
        }
    }

    auto get_sum = [&](ll sa, ll sb, ll sc, ll sd){
        if (sa > sc || sb > sd) return 0ll;
        assert(sa <= sc);
        assert(sb <= sd);
        assert(sc < sa+n);
        assert(sd < sb+n);
        sa %= n;
        sb %= n;
        sc %= n;
        sd %= n;
        vector<ll> inds = {sa,sb,sc,sd};
        if (mp.find(inds) != mp.end()) return mp[inds];
        ll ct = 0ll;
        if (sa <= sc && sb <= sd){
            rep(i,sa,sc,1ll){
                ct += stx[i][sd]-(sb == 0ll?0ll:stx[i][sb-1ll]);
                // rep(j,sb,sd,1ll){
                //     ct += (p[i%n][j%n] == black);
                // }
            }
        }
        else if (sa <= sc){
            rep(i,sa,sc,1ll){
                ct += stx[i][n-1ll]-(sb == 0ll?0ll:stx[i][sb-1ll]);
                // rep(j,sb,n-1ll,1ll){
                //     ct += (p[i%n][j%n] == black);
                // }
                ct += stx[i][sd];
                // rep(j,0ll,sd,1ll){
                //     ct += (p[i%n][j%n] == black);
                // }
            }
        }
        else if (sb <= sd){
            rep(j,sb,sd,1ll){
                ct += sty[n-1ll][j]-(sa==0ll?0ll:sty[sa-1ll][j]);
                // rep(i,sa,n-1ll,1ll){
                //     ct += (p[i%n][j%n] == black);
                // }
                ct += sty[sc][j];
                // rep(i,0ll,sc,1ll)
                //     ct += (p[i%n][j%n] == black);
            }
        }
        else{
            rep(i,sa,n-1ll,1ll){
                ct += stx[i][n-1ll]-(sb == 0ll?0ll:stx[i][sb-1ll]);
                // rep(j,sb,n-1ll,1ll){
                //     ct += (p[i%n][j%n] == black);
                // }
                ct += stx[i][sd];
                // rep(j,0ll,sd,1ll){
                //     ct += (p[i%n][j%n] == black);
                // }
            }
            rep(i,0ll,sc,1ll){
                ct += stx[i][n-1ll] - (sb == 0?0ll:stx[i][sb-1ll]);
                // rep(j,sb,n-1ll,1ll){
                //     ct += (p[i%n][j%n] == black);
                // }
                ct += stx[i][sd];
                // rep(j,0ll,sd,1ll){
                //     ct += (p[i%n][j%n] == black);
                // }
            }
        }
        return mp[inds] = ct;
    };
    while(q--){
        ll a, b, c, d; cin >> a >> b >> c >> d;
        ll ia, ib;
        ia = a%n;
        ib = b%n;
        ll ct = 0;
        if (c < a + n-ia && d < b + n-ib){
            // rep(i,a,c,1){
            //     rep(j,b,d,1){
            //         ct += (p[i%n][j%n] == black);
            //     }
            // }
            // cout << ct << endl;
            cout << get_sum(a,b,c,d) << endl;
            continue;
        }
        else if (d < b + n-ib){
            ll rp = (c - a - (n-ia-1ll))/n;
            ll curct = get_sum(0,b,n-1ll,d);
            // rep(i,n){
            //     rep(j,b,d,1ll){
            //         curct += (p[i%n][j%n] == black);
            //     }
            // }
            ct = curct*rp;
            ct += get_sum(a,b,a+n-ia-1ll,d);
            // rep(i,a,a+n-ia-1ll,1ll){
            //     rep(j,b,d,1ll){
            //         ct += (p[i%n][j%n] == black);
            //     }
            // }
            ct += get_sum(c-((c-a-(n-ia-1ll))%n)+1ll,b,c,d);
            // rep(i,c-((c-a-(n-ia-1ll))%n)+1ll, c, 1ll){
            //     rep(j,b,d,1ll){
            //         ct += (p[i%n][j%n] == black);
            //     }
            // }
            cout << ct << endl;
            continue;
        }
        else if (c < a + n-ia){
            ll rp = (d-b-(n-ib-1ll))/n;
            ll curct = get_sum(a,0,c,n-1ll);
            // rep(i,a,c,1ll){
            //     rep(j,n){
            //         curct += (p[i%n][j%n] == black);
            //     }
            // }
            ct = curct*rp;
            ct += get_sum(a,b,c,b+n-ib-1ll);
            // rep(i,a,c,1ll){
            //     rep(j,b,b+n-ib-1ll,1ll){
            //         ct += (p[i%n][j%n] == black);
            //     }
            // }
            ct += get_sum(a,d-((d-b-(n-ib-1ll))%n)+1ll,c,d);
            // rep(i,a,c,1ll){
            //     rep(j,d-((d-b-(n-ib-1ll))%n)+1ll,d,1ll){
            //         ct += (p[i%n][j%n] == black);
            //     }
            // }
            cout << ct << endl;
            continue;
        }
        // debug(q);
        ll ra = (c - a - (n-ia-1ll))/n, rb = (d-b-(n-ib-1ll))/n;
        // debug(ra,rb);
        ll curct = get_sum(0,0,n-1ll,n-1ll);
        // rep(i,n) rep(j,n) curct += (p[i][j]==black);
        ct = curct*ra*rb;

        curct = get_sum(0,b,n-1ll,b+(n-ib-1ll)) + get_sum(0,d-((d-b-(n-ib-1ll))%n)+1ll,n-1ll,d);
        // rep(i,n){
        //     rep(j,b,b+(n-ib-1ll),1ll){
        //         curct += (p[i%n][j%n] == black);
        //     }
        //     rep(j,d-((d-b-(n-ib-1ll))%n)+1ll, d, 1ll){
        //         curct += (p[i%n][j%n] == black);
        //     }
        // }
        ct += curct*ra;

        curct = get_sum(a,0,a+(n-ia-1ll),n-1ll) + get_sum(c-((c-a-(n-ia-1ll))%n)+1ll,0,c,n-1ll);
        // rep(j,n){
        //     rep(i,a,a+(n-ia-1ll),1ll){
        //         curct += (p[i%n][j%n] == black);
        //     }
        //     rep(i,c-((c-a-(n-ia-1ll))%n)+1ll,c,1ll)
        //         curct += (p[i%n][j%n] == black);
        // }
        ct += curct*rb;
        
        ct += get_sum(a,b,a+(n-ia-1ll),b+(n-ib-1ll));
        // rep(i,a,a+(n-ia-1ll),1ll){
        //     rep(j,b,b+(n-ib-1ll),1ll)
        //         ct += (p[i%n][j%n] == black);
        // }
        ct += get_sum(c-((c-a-(n-ia-1ll))%n)+1ll,d-((d-b-(n-ib-1ll))%n)+1ll,c,d);
        // rep(i,c-((c-a-(n-ia-1ll))%n)+1ll,c,1ll){
        //     rep(j,d-((d-b-(n-ib-1ll))%n)+1ll,d,1ll)
        //         ct += (p[i%n][j%n] == black);
        // }

        ct += get_sum(a,d-((d-b-(n-ib-1ll))%n)+1ll,a+(n-ia-1ll),d);
        // rep(i,a,a+(n-ia-1ll),1ll){
        //     rep(j,d-((d-b-(n-ib-1ll))%n)+1ll,d,1ll)
        //         ct += (p[i%n][j%n] == black);
        // }
        ct += get_sum(c-((c-a-(n-ia-1ll))%n)+1ll,b,c,b+(n-ib-1ll));
        // rep(i,c-((c-a-(n-ia-1ll))%n)+1ll,c,1ll){
        //     rep(j,b,b+(n-ib-1ll),1ll)
        //         ct += (p[i%n][j%n] == black);
        // }
        cout << ct << endl;

    }
}