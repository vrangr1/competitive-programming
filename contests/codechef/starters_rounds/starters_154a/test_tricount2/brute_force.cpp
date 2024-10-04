/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Wed Oct  2 21:44:41 IST 2024
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
    auto get = [&](vector<ll> a) -> ll {
        ll n = sz(a);
        if (n == 1) return 0;
        sort(rall(a));
        set<pair<int,int>> st;
        rep(i,n-1) {
            assert(a[i]-a[i+1]+1 <= a[i]);
            if (st.empty()) {
                st.emplace(a[i]-a[i+1]+1,a[i]+a[i+1]-1);
                continue;
            }
            int l = a[i]-a[i+1]+1, r = a[i]+a[i+1]-1;
            auto it = st.lower_bound({l,0});
            vector<pair<int,int>> del;
            if (it != st.begin() && prev(it)->second >= l) {
                auto p = prev(it);
                del.push_back(*p);
                l = min(p->first,l);
                r = max(p->second,r);
            }
            if (it != st.end() && it->first <= r) {
                del.push_back(*it);
                l = min(l,it->first);
                r = max(r,it->second);
            }
            for (auto [cl,cr] : del)
                st.erase({cl,cr});
            st.emplace(l,r);
        }
        debug(a);
        debug(st);
        int sol = 0, mx = 0;
        for (auto [l,r] : st) {
            sol += r-l+1;
            mx = max(r,mx);
        }
        // debug(mx);
        assert(mx == a[0]+a[1]-1);
        // if (mx < a[0]+a[1]-1)
        //     sol += a[0]+a[1]-1-max(mx,a[0]-a[1]);
        // cout << sol << endl;
        return sol;
    };
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    // if (n == 1ll) return void(cout << "0\n");
    rep(i,1,n-1,1) {
        ll sol = get(vector<ll>(a.begin(),a.begin()+i+1ll));
        cout << sol << " \n"[i==n-1ll];
    }
}