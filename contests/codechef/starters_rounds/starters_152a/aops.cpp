/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Wed Sep 18 21:38:38 IST 2024
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
    auto process = [&](string &s, vector<int> &ops, bool rev = false) -> void {
        vector<pair<int,int>> a;
        char last = s[0];
        a.emplace_back(0,last-'0');
        rep(i,n) {
            if (s[i] == last)
                a.back().first++;
            else {
                last = s[i];
                a.emplace_back(1,last-'0');
            }
        }
        int sum = 0, asum = 0;
        for (auto &[ct,v] : a) {
            asum += ct;
            if (!v) ct%=2;
            sum += ct;
            if (v) {
                if (sum == asum) continue;
                // rep(i,)
            }
        }
        while(!a.empty() && a.back().second == 0) {
            sum -= a.back().first;
            a.pop_back();
        }
    };
    string s; cin >> s;
    
    // if (!a.empty() && a.front().second == 0 && a.front().first == 1 && (sum%2 == n%2)) {
    //     sum--;
    // }
    // int rem = n-sum;
    // int sol = int(count(all(s),'1')) + (rem/3)*2;
    // if (rem%3 == 2) sol++;
    // cout << sol << endl;
}