/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Fri Nov  1 20:09:45 IST 2024
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
    if (k == (n+1)/2) {
        cout << "1\n1\n";
        return;
    }
    if (k == 1 || k == n) return void(cout << "-1\n");
    if (k < (n+1)/2) {
        int x = k-1;
        cout << 2*x +1 << endl;
        rep(i,1,x,1) cout << i << " ";
        cout << k << " ";
        assert(k+x <= n);
        rep(i,k+1,k+x-1,1)
            cout << i << " ";
        cout << k+x << endl;
    } else {
        int x = n-k;
        cout << 2*x + 1 << endl;
        assert(x < k);
        rep(i,1,x,1)
            cout << i << " ";
        cout << k << " ";
        rep(i,k+1,n,1)
            cout << i << " \n"[i==n];
    }
}