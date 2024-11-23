/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sun Nov 17 20:23:47 IST 2024
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
    ll n; cin >> n;
    ll asks = 0;
    auto ask = [&](ll l, ll r) -> ll {
        assert(l > 0 && l < r && r <= n);
        cout << "? " << l << " " << r << endl;
        cout.flush();
        asks++;
        if (asks > n) exit(0);
        ll sol; cin >> sol;
        return sol;
    };
    auto ans = [&](string s) -> void {
        if (s.empty()) cout << "! IMPOSSIBLE\n";
        else {
            assert(sz(s) == n);
            assert(find(all(s),'.') == s.end());
            cout << "! " << s << endl;
        }
        cout.flush();
    };
    string s(n,'.');
    if (ask(n-1,n) == 1) {
        s[n-2] = '0';
        s[n-1] = '1';
        ll o = 1, ct = 1;
        rep(i,n-3,0ll,-1) {
            ll cur = ask(i+1,n);
            if (cur == o+ct) {
                s[i] = '0';
                ct = ct+o;
            } else {
                assert(cur == ct);
                o++;
                s[i] = '1';
            }
        }
        assert(find(all(s),'.') == s.end());
        ans(s);
        return;
    }
    /*
    1*0*
    */
    vector<ll> sol(n,-1);
    sol[n-2] = 0;
    bool fd = false;
    ll o = 0, ct = 0;
    rep(i,n-3,0ll,-1) {
        sol[i] = ask(i+1,n);
        if (!fd) {
            if (sol[i]) {
                s = string(i,'.') + "0" + string(sol[i],'1') + string(n-i-1-sol[i],'0');
                fd = true;
                o = sol[i];
                ct = o;
            }
            continue;
        }
        if (sol[i] == o+ct) {
            s[i] = '0';
            ct = ct+o;
        } else {
            assert(sol[i] == ct);
            o++;
            s[i] = '1';
        }
    }
    if (!fd) ans("");
    else ans(s);
}

/*
01001
*/