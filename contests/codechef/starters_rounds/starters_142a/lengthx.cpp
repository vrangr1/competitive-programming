/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed Jul 10 21:28:26 IST 2024
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

class trie {
public:
    ll ct;
    vector<trie*> children;
    trie() : children(10,nullptr), ct(0) {}
};

void solve() {
    ll n, x; cin >> n >> x;
    trie *root = new trie();
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    auto insert = [&](ll v) -> void {
        string s = to_string(v);
        if (sz(s) > x) return;
        reverse(all(s));
        while(sz(s) < x) s.push_back('0');
        reverse(all(s));
        trie *node = root;
        node->ct++;
        for (char &ch : s) {
            if (!node->children[ch-'0'])
                node->children[ch-'0'] = new trie();
            node = node->children[ch-'0'];
            node->ct++;
        }
    };
    auto get = [&](auto &&self, string &s, ll ind, trie *node, bool m = false) -> ll {
        if (!node) return 0ll;
        if (ind >= x) return 0ll;
        assert(sz(s) == x);
        ll v = s[ind]-'0';
        ll sol = 0ll;
        if (m) {
            rep(i,10ll-v,9ll,1ll) {
                sol += (node->children[i]?node->children[i]->ct:0ll);
            }
            sol += self(self,s,ind+1ll,node->children[9ll-v],true);
            return sol;
        }
        if (ind == 0ll && v == 0ll) {
            sol = self(self,s,ind+1ll,node->children[9], true);
            return sol;
        }
        if (v == 9ll) {
            sol = self(self,s,ind+1ll,node->children[0], false);
            return sol;
        }
        sol = self(self, s, ind+1ll,node->children[9ll-v], false);
        rep(i,0ll,8ll-v,1ll) {
            sol += (node->children[i]?node->children[i]->ct:0ll);
        }
        return sol;
    };
    ll sol = 0ll, ct = 0ll;
    rep(i,n-1ll,0ll,-1ll) {
        string s = to_string(a[i]);
        if (sz(s) > x) continue;
        reverse(all(s));
        while(sz(s) < x) s.push_back('0');
        reverse(all(s));
        sol += ct;
        ll cur = get(get,s,0,root);
        ct += cur;
        
    }
}