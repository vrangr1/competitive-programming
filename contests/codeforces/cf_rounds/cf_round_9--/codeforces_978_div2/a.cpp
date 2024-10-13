/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Mon Oct 14 01:01:32 IST 2024
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
    int n, r; cin >> n >> r;
    vector<int> a(n), e, o;
    rep(i,n) {
        cin >> a[i];
        if (a[i]%2) o.push_back(a[i]);
        else e.push_back(a[i]);
    }
    int sol = 0;
    for (int v : e) {
        sol += v;
        r -= v/2;
    }
    int s = accumulate(all(o),0);
    assert(s <= 2*r);
    int rem = sz(o);
    for (int v : o) {
        sol += v-1;
        r -= (v-1)/2;
    }
    debug(sol,rem,r);
    while(true) {
        assert(rem >= 0);
        if (rem == 0) break;
        if (rem == 2*r) break;
        if ((rem-1) <= 2*(r-1)) {
            sol++;
            rem--;
            --r;
            continue;
        }
        if (rem%2) sol++;
        break;
    }
    cout << sol << endl;
}