/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Wed Oct  2 20:00:12 IST 2024
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
    int n, k; cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> b(n,-1ll);
    int sol = 0, last = -1;
    rep(i,n) {
        if (a[i]%k) {
            b[i] = a[i]^k;
            continue;
        }
        b[i] = 0;
    }
    debug(b);
    bool fd = false;
    rep(i,n) {
        if (b[i]) {
            if (i != last+1) {
                sol+=fd;
                fd = false;
            }
            last = i;
            continue;
        }
        if (a[i] != k) fd = true;
    }
    debug(fd);
    sol += fd;
    debug(sol);
    {
        vector<int> c;
        rep(i,n)
            if (c.empty() || c.back() != b[i])
                c.push_back(b[i]);
        swap(b,c);
    }
    n = sz(b);
    last = -1;
    rep(i,n) {
        if (b[i]) sol++;
    }
    cout << sol << endl;
}

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    if (*min_element(all(a)) == k && *max_element(all(a)) == k) return void(cout << "0\n");
    int sol = 0;
    vector<int> b;
    rep(i,n)
        if (b.empty() || b.back() != a[i]%k) {
            b.push_back(a[i]%k);
            if (b.back()) sol++;
        }
    sol++;
    cout << sol << endl;
}