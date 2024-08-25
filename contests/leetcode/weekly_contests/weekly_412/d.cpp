/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sun Aug 25 08:28:29 IST 2024
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

class Solution {
public:
    int countPairs(vector<int>& a) {
        int sol = 0;
        map<int,int> mp;
        for (int &v : a) mp[v]++;
        debug(mp);
        for (int v : a) {
            debug('\n');
            debug(v);
            string s = to_string(v);
            int n = int(s.size());
            sol += mp[v];
            set<int> st = {v};
            for (int i = 0; i < n-1; ++i) {
                for (int j = i+1; j < n; ++j) {
                    swap(s[i],s[j]);
                    int cur = stoi(s);
                    if (st.find(cur) == st.end()) {
                        sol += mp[cur];
                        if (s.front() == '0') sol += mp[cur];
                        debug(s);
                        debug(mp[cur]);
                    }
                    // else {
                    //     swap(s[i],s[j]);
                    //     continue;
                    // }
                    st.insert(cur);
                    for (int ii = 0; ii < n-1; ++ii) {
                        for (int jj = ii+1; jj < n; ++jj) {
                            if ((i == jj && j == ii) || (i == ii && j == jj)) continue;
                            swap(s[ii],s[jj]);
                            int cur2 = stoi(s);
                            // assert(cur2 != v);
                            if (st.find(cur2) == st.end()) {
                                debug(cur2);
                                sol += mp[cur2];
                                debug(mp[cur2]);
                                if (s.front() == '0') sol += mp[cur2];
                            }
                            st.insert(cur2);
                            swap(s[ii],s[jj]);
                        }
                    }
                    swap(s[i],s[j]);
                }
            }
            debug(sol);
        }
        return (sol-int(a.size()))/2;
    }
};

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    Solution sol;
    cout << sol.countPairs(a) << endl;
}