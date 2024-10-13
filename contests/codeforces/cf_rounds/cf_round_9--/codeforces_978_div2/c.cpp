/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Mon Oct 14 01:43:45 IST 2024
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
    int n; cin >> n;
    vector<string> s(2);
    cin >> s[0] >> s[1];
    int sol = 0;
    auto comp = [&](string t) -> int {
        return (count(all(t),'A') > count(all(t),'J'));
    };
    rep(i,2,n-1,3) {
        int cur = 0;
        cur = max(cur,comp(s[0].substr(i-2,3)) + comp(s[1].substr(i-2,3)));
        string t;
        t.push_back(s[0][i-2]);
        t.push_back(s[1][i-2]);
        t.push_back(s[0][i-1]);
        {
            int temp = comp(t);
            t.clear();
            t.push_back(s[1][i-1]);
            t.push_back(s[0][i]);
            t.push_back(s[1][i]);
            temp += comp(t);
            t.clear();
            cur = max(cur,temp);
        }

        t.push_back(s[0][i-2]);
        t.push_back(s[1][i-2]);
        t.push_back(s[1][i-1]);
        {
            int temp = comp(t);
            t.clear();
            t.push_back(s[0][i]);
            t.push_back(s[1][i]);
            t.push_back(s[0][i-1]);
            temp += comp(t);
            cur = max(cur,temp);
        }
        sol += cur;
    }
    cout << sol << endl;
}


#define full 0
#define upl 1
#define dl 2
#define uph 3
#define dh 4
#define rupl 5
#define rdl 6
#define bh 7

void solve() {
    int n; cin >> n;
    vector<string> s(2);
    cin >> s[0] >> s[1];
    vector<array<int,5>> dp(n,{INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN});
    // vector<array<int,5>> dp(n);
    auto comp = [&](string t) -> int {
        return (count(all(t),'A') > count(all(t),'J'));
    };
    auto get = [&](int i, int c) -> int {
        string t;
        switch(c) {
            case upl:
                assert(i >= 1);
                t += s[0].substr(i-1,2);
                t.push_back(s[1][i-1]);
                return comp(t);
            case dl:
                assert(i >= 1);
                t += s[1].substr(i-1,2);
                t.push_back(s[0][i-1]);
                return comp(t);
            case uph:
                assert(i >= 4);
                return comp(s[0].substr(i-2,3)) + comp(s[1].substr(i-3,3));
            case dh:
                assert(i >= 4);
                return comp(s[1].substr(i-2,3)) + comp(s[0].substr(i-3,3));
            case rupl:
                assert(i >= 2);
                t += s[0].substr(i-1,2);
                t.push_back(s[1][i]);
                return comp(t);
            case rdl:
                assert(i>=2);
                t += s[1].substr(i-1,2);
                t.push_back(s[0][i]);
                return comp(t);
            case bh:
                assert(i>=2);
                return comp(s[0].substr(i-2,3)) + comp(s[1].substr(i-2,3));
        }
        assert(false);
        return -1;
    };
    rep(i,n) {
        if (i == 0) continue;
        if (i == 1) {
            dp[i][upl] = get(i,upl);
            dp[i][dl] = get(i,dl);
            continue;
        }
        if (i == 2) {
            dp[i][full] = max({get(i,bh),get(i,rdl) + dp[i-1][upl], get(i,rupl) + dp[i-1][dl]});
            continue;
        }
        if (i == 3) {
            dp[i][full] = dp[i-3][full] + max({get(i,bh),get(i,rdl) + dp[i-1][upl], get(i,rupl) + dp[i-1][dl]});
            dp[i][upl] = dp[i-2][full] + get(i,upl);
            dp[i][dl] = dp[i-2][full] + get(i,dl);
            continue;
        }
        dp[i][full] = max({dp[i-3][full] + get(i,bh),get(i,rdl) + max(dp[i-1][upl],dp[i-1][uph]), get(i,rupl) + max(dp[i-1][dl],dp[i-1][dh])});
        dp[i][upl] = dp[i-2][full] + get(i,upl);
        dp[i][dl] = dp[i-2][full] + get(i,dl);
        dp[i][uph] = max(dp[i-3][upl],dp[i-3][uph]) + get(i,uph);
        dp[i][dh] = max(dp[i-3][dl],dp[i-3][dh]) + get(i,dh);
    }
    debug(dp);
    cout << dp[n-1][full] << endl;
}