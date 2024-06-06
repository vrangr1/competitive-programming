/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Thu Jun  6 20:50:49 IST 2024
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
    string s; cin >> s;
    if (k == n) {
        int ct = (int)count(all(s),'1');
        if (ct != n && ct != 0) return void(cout << "-1\n");
        cout << n << endl;
        return;
    }
    int lct = 0;
    char ch = s.back();
    rep(i,n-1,0,-1){
        if (s[i] != ch) break;
        lct++;
    }
    auto check = [&](int left, int right) -> bool {
        assert(left <= right);
        assert(right < n);
        assert(left >= 0);
        if ((right-left+1)%k) return false;
        int curct = 0, curch = s[left];
        rep(i,left,right,1) {
            if (curch == s[i]) {
                curct++;
                if (curct > k) return false;
                continue;
            }
            if (curct != k) return false;
            curct = 1;
            curch = s[i];
        }
        return curct == k;
    };
    int ind = n-lct-1;
    if (lct > k) return void(cout << "-1\n");
    if (lct == k) {
        if (check(0,n-1)) return void(cout << n << endl);
        // if (!check(0,(2*k)-1) || !check(2*k,n-1)) return void(cout << "-1\n");
        // cout << 2*k << endl;
        // return;
        ind = n-1;
    }
    else ind = n-lct-1;
    ch = s[ind];
    int ct = 0;
    // debug(ind,ch,ct);
    bool fd = false;
    rep(i,ind,0,-1) {
        // debug(i,ch,ct,s[i]);
        if (ch == s[i]) {
            ct++;
            if (ct > k) {
                ind = i;
                fd = true;
                break;
            }
            continue;
        }
        assert(ct <= k);
        if (ct < k) {
            ind = i+ct;
            fd = true;
            break;
        }
        ct = 1;
        ch = s[i];
    }
    if (!fd) {
        assert(ct < k);
        ind = ct-1;
        fd = true;
    }
    debug(lct,ind);
    string temp = s.substr(0,ind+1);
    reverse(all(temp));
    s = s.substr(ind+1) + temp;
    debug(temp,s);
    if (check(0,n-1)) cout << ind+1 << endl;
    else cout << "-1\n";
}