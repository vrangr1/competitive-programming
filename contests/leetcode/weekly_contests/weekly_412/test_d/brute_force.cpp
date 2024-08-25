/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sun Aug 25 08:30:37 IST 2024
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
	TEST1;
#ifdef LOCAL
    cout << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

void solve() {
    auto check = [](auto &&self, int a, int b, bool first = true) -> bool {
        if (a == b) return true;
        string s = to_string(a);
        int n = sz(s);
        rep(i,n) {
            rep(j,i+1,n-1,1) {
                swap(s[i],s[j]);
                if (stoi(s) == b) return true;
                rep(ii,n) {
                    rep(jj,ii+1,n-1,1) {
                        swap(s[ii],s[jj]);
                        if (stoi(s) == b) return true;
                        swap(s[ii],s[jj]);
                    }
                }
                swap(s[i],s[j]);
            }
        }
        if (first) return self(self,b,a,false);
        return false;
    };
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int sol = 0;
    rep(i,n) {
        rep(j,i+1,n-1,1) {
            sol += check(check,a[i],a[j]);
            if (check(check,a[i],a[j])) {
                debug(i,j);
            }
        }
    }
    cout << sol << endl;
}

/*
4
1023 2310 2130 213

3
1 10 100
[1023,2310,2130,213]
[1,10,100]
*/