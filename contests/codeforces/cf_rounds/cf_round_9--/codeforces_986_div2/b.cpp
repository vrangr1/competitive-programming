/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sun Nov 10 21:10:07 IST 2024
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
    ll n, b, c; cin >> n >> b >> c;
    if (b == c && b == 0) {
        if (n == 1 || n == 2) cout << n-1 << endl;
        else cout << "-1\n";
        return;
    }
    if (n == 1) {
        if (c == 0) cout << "0\n";
        else cout << "1\n";
        return;
    }
    if (c == 0) {
        if (b == 1) return void(cout << "0\n");
        assert(b > 1);
        if (b >= n) {
            // if (b == n-1) cout << n-2 << endl;
            // else if (b == n-2) cout << n-3 << endl;
            // else 
            cout << n-1 << endl;
            return;
        }
        ll ct = (n-1ll)/b + 1ll;
        cout << n-ct << endl;
        // cout << "-1\n";
        return;
    }
    if (b == 0) {
        if (c < n-2) return void(cout << "-1\n");
        if (c <= n-1) {
            // if (c == n-2) cout << n-2 << endl;
            // else 
            cout << n-1 << endl;
        } else cout << n << endl;
        return;
    }
    if (c == n-1) {
        cout << n-1 << endl;
        return;
    } else if (c > n-1) {
        cout << n << endl;
        return;
    } else if (c == n-2) {
        if (b == 1) cout << n-2 << endl;
        else cout << n-1 << endl;
        return;
    } else {
        assert(c < n-2);
        if (b == 1) {
            cout << c << endl;
            return;
        }
        ll ct = ((n-1ll-c)/b) + 1ll;
        assert(ct < n);
        cout << n-ct << endl;
        return;
    }
}