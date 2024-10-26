/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sat Oct 26 20:53:45 IST 2024
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
    int sol = n-1;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> lt;
    rep(i,n) {
        if (lt.empty() || lt.back() < a[i]) {
            int cur = sz(lt), last = a[i];
            rep(j,i+1,n-1,1) {
                if (a[j] <= a[i]) continue;
                if (a[j] < last) continue;
                cur++;
                last = a[j];
            }
            sol = min(sol,cur);
            lt.push_back(a[i]);
        } else if (lt.back() == a[i]) {
            lt.push_back(a[i]);
        }
    }
    cout << sol << endl;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    deque<int> dq;
    rep(i,n-1,0,-1) {
        while(!dq.empty() && dq.front() < a[i]) {
            dq.pop_front();
        }
        dq.push_front(a[i]);
    }
    int m = sz(dq), sol = m-1;
    int ct = 0, cur = dq.front();
    while(!dq.empty()) {
        if (dq.front() == cur) {
            ct++;
        } else {
            sol = min(sol,m-ct);
            ct = 1;
            cur = dq.front();
        }
        dq.pop_front();
    }
    sol = min(sol,m-ct);
    cout << sol << endl;
}