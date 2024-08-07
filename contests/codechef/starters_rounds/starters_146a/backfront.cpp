/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed Aug  7 20:08:53 IST 2024
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

const int b = 0, ba = 1, bac = 2, back = 3, a = 4, ac = 5, ack = 6, c = 7, ck = 8, k = 9;
const int f = 0, fr = 1, fro = 2, fron = 3, front = 4, r = 5, ro = 6, ron = 7, ront = 8,
    o = 9, on = 10, ont = 11, n = 12, nt = 13, t = 14;
const string bstr = "back", fstr = "front";

void solve() {
    int m; cin >> m;
    string s; cin >> s;
    vector<vector<int>> dpb(m,vector<int>(10,0)), dpf(m,vector<int>(15,0));
    map<char,bool> bk = {{'b',true},{'a',true},{'c',true},{'k',true}};
    map<char,bool> ft = {{'f',true},{'r',true},{'o',true},{'n',true},{'t',true}};
    map<char,int> bi, fi;
    rep(i, sz(bstr))
        bi[bstr[i]] = i;
    rep(i,sz(fstr))
        fi[fstr[i]] = i;
    rep(i,m) {
        if (i) {
            dpb[i] = dpb[i-1];
            dpf[i] = dpf[i-1];
        }
        if (!bk[s[i]] && !ft[s[i]]) continue;
        if (bk[s[i]]) {
            switch(s[i]) {
                case 'b': 
                    dpb[i][b]++;
                    break;
                case 'a':
                    if (dpb[i][b] > 0) {
                        dpb[i][b]--;
                        dpb[i][ba]++;
                    }
                    else {
                        dpb[i][a]++;
                    }
                    break;
                case 'c':
                    if (dpb[i][ba] > 0) {
                        dpb[i][ba]--;
                        dpb[i][bac]++;
                    }
                    else if (dpb[i][a] > 0) {
                        dpb[i][a]--;
                        dpb[i][ac]++;
                    }
                    else dpb[i][c]++;
                    break;
                case 'k':
                    if (dpb[i][bac]) {
                        dpb[i][bac]--;
                        dpb[i][back]++;
                    }
                    else if (dpb[i][ac] > 0) {
                        dpb[i][ac]--;
                        dpb[i][ack]++;
                    }
                    else if (dpb[i][c]) {
                        dpb[i][c]--;
                        dpb[i][ck]++;
                    }
                    else {
                        dpb[i][k]++;
                    }
                    break;
            }
        }
        if (ft[s[i]]) {
            switch(s[i]) {
                case 'f': 
                    dpf[i][f]++;
                    break;
                case 'r':
                    if (dpf[i][f] > 0) {
                        dpf[i][f]--;
                        dpf[i][fr]++;
                    }
                    else {
                        dpf[i][r]++;
                    }
                    break;
                case 'o':
                    if (dpf[i][fr] > 0) {
                        dpf[i][fr]--;
                        dpf[i][fro]++;
                    }
                    else if (dpb[i][r] > 0) {
                        dpf[i][r]--;
                        dpf[i][ro]++;
                    }
                    else dpf[i][o]++;
                    break;
                case 'n':
                    if (dpf[i][fro]) {
                        dpf[i][fro]--;
                        dpf[i][fron]++;
                    }
                    else if (dpf[i][ro] > 0) {
                        dpf[i][ro]--;
                        dpf[i][ron]++;
                    }
                    else if (dpf[i][o]) {
                        dpf[i][o]--;
                        dpf[i][on]++;
                    }
                    else {
                        dpf[i][n]++;
                    }
                    break;
                case 't':
                    if (dpf[i][fron]) {
                        dpf[i][fron]--;
                        dpf[i][front]++;
                    }
                    else if (dpf[i][ron]) {
                        dpf[i][ron]--;
                        dpf[i][ront]++;
                    }
                    else if (dpf[i][on]) {
                        dpf[i][on]--;
                        dpf[i][ont]++;
                    }
                    else if (dpf[i][n]) {
                        dpf[i][n]--;
                        dpf[i][nt]++;
                    }
                    else dpf[i][t]++;
                    break;
            }
        }
    }
    debug(dpb[m-1],dpf[m-1]);
    int k1 = dpb[m-1][back], k2 = dpf[m-1][front];
    int sol = m - k1*4 - k2*5;
    debug(m,k1,k2);
    assert(sol>=0);
    if (k1 > 0) {
        sol -= dpb[m-1][ack]*3 + dpf[m-1][ront]*4;
    }
    if (k2 > 0)
        sol -= dpb[m-1][bac]*3 + dpf[m-1][fron]*4;
    if (k1 > 0) {
        int ct = min(k1-1,dpf[m-1][ont]);
        k1-=ct;
        sol -= 3*ct;
    }
    if (k2 > 0) {
        int ct = min(k2-1,dpf[m-1][fro]);
        k2-=ct;
        sol -= 3*ct;
    }
    if (k1 > 0) {
        int ct = min((k1-1)/2,dpf[m-1][nt]);
        k1 -= 2*ct;
        sol -= 2*ct;
    }
    if (k2 > 0) {
        int ct = min((k2-1)/2,dpf[m-1][fr]);
        k2 -= 2*ct;
        sol -= 2*ct;
    }
    if (k1 > 0) {
        int ct = min((k1-1)/2,dpb[m-1][ck]);
        k1 -= 2*ct;
        sol -= 2*ct;
    }
    if (k2 > 0) {
        int ct = min((k2-1)/2,dpb[m-1][ba]);
        k2 -= 2*ct;
        sol -= 2*ct;
    }
    if (k1 > 0) {
        int ct = min((k1-1)/3,dpf[m-1][t]);
        k1 -= 3*ct;
        sol -= ct;
    }
    if (k2 > 0) {
        int ct = min((k2-1)/3,dpf[m-1][f]);
        k2 -= 3*ct;
        sol-=ct;
    }
    if (k1 > 0) {
        int ct = min((k1-1)/3,dpb[m-1][k]);
        k1 -= 3*ct;
        sol-=ct;
    }
    if (k2 > 0) {
        int ct = min((k2-1)/3,dpb[m-1][b]);
        k2-=3*ct;
        sol-=ct;
    }
    assert(sol >= 0 && k1 >= 0 && k2 >= 0);
    int ct = k1+k2;
    if (ct%5 == 0) ct = 0;
    else if (ct%4 == 0) ct = 0;
    else {
        while(ct >= 5 && ct%4) {
            ct-=5;
        }
        ct%=4;
    }
    cout << sol + ct << endl;
}