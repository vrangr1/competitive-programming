/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sun Jun 23 20:43:02 IST 2024
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
#define yes "YES\n"
#define no "NO\n"
template<typename type>inline void print_vec(const vector<type> &v){rep(i,sz(v))cout<<v[i]<<" \n"[i==sz(v)-1];}
void solve();

// IMPORT SNIPPETS HERE

// END OF SNIPPETS

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
    string s; cin >> s;
    char mn = *min_element(all(s));
    if (mn == '0') {
        if (n == 2) {
            cout << stoi(s) << endl;
            return;
        }
        if (n == 3 && s.front() != '0' && s.back() != '0') {
            int a = s[0]-'0', b = s[2]-'0', sol = INT_MAX;
            if (a == 1 || b == 1) sol = max(a,b);
            else sol = a+b;
            assert(sol != INT_MAX);
            cout << sol << endl;
            return;
        }
        cout << 0 << endl;
        return;
    }
    if (n == 2) return void(cout << stoi(s) << endl);
    vector<int> a(n);
    rep(i,n) a[i] = s[i]-'0';
    if (*max_element(all(a)) == 1) return void(cout << "11\n");
    int sum = 0;
    rep(i,n) {
        if (a[i] == 1) continue;
        sum += a[i];
    }
    int sol = INT_MAX;
    rep(i,n-1) {
        int cur = a[i]*10 + a[i+1];
        int cursm = sum;
        if (a[i] != 1) cursm -= a[i];
        if (a[i+1] != 1) cursm -= a[i+1];
        sol = min(sol, cur+cursm);
    }
    assert(sol != INT_MAX);
    cout << sol << endl;
}