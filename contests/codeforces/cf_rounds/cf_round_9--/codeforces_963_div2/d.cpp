/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sun Aug  4 20:53:33 IST 2024
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
    int n, k; cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> b = a;
    sort(all(b));
    map<int,int> mp, mind;
    rep(i,n) {
        if (mp.find(b[i]) == mp.end()) {
            mp[b[i]] = i;
            mind[b[i]]++;
        }
        else mind[b[i]]++;
    }
    int x = n%k;
    if (x == 0) x+=k;
    int l, r;
    if (x%2) {
        l = (x-1)/2;
        r = (x-1)/2;
    }
    else {
        l = (x/2)-1;
        r = (x/2);
    }
    int sol = -1;
    debug(x,l,r);
    auto get = [&](int val) -> tuple<int,int,int> {
        int sm = mp[val], eq = mind[val];
        return {sm,eq,n-sm-eq};
    };
    auto proc = [&](int ind) -> int {
        // if ((((ind%k) + (n-ind-1)%k) + 1)%k != x) return -1;
        // debug(ind);
        int cl = ind, cr = n-ind-1;
        if ((cl%k) != l) return -1;
        if ((cr%k) != r) return -1;
        auto [sm,eq,bg] = get(a[ind]);
        debug(sm,eq,bg);
        int req = max(0,l-sm) + max(0,r-bg);
        if (req < eq-1) return -1;
        int ls = 0, mr = 0, e = 0, i =0;
        while (i < ind) {
            if ((ind-i)%k == 0) break;
            req = (l-ls) + (r-mr);
            if (req == e) {
                return -1;
            }
            if (a[i] < a[ind]) {
                if (ls == l) {
                    i+=k;
                    continue;
                }
                ls++;
                i++;
                continue;
            }
            if (a[i] > a[ind]) {
                if (mr == r) {
                    i+=k;
                    continue;
                }
                mr++;
                i++;
                continue;
            }
            assert(e < req);
            e++;
            i++;
            continue;
        }
        req = (l-ls) + (r-mr);
        if (req == e) return a[ind];
        i = n-1;
        while(i > ind) {

        }
    
        // int ct = 0;
        // int i = 0;
        // while(i < ind) {
        //     if (a[i] <= a[ind]) {
        //         ct++;
        //         i++;
        //         continue;
        //     }

        // }
    };
    rep(i,n) {
        sol = max(sol,proc(i));
    }
    cout << sol << endl;
}