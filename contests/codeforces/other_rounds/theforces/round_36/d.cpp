/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Fri Oct 25 20:32:34 IST 2024
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
    int n, m; cin >> n >> m;
    vector<int> p(n);
    iota(all(p),1);
    if (m == 3) {
        if (n == 2) return void(cout << "-1\n");
        vector<vector<int>> vals(3);
        rep(i,1,n,1)
            vals[i%3].push_back(i);
        p.clear();
        assert(sz(vals[1]) >= sz(vals[0]));
        p.insert(p.end(),all(vals[2]));
        while(!vals[0].empty()) {
            p.push_back(vals[0].back());
            vals[0].pop_back();
            assert(!vals[1].empty());
            p.push_back(vals[1].back());
            vals[1].pop_back();
        }
        while(!vals[1].empty()) {
            p.push_back(vals[1].back());
            vals[1].pop_back();
        }
        print_vec(p);
        return;
    }
    if (m%2) {
        rep(k,m/2,n,m) {
            int ind = k-1;
            if (ind+1 >= n) break;
            if (ind == 0 && ind+1 == n-1) return void(cout << "-1\n");
            if (ind == 0) swap(p[ind+1],p[ind+2]);
            else swap(p[ind],p[ind-1]);
        }
    }
    print_vec(p);
}