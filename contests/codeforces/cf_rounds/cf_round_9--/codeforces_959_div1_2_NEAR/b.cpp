/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Thu Jul 18 20:15:39 IST 2024
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

void solve1() {
    int n; cin >> n;
    string s, t; cin >> s >> t;
    if (s == t) return void(cout << yes);
    if (s.back() == '0' && t.back() == '1') return void(cout << no);
    bool p = (t.back() == '1');
    if (s.back() == t.back()) {
        rep(i,n-2,0,-1) {
            p |= t[i] == '1';
            if (p) return void(cout << yes);
            if (s.back() == t.back()) continue;
            if (s[i] == '0' && t[i] == '1') return void(cout << no);
            if (count(t.begin(),t.begin()+i,'1') > 0) return void(cout << no);
            return void(cout << yes);
        }
        cout << yes;
        return;
    }
    if (count(t.begin(),t.begin()+n-1,'0') == n-1) {
        return void(cout << yes);
    }
    if (p) cout << yes;
    else cout << no;
}

void solve() {
    int n; cin >> n;
    string s, t; cin >> s >> t;
    if (s == t) return void(cout << yes);
    if (s[0] == '0' && t[0] == '1') return void(cout << no);
    if (t[0] == '1') return void(cout << yes);
    bool p = s[0] == '1';
    rep(i,1,n-1,1) {
        if (s[i] == '0' && t[i] == '1') {
            if (p) return void(cout << yes);
            return void(cout << no);
        }
        if (t[i] == '1') return void(cout << yes);
        p |= s[i] == '1';
    }
    cout << yes;
}