/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sun Oct 27 20:15:15 IST 2024
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
    int n; cin >> n;
    vector<int> p(n);
    if (n&1) {
        p.back() = n;
        p[n-2] = n - 1;
        p[n-3] = 1;
        p[n-4] = 3;
        set<int> st;
        rep(i,1,n,1) st.insert(i);
        st.erase(p.back());
        st.erase(p[n-2]);
        st.erase(p[n-3]);
        st.erase(p[n-4]);
        rep(i,n-4) {
            assert(!st.empty());
            p[i] = *st.begin();
            st.erase(st.begin());
        }
    } else {
        if (__builtin_popcount(n) == 1) {
            p.back() = n;
            p[n-2] = n-1;
            p[n-3] = n-2;
            p[n-4] = 1;
            p[n-5] = 3;
            set<int> st;
            rep(i,1,n,1) st.insert(i);
            st.erase(p.back());
            st.erase(p[n-2]);
            st.erase(p[n-3]);
            st.erase(p[n-4]);
            st.erase(p[n-5]);
            rep(i,n-5) {
                assert(!st.empty());
                p[i] = *st.begin();
                st.erase(st.begin());
            }
        } else {
            // int bit = (1<<(31-__builtin_clz(n)));
            // while(bit >= 1 && (n&bit)) {
            //     bit >>= 1;
            // }
            // assert(bit >= 1);
            int val = (1<<(32-__builtin_clz(n)));
            val--;
            val = (val^n);
            // if (bit != 1) {
            //     p[n-1] = bit;
            //     p[n-2] = n;
            //     p[n-3] = n - (n&(-n));
            //     p[n-4] = (n&(-n));
            //     p[n-5] = p[n-4] + 1;
            // } else {
            //     p[n-1] = 1;
            //     p[n-2] = n;
            //     p[n-3] = n - (n&(-n));
            //     p[n-4] = (n&(-n));
            //     p[n-5] = p[n-4] + 1;
            // }
            p[n-1] = val;
            p[n-2] = n;
            p[n-3] = n - (n&(-n));
            p[n-4] = (n&(-n));
            p[n-5] = p[n-4] + 1;
            set<int> st;
            rep(i,1,n,1) st.insert(i);
            st.erase(p.back());
            st.erase(p[n-2]);
            st.erase(p[n-3]);
            st.erase(p[n-4]);
            st.erase(p[n-5]);
            rep(i,n-5) {
                assert(!st.empty());
                p[i] = *st.begin();
                st.erase(st.begin());
            }
        }
    }
    int sol = 0;
    rep(i,n) {
        if (i%2)
            sol |= p[i];
        else sol &= p[i];
    }
    cout << sol << endl;
    print_vec(p);
}