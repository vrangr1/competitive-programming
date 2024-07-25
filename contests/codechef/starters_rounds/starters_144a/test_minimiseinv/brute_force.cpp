/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed Jul 24 20:24:47 IST 2024
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

class segtree {
public:
    ll n;
    vector<ll> tree;
    segtree(ll gn) {
        n = gn;
        gn<<=1ll;
        if (__builtin_popcountll(gn) != 1)
            gn = (1ll<<(64ll-__builtin_clzll(gn)));
        tree.assign(gn,0ll);
    }

    void clear() {
        fill(all(tree),0ll);
    }

    void update(ll ind, ll x) {
        for(tree[ind+=n]=x;ind>1;ind>>=1ll)
            tree[ind>>1ll] = tree[ind]+tree[ind^1ll];
    }

    ll query(ll l, ll r) {
        ll res = 0ll;
        for (l+=n,r+=n;l<r;l>>=1ll,r>>=1ll) {
            if (l&1ll) res += tree[l++];
            if (r&1ll) res += tree[--r];
        }
        return res;
    }
};

void solve() {
    ll n, k; cin >> n >> k;
    string s; cin >> s;
    segtree seg(n);
    auto comp = [&]() -> ll {
        ll sol = 0ll;
        seg.clear();
        rep(i,n) {
            if (s[i] == '0') sol += seg.query(0,i);
            else seg.update(i,1);
        }
        return sol;
    };
    ll sol = comp();
    string t = s;
    auto rec = [&](auto &&self, ll i, ll rem) -> void {
        ll cur = comp();
        if (cur < sol) {
            t = s;
            sol = cur;
        }
        if (i >= n) return;
        self(self,i+1,rem);
        if (!rem) return;
        s[i] = (s[i] == '1'?'0':'1');
        self(self,i+1,rem-1);
        s[i] = (s[i] == '1'?'0':'1');
    };
    rec(rec,0,k);
    debug(t);
    cout << sol << endl;
}