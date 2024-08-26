/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sun Aug 25 20:12:03 IST 2024
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
    int n; cin >> n;
    string s; cin >> s;
    auto check = [](int i, int j, string &o) -> bool {
        assert(i < j);
        if (o[i] == o[j]) return true;
        rep(k,i,j-1,1) {
            if (o[k] == o[k+1]) continue;
            if (o[k] == o[i] && o[k+1] == o[j]) continue;
            return true;
        }
        return false;
    };
    auto get = [&](string &o) -> int {
        int sol = 0;
        rep(i,n-1) {
            rep(j,i+1,n-1,1) {
                sol += check(i,j,o);
            }
        }
        return sol;
    };
    sort(all(s));
    string sols = s;
    int sol = get(s);
    do {
        int temp = get(s);
        if (temp > sol) {
            sol = temp;
            sols = s;
        }
    } while(next_permutation(all(s)));
    cout << sols << endl;
    debug(sol);
}

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> ct(26,0);
    rep(i,n) ct[s[i]-'a']++;
    vector<int> order(26);
    iota(all(order),0);
    sort(all(order),[&](const int &i, const int &j) {
        return ct[i] > ct[j];
    });
    string sol;
    while(n--) {
        // debug(ct);
        int ind = order[0];
        // if (ct[order[0]] == 0) {
        //     debug(order);
        //     debug(n);
        //     exit(0);
        // }
        assert(ct[order[0]] > 0);
        if (sol.empty() || sol.back() != (char)(ind+'a') || ct[order[1]] == 0) {
            sol.push_back((char)(ind+'a'));
            ct[order[0]]--;
        }
        else {
            sol.push_back(char(order[1]+'a'));
            ct[order[1]]--;
        }
        sort(all(order),[&](const int &i, const int &j) {
            return ct[i] > ct[j];
        });
    }
    cout << sol << endl;
}