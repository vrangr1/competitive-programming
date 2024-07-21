/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sun Jul 21 20:31:25 IST 2024
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
    int n; cin >> n;
    string s; cin >> s;
    if (n == 1) {
        cout << "0 0\n";
        return;
    }
    if (*max_element(all(s)) == '0') {
        rep(m,0,n,1) {
            cout << max(m-1,0) << " \n"[m==n];
        }
        return;
    }
    if (*min_element(all(s)) == '1') {
        rep(m,0,n,1) {
            cout << max((n-m)-1,0) << " \n"[m==n];
        }
        return;
    }
    vector<pair<int,int>> segs, ogsegs;
    int last = -1, z = 0, rem = int(count(all(s),'0'));
    vector<int> prob, ogprob;
    rep(i,n) {
        if (s[i] == '1') {
            if (i == 0 || i-last > 1) {
                if (i == 0 || i == n-1) ogsegs.emplace_back(1,1);
                else ogsegs.emplace_back(0,1);
            }
            else {
                assert(!ogsegs.empty());
                ogsegs.back().second++;
                if (i == n-1) ogsegs.back().first = 1;
            }
            if (i-last == 1) {
                z += (last!=-1);
                last = i;
                continue;
            }
            if (last == -1) segs.emplace_back(1,i-last-1);
            else segs.emplace_back(0,i-last-1);
            last = i;
        }
    }
    if (n-last > 1)
        segs.emplace_back(1,n-last-1);
    sort(all(segs));
    sort(rall(ogsegs));
    int m = sz(segs), k = sz(ogsegs);
    vector<int> segsum(m), res(m), ogsegsum(k), ogres(k);
    rep(i,m) {
        auto [t,len] = segs[i];
        if (t == 1) prob.push_back(i);
        segsum[i] = len;
        res[i] = len+1;
        if (i) {
            segsum[i] += segsum[i-1];
            res[i] += res[i-1];
        }
    }
    rep(i,k) {
        auto [t,len] = ogsegs[i];
        if (t == 1) ogprob.push_back(i);
        ogsegsum[i] = len;
        ogres[i] = len+1;
        if (i) {
            ogsegsum[i] += ogsegsum[i-1];
            ogres[i] += ogres[i-1];
        }
    }
    assert(sz(prob) <= 2);
    debug(ogsegs,ogsegsum,ogres,ogprob,segs,segsum,res,prob);
    rep(b,0,n,1) {
        if (b > rem) {
            int ct = b-rem;
            auto it = lower_bound(all(ogsegsum),ct);
            if (it == ogsegsum.end()) {
                cout << n-1-ogres.back()+sz(ogprob) << " \n"[b==n];
                continue;
            }
            int ind = int(it-ogsegsum.begin());
            int cur = n-1 - (ind?ogres[ind-1]+ct-ogsegsum[ind-1]+1:ct+1);
            rep(j,sz(ogprob)) {
                if (ogprob[j] <= ind) cur++;
            }
            cout << cur << " \n"[b==n];
            continue;
        }
        if (!b) {
            cout << z << " \n"[b==n];
            continue;
        }
        auto it = lower_bound(all(segsum),b);
        if (it == segsum.end()) {
            cout << z + res.back() << " \n"[b==n];
            continue;
        }
        int ind = int(it-segsum.begin());
        // debug(endl,b,ind);
        int cur = z + (ind?res[ind-1]+b-segsum[ind-1]:b);
        rep(j,sz(prob)) {
            if (prob[j] < ind) cur--;
        }
        if (segs[ind].second == b-(ind?segsum[ind-1]:0) && find(all(prob),ind) == prob.end()) cur++;
        cout << cur << " \n"[b==n];
    }
}