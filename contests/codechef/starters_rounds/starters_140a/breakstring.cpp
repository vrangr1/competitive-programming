/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed Jun 26 20:17:00 IST 2024
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
    string s; cin >> s;
    int n = sz(s);
    vector<int> lps(n,0), lpsb(n);
    lps[0] = 0;
    {
        int i = 1, len = 0;
        while(i < n) {
            if (s[i] == s[len])
                lps[i++] = ++len;
            else {
                if (len) len = lps[len-1];
                else i++;
            }
        }
    }
    {
        reverse(all(s));
        int i = 1, len = 0;
        while(i < n) {
            if (s[i] == s[len])
                lpsb[i++] = ++len;
            else {
                if (len) len = lpsb[len-1];
                else i++;
            }
        }
        reverse(all(s));
    }
    debug(lps,lpsb);
    int sol = 0;
    set<pair<int,int>> fst, bst;
    rep(i,n) fst.emplace(lps[i],i);
    rep(i,n) bst.emplace(lpsb[i],i);
    debug(fst,bst);
    auto fcheck = [&](int ind) -> bool {
        if (ind%2 == 0) return false;
        int t = (ind+1)/2;
        if (lps[ind] == t) return true;
        if (lps[ind] < t) return false;
        ind = lps[ind];
        auto it = fst.lower_bound({t,ind});
        if (it == fst.begin()) return false;
        it = prev(it);
        return it->first == t;
    };
    auto bcheck = [&](int ind) -> bool {
        if ((n-ind)%2 == 0) return false;
        int t = (n-ind-1)/2;
        if (t == 0) return true;
        ind = n-ind-2;
        if (lpsb[ind] == t) return true;
        if (lpsb[ind] < t) return false;
        ind = lpsb[ind];
        auto it = bst.lower_bound({t,ind});
        if (it == bst.begin()) return false;
        it = prev(it);
        return it->first == t;
    };
    rep(i,n) {
        if (fcheck(i) && bcheck(i)) {
            debug(i);
            sol++;
        }
    }
    if (fcheck(n-1)) sol++;
    cout << sol << endl;
}

const ll mod = (ll)1e9+123ll, p = 43ll;

ll inv(ll n) {
    if (n <= 1ll) return 1ll;
    return ((mod-mod/n)*inv(mod%n))%mod;
}

ll pwr(ll a, ll n) {
    if (n == 0ll) return 1ll;
    ll a2 = (a*a)%mod;
    if (n%2ll) return (a*pwr(a2,n/2ll))%mod;
    return pwr(a2,n/2ll);
}

class segtree {
private:
    ll merge(ll h1, ll l1, ll h2, [[maybe_unused]] ll l2) {
        return ((h2*pwr(p,l1))%mod + h1)%mod;
    }
public:
    vector<ll> tree, lens;
    ll n;
    segtree(const string &s) {
        n = sz(s);
        if (__builtin_popcountll(n) != 1ll)
            n = (1ll<<(64ll-__builtin_clzll(n)));
        vector<ll> a(n);
        ll gn = (n<<1ll);
        tree.assign(gn,0);
        lens.assign(gn,0);
        rep(i,n) 
            if (i < sz(s)) {
                a[i] = s[i]-'a';
                tree[i+n] = a[i];
                lens[i+n] = 1ll;
            }
            else {
                a[i] = 0ll;
            }
        rep(i,n-1ll,1ll,-1ll) {
            tree[i] = merge(tree[i<<1ll], lens[i<<1ll], tree[i<<1ll|1ll], lens[i<<1ll|1ll]);
            lens[i] = lens[i<<1ll] + lens[i<<1ll|1ll];
        }
    }

    ll query(ll l, ll r) {
        ll resl = 0ll, resr = 0ll, lenl = 0ll, lenr = 0ll;
        for(l+=n,r+=n;l<r;l>>=1ll,r>>=1ll) {
            if (l&1ll) {
                resl = merge(resl, lenl, tree[l], lens[l]);
                lenl += lens[l];
                l++;
            }
            if (r&1ll) {
                --r;
                resr = merge(tree[r], lens[r], resr, lenr);
                lenr += lens[r];
            }
        }
        return merge(resl, lenl, resr, lenr);
    }
};

void solve() {
    string s; cin >> s;
    int n = sz(s);
    segtree st(s);
    auto fcheck = [&](int ind) -> bool {
        if (ind%2 == 0) return false;
        int t = (ind+1)/2;
        return st.query(0,t) == st.query(t, ind+1ll);
    };
    auto bcheck = [&](int ind) -> bool {
        if ((n-ind)%2 == 0) return false;
        int t = (n-ind-1)/2;
        if (t == 0) return true;
        return st.query(ind+1ll,ind+1ll+t) == st.query(ind+1ll+t, n);
    };
    ll sol = 0ll;
    rep(i,n) {
        if (fcheck(i) && bcheck(i)) {
            sol++;
        }
    }
    if (fcheck(n-1)) sol++;
    cout << sol << endl;
}