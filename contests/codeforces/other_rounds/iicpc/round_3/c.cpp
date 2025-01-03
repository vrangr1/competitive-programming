/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sat Aug 24 20:21:28 IST 2024
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
    ll n, k; cin >> n >> k;
    vector<ll> a, b;
    rep(i,n) {
        ll v; cin >> v;
        if (v <= k) a.push_back(v);
        else b.push_back(v);
    }
    sort(rall(a));
    // sort(rall(b));
    ll sol = 0ll;
    rep(i,sz(a)) {
        if (i%2) continue;
        sol += a[i];
    }
    bool turn = (sz(a)%2 == 0);
    priority_queue<ll> pq(all(b)), apq;
    while(!pq.empty() || !apq.empty()) {
        if (!apq.empty()) {
            ll v = apq.top();
            apq.pop();
            if (turn) sol += v;
            turn = !turn;
            continue;
        }
        ll v = pq.top();
        pq.pop();
        assert(v > k);
        if (v <= k) {
            if (turn) sol += v;
        }
        else {
            if (v/2ll > k)
                pq.push(v/2ll);
            else apq.push(v/2ll);
            if (v-v/2ll > k)
                pq.push((v-v/2ll));
            else apq.push(v-v/2ll);
        }
        turn = !turn;
    }
    cout << sol << endl;
}