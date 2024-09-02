/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sun Sep  1 20:42:31 IST 2024
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
    int n, q; cin >> n >> q;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    sort(all(a));
    auto pos = [&](int med, int x) -> bool {
        int ct = 0;
        rep(i,n) {
            int v = a[i];
            v%=x;
            ct += ((v<=med)?1:-1);
        }
        return ct > 0;
    };
    auto get = [&](int x) -> int {
        int low = 0, high = x;
        while(low < high) {
            int mid = (low+high)/2;
            if (pos(mid,x)) high = mid;
            else low = mid+1;
        }
        return high;
    };
    while(q--) {
        int x; cin >> x;
        cout << get(x) << " \n"[q==0];
    }
}

void solve2() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    sort(all(a));
    vector<int> delims(n);
    iota(all(delims),0);
    auto get_ct = [&](int x, int l, int r, const int med) -> int {
        assert(l >= 0 && l <= r && r < n);
        if (a[l]/x != a[r]/x) {
            debug(l,r,x);
            exit(0);
        }
        assert(a[l]/x == a[r]/x);
        assert(a[l]%x <= a[r]%x);
        if (a[l]%x > med) return -(r-l+1);
        int low = l, high = r;
        while(low < high) {
            int mid = (low+high+1)/2;
            if (a[mid]%x <= med) low = mid;
            else high = mid-1;
        }
        return (low-l+1 - (r-low));
    };
    auto pos = [&](int med, int x) -> bool {
        int ct = 0;
        int stt = 0;
        for (int edd : delims) {
            assert(stt <= edd);
            ct += get_ct(x, stt, edd, med);
            stt = edd+1;
        }
        return ct > 0;
    };
    // auto upd = [&](int x) -> void {
    //     int last = -1;
    //     vector<int> nd;
    //     ++x;
    //     int t = 0;
    //     while(t < n-1 && a[t+1]/x == a[t]/x) {
    //         t++;
    //     }
    //     nd.push_back(t);
    //     last = t;
    //     for (int edd : delims) {
    //         if (edd <= last) continue;
    //         while(edd < n-1 && a[edd+1]/x == a[edd]/x) {
    //             edd++;
    //         }
    //         nd.push_back(edd);
    //         last = edd;
    //     }
    //     swap(nd,delims);
    // };
    auto upd = [&](int x) -> void {
        int last = n-1;
        vector<int> nd;
        ++x;
        int m = sz(delims);
        rep(i,m-2,0,-1) {
            int edd = delims[i];
            if (edd > last) continue;
            while(edd < last && a[edd]/x < a[last]/x) {
                edd++;
            }
            nd.push_back(last);
            last = edd-1;
        }
        while(last >= 0) {
            int edd = 0;
            while(edd < last && a[edd]/x < a[last]/x) {
                edd++;
            }
            nd.push_back(last);
            last = edd-1;
        }
        reverse(all(nd));
        swap(nd,delims);
    };
    auto get = [&](int x) -> int {
        int low = 0, high = x;
        while(low < high) {
            int mid = (low+high)/2;
            if (pos(mid,x)) high = mid;
            else low = mid+1;
        }
        return high;
    };
    vector<int> sol(n+1,INT_MAX);
    debug(a);
    rep(x,1,n,1) {
        debug(endl,x,get(x));
        sol[x] = get(x);
        debug(delims);
        upd(x);
        debug(delims);
    }
    while(q--) {
        int x; cin >> x;
        cout << sol[x] << " \n"[q==0];
    }
}

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> ct(n+1,0);
    rep(i,n) ct[a[i]]++;
    vector<int> psum(n+1);
    partial_sum(all(ct),psum.begin());
    auto get_sum = [&](int l, int r) -> int {
        assert(l <= r && l >= 0 && r <= n);
        return psum[r]-(l>0?psum[l-1]:0);
    };
    vector<int> sol(n+1,0);
    auto pos = [&](const int med, const int x) -> bool {
        assert(med < x);
        int d = 0;
        rep(i,0,n,x) {
            d += get_sum(i,min(i+med,n));
        }
        return d > n-d;
    };
    rep(x,1,n,1) {
        int low = 0, high = x-1;
        while(low < high) {
            int mid = (low+high)/2;
            if (pos(mid,x)) high = mid;
            else low = mid+1;
        }
        sol[x] = high;
    }
    while(q--) {
        int x; cin >> x;
        cout << sol[x] << " \n"[q==0];
    }
}