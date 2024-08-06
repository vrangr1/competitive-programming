/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Tue Aug  6 20:39:31 IST 2024
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
    auto ask = [&](int a, int b) -> int {
        cout << "? " << a << " " << b << endl;
        cout.flush();
        int ar; cin >> ar;
        if (ar == -1) exit(0);
        return ar;
    };
    auto ans = [&](int x) -> void {
        cout << "! " << x << endl;
        cout.flush();
    };
    int low = 2, high = 999;
    while(low < high) {
        if (high == low+2) {
            int v = ask(low,low+1);
            int t = (low*(low+1));
            if (v == t) ans(high);
            else if (v == t+low+low+1+1) ans(low);
            else {
                assert(v == t+low);
                ans(low+1);
            }
            return;
        }
        if (low+1 == high) {
            int v = ask(low,1);
            if (v == low) ans(high);
            else ans(low);
            return;
        }
        int m1 = (low*2 + high)/3, m2 = (low+high*2)/3;
        assert(m1 > low && m1 < high);
        assert(m2 > low && m2 < high);
        assert(m1 < m2);
        int v = ask(m1,m2), t = m1*m2;
        if (v == t) low = m2+1;
        else if (v == t+m1) {
            low = m1+1;
            high = m2;
        }
        else {
            assert(v == t +m1+m2+1);
            high=m1;
        }
    }
    ans(low);
}