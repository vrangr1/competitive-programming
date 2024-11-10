/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sat Nov  9 20:13:25 IST 2024
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
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    if (n == 1) return void(cout << "0\n");
    auto pos = [&](int r) -> bool {
        vector<int> lt(n+1), rt(n+1);
        lt[0] = 0;
        rep(i,1,n,1) {
            if (lt[i-1] < a[i-1]) lt[i] = lt[i-1]+1;
            else if (lt[i-1] == a[i-1]) lt[i] = lt[i-1];
            else lt[i] = lt[i-1]-1;
        }
        rt[n] = r;
        multiset<int> mst(all(lt));
        mst.erase(mst.find(lt.back()));
        if (mst.find(rt.back()) != mst.end()) return true;
        rep(i,n-1,0,-1) {
            mst.erase(mst.find(lt[i]));
            if (rt[i+1] > a[i]) rt[i] = rt[i+1]+1;
            else if (rt[i+1] == a[i]) rt[i] = rt[i+1]-1;
            else {
                if (rt[i+1] == 0) return true;
                rt[i] = rt[i+1]-1;
            }
            if (mst.find(rt[i]) != mst.end()) return true;
        }
        if (r == 3) {
            debug(lt,rt);
        }
        return false;
    };
    int low = 1, high = n;
    while(low < high) {
        int mid = (low+high+1)/2;
        debug(endl,mid,pos(mid));
        if (pos(mid)) low = mid;
        else high = mid-1;
    }
    cout << low << endl;
}