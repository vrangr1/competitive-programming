/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Thu Jun 27 20:30:51 IST 2024
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
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    int p = 0, q = 0, r = 0, s = 0;
    rep(i,n) {
        if (a[i] == 0 && b[i] == 0) continue;
        if (a[i] == 1 && b[i] == 1) {
            r++;
            continue;
        }
        if (a[i] == -1 && b[i] == -1) {
            ++s;
            continue;
        }
        assert(a[i] != b[i]);
        if (a[i] == 0) {
            if (b[i] == 1) {
                q++;
            }
            continue;
        }
        if (b[i] == 0) {
            if (a[i] == 1)
                p++;
            continue;
        }
        if (a[i] == 1) {
            assert(b[i] == -1);
            p++;
            continue;
        }
        assert(a[i] == -1);
        assert(b[i] == 1);
        q++;
    }
    debug(p,q,r,s);
    while (r != 0) {
        if (p < q)
            p++;
        else if (q < p) q++;
        else break;
        r--;
    }
    while(s != 0) {
        if (p < q) q--;
        else if (q < p) p--;
        else break;
        s--;
    }
    if (r >= s && r != 0) {
        assert(p == q);
        r-=s;
        s = 0;
        p+=r/2;
        q+=r/2;
        if (r%2) p++;
        r = 0;
    }
    else if (r < s) {
        assert(p == q);
        s-=r;
        r = 0;
        p-=s/2;
        q-=s/2;
        if (s%2) p--;
        s = 0;
    }
    assert(r == 0 && s == 0);
    cout << min(p,q) << endl;
}