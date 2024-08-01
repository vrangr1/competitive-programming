/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed Jul 31 20:34:03 IST 2024
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

// class DSU {
// public:
//     int n;
//     vector<int> parent, rank;
//     DSU(int gn) : parent(gn,-1),rank(gn,1) {
//         n = gn;
//     }

//     int find(int x) {
//         if (parent[x] == -1) return x;
//         return parent[x] = find(parent[x]);
//     }

//     void unite(int x, int y) {
//         int px = find(x), py = find(y);
//         if (px == py) return;
//         if (rank[px] > rank[py]) swap(px,py);
//         parent[px] = py;
//         if (rank[px] == rank[py]) ++rank[py];
//     }
// };

void solve() {
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
    vector<vector<bool>> match(25,vector<bool>(25,false));
    rep(b1,25) {
        assert(ranges[b1] == sz(actual[b1]));
        match[b1][b1] = true;
        rep(b2,b1+1,24,1) {
            if (ranges[b1] != ranges[b2]) continue;
            match[b1][b2] = match[b2][b1] = (actual[b1] == actual[b2]);
        }
    }
    while(q--) {
        int k, x; cin >> k >> x;
        int sol = oand;
        rep(bit,24,0,-1) {
            int val = (1<<bit);
            if ((val&x) == 0) continue;
            if (val&oand) break;
            if (ranges[bit] > k) continue;
            sol|=val;
            rep(b2,bit-1,0,-1) {
                val = (1<<b2);
                if ((x&val) == 0) continue;
                if (sol&val) {
                    sol^=val;
                    continue;
                }
                if (match[bit][b2]) sol|=val;
            }
            break;
        }
        cout << sol << endl;
    }
}