/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sun Aug 25 09:16:31 IST 2024
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
	TEST1;
#ifdef LOCAL
    cout << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

const ll mod = ll(1e9) + 7ll;
class Solution {
public:
    vector<int> getFinalState(vector<int>& a, ll k, ll mult) {
        if (mult == 1ll) return a;
        vector<ll> sprs = {1ll,mult,mult*mult};
        auto pwr = [](auto &&self, ll a1, ll n) -> ll {
            if (n == 0ll) return 1ll;
            ll a2 = (a1*a1)%mod;
            if (n%2ll) return (self(self,a2,n/2ll)*a1)%mod;
            return self(self,a2,n/2ll);
        };
        auto comp = [&sprs](const array<ll,3> &a1, const array<ll,3> &b) -> bool {
            auto [av, ap, ia] = a1;
            auto [bv, bp, ib] = b;
            if (ap == bp) {
                if (av != bv)
                    return av > bv;
                return ia > ib;
            }
            if (ap > bp) {
                ll p = ap-bp;
                if (p > 4ll) return true;
                // assert(p <= 4ll);
                
                ll temp = av*sprs[p];
                if (temp != bv) return temp > bv;
                return ia > ib;
                // return (av*sprs[p]) > bv;
            }
            ll p = bp-ap;
            // assert(p <= 4ll);
            if (p > 2ll) return false;
            ll temp = bv*sprs[p];
            if (av != temp) return av > temp;
            return ia > ib;
            // return av > (bv*sprs[p]);
        };
        priority_queue<array<ll,3>,vector<array<ll,3>>, decltype(comp)> pq(comp);
        ll n = ll(a.size());
        for (ll i = 0; i < n; ++i) {
            pq.push({(ll)a[i],0ll,i});
        }
        auto inc = [&](ll r) {
            if (r == 0) return;
            priority_queue<array<ll,3>,vector<array<ll,3>>, decltype(comp)> temp(comp);
            while(!pq.empty()) {
                auto [v, p, i] = pq.top();
                pq.pop();
                p+=r;
                temp.push({v,p,i});
            }
            while(!temp.empty()) {
                pq.push(temp.top());
                temp.pop();
            }
        };
        ll ct = n;
        bool done = false;
        while(k--) {
            assert(k >= 0);
            auto [v, p, i] = pq.top();
            pq.pop();
            p++;
            if (p == 1ll) ct--;
            pq.push({v,p,i});
            if (!ct && !done) {
                debug('h');
                done = true;
                ll r = k/n;
                k%=n;
                inc(r);
            }
        }
        debug(pq);
        vector<int> sol(n);
        while(!pq.empty()) {
            auto [v, p,i] = pq.top();
            pq.pop();
            sol[i] = int((v*pwr(pwr,mult,p))%mod);
        }
        return sol;
    }
};

void solve() {
    ll n, k, m; cin >> n >> k >> m;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    Solution sol;
    auto s = sol.getFinalState(a,k,m);
    print_vec(s);
}