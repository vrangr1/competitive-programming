/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sat Oct 26 20:03:13 IST 2024
****************************************************/
#include <bits/stdc++.h>

#define debug(...) (void)42
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
template<typename type>inline void print_vec(const vector<type> &v){rep(i,sz(v))cout<<v[i]<<" \n"[i==sz(v)-1];}
void solve();

int main() {
	fastIO;
	TEST;
#ifdef LOCAL
    cout << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

void solve() {
    int n; cin >> n;
    vector<pair<int,int>> sh;
    rep(i,n) {
        int w, h; cin >> w >> h;
        debug(endl,w,h);
        if (sh.empty()) {
            sh.emplace_back(w,h);
            debug(sh);
            continue;
        }
        vector<pair<int,int>> nw;
        for (auto [cw, ch] : sh) {
            if (h <= 0) {
                nw.emplace_back(cw,ch);
                continue;
            }
            if (cw >= w) {
                nw.emplace_back(cw,ch);
                h-=ch;
                continue;
            }
            if (h >= ch) {
                nw.emplace_back(w,ch);
                h-=ch;
                continue;
            }
            nw.emplace_back(w,h);
            nw.emplace_back(cw,ch-h);
            h = 0;
        }
        debug(nw,w,h);
        if (h > 0) nw.emplace_back(w,h);
        swap(nw,sh);
        debug(sh);
    }
    assert(!sh.empty());
    debug(sh);
    int sol = sh[0].first*2 + sh[0].second*2;
    rep(i,1,(int)sz(sh)-1,1) {
        auto [w,h] = sh[i];
        sol += 2*h;
    }
    cout << sol << endl;
}