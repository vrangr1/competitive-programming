/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Fri Nov  1 20:34:28 IST 2024
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
template<typename type>inline void print_vec(const vector<type> &v){rep(i,sz(v))cout<<v[i]<<" \n"[i==sz(v)-1];}
void solve();

int main() {
	fastIO;
	TEST;
#ifdef LOCAL
    cout << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

void solve() {
    int n; cin >> n;
    assert(n!=-1);
    if (n == -1) exit(0);
    auto ask = [](int a, int b) -> bool {
        cout << "? " << a << " " << b << endl;
        cout.flush();
        int r; cin >> r;
        assert(r!=-1);
        if (r == -1) exit(0);
        return r;   
    };
    auto ans = [&](vector<int> &p) -> void {
        cout << "! ";
        rep(i,1,n-1,1)
            cout << p[i] << " \n"[i==n-1];
        cout.flush();
    };
    vector<int> p(n);
    p[1] = 0;
    int l = 1;
    set<int> rts = {1};
    map<int,int> mp;
    mp[1] = 1;
    auto it = rts.begin();
    rep(u,2,n-1,1) {
        if (l == 1) {
            if (ask(1,u)) {
                mp[u] = u;
                rts.insert(u);
                p[u] = 0;
                continue;
            }
            p[u] = 1;
            l++;
            mp[1] = u;
            it = next(rts.begin());
            continue;
        }
        assert(!rts.empty());
        if (it == rts.end()) {
            it = rts.begin();
        }
        int v = *it;
        if (sz(rts) == 1) {
            p[u] = mp[v];
            mp[v] = u;
            continue;
        }
        while(ask(v,u)) {
            it = rts.erase(it);
            assert(!rts.empty());
            if (it == rts.end())
                it = rts.begin();
            v = *it;
            if (sz(rts) == 1) break;
        }
        p[u] = mp[v];
        mp[v] = u;
        it++;
    }
    ans(p);
}