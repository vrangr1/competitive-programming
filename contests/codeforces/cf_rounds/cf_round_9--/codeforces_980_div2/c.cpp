/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sun Oct 20 14:55:51 IST 2024
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
    vector<pair<int,int>> a(n);
    for (auto &[x,y] : a)
        cin >> x >> y;
    sort(all(a), [](const pair<int,int> &l, const pair<int,int> &r) {
        auto [v1l, v1r] = l;
        auto [v2l, v2r] = r;
        if (v1l > v1r) swap(v1l,v1r);
        if (v2l > v2r) swap(v2l,v2r);
        if (v1l != v2l) return v1l < v2l;
        return v1r < v2r;
        // return min(v1l,v1r) < min(v2l,v2r);
        // int v1 = int(v1l > v2l) + int(v1l > v2r) + int(v1r > v2l) + int(v1r > v2r);
        // int v2 = int(v2l > v1l) + int(v2l > v1r) + int(v2r > v1l) + int(v2r > v1r);
        // return v1 < v2;
    });
    rep(i,n)
        cout << a[i].first << " " << a[i].second << " \n"[i==n-1];
    [[maybe_unused]] auto invct = [&n](vector<pair<int,int>> &vec) -> int {
        int sol = 0;
        rep(i,n) {
            auto [x,y] = vec[i];
            if (x > y) sol++;
            rep(j,i+1,n-1,1) {
                auto [p,q] = vec[j];
                sol += int(x>p) + int(x > q) + int(y > p) + int(y > q);
            }
        }
        return sol;
    };
    debug(invct(a));
}