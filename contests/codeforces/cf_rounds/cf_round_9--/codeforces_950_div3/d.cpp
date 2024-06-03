/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Mon Jun  3 20:47:01 IST 2024
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
    vector<int> a(n), b(n-1);
    rep(i,n) cin >> a[i];
    rep(i,n-1)
        b[i] = gcd(a[i],a[i+1]);
    if (is_sorted(all(b))) return void(cout << yes);
    vector<bool> left(n-1,false), right(n-1,false);
    left[0] = true;
    rep(i,1,n-2,1) {
        if (b[i] >= b[i-1]) left[i] = true;
        else break;
    }
    right.back() = true;
    rep(i,n-3,0,-1)
        if (b[i] <= b[i+1]) right[i] = true;
        else break;
    debug(a,b,left,right);
    rep(i,n) {
        if (!i) {
            if (right[i+1]) return void(cout << yes);
            continue;
        }
        if (i == n-1) {
            if (left[n-3]) return void(cout << yes);
            continue;
        }
        if (i > 1 && !left[i-2]) continue;
        if (i < n-2 && !right[i+1]) continue;
        int temp = gcd(a[i-1],a[i+1]);
        if (i > 1 && temp < b[i-2]) continue;
        if (i < n-2 && temp > b[i+1]) continue;
        cout << yes;
        return;
    }
    cout << no;
}