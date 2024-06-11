/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sun Jun  9 20:03:45 IST 2024
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

#define red 'R'
#define blue 'B'

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int ct1 = (int)count(all(a),a.front()), ct2 = (int)count(all(a),a.back());
    if (ct1 == n || ct2 == n) return void(cout << no);
    cout << yes;
    string col(n,red);
    assert(ct1 >= 1);
    assert(ct2 >= 1);
    if (ct1 == 1 && ct2 == 1) {
        col[0] = blue;
        col.back() = blue;
        cout << col << endl;
        return;
    }
    rep(i,n) {
        if (ct1 > 1 && a[i] == a.front()) {
            col[i] = blue;
            break;
        }
        else if(ct2 > 1 && a[i] == a.back()) {
            col[i] = blue;
            break;
        }
    }
    cout << col << endl;
}