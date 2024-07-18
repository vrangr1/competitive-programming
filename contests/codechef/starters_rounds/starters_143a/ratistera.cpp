/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed Jul 17 21:20:12 IST 2024
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

class DSU {
public:
    vector<int> parent, size, rank;
    DSU(int n) {
        parent.assign(n,-1);
        size.assign(n,1);
        rank.assign(n,1);
    }

    int find(int x) {
        if (parent[x] == -1) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        if (rank[px] > rank[py]) {
            parent[py] = px;
            size[px] += size[py];
        }
        else if (rank[px] < rank[py]) {
            parent[px] = py;
            size[py] += size[px];
        }
        else {
            parent[py] = px;
            rank[px]++;
            size[px] += size[py];
        }
    }

    int get_size(int x) {
        return size[find(x)];
    }
};

void solve() {
    int n; cin >> n;
    vector<pair<int,int>> r(n);
    rep(i,n)
        cin >> r[i].first >> r[i].second;
    vector<int> order(n);
    iota(all(order),0);
    sort(all(order),[&](const int &i, const int &j) {
        if (r[i].first != r[j].first) return r[i].first < r[j].first;
        return r[i].second < r[j].second;
    });
    DSU dsu(n);
    auto [left, right] = r[order[0]];
    rep(i,1,n-1,1) {
        int ind = order[i];
        int lb = max(r[ind].first,left), rb = min(r[ind].second,right);
        if (lb > rb || (lb == rb && (r[ind].first == right || r[ind].second == left))) {
            left = r[ind].first;
            right = r[ind].second;
            continue;
        }
        dsu.unite(order[i],order[i-1]);
        left = min(r[ind].first,left);
        right = max(r[ind].second,right);
    }
    rep(i,n) cout << dsu.get_size(i) << " \n"[i==n-1];
}