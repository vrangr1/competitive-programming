/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Thu Jul 18 21:41:45 IST 2024
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

// tourist's solution
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<bool> used(n,false);
    vector<pair<int,int>> sol;
    rep(i,n-1,1,-1) {
        vector<int> p(i,-1);
        rep(j,n) {
            if (p[a[j]%i] == -1) p[a[j]%i] = j;
            else if (!used[j]){
                used[j] = true;
                sol.emplace_back(p[a[j]%i]+1,j+1);
                break;
            }
        }
    }
    cout << yes;
    reverse(all(sol));
    assert(sz(sol) == n-1);
    int cur = 1;
    for (auto &[u, v] : sol) {
        assert((abs(a[u-1]-a[v-1])%cur) == 0);
        cur++;
        cout << u << " " << v << endl;
    }
}