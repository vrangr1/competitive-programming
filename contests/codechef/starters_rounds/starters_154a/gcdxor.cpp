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

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    if (*max_element(all(a)) == k && *min_element(all(a)) == k) return void(cout << "0\n");
    auto isgcd = [&]() -> bool {
        for (int &v : a)
            if (gcd(v,k) != k) return false;
        return true;
    };
    auto isxor = [&]() -> bool {
        int cur = -1;
        bool fin = false;
        rep(i,n) {
            if (cur == -1 && a[i] == k) continue;
            if (cur == -1) {
                cur = (a[i]^k);
                continue;
            }
            if (!fin) {
                if (cur == (a[i]^k)) continue;
                if (a[i] != k) return false;
                fin = true;
                continue;
            }
            if (a[i] == k) continue;
            return false;
        }
        return true;
    };
    if (isgcd() || isxor()) return void(cout << "1\n");
    cout << "2\n";
}