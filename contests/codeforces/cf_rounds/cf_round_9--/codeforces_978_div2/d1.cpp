/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Mon Oct 14 02:03:36 IST 2024
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
    if (n == -1) exit(0);
    auto ask = [&](int i, int j) -> int {
        cout << "? " << i+1 << " " << j+1 << endl;
        cout.flush();
        int s; cin >> s;
        if (s == -1) exit(0);
        return s;
    };
    auto ans = [&](int i) -> void {
        cout << "! " << i+1 << endl;
        cout.flush();
    };
    int ind = -1;
    rep(i,0,n-1-n%2,2) {
        if (ask(i,i+1) == ask(i+1,i)) continue;
        ind = i;
        break;
    }
    if (ind == -1) {
        assert(n%2);
        ans(n-1);
        return;
    }
    if (n == 3) {
        assert(ind == 0);
        if (ask(0,2) == ask(2,0)) ans(1);
        else ans(0);
        return;
    }
    if (n%2) n--;
    if (ind == 0) {
        if (ask(0,2) == ask(2,0)) ans(1);
        else ans(0);
        return;
    }
    if (ask(ind,0) == ask(0,ind)) ans(ind+1);
    else ans(ind);
}