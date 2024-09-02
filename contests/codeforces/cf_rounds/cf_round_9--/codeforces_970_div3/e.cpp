/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sun Sep  1 20:23:39 IST 2024
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
    string s; cin >> s;
    if (n%2 == 0) {
        vector<int> even(26,0), odd(26,0);
        rep(i,n)
            if (i%2) odd[s[i]-'a']++;
            else even[s[i]-'a']++;
        int ct = n/2;
        int mxe = 0, mxo = 0;
        rep(i,26) {
            mxe = max(mxe,even[i]);
            mxo = max(mxo,odd[i]);
        }
        cout << ct-mxe + ct-mxo << endl;
        return;
    }
    vector<int> le(26,0), lo(26,0), re(26,0), ro(26,0);
    rep(i,n) 
        if (i%2) ro[s[i]-'a']++;
        else re[s[i]-'a']++;
    int sol = INT_MAX;
    rep(i,n) {
        vector<int> e(26,0), o(26,0);
        if (i%2) ro[s[i]-'a']--;
        else re[s[i]-'a']--;
        int mxe = 0, mxo = 0;
        rep(j,26) {
            e[j] = le[j] + ro[j];
            o[j] = lo[j] + re[j];
            mxe = max(mxe,e[j]);
            mxo = max(mxo,o[j]);
        }
        int ct = n/2;
        sol = min(sol,ct-mxe+ct-mxo+1);
        if (i%2) lo[s[i]-'a']++;
        else le[s[i]-'a']++;
    }
    cout << sol << endl;
}