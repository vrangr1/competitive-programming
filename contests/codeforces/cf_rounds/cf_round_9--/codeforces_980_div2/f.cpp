/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sun Oct 20 16:28:14 IST 2024
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
	TEST1;
#ifdef LOCAL
    cout << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

void solve() {
    ll n; cin >> n;
    vector<pair<ld,ld>> pw(n);
    for (auto &[p,w] : pw) {
        cin >> p >> w;
        p/=(ld)100;
    }
    sort(all(pw),[](auto a, auto b) {
        return a.first*a.second < b.first*b.second;
    });
    // sort(all(pw));
    ld pp = pw[0].first, sw = pw[0].second;
    rep(i,1,n-1,1) {
        auto [p,w] = pw[i];
        if ((ld(1)-p)*pp*sw < pp*p*w) {
            pp*=p;
            sw+=w;
        }
    }
    cout << fixed << setprecision(10) << pp*sw << endl;
}