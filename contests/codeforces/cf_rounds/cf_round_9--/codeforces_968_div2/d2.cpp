/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sun Aug 25 21:16:59 IST 2024
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
    vector<pair<ll,ll>> vals;
    rep(i,n) {
        ll l; cin >> l;
        set<ll> st;
        ll mex = 0ll;
        rep(j,l) {
            ll v; cin >> v;
            st.insert(v);
            while(st.find(mex) != st.end())
                mex++;
        }
        ll v1 = mex;
        st.insert(v1);
        while(st.find(mex) != st.end())
            mex++;
        vals.emplace_back(v1,mex);
    }
    sort(all(vals));
    debug(vals);
    map<ll,ll> mp;
    rep(i,n-1,0ll,-1ll) {
        auto [m1,m2] = vals[i];
        // if (mp.find(m2) != mp.end()) mp[m1] = mp[m2];
        // else mp[m1] = m2;
        if (mp.find(m2) != mp.end()) mp[m1] = max(mp[m1],mp[m2]);
        else mp[m1] = max(mp[m1],m2);
    }
    debug(mp);
    // {
    //     ll mxval = vals[0].second;
    //     ll ct = 0ll;
    //     for (auto [_,v]:vals){
    //         if (v == mxval) ct++;
    //         else if (v > mxval) {
    //             mxval = v;
    //             ct = 1;
    //         }
    //         // mxval = max(v,mxval);
    //     }
    //     ll sol = 0ll;
    //     debug(ct);
    //     if (ct > 1ll) {
    //         if (mxval >= m) {
    //             sol += (m+1ll)*mxval;
    //         }
    //         else {
    //             sol += (mxval+1ll)*mxval;
    //             sol += ((m*(m+1ll))/2ll) - (mxval*(mxval+1ll))/2ll;
    //         }
    //         cout << sol << endl;
    //         return;
    //     }
    // }
    auto [mx,_] = vals.back();
    map<pair<ll,ll>,ll> vct;
    ll mxval = -1;
    for (auto &p : vals) {
        vct[p]++;
        if (vct[p] > 1) mxval = max(mxval,p.second);
    }
    ll sol = 0ll;
    if (mxval >= m) {
        sol += (m+1ll)*mxval;
        cout << sol << endl;
        return;
    }
    if (mxval == -1) {
        set<ll> seen;
        ll ct1 = 0ll, ct2 = 0ll;
        for (auto [m1,m2] : vals) {
            if (seen.find(m1) != seen.end()) continue;
            if (m1 <= m) {
                assert(m1 <= mx);
                sol += mp[m1];
                if (m1 <= mx) ct1++;
                else ct2++;
            }
            seen.insert(m1);
        }
        debug(ct1,ct2);
        // return;
        assert(ct1+ct2 <= m+1ll);
        assert(ct1 <= mx+1ll);
        assert(ct2 == 0ll);
        sol += (mx+1ll-ct1)*mx;
        sol += ((m*(m+1ll))/2ll) - ((mx*(mx+1ll))/2ll);
        cout << sol << endl;
        return;
    }
    set<ll> seen;
    ll ct1 = 0ll, ct2 = 0ll, ct3 = 0ll;
    for (auto [m1,m2] : vals) {
        if (seen.find(m1) != seen.end()) continue;
        if (m1 > m) continue;
        if (m1 <= mxval) {
            sol += max({mp[m1],mxval,mp[mxval]});
            ct1++;
        }
        else {
            if (m1 <= mp[mxval]) {
                ct3++;
                sol += max({mp[m1],mxval,mp[mxval]});
            }
            else {
                ct2++;
                sol += max({mp[m1],mxval,mp[mxval]});
                sol -= m1;
            }
        }
        seen.insert(m1);
    }
    if (mp[mxval] > mxval) {
        sol += (mxval+1ll-ct1)*mxval;
        if (mp[mxval] <= m) {
            sol += (mp[mxval]-mxval-ct3)*(mp[mxval]);
            sol += ((m*(m+1ll))/2ll) - ((mp[mxval]*(mp[mxval]+1ll))/2ll);
        }
        else {
            sol += (m-mxval-ct3)*mp[mxval];
        }
        cout << sol << endl;
        return;
    }
    ct2+=ct3;
    debug(mxval,ct1,ct2,sol);
    sol += (mxval+1ll-ct1)*mxval;
    sol += ((m*(m+1ll))/2ll) - ((mxval*(mxval+1ll))/2ll);
    cout << sol << endl;
}