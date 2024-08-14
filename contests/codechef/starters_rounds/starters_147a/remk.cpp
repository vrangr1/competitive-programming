/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed Aug 14 20:19:35 IST 2024
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
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    set<pair<int,int>> vals;
    set<int> inds;
    vector<int> mx(n,0);
    rep(i,1,n-1,1)
        mx[i] = max(mx[i-1],a[i-1]);
    int sum = 0, sol = 0;
    rep(i,n) {
        if (!i) continue;
        if (i < k-1) {
            vals.emplace(a[i],i);
            inds.insert(i);
            sum += a[i];
            continue;
        }
        if (k == 2) {
            sol = max(sol,a[i]+mx[i]);
            continue;
        }
        int cind = *inds.begin();
        sol = max(sol,mx[cind]+a[i]+2*sum);
        vals.emplace(a[i],i);
        sum += a[i];
        inds.insert(i);
        auto [v,j] = *vals.begin();
        inds.erase(j);
        vals.erase(vals.begin());
        sum -= v;
        auto [v2,j2] = *vals.begin();
        vals.erase(vals.begin());
        inds.erase(j2);
        sum -= v2;
        int st = n;
        if (!inds.empty()) st = *inds.begin();
        if (2*v2 + mx[min(j2,st)] < 2*v+mx[min(j,st)]) {
            sum+=v;
            inds.insert(j);
            vals.emplace(v,j);
        }
        else {
            inds.insert(j2);
            vals.emplace(v2,j2);
            sum += v2;
        }
    }
    cout << sol << endl;
}

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> order(n);
    iota(all(order),0);
    sort(all(order),[&](const int &i, const int &j) {
        return a[i] < a[j];
    });
    int sol = 0, sum = 0;
    vector<vector<int>> inds(51);
    rep(i,n) inds[a[i]].push_back(i);
    int mx = a[order[n-1]];
    auto get_ct = [&](int v, int l, int r) -> int {
        if (inds[v].empty()) return 0;
        auto it1 = upper_bound(all(inds[v]),l);
        auto it2 = lower_bound(all(inds[v]),r);
        if (it1 == inds[v].end()) return 0;
        if (it2 == inds[v].begin()) return 0;
        it2 = prev(it2);
        return max(int(it2-it1)+1,0);
    };
    rep(v1,1,mx,1) {
        if (inds[v1].empty()) continue;
        int l = inds[v1].front();
        rep(v2,1,mx,1) {
            if (inds[v2].empty()) continue;
            int r = inds[v2].back();
            if (r-l-1 < k-2) continue;
            int i = mx, rem = k-2;
            sum = 0;
            while(rem > 0 && i >= 1) {
                int cur = get_ct(i,l,r);
                int ct = min(cur,rem);
                sum += ct*i;
                rem-=ct;
                --i;
            }
            sol = max(sol,2*sum+v1+v2);
        }
    }
    cout << sol << endl;
}