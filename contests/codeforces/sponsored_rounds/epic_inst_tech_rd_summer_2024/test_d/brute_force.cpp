/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sun Jun 30 20:55:49 IST 2024
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

void solve1() {
    ll n; cin >> n;
    vector<ll> a(n); rep(i,n) cin >> a[i];
    sort(all(a));
    vector<ll> order(n);
    iota(all(order),0);
    vector<ll> ct(n+1,0);
    rep(i,n) ct[a[i]]++;
    debug(a);
    // order = {0,5,1,6,3,7,2,4};
    auto get = [&](bool pr = false) -> ll {
        multiset<ll> st(all(a));
        ll sol = 0ll, last = 0ll;
        bool alice = true;
        // bool prob = false;
        for (ll i : order) {
            if (alice) {
                if (a[i] <= last) {
                    // prob = true;
                    // debug('a');
                    continue;
                }
                // if (prob) {
                //     return INT_MAX;
                //     debug('b');
                // }
                while(!st.empty() && *st.begin() <= last) {
                    st.erase(st.begin());
                }
                assert(!st.empty());
                if (*st.begin() < a[i]) {
                    return INT_MAX;
                }
                if (pr) {
                    debug(a[i]);
                }
                alice = false;
                sol++;
                last = a[i];
                st.erase(st.find(a[i]));
            }
            else {
                alice = true;
                auto it = st.find(a[i]);
                if (it != st.end())
                    st.erase(st.find(a[i]));
            }
        }
        return sol;
    };
    // debug(get());
    // return;
    ll sol = INT_MAX;
    vector<ll> opt;
    do {
        ll cur = get();
        if (cur < sol) {
            sol = cur;
            opt = order;
        }
    } while(next_permutation(all(order)));
    cout << sol << endl;
    debug(opt);
    order = opt;
    debug(get(true));
}

void solve() {
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(rall(a));
    auto dfs = [n](auto &&self, vector<ll> arr, bool alice, ll last, ll x) -> ll {
        if (arr.empty()) return x;
        if (alice) {
            while(!arr.empty() && arr.back() <= last) {
                arr.pop_back();
            }
            if (arr.empty()) return x;
            last = arr.back();
            arr.pop_back();
            x++;
            return self(self,arr,false,last,x);
        }
        while(!arr.empty() && arr.back() <= last) {
            arr.pop_back();
        }
        if (arr.empty()) return x;
        ll mx = LLONG_MAX;
        for (ll i = 0; i < sz(arr); i++) {
            auto temp = arr;
            temp.erase(temp.begin()+i);
            mx = min(mx,self(self,temp,true,last,x));
        }
        if (mx == LLONG_MAX) return x;
        return mx;
    };
    cout << dfs(dfs,a,true,0,0) << endl;
}