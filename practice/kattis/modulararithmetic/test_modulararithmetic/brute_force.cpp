/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sat Sep  7 20:31:58 IST 2024
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
	TEST1;
#ifdef LOCAL
    cout << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

ll gcd(ll a, ll b){
    if (a == 0) return b;
    return gcd(b%a,a);
}

ll mod_inv(ll a, ll b){
	ll bb = b, temp, q;
	ll x0 = 0, x1 = 1;
	if (b == 1) return 1;
	while (a > 1) {
		q = a / b;
		temp = b, b = a % b, a = temp;
		temp = x0, x0 = x1 - q * x0, x1 = temp;
	}
	if (x1 < 0) x1 += bb;
	return x1;
}

ll mul(ll x, ll y, ll n){
    return (x*y)%n; // to be fixed! long long out of range!!
}

void solve() {
    ll n;
    int t;
    while (cin >> n >> t && (n || t)){
        while (t--){
            ll x,y,m;
            char o;
            cin >> x >> o >> y;
            if (o == '+') m = (x - n) + y;
            else if (o == '-') m = x - y;
            else if (o == '/'){
                if (gcd(y,n) != 1){ // Modular Inverse doesn't exist
                    cout << "-1" << endl;
                    continue;
                }
                m = mul(x,mod_inv(y,n),n);
            }
            else m = mul(x,y,n);
            if (m < 0) m += n;
            cout << m << endl;
        }
    }
}