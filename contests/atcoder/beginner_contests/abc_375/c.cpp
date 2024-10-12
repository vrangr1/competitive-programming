/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sat Oct 12 17:34:23 IST 2024
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
    int n; cin >> n;
    vector<string> a(n);
    rep(i,n) cin >> a[i];
    // vector<string> b(n,string(n,'-'));
    auto acrotate = [&](int ind) -> void {
        string t;
        rep(j,ind,n-ind-1,1)
            t.push_back(a[ind][j]);
        rep(i,ind,n-ind-1,1)
            t.push_back(a[i][n-ind-1]);
        rep(j,n-ind-1,ind,-1)
            t.push_back(a[n-ind-1][j]);
        rep(i,n-ind-1,ind,-1)
            t.push_back(a[i][ind]);
        int cur = 0;
        rep(i,n-ind-1,ind,-1)
            a[i][ind] = t[cur++];
        rep(j,ind,n-ind-1,1)
            a[ind][j] = t[cur++];
        rep(i,ind,n-ind-1,1)
            a[i][n-ind-1] = t[cur++];
        rep(j,n-ind-1,ind,-1)
            a[n-ind-1][j] = t[cur++];
    };
    int cur = 0;
    rep(s,n/2) {
        // cur = (cur+1)%4;
        cur = (cur+3)%4;
        rep(c,cur)
            acrotate(s);
        if (DEBUG){
            debug(endl,s);
            rep(i,n) cout << a[i] << endl;
        }
    }
    rep(i,n) cout << a[i] << endl;
}