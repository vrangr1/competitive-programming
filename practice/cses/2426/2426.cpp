/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Aug  3 07:38:17 IST 2024
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

// Wrong solution
void solve1() {
    ll a, b, n; cin >> b >> a >> n;
    vector<ll> p(n), q(n);
    rep(i,n) cin >> q[i] >> p[i];
    ll sol = 0ll;
    vector<ll> order(n);
    iota(all(order),0);
    sort(all(order),[&](const ll &i, const ll &j) {
        return p[i] > p[j];
    });
    priority_queue<ll> pq;
    rep(i,a+b) {
        sol += p[order[i]];
        pq.push(q[order[i]]-p[order[i]]);
    }
    while(sz(pq) > a) {
        sol += pq.top();
        pq.pop();
    }
    cout << sol << endl;
}

// Correct solution but can it be shortened?
void solve() {
    ll a, b, n; cin >> a >> b >> n;
    vector<ll> p(n), q(n);
    rep(i,n) cin >> p[i] >> q[i];
    vector<ll> order(n);
    iota(all(order),0);
    sort(all(order),[&](const ll &i, const ll &j) {
        return p[i] > p[j];
    });
    priority_queue<ll> dpq;
    auto comp = [&](const ll &i, const ll &j) -> bool {
        return q[i] < q[j];
    };
    multiset<ll,decltype(comp)> bst(comp);
    ll sol = 0, rest = 0, sum = 0ll;
    rep(i,a) {
        sum += p[order[i]];
        dpq.push(q[order[i]]-p[order[i]]);
    }
    rep(i,a,n-1,1){
        bst.insert(order[i]);
        rest += q[order[i]];
    }
    while(sz(bst) > b) {
        assert(!bst.empty() && *bst.begin() < n && *bst.begin() >= 0);
        rest -= q[*bst.begin()];
        bst.erase(bst.begin());
    }
    sol = sum + rest;
    rep(i,a,a+b-1ll,1) {
        sum += p[order[i]];
        assert(sz(bst) == a+b-i);
        auto it = bst.find(order[i]);
        if (it != bst.end()) {
            rest -= q[order[i]];
            bst.erase(it);
        }
        else {
            assert(!bst.empty());
            assert(*bst.begin() < n && *bst.begin() >= 0);
            rest -= q[*bst.begin()];
            bst.erase(bst.begin());
        }
        assert(sz(bst) == a+b-i-1);
        dpq.push(q[order[i]]-p[order[i]]);
        sum += dpq.top();
        dpq.pop();
        sol = max(sol,sum+rest);
    }
    cout << sol << endl;
}

// Attempting shorter solution
void solve() {
    ll a, b, n; cin >> a >> b >> n;
    vector<vector<ll>> vals(n,vector<ll>(2));
    rep(i,n) cin >> vals[i][0] >> vals[i][1];
    vector<ll> rest(n,0ll);
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    sort(all(vals),[](const auto &v1, const auto &v2) {
        return v1[0] > v2[0];
    });
    ll sum = 0ll;
    rep(i,n-1,a-1ll,-1) {
        rest[i] = sum;
        // sum += 
    }
}