/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Mon Oct 14 20:20:05 IST 2024
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
    sort(all(a));
    vector<pair<int,int>> b;
    for (int v : a) {
        if (b.empty() || b.back().first != v)
            b.emplace_back(v,1);
        else b.back().second++;
    }
    int sol = 0, cur = 0;
    int stt = 0;
    sol = cur = b[0].second;
    int m = sz(b);
    debug(n,k,m,a,b);
    rep(i,1,m-1,1) {
        debug(endl,i);
        if (b[i].first != b[i-1].first+1) {
            debug('h');
            cur = b[i].second;
            sol = max(sol,cur);
            stt = i;
            continue;
        }
        debug('g');
        cur += b[i].second;
        debug(b[i],b[stt],stt);
        if (b[i].first - b[stt].first >= k) {
            cur -= b[stt].second;
            sol = max(sol,cur);
            stt++;
            continue;
        }
        debug('r');
        sol = max(sol,cur);
    }
    cout << sol << endl;
}