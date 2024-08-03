/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Jul 27 19:41:54 IST 2024
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
	TEST1;
#ifdef LOCAL
    cout << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

void solve1() {
    string a, b; cin >> a >> b;
    int pa = int(count(all(a),'1')), pb = int(count(all(b),'1'));
    if (a == b) return void(cout << "0\n");
    if (pa < pb){
        if (b.back() == '1')
            return void(cout << pb-pa << endl);
        int n = sz(b)-1;
        while(b[n] != '1') {
            --n;
        }
        n = sz(b)-n-1;
        pb = pb-1+n;
        assert(pa < pb);
        cout << pb-pa+1 << endl;
        return;
    }
    if (pb == 1) {
        if (b == "1") return void(cout << "-1\n");
        assert(b[0] == '1');
        int req = sz(b)-1;
        if (pa < req) {
            cout << (req-pa+1) << endl;
            return;
        }
        if (pa == req) return void(cout << "1\n");
        cout << "2\n";
        return;
    }
    if (pa > pb) {
        if (b.back() == '1') {
            cout << "2\n";
            return;
        }
        int n = sz(b)-1;
        while(b[n] != '1') {
            --n;
        }
        n = sz(b)-n-1;
        pb = pb-1+n;
        if (pa > pb) {
            cout << "3\n";
            return;
        }
        if (pa < pb) {
            cout << pb-pa+1 << endl;
            return;
        }
        cout << "3\n";
        return;
    }
    if (b.back() == '1') {
        cout << "2\n";
        return;
    }
    int n = sz(b)-1;
    while(b[n] != '1') {
        --n;
    }
    n = sz(b)-n-1;
    pb = pb-1+n;
    assert(pa <= pb);
    if (pa == pb) return void(cout << "3\n");
    cout << (pb-pa+1) << endl;
}

void solve2() {
    string a, b; cin >> a >> b;
    if (a == b) return void(cout << "0\n");
    auto get = [](auto &&self, int pa, int pb, int ctz) -> int {
        assert(pa > 0 && pb > 0);
        if (ctz == 0) {
            if (pb == 1) return -1;
            if (pa < pb) return pb-pa;
            return 2;
        }
        assert(ctz > 0);
        if (pb-1+ctz == pa) return 1;
        int sol = self(self,pa,pb-1+ctz,0);
        assert(sol != -1);
        return 1 + sol;
    };
    reverse(all(b));
    int pa = int(count(all(a),'1')), pb = int(count(all(b),'1')), ctz = int(find(all(b),'1')-b.begin());
    debug(pa,pb,ctz);
    cout << get(get,pa,pb,ctz) << endl;
}

void solve() {
    string a, b; cin >> a >> b;
    if (a == b) return void(cout << "0\n");
    int pa = int(count(all(a),'1')), pb = int(count(all(b),'1'));
    reverse(all(b));
    int ctz = int(find(all(b),'1')-b.begin());
    debug(pa,pb,ctz);
    pb = pb-1+ctz;
    if (pb == 0) return void(cout << "-1\n");
    if (pa >= pb) cout << "2\n";
    else cout << pb-pa+1 << endl;
}