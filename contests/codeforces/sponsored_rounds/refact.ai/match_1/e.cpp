/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sat Nov  9 21:24:23 IST 2024
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

const int maxn = int(4e5)+10;

vector<bool> isp(maxn,true);
vector<int> lg(maxn,-1);

void init() {
    static bool init = false;
    if (init) return;
    init = true;
    isp[0] = isp[1] = false;
    rep(v,4,maxn-1,2) {
        isp[v] = false;
        assert(lg[v] == -1);
        lg[v] = v/2;
    }
    rep(f,3,maxn-1,2) {
        if (!isp[f]) continue;
        rep(v,f*2,maxn-1,f) {
            isp[v] = false;
            if (lg[v] == -1)
                lg[v] = v/f;
        }
    }
}

void solve() {
    init();
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    sort(all(a));
    if (a[0] == 2 || !isp[a[0]]) {
        rep(i,1,n-1,1) {
            if (a[i] == 2) continue;
            if (isp[a[i]]) return void(cout << "-1\n");
        }
        cout << "2\n";
        return;
    }
    rep(i,1,n-1,1) {
        if (a[i] == a[0]) continue;
        if (isp[a[i]]) {
            return void(cout << "-1\n");
        }
        if (lg[a[i]] < a[0]) {
            int v = (a[i]/lg[a[i]]) * (lg[a[i]]-1);
            assert(v%2 == 0);
            if (v/2 < a[0]) return void(cout << "-1\n");
        }
        // if (isp[a[i]] || lg[a[i]] < a[0]) {
        // if (isp[a[i]]) {
            // debug(a[i],isp[a[i]],lg[a[i]]);
            // return void(cout << "-1\n");
        // }
    }
    cout << a[0] << endl;
}