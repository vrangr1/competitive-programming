/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sun Nov 17 20:15:01 IST 2024
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
    int n, m, t; cin >> n >> m >> t;
    vector<pair<int,int>> h(n), p(m);
    for (auto &[l,r]: h) {
        cin >> l >> r;
    }
    for (auto &[x, v] : p) {
        cin >> x >> v;
    }
    multiset<int> mst;
    int sol = 0, cur = 1, jp = 1, i = 0;
    for (auto &[l,r] : h) {
        while(i < m && p[i].first < l) {
            mst.insert(p[i].second);
            i++;
        }
        assert(cur < l);
        int req = r-l+2;
        while(jp < req && !mst.empty()) {
            jp += *mst.rbegin();
            sol++;
            mst.erase(prev(mst.end()));
        }
        if (jp < req) return void(cout << "-1\n");
        cur = r+1;

    }
    cout << sol << endl;
}