/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Tue Aug 13 20:55:31 IST 2024
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
    vector<pair<int,int>> rs(n);
    rep(i,n) {
        cin >> rs[i].first >> rs[i].second;
    }
    // sort(all(rs),[&](const pair<int,int> &a, const pair<int,int> &b) {
    //     // return min(a.first,a.second) < min(b.first,b.second);
    //     ld al = a.first, ar = a.second;
    //     ld bl = b.first, br = b.second;
    //     return ((al+ar)/(al*ar)) > ((bl+br)/(bl*br));
    // });
    // debug(rs);
    // int cost = 0ll, i = 0ll;
    // for(;i<n;++i) {
    //     if (k <= 0) break;
    //     auto [l, r] = rs[i];
    //     if (l > r) swap(l,r);
    //     if (k <= l+r)
    //         break;
    //     cost += l*r;
    //     k-=(l+r);
    // }
    // if (k <= 0) return void(cout << cost << endl);
    // if (i == n) return void(cout << "-1\n");
    int cost = 0;
    [[maybe_unused]] auto c2 = [&](const pair<int,int> &a, const pair<int,int> &b) {
        // return min(a.first,a.second) < min(b.first,b.second);
        ld al = a.first, ar = a.second;
        ld bl = b.first, br = b.second;
        return ((al+ar)/(al*ar)) < ((bl+br)/(bl*br));
    };
    auto comp = [&](const pair<int,int> &a, const pair<int,int> &b) -> bool {
        auto [al,ar] = a;
        auto [bl,br] = b;
        // return c2(a,b);
        // return al*ar < bl*br;
        return al + ar > bl + br;
        // if (al != bl) return al > bl;
        // return ar > br;
    };
    priority_queue<pair<int,int>,vector<pair<int,int>>, decltype(comp)> pq(comp);
    rep(i,n) {
        auto [l, r] = rs[i];
        if (l > r) swap(l,r);
        pq.emplace(l,r);
    }
    debug(pq);
    while(k>0) {
        if (pq.empty()) break;
        auto [l,r] = pq.top();
        pq.pop();
        debug(l,r);
        if (l == 1 && r == 1) {
            k-=2;
            cost++;
            continue;
        }
        assert(l > 1 || r > 1);
        assert(l > 0 && r > 0);
        cost += l;
        k--;
        r--;
        if (l > r) swap(l,r);
        pq.emplace(l,r);
    }
    // sort(rs.begin()+i,rs.end(),[&](const pair<int,int> &a, const pair<int,int> &b) {
    //     return min(a.first,a.second) < min(b.first,b.second);
    // });
    // debug(i,rs);
    // for(;i<n;++i) {
    //     if (k <= 0) break;
    //     auto [l, r] = rs[i];
    //     if (l > r) swap(l,r);
    //     if (k < r) {
    //         while(k) {
    //             assert(l != 1 || r != 1);
    //             cost += l;
    //             r--;
    //             if (l > r) swap(l,r);
    //             k--;
    //         }
    //         break;
    //     }
    //     if (k >= r && k <= l+r) {
    //         if (k == l+r) {
    //             cost += l*r;
    //             break;
    //         }
    //         while(k) {
    //             if (l == 1 && r == 1) {
    //                 k-=2;
    //                 assert(k < 0);
    //                 cost+=1;
    //                 break;
    //             }
    //             cost += l;
    //             r--;
    //             if (l > r) swap(l,r);
    //             k--;
    //         }
    //         break;
    //     }
    //     k-=l+r;
    //     cost += l*r;
    // }
    if (k > 0) cout << "-1\n";
    else cout << cost << endl;
}

void solve() {
    int n, k; cin >> n >> k;
    vector<pair<int,int>> rs;
    rep(i,n) {
        int l, w; cin >> l >> w;
        if (l > w) swap(l,w);
        rs.emplace_back(l,w);
    }
    vector<pair<int,int>> take;
    pair<int,int> part = {-1,-1};
    int ops = 0, ptops = 0, sol = INT_MAX;
    auto comp = [](auto &tk, auto &p) -> int {
        
    };
    auto ins = [&](pair<int,int> r) -> void {
        auto [l, w] = r;
        if (take.empty() && part.first == -1) {
            if (l+w <= k+1) {
                ops+=l*w;
                take.emplace_back(l,w);
                return;
            }
            while(ops < k) {
                ptops++;
                ops++;
                w--;
                if (l > w) swap(l,w);
            }
            part = r;
            return;
        }
        
    };
    rep(i,n) {

    }
}