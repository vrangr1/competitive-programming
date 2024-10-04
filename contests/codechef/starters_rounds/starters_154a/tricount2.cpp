/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Wed Oct  2 21:20:24 IST 2024
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
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    // if (n == 1) return void(cout << "0\n");
    set<pair<int,int>> st;
    set<int> vals;
    vals.insert(a[0]);
    int sol = 0;
    auto insert = [&](int l, int r) -> void {
        debug(endl,l,r);
        if (st.empty()) {
            st.emplace(l,r);
            sol += r-l+1;
            debug(st);
            return;
        }
        auto it = st.lower_bound({l,0});
        vector<pair<int,int>> del;
        if (it != st.begin() && prev(it)->second >= l) {
            auto p = prev(it);
            del.push_back(*p);
            l = min(p->first,l);
            r = max(p->second,r);
        }
        while(it != st.end() && it->first <= r) {
            del.push_back(*it);
            l = min(l,it->first);
            r = max(r,it->second);
            ++it;
        }
        for (auto [cl,cr] : del) {
            st.erase({cl,cr});
            sol -= cr-cl+1;
        }
        st.emplace(l,r);
        debug(st);
        sol += r-l+1;
    };
    rep(i,1,n-1,1) {
        vals.insert(a[i]);
        auto it = vals.lower_bound(a[i]);
        assert(it != vals.end() && *it == a[i]);
        if (it != vals.begin()) {
            auto p = prev(it);
            int pv = *p;
            insert(a[i]-pv+1,a[i]+pv-1);
        }
        auto nxt = next(it);
        if (nxt != vals.end()) {
            int nv = *nxt;
            insert(nv-a[i]+1,nv+a[i]-1);
        }
        debug(endl,i,a[i],st,sol);
        cout << sol << " \n"[i == n-1];
    }
}