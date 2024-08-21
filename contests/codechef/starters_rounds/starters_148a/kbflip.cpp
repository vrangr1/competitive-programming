/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed Aug 21 20:30:57 IST 2024
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
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int z = int(count(all(s),'0')), o = n-z;
    if (abs(z-o) <= 1) return void(cout << min(z,o) << endl);
    char ch = (z > o?'0':'1');
    int d = abs(z-o)/2;
    int ct = 0, mx = 0, stt = 0;
    debug(z,o,d,ch);
    rep(i,n) {
        debug(i,stt);
        if (s[i] == ch) ct++;
        else ct--;
        while(i-stt+1 > k || ct < 0) {
            if (s[stt] == ch) ct--;
            else ct++;
            stt++;
        }
        mx = max(ct,mx);
    }
    debug(mx);
    z += (z>o?-1:1)*min(d,mx);
    o += (z>o?1:-1)*min(d,mx);
    cout << min(z,o) << endl;
}

class segtree {
public:
    int n;
    vector<int> tree;
    segtree(const vector<int> &dp) {
        n = sz(dp);
        int gn = (n<<1);
        if (__builtin_popcount(gn) != 1)
            gn = (1<<(32-__builtin_clz(gn)));
        tree.assign(gn,INT_MIN);
        rep(i,n)
            tree[i+n] = dp[i];
        rep(i,n-1,1,-1)
            tree[i] = max(tree[i<<1],tree[i<<1|1]);
    }

    int query(int l, int r) {
        int res = INT_MIN;
        for (l+=n,r+=n; l < r; l>>=1,r>>=1) {
            if (l&1) res = max(res,tree[l++]);
            if (r&1) res = max(res,tree[--r]);
        }
        return res;
    }
};

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int z = int(count(all(s),'0')), o = n-z;
    if (abs(z-o) <= 1) return void(cout << min(z,o) << endl);
    vector<int> dp(n);
    char ch = (z > o?'0':'1');
    int d = abs(z-o)/2;
    rep(i,n) {
        dp[i] = (s[i] == ch?1:-1);
        if (i) dp[i] += dp[i-1];
    }
    segtree seg(dp);
    int mx = 0;
    debug(dp);
    rep(i,n) {
        int cmx = seg.query(i,min(i+k,n));
        int cur = (i?dp[i-1]:0);
        cur = cmx-cur;
        if (cur == 2) {
            debug(i,cmx);
        }
        mx = max(mx,cur);
    }
    debug(z,o,mx,d);
    z += (z>o?-1:1)*min(d,mx);
    o += (z>o?1:-1)*min(d,mx);
    cout << min(z,o) << endl;
}

/*
54 1
110000110101001011010001001001000100100110110000011001




[23,32]
(38,51)
11110010101111101000100 -> (10,13)
1101101111 -> (2,8)
00110011001010100101011111001110000111110000101110011011 -> (26,30)
(44,45)


88 17
0011011101100111100110001110001111111011111100111011100111111110110101101111101101011010

[30,43]
(29,59)
001101110110011110011000111000 -> (14,16) 
11111110111111 -> (1,13)
00111011100111111110110101101111101101011010 -> (14,30)

(41,47)
(40,48)
*/