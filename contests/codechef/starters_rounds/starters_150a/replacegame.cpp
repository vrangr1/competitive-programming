/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Wed Sep  4 20:15:46 IST 2024
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
    string a, b; cin >> a >> b;
    if (a == b) return void(cout << "0\n");
    vector<int> freq(26,0);
    rep(i,k-1)
        freq[b[i]-'a']++;
    int ind = -1;
    rep(i,k-1,n-1,1) {
        freq[b[i]-'a']++;
        if (i-k >= 0) freq[b[i-k]-'a']--;
        if (*max_element(all(freq)) == k) {
            ind = i-k+1;
            break;
        }
    }
    if (ind == -1) return void(cout << "-1\n");
    cout << n-k+1 << endl;
    rep(i,ind) cout << i+1 << " " << b[i] << endl;
    rep(i,n-1,ind+k,-1)
        cout << i-k+2 << " " << b[i] << endl;
    cout << ind+1 << " " << b[ind] << endl;
}