/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sat Sep 14 20:24:33 IST 2024
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

const string name = "narek";

void solve() {
    int n, m; cin >> n >> m;
    vector<string> x(n);
    rep(i,n) cin >> x[i];
    // map<char,set<pair<int,char>>> mp;
    auto nxt = [](char ch) -> char {
        int ind = int(find(all(name),ch) - name.begin());
        return name[(ind+1)%5];
    };
    auto get = [](char ch) -> int {
        int ind = int(find(all(name),ch) - name.begin());
        return (ind+1)%5;
    };
    int sol = 0;
    map<char,int> mp;
    mp['k'] = 0;
    for (auto &s : x) {
        debug(endl,s);
        vector<pair<char,int>> ins;
        for (char ch : "narek") {
            if (mp.find(ch) == mp.end()) continue;
            int sc = mp[ch]+get(ch), last = get(ch);
            char cch = nxt(ch);
            for (auto c : s) {
                assert(last < 5);
                if (find(all(name),c) == name.end()) continue;
                if (cch == c) {
                    if (c == 'k') {
                        sc+=5;
                        last = 0;
                    }
                    else {
                        last++;
                    }
                    cch = nxt(cch);
                    continue;
                }
                sc--;
            }
            assert(last < 5);
            char lch = name[(last+4)%5];
            sc-=get(lch);
            debug(ch,lch,sc);
            ins.emplace_back(lch,sc);
        }
        for (auto [ch, sc] : ins) {
            if (mp.find(ch) == mp.end()) mp[ch] = sc;
            else mp[ch] = max(mp[ch],sc);
        }
        debug(mp);
    }
    for (auto [_,sc] : mp)
        sol = max(sol,sc);
    cout << sol << endl;
}