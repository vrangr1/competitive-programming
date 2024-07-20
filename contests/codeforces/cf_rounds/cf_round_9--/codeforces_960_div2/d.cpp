/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Jul 20 21:50:34 IST 2024
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
    vector<int> a(n);
    int sol = 0;
    rep(i,n) {
        cin >> a[i];
        if (a[i] == 3) a[i] = 4;
        if (a[i] == 1) a[i] = 2;
        sol += (a[i]>0);
    }
    int alt = 0;
    int l = 0, r = 0;
    while(l < n) {
        if (a[l] == 0) {
            l++;
            continue;
        }
        if (a[l] > 2) {
            alt++;
            l++;
            continue;
        }
        r = l+1;
        while(r < n && a[r] == 4)
            r++;
        if (r == n) {
            alt += r-l;
            break;
        }
        if (a[r] == 0) {
            alt += r-l;
            l = r+1;
            continue;
        }
        if (a[r] == 2) {
            if ((r-l)%2) {
                alt += r-l;
                l = r+1;
                continue;
            }
            alt += r-l;
            l = r;
            continue;
        }
        assert(a[r] > 4);
        alt += r-l+1;
        l = r+1;
    }
    cout << min(sol,alt) << endl;
}