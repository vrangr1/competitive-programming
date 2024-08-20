/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Tue Aug 20 20:43:54 IST 2024
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
#define yes "YES\n"
#define no "NO\n"
template<typename type>inline void print_vec(const vector<type> &v){rep(i,sz(v))cout<<v[i]<<" \n"[i==sz(v)-1];}
void solve();

// IMPORT SNIPPETS HERE

// END OF SNIPPETS

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
    vector<int> a(n);
    set<int> seen;
    vector<bool> last(n,false);
    rep(i,n) {
        cin >> a[i];
    }
    rep(i,n-1,0,-1) {
        if (seen.find(a[i]) != seen.end()) continue;
        last[i] = true;
        seen.insert(a[i]);
    }
    vector<int> b;
    set<int> used;
    set<int> inds;
    set<pair<int,int>> mxvals, mnvals;
    debug(last);
    rep(i,n) {
        if (used.find(a[i]) != used.end()) continue;
        mxvals.emplace(a[i],-i);
        mnvals.emplace(a[i],i);
        inds.insert(i);
        if (!last[i])
            continue;
        debug(i);
        while(!inds.empty() && *inds.begin() <= i) {
            if (sz(b)%2) {
                // find min
                while(!mnvals.empty() && used.find(mnvals.begin()->first) != used.end()) {
                    auto [val, ind] = *mnvals.begin();
                    mnvals.erase(mnvals.begin());
                    inds.erase(ind);
                    mxvals.erase({val,-ind});
                }
                if (inds.empty() || *inds.begin() > i) break;
                debug(mxvals,mnvals,b,i);
                auto [val, ind] = *mnvals.begin();
                used.insert(val);
                b.push_back(val);
                while(!inds.empty() && *inds.begin() < ind) {
                    auto cind = *inds.begin();
                    mnvals.erase({a[cind],cind});
                    mxvals.erase({a[cind],-cind});
                    inds.erase(inds.begin());
                }
            }
            else {
                // find max
                while(!mxvals.empty() && used.find(mxvals.rbegin()->first) != used.end()) {
                    auto [val,ind] = *mxvals.rbegin();
                    mxvals.erase(prev(mxvals.end()));
                    inds.erase(-ind);
                    mnvals.erase({val,-ind});
                }
                if (inds.empty() || *inds.begin() > i) break;
                auto [val, ind] = *mxvals.rbegin();
                used.insert(val);
                b.push_back(val);
                while(!inds.empty() && *inds.begin() < -ind) {
                    auto cind = *inds.begin();
                    mxvals.erase({a[cind],-cind});
                    mnvals.erase({a[cind],cind});
                    inds.erase(inds.begin());
                }
            }
            if (used.find(a[i]) != used.end()) break;
        }
    }
    // assert(inds.empty());
    cout << sz(b) << endl;
    print_vec(b);
}