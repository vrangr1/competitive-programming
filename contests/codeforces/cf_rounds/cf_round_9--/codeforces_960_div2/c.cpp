/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Jul 20 20:41:25 IST 2024
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
    ll n; cin >> n;
    vector<ll> a(n);
    ll sum = 0ll;
    set<ll> st;
    ll mx = 0;
    rep(i,n) {
        cin >> a[i];
        sum += a[i];
        if (st.find(a[i]) != st.end()) {
            mx = max(mx,a[i]);
        }
        st.insert(a[i]);
        a[i] = mx;
    }
    vector<pair<ll,ll>> vals;
    ll cur = a.front(), stt = 0;
    rep(i,1,n-1ll,1) {
        if (a[i] == cur) continue;
        vals.emplace_back(cur,i-stt);
        cur = a[i];
        stt = i;
    }
    vals.emplace_back(cur,n-stt);
    {
        vector<pair<ll,ll>> newvals;
        bool done = false;
        rep(i,(ll)sz(vals)) {
            auto [val,ct] = vals[i];
            if (val == 0) {
                newvals.emplace_back(val,ct);
                continue;
            }
            if (ct == 1ll) {
                done = true;
                newvals.back().second++;
                sum += val;
                if (i == sz(vals)-1ll) newvals.back().second--;
                continue;
            }
            sum += val*ct;
            if (done && i == sz(vals)-1ll) ct--;
            newvals.emplace_back(val,ct);
        }
        swap(vals,newvals);
        if (!done) sum -= accumulate(all(a),0ll);
    }
    ll cct = 0ll;
    while(sz(vals) > 1) {
        auto [val, ct] = vals.back();
        if (ct == 1ll) {
            sum += val;
            cct++;
            vals.pop_back();
            continue;
        }
        sum += (((ct*(ct+1ll))/2ll)*val) + ((val*ct)*cct);
        vals.pop_back();
        cct += ct;
    }
    cout << sum << endl;
}
