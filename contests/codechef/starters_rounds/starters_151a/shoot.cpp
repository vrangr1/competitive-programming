/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Wed Sep 11 20:53:01 IST 2024
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

#define up 0
#define right 1
#define down 2
#define left 3

void solve() {
    ll n, m; cin >> n >> m;
    vector<vector<pair<array<ll,3>,array<ll,3>>>> a(n,vector<pair<array<ll,3>,array<ll,3>>>(m));
    rep(i,n) rep(j,m) {
        ll v; cin >> v;
        auto &[pos, neg] = a[i][j];
        if (v == 0 || v == 3) {
            pos = neg = {0ll,0ll,0ll};
            continue;
        }
        if (v == 1)
            pos = {i,j,1ll};
        else neg = {i,j,1ll};
    }
    auto add = [&](array<ll,3> &l, array<ll,3> &r) -> array<ll,3> {
        array<ll,3> res;
        res[0] = l[0]+r[0];
        res[1] = l[1]+r[1];
        res[2] = l[2]+r[2];
        return res;
    };
    auto subtract = [&](array<ll,3> &l, array<ll,3> &r) -> array<ll,3> {
        array<ll,3> res;
        rep(i,3) {
            assert(l[i] >= r[i]);
            res[i] = l[i]-r[i];
        }
        return res;
    };
    auto preproc = [&](ll dir, vector<vector<vector<pair<array<ll,3>,array<ll,3>>>>> &dp) -> void {
        switch(dir) {
            case up:
                rep(i,n) {
                    rep(j,m) {
                        auto &[pos,neg] = dp[i][j][up];
                        auto &[cpos, cneg] = a[i][j];
                        pos = cpos;
                        neg = cneg;
                        if (!i) {
                            continue;
                        }
                        if (i == 1) {
                            if (j > 0) {
                                pos = add(pos,a[i-1][j-1].first);
                                neg = add(neg,a[i-1][j-1].second);
                            }
                            if (j < m-1) {
                                pos = add(pos,a[i-1][j+1].first);
                                neg = add(neg,a[i-1][j+1].second);
                            }
                            continue;
                        }
                        if (m == 1) {
                            pos = add(pos,dp[i-1][j][up].first);
                            neg = add(neg,dp[i-1][j][up].second);
                            continue;
                        }
                        pos = add(pos,a[i-1][j].first);
                        neg = add(neg,a[i-1][j].second);
                        if (m == 2) {
                            if (j) {
                                pos = add(pos,dp[i-1][j-1][up].first);
                                neg = add(neg,dp[i-1][j-1][up].second);
                            }
                            else {
                                pos = add(pos,dp[i-1][j+1][up].first);
                                neg = add(neg,dp[i-1][j+1][up].second);
                            }
                            continue;
                        }
                        if (!j) {
                            pos = add(pos,dp[i-1][j+1][up].first);
                            neg = add(neg,dp[i-1][j+1][up].second);
                            continue;
                        }
                        if (j == m-1) {
                            pos = add(pos,dp[i-1][j-1][up].first);
                            neg = add(neg,dp[i-1][j-1][up].second);
                            continue;
                        }
                        pos = add(pos,dp[i-1][j+1][up].first);
                        neg = add(neg,dp[i-1][j+1][up].second);
                        pos = add(pos,dp[i-1][j-1][up].first);
                        neg = add(neg,dp[i-1][j-1][up].second);
                        pos = subtract(pos,dp[i-2][j][up].first);
                        neg = subtract(neg,dp[i-2][j][up].second);
                    }
                }
                break;
            case right:
                rep(j,m-1,0ll,-1) {
                    rep(i,n) {
                        auto &[pos,neg] = dp[i][j][right];
                        auto &[cpos, cneg] = a[i][j];
                        pos = cpos;
                        neg = cneg;
                        if (j == m-1) {
                            continue;
                        }
                        if (j == m-2) {
                            if (i > 0) {
                                pos = add(pos,a[i-1][j+1].first);
                                neg = add(neg,a[i-1][j+1].second);
                            }
                            if (i < n-1) {
                                pos = add(pos,a[i+1][j+1].first);
                                neg = add(neg,a[i+1][j+1].second);
                            }
                            continue;
                        }
                        if (n == 1) {
                            pos = add(pos,dp[i][j+1][right].first);
                            neg = add(neg,dp[i][j+1][right].second);
                            continue;
                        }
                        pos = add(pos,a[i][j+1].first);
                        neg = add(neg,a[i][j+1].second);
                        if (n == 2) {
                            if (i) {
                                pos = add(pos,dp[i-1][j+1][right].first);
                                neg = add(neg,dp[i-1][j+1][right].second);
                            }
                            else {
                                pos = add(pos,dp[i+1][j+1][right].first);
                                neg = add(neg,dp[i+1][j+1][right].second);
                            }
                            continue;
                        }
                        if (!i) {
                            pos = add(pos,dp[i+1][j+1][right].first);
                            neg = add(neg,dp[i+1][j+1][right].second);
                            continue;
                        }
                        if (i == n-1) {
                            pos = add(pos,dp[i-1][j+1][right].first);
                            neg = add(neg,dp[i-1][j+1][right].second);
                            continue;
                        }
                        pos = add(pos,dp[i+1][j+1][right].first);
                        neg = add(neg,dp[i+1][j+1][right].second);
                        pos = add(pos,dp[i-1][j+1][right].first);
                        neg = add(neg,dp[i-1][j+1][right].second);
                        pos = subtract(pos,dp[i][j+2][right].first);
                        neg = subtract(neg,dp[i][j+2][right].second);
                    }
                }
                break;
            case down:
                rep(i,n-1,0ll,-1) {
                    rep(j,m) {
                        auto &[pos,neg] = dp[i][j][down];
                        auto &[cpos, cneg] = a[i][j];
                        pos = cpos;
                        neg = cneg;
                        if (i == n-1ll) {
                            continue;
                        }
                        if (i == n-2ll) {
                            if (j > 0) {
                                pos = add(pos,a[i+1][j-1].first);
                                neg = add(neg,a[i+1][j-1].second);
                            }
                            if (j < m-1) {
                                pos = add(pos,a[i+1][j+1].first);
                                neg = add(neg,a[i+1][j+1].second);
                            }
                            continue;
                        }
                        if (m == 1) {
                            pos = add(pos,dp[i+1][j][down].first);
                            neg = add(neg,dp[i+1][j][down].second);
                            continue;
                        }
                        pos = add(pos,a[i+1][j].first);
                        neg = add(neg,a[i+1][j].second);
                        if (m == 2) {
                            if (j) {
                                pos = add(pos,dp[i+1][j-1][down].first);
                                neg = add(neg,dp[i+1][j-1][down].second);
                            }
                            else {
                                pos = add(pos,dp[i+1][j+1][down].first);
                                neg = add(neg,dp[i+1][j+1][down].second);
                            }
                            continue;
                        }
                        if (!j) {
                            pos = add(pos,dp[i+1][j+1][down].first);
                            neg = add(neg,dp[i+1][j+1][down].second);
                            continue;
                        }
                        if (j == m-1) {
                            pos = add(pos,dp[i+1][j-1][down].first);
                            neg = add(neg,dp[i+1][j-1][down].second);
                            continue;
                        }
                        pos = add(pos,dp[i+1][j+1][down].first);
                        neg = add(neg,dp[i+1][j+1][down].second);
                        pos = add(pos,dp[i+1][j-1][down].first);
                        neg = add(neg,dp[i+1][j-1][down].second);
                        pos = subtract(pos,dp[i+2][j][down].first);
                        neg = subtract(neg,dp[i+2][j][down].second);
                    }
                }
                break;
            default:
                rep(j,m) {
                    rep(i,n) {
                        auto &[pos,neg] = dp[i][j][left];
                        auto &[cpos, cneg] = a[i][j];
                        pos = cpos;
                        neg = cneg;
                        if (j == 0ll) {
                            continue;
                        }
                        if (j == 1ll) {
                            if (i > 0) {
                                pos = add(pos,a[i-1][j-1].first);
                                neg = add(neg,a[i-1][j-1].second);
                            }
                            if (i < n-1) {
                                pos = add(pos,a[i+1][j-1].first);
                                neg = add(neg,a[i+1][j-1].second);
                            }
                            continue;
                        }
                        if (n == 1) {
                            pos = add(pos,dp[i][j-1][left].first);
                            neg = add(neg,dp[i][j-1][left].second);
                            continue;
                        }
                        pos = add(pos,a[i][j-1].first);
                        neg = add(neg,a[i][j-1].second);
                        if (n == 2) {
                            if (i) {
                                pos = add(pos,dp[i-1][j-1][left].first);
                                neg = add(neg,dp[i-1][j-1][left].second);
                            }
                            else {
                                pos = add(pos,dp[i+1][j-1][left].first);
                                neg = add(neg,dp[i+1][j-1][left].second);
                            }
                            continue;
                        }
                        if (!i) {
                            pos = add(pos,dp[i+1][j-1][left].first);
                            neg = add(neg,dp[i+1][j-1][left].second);
                            continue;
                        }
                        if (i == n-1) {
                            pos = add(pos,dp[i-1][j-1][left].first);
                            neg = add(neg,dp[i-1][j-1][left].second);
                            continue;
                        }
                        pos = add(pos,dp[i+1][j-1][left].first);
                        neg = add(neg,dp[i+1][j-1][left].second);
                        pos = add(pos,dp[i-1][j-1][left].first);
                        neg = add(neg,dp[i-1][j-1][left].second);
                        pos = subtract(pos,dp[i][j-2][left].first);
                        neg = subtract(neg,dp[i][j-2][left].second);
                    }
                }
                break;
        }
    };
    vector<vector<vector<pair<array<ll,3>,array<ll,3>>>>> dp(n,vector<vector<pair<array<ll,3>,array<ll,3>>>>(m,vector<pair<array<ll,3>,array<ll,3>>>(4)));
    preproc(up,dp);
    preproc(right,dp);
    preproc(down,dp);
    preproc(left,dp);
    debug(a,dp[0][0]);
    return;
    auto getx = [&](ll i, ll j) -> pair<ll,ll> {
        ll lp = 0ll, ln = 0ll, rp = 0ll, rn = 0ll;
        lp += dp[i][j][left].first.at(0);
        lp -= i*dp[i][j][left].first.at(2);
        assert(lp <= 0ll);
        lp = llabs(lp);
        rp += dp[i][j][right].first.at(0);
        rp -= i*dp[i][j][right].first.at(2);
        assert(rp >= 0ll);
        ln = dp[i][j][left].second.at(0);
        ln -= i*dp[i][j][left].second.at(2);
        assert(ln <= 0ll);
        ln = -ln;
        rn = dp[i][j][right].second.at(0);
        rn -= i*dp[i][j][right].second.at(2);
        assert(rn >= 0ll);
        return {lp+rp,ln+rn};
    };
    auto gety = [&](ll i, ll j) -> pair<ll,ll> {
        ll lp = 0ll, ln = 0ll, rp = 0ll, rn = 0ll;
        lp += dp[i][j][up].first.at(1);
        lp -= j*dp[i][j][up].first.at(2);
        assert(lp <= 0ll);
        lp = llabs(lp);
        rp += dp[i][j][down].first.at(1);
        rp -= j*dp[i][j][down].first.at(2);
        assert(rp >= 0ll);
        ln = dp[i][j][up].second.at(1);
        ln -= j*dp[i][j][up].second.at(2);
        assert(ln <= 0ll);
        ln = -ln;
        rn = dp[i][j][down].second.at(1);
        rn -= j*dp[i][j][down].second.at(2);
        assert(rn >= 0ll);
        return {lp+rp,ln+rn};
    };
    rep(i,n) {
        rep(j,m) {
            auto [xp,xn] = getx(i,j);
            auto [yp,yn] = gety(i,j);
            cout << llabs(xp+yp-xn-yn) << " \n"[j==m-1ll];
        }
    }
}