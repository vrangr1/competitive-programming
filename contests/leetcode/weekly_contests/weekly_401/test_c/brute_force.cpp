/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sun Jun  9 09:09:12 IST 2024
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
class Solution {
public:
    int maxTotalReward1(vector<int>& a) {
        sort(all(a));
        int n = a.size();
        vector<bool> vis((2*(n)*a.back())+1,false);
        vis[0] = true;
        for (int i = 0; i < n; ++i) {
            for (int j = a[i]-1; j >= 0; --j) {
                assert(j+a[i] < vis.size());
                if (vis[j]) vis[j+a[i]] = true;
            }
        }
        for (int sol = vis.size()-1; sol >= 0; --sol)
            if (vis[sol]) return sol;
        return 0;
    }

    int maxTotalReward(vector<int>& a) {
        set<ll> vals(all(a)), toadd;
        vector<ll> mx(*vals.rbegin()+3ll,0ll);
        for (ll i = 1ll; i < mx.size(); ++i) {
            mx[i] = mx[i-1];
            if (!toadd.empty()) {
                assert(*toadd.begin() >= i-1);
                if (*toadd.begin() == i-1) {
                    toadd.erase(i-1);
                    mx[i] = max(mx[i],i-1);
                }
                if (!toadd.empty())
                    assert(*toadd.begin() >= i);
            }
            if (vals.find(i-1) != vals.end()) {
                mx[i] = i-1;
                if (i-1 + mx[i-1] < i) {
                    mx[i] = max(mx[i],i-1 + mx[i-1]);
                }
                else {
                    toadd.insert(mx[i-1]+i-1);
                }
            }
        }
        ll sol = mx.back();
        debug(vals,mx,toadd);
        if (!toadd.empty()) sol = max(sol,*toadd.rbegin());
        return sol;
    }
};

/*
[1,1,3,3]
[1,6,4,3,2]
[14,3,5,13,6,10]
[6,17,10,13]

4
4
1 1 3 3
5
1 6 4 3 2
6
14 3 5 13 6 10
4
6 17 10 33
*/

void solve() {
    Solution sol;
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    cout << sol.maxTotalReward1(a) << endl;
}