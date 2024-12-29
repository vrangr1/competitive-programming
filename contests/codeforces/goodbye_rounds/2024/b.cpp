/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sat Dec 28 20:14:48 IST 2024
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

void solve1() {
    int n; cin >> n;
    vector<pair<int,int>> rngs(n);
    for (auto &[l,r] : rngs)
        cin >> l >> r;
    multiset<pair<int,int>> mst;
    set<pair<int,int>> st;
    for (auto &[l,r] : rngs) {
        if (l != r) continue;
        mst.emplace(l,r);
        auto it = st.lower_bound({l,r});
        if (it == st.end()) {
            if (st.empty() || st.rbegin()->second + 1 != l)
                st.emplace(l,r);
            else {
                auto [pl,pr] = *st.rbegin();
                st.erase(prev(st.end()));
                st.emplace(pl,r);
            }
            continue;
        }
        auto [nl,nr] = *it;
        if (l == nl) continue;
        if (it == st.begin()) {
            if (r+1 == nl) {
                st.erase(it);
                st.emplace(l,nr);
            } else {
                st.emplace(l,r);
            }
            continue;
        }
        auto pv = prev(it);
        auto [pl,pr] = *pv;
        if (nl > l+1) {
            if (pr + 1 != l) {
                st.emplace(l,r);
                continue;
            }
            st.erase(pv);
            st.emplace(min(pl,l), r);
            continue;
        }
        if (nl == l) continue;
        if (pr + 1 != l) {
            st.erase(it);
            st.emplace(l,max(r,nr));
            continue;
        }
        it = st.erase(pv);
        st.erase(it);

    }
    string sol;
    rep(i,n) {
        auto [l,r] = rngs[i];
        if (l != r) {
            auto it = st.lower_bound({l,l});

        }
    }
    
}

void solve() {
    int n; cin >> n;
    vector<pair<int,int>> rngs(n);
    vector<int> sum(2*n+1,0);
    for (auto &[l,r] : rngs) {
        cin >> l >> r;
        if (l == r) sum[l]++;
    }
    vector<int> psum(2*n+1,0);
    rep(i,sz(psum)) {
        if (!i) continue;
        psum[i] = psum[i-1] + int(sum[i] > 0);
    }
    auto get = [&](int l, int r) -> int {
        assert(l);
        return psum[r] - psum[l-1];
    };
    string s;
    rep(i,n) {
        auto [l,r] = rngs[i];
        if (l == r) {
            if (sum[l] > 1) s.push_back('0');
            else s.push_back('1');
        } else {
            int g = get(l,r);
            if (g == r-l+1) s.push_back('0');
            else s.push_back('1');
        }
    }
    cout << s << endl;
}