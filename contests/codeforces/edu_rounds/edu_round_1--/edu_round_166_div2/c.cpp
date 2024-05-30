/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Thu May 30 20:18:26 IST 2024
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
    ll n, m; cin >> n >> m;
    ll l = n+m+1ll;
    vector<ll> p(l), t(l);
    rep(i,l) cin >> p[i];
    rep(i,l) cin >> t[i];
    ll pl = -1, tl = -1, pnxt = -1, tnxt = -1;
    ll pct = 0, tct = 0;
    ll sol = 0ll;
    debug(l);
    rep(i,l-1ll) {
        if (pct < n && tct < m) {
            if (p[i] > t[i]) {
                pct++;
                sol += p[i];
                if (pct == n) pl = i;
                continue;
            }
            tct++;
            sol += t[i];
            if (tct == m) tl = i;
            continue;
        }
        if (pct == n) {
            tct++;
            sol += t[i];
            if(tct == m) tl = i;
            if (p[i] > t[i] && pnxt == -1) pnxt = i;
            continue;
        }
        pct++;
        sol += p[i];
        if (pct == n) pl = i;
        if (t[i] >= p[i] && tnxt == -1) tnxt = i;
    }
    debug(pl,tl,pnxt,tnxt,pct,tct,sol);
    // assert(pct == n && tct == m);
    // assert(pnxt != -1 || tnxt != -1);
    // assert(pnxt == -1 || tnxt == -1);
    // assert(pnxt == -1 || (pnxt > pl));
    // assert(tnxt == -1 || (tnxt > tl));
    // assert(pl != -1 && tl != -1);
    // assert(pl == l-1ll || tl == l-1ll);
    if (tnxt == -1) tnxt = l-1ll;
    if (pnxt == -1) pnxt = l-1ll;
    rep(i,l) {
        if (i == l-1ll) {
            cout << sol << endl;
            break;
        }
        ll cur = sol;
        if (p[i] > t[i]) {
            if (pl < i) {
                cur -= t[i] - t.back();
                cout << cur << " ";
                continue;
            }
            if (pnxt < l-1ll) {
                cur = cur - p[i] + p[pnxt] - t[pnxt] + t.back();
            }
            else {
                cur = cur - p[i] + p[pnxt];
            }
            cout << cur << " ";
            continue;
        }
        if (tl < i) {
            cur = cur - p[i] + p.back();
            cout << cur << " ";
            continue;
        }
        if (tnxt < l-1ll) {
            if (i==0ll) debug('h',cur,t[i],tnxt,pnxt,p.back());
            cur = cur - t[i] + t[tnxt] - p[tnxt] + p.back();
        }
        else cur = cur - t[i] + t.back();
        cout << cur << " ";
    }
}

/*
4

1
1 0
2 1
1 2

1
0 2
4 5 5
5 4 1

1
1 2
2 1 5 4
5 2 3 1

1
3 1
4 3 3 4 1
5 5 4 5 2



*/