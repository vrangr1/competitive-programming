/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sun Jul 21 20:08:32 IST 2024
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
    set<int> miss;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    auto get_mex = [&]() -> int {
        int mex = 0;
        auto b = a;
        sort(all(b));
        rep(i,n) {
            if(mex == b[i])
                mex++;
            else if (mex < b[i]) break;
        }
        return mex;
    };
    int mex = get_mex();
    if (mex == 0) return void(cout << "1\n");
    debug(mex);
    vector<int> cts(mex,0);
    rep(i,mex) miss.insert(i);
    int last = 0, sol = n;
    rep(i,n) {
        last = max(last,i);
        while(!miss.empty() && last < n) {
            assert(a[last] != mex);
            if (a[last] > mex) {
                last++;
                continue;
            }
            assert(a[last] < mex);
            cts[a[last]]++;
            if (cts[a[last]] == 1) {
                assert(miss.find(a[last]) != miss.end());
                miss.erase(a[last]);
            }
            last++;
        }
        if (!miss.empty()) break;
        sol = min(sol,last-i);
        if (a[i] > mex) continue;
        cts[a[i]]--;
        if (cts[a[i]] == 0) miss.insert(a[i]);
    }
    cout << sol << endl;
}