/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sat Sep 21 20:28:47 IST 2024
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

void solve1() {
    int n, d, k; cin >> n >> d >> k;
    vector<int> dp(n+1,0);
    rep(i,k) {
        int l, r; cin >> l >> r;
        dp[l]++;
        if (r+1 <= n) dp[r+1]--;
    }
    rep(i,1,n,1)
        dp[i] += dp[i-1];
    assert(*min_element(all(dp)) >= 0);
    deque<pair<int,int>> dq;
    auto pop = [&](int cur) -> void {
        while(!dq.empty() && dq.front().second < cur-d+1) {
            dq.pop_front();
        }
    };
    auto push = [&](int val, int cur) -> void {
        while(!dq.empty() && dq.back().first <= val) {
            dq.pop_back();
        }
        dq.emplace_back(val,cur);
    };
    debug(dp);
    int mn = INT_MAX, mnx = -1, mx = INT_MIN, mxx = -1;
    rep(i,1,n,1) {
        debug(i,endl);
        push(dp[i],i);
        if (i < d) {
            continue;
        }
        pop(i);
        assert(!dq.empty() && dq.front().second >= i-d+1);
        auto [val, _] = dq.front();
        debug(val);
        if (val > mx) {
            mx = val;
            mxx = i-d+1;
        }
        if (val < mn) {
            mn = val;
            mnx = i-d+1;
        }
    }
    cout << mxx << " " << mnx << endl;
}

void solve() {
    int n, d, k; cin >> n >> d >> k;
    vector<vector<int>> stt(n+1), edd(n+1);
    rep(i,k) {
        int l, r; cin >> l >> r;
        stt[l].push_back(i);
        edd[r].push_back(i);
    }
    set<int> st;
    int mx = INT_MIN, mxx = -1, mn = INT_MAX, mnx = -1;
    rep(i,1,n,1) {
        st.insert(all(stt[i]));
        if (i > d) {
            for (int v : edd[i-d])
                st.erase(v);
        }
        int val = sz(st);
        if (val > mx && i >= d) {
            mx = val;
            mxx = i-d+1;
        }
        if (i >= d && val < mn) {
            mn = val;
            mnx = i-d+1;
        }
    }
    cout << mxx << " " << mnx << endl;
}