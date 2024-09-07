/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sat Sep  7 18:54:08 IST 2024
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
    int n, k; cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> psum(n);
    partial_sum(all(a),psum.begin());
    const int tval = psum.back()/k;
    vector<map<int,int>> dp(n);
    auto get_ind = [&](int i, int tt) -> int {
        if (psum.back()-psum[i]+a[i] < tt) return n-1;
        if (a[i] >= tt) return i;
        int low = i, high = n-1;
        while(low < high) {
            int mid = (low+high+1)/2;
            if (psum[mid]-psum[i]+a[i] <= tt) low = mid;
            else high = mid-1;
        }
        return low;
    };
    auto get = [&](int l, int r) -> int {
        return psum[r] - (l?psum[l-1]:0);
    };
    auto upd = [&](int ind, int tct) -> void {
        int ti = get_ind(ind,tval);
        if (ti == n-1) {
            if (tct == 1) dp[ind][tct] = max(dp[ind][tct],get(ind,ti));
            if (tct != 2) return;
            if (ind == n-1) return;
            
        }
    };
}