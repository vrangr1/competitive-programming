/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sun Aug 18 18:25:12 IST 2024
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

void solve() {
    int n; cin >> n;
    string s, t; cin >> s >> t;
    if (s == t) return void(cout << "0\n");
    vector<int> a(n);
    auto rev = [](char ch) -> char {
        return (char)(25-(ch-'a')+'a');
    };
    auto opp = [](char ch) -> char {
        return char(((ch-'a')+13)%26 + 'a');
    };
    rep(i,n) {
        if (s[i] == t[i]) a[i] = 0;
        else if (s[i] == rev(t[i]) && (s[i] == 'g' || s[i] == 't')) a[i] = 4;
        else if (s[i] == rev(t[i])) a[i] = 1;
        else if (s[i] == opp(t[i])) a[i] = 2;
        else if (s[i] == rev(opp(t[i]))) a[i] = 3;
        else return void(cout << "-1\n");
    }
    debug(a);
    // int sol = 0;
    // {
    //     int last, ind = int(find(all(a),3)-a.begin());
    //     sol = (ind!=n);
    //     if (ind != n) {
    //         int old = ind;
    //         if (ind) {
    //             ind--;
    //             last = a[ind];
    //             while(ind > 0 && (a[ind-1] == last || last == 0 || a[ind-1] == 0)){
    //                 ind--;
    //                 if (last == 0) last = a[ind];
    //             }
    //             while(ind < old && a[ind] == 0) ind++;
    //             last = a[ind];
    //             assert(last != 0);
    //             if (last != 3) sol++;
    //         }
    //         else last = 3;
    //         rep(i,ind,n-1,1) {
    //             if (a[i] == last) continue;
    //             if (last == 3) sol++;
    //             last = a[i];
    //         }
    //         if (last == 3) sol++;
    //         a.erase(a.begin()+ind,a.end());
    //     }
    // }
    // if (a.empty()) return void(cout << sol << endl);
    // n = sz(a);
    // debug(a,sol);
    auto proc = [](vector<int> &v) -> int {
        assert(find(all(v),0) == v.end());
        debug(v);
        int m = sz(v);
        int last = v.front(), ind = int(find(all(v),3)-v.begin()), sol = (ind!=m);
        if (ind != m) {
            if (ind) {
                ind--;
                last = v[ind];
                while(ind > 0 && (v[ind-1] == last || last == 4 || v[ind-1] == 4)) {
                    ind--;
                    if (last == 4) last = v[ind];
                }
            }
            else last = 3;
            rep(i,ind,m-1,1) {
                if (v[i] == last || (last != 3 && (last == 4 || v[i] == 4))) continue;
                if (last == 3) sol++;
                last = v[i];
            }
            if (last == 3) sol++;
            v.erase(v.begin()+ind,v.end());
        }
        if (v.empty()) return sol;
        m = sz(v);
        debug(v);
        last = v.front();
        assert(find(all(v),3) == v.end());
        rep(i,m) {
            if (v[i] == last || last == 4 || v[i] == 4) continue;
            sol++;
            last = v[i];
        }
        sol++;
        return sol;
    };
    vector<int> v;
    int sol = 0;
    rep(i,n) {
        if (a[i] != 0) {
            v.push_back(a[i]);
            continue;
        }
        if (!v.empty()) sol += proc(v);
        v.clear();
    }
    if (!v.empty()) sol += proc(v);
    cout << sol << endl;
}