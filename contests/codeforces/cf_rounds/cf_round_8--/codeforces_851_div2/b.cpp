/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Fri Jul 12 18:20:03 IST 2024
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

void solve1() {
    int n; cin >> n;
    vector<int> tens(10);
    tens[0] = 1;
    rep(i,1,9,1) tens[i] = 10*tens[i-1];
    auto get = [](int x) -> int {
        string s = to_string(x);
        return accumulate(all(s),0,[](int sm, char ch){
            return sm + ch-'0';
        });
    };
    auto rec = [&](auto &&self, int x, int ind, int cur, const int s) -> bool {
        if (x > n) return false;
        if (cur > 9*(ind+1)) return false;
        assert(cur >= 0);
        if (ind == 0) {
            if (cur > 9) return false;
            x += cur;
            if (x > n) return false;
            int y = n-x;
            if (abs(s-get(y)) > 1) return false;
            cout << x << " " << y << endl;
            return true;
        }
        assert(ind > 0);
        if (cur == 0) {
            int y = n-x;
            assert(y <= n);
            if (abs(s-get(y)) > 1) return false;
            cout << x << " " << y << endl;
            return true;
        }
        assert(ind < 10);
        rep(c,(int)min(9,cur),0,-1) {
            if (self(self,x+c*tens[ind],ind-1,cur-c, s))
                return true;
        }
        return false;
    };
    int k = int(to_string(n).size());
    assert(k > 0);
    rep(l,k,k-1,-1) {
        if (l == 0) continue;
        rep(s,l*9,0,-1) {
            if (rec(rec, 0, l-1, s, s)) return;
        }
    }
    assert(false);
}

void solve() {
    int n; cin >> n;
    string s = to_string(n), sol(sz(s),'0');
    int l = sz(s), d = 0;
    rep(i,l) {
        int v = s[i]-'0';
        if (d == 0) {
            sol[i] = v/2 + '0';
            d = v%2;
        }
        else {
            assert(d == 1);
            sol[i] = (v+1)/2 + '0';
            d -= v%2;
        }
        s[i] -= sol[i] - '0';
    }
    cout << stoi(s) << " " << stoi(sol) << endl;
}