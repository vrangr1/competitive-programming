/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sun Aug  4 17:36:36 IST 2024
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
    vector<int> p(n);
    rep(i,n) cin >> p[i];
    if (is_sorted(all(p))) return void(cout << "0\n");
    int mex = 1;
    set<int> st;
    rep(i,n) {
        st.insert(p[i]);
        while(st.find(mex) != st.end())
            mex++;
        assert(mex <= i+2);
        if (mex == i+2 && p[i] == i+1) return void(cout << "1\n");
    }
    int hex = n;
    st.clear();
    rep(i,n-1,0,-1) {
        st.insert(p[i]);
        while(st.find(hex) != st.end())
            hex--;
        assert(hex >= n-(n-i));
        if (hex == i && p[i] == i+1) return void(cout << "1\n");
    }
    if (p.front() == n && p.back() == 1) return void(cout << "3\n");
    cout << "2\n";
}