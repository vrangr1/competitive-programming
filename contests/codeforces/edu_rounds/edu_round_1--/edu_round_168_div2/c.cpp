/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Tue Jul 30 20:27:13 IST 2024
****************************************************/
#include <bits/stdc++.h>
#include <iostream> // Strange mac vs code issue!
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
    string s; cin >> s;
    vector<int> ct(n,0);
    rep(i,n-1,0,-1) {
        ct[i] = (s[i] == '(');
        if (i != n-1) ct[i] += ct[i+1];
    }
    int sol = 0;
    vector<int> inds;
    debug(ct);
    rep(i,0,n-1,1) {
        if (s[i] != '_') {
            if (s[i] == ')') {
                assert(!inds.empty());
                sol += i-inds.back();
                inds.pop_back();
            }
            else inds.push_back(i);
            continue;
        }
        if (inds.empty()) {
            inds.push_back(i);
            continue;
        }
        sol += i-inds.back();
        inds.pop_back();
    }
    assert(inds.empty());
    cout << sol << endl;
}