/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sun Jan 12 20:28:45 IST 2025
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
    ll n, k, l; cin >> n >> k >> l;
    l<<=1ll;
    k<<=1ll;
    vector<ll> a(n);
    rep(i,n) {
        cin >> a[i];
        a[i]<<=1ll;
    }
    sort(all(a));
    ll sol = 0, x = 0, i = 0;
    bool push = false;
    debug(a);
    while (i < n && x < l) {
        if (a[i] >= x) {
            a[i] = max(x,a[i]-sol);
            if (push) {
                assert((a[i]-x)%2ll == 0ll);
                sol += (a[i]-x)/2ll;
                x += (a[i]-x)/2ll + k;
            } else {
                sol += a[i]-x;
                x += k;
                push = true;
            }
            i++;
        } else {
            a[i] = min(x,a[i]+sol);
            if (push) {
                x = max(x,a[i]+k);
                i++;
                continue;
            } else {
                if (i != n-1 && max(x-k-a[i],0ll) > a[i+1]-x) {
                    i++;
                    continue;
                }
                sol += max(x-k-a[i],0ll);
                x = max(a[i]+k,x);
                push = true;
                i++;
            }
        }
    }
    debug(sol,push,x);
    if (x >= l) cout << sol << endl;
    else {
        assert(i == n);
        if (push) {
            sol += l-x;
        } else {
            sol += max(x-k-a.back(),0ll);
            x = max(x,a.back()+k);
            sol += l-x;
        }
        cout << sol << endl;
    }
}