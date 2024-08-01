/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed Jul 31 21:04:07 IST 2024
****************************************************/
#include <bits/stdc++.h>
#include <iostream> // Strange mac vs code issue!
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
    int n, q; cin >> n >> q;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int oand = accumulate(all(a),(1<<25)-1, [](const int &v1, const int &v2) {
        return v1&v2;
    });
    vector<int> ranges(25,0);
    vector<vector<pair<int,int>>> actual(25);
    rep(bit,0,24,1) {
        int val = (1<<bit);
        bool pres = true;
        rep(i,n) {
            if (a[i]&val) {
                pres = true;
                continue;
            }
            if (pres) {
                ranges[bit]++;
                actual[bit].emplace_back(i,i);
            }
            pres = false;
            assert(!actual[bit].empty());
            actual[bit].back().second = i;
        }
    }
    // debug(ranges,actual);
    while(q--) {
        int k, x; cin >> k >> x;
        vector<int> temp = a;
        int sol = oand;
        rep(bit,24,0,-1) {
            int val = (1<<bit);
            if ((val&x) == 0) continue;
            if (val&oand) break;
            if (ranges[bit] > k) break;
            for (auto &[l, r] : actual[bit]) {
                rep(i,l,r,1)
                    temp[i] ^= x;
            }
            sol = accumulate(all(temp),(1<<25)-1,[](const int &v1, const int &v2){return v1&v2;});
            break;
        }
        cout << sol << endl;
    }
}

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int oand = accumulate(all(a),(1<<25)-1, [](const int &v1, const int &v2) {
        return v1&v2;
    });
    auto proc = [&](auto &&self, int k, int x, vector<int> &temp, int &sol) -> void {
        if (k == 0) return;
        rep(l,n) {
            rep(r,l,n-1,1) {
                auto t = temp;
                rep(i,l,r,1)
                    t[i]^=x;
                sol = max(sol,accumulate(all(t),(1<<25)-1,[](const int &v1, const int &v2){return v1&v2;}));
                self(self,k-1,x,t,sol);
            }
        }
    };
    while(q--) {
        int k, x; cin >> k >> x;
        int sol = oand;
        proc(proc,k,x,a,sol);
        cout << sol << endl;
    }
}