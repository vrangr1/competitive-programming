/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Fri May 31 15:51:14 IST 2024
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
    vector<int> a(n), b(n), p(n);
    rep(i,n) {
        cin >> a[i];
        b[i] = a[i];
        p[i] = a[i];
        if (a[i] == -1) continue;
        p[i] = 31-__builtin_clz(a[i]);
    }
    if (a[0] == -1) {
        int ind = 0;
        while(ind < n && a[ind] == -1) ind++;
        if (ind == n) {
            rep(i,n)
                if (i%2) cout << "2" << " \n"[i==n-1];
                else cout << "1" << " \n"[i==n-1];
            return;
        }
        rep(i,ind-1,0,-1) {
            assert(b[i] == -1);
            assert(b[i+1] != -1);
            if (b[i+1] == 1) {
                b[i] = 2;
                continue;
            }
            b[i] = b[i+1]/2;
        }
    }
    if (b.back() == -1) {
        int ind = n-1;
        while(ind >= 0 && b[ind] == -1) ind--;
        assert(ind >= 0);
        rep(i,ind+1,n-1,1) {
            assert(b[i] == -1);
            assert(b[i-1] != -1);
            if (b[i-1] == 1) {
                b[i] = 2;
                continue;
            }
            b[i] = b[i-1]/2;
        }
    }
    vector<int> inds;
    rep(i,n) {
        if (b[i] > 0) inds.push_back(i);
    }
    int m = sz(inds);
    assert(m>0);
    if (m == n) {
        rep(i,n-1) {
            if (b[i] >= b[i+1]) {
                if (b[i+1] != b[i]/2) return void(cout << "-1\n");
                continue;
            }
            if (b[i] != b[i+1]/2) return void(cout << "-1\n");
        }
        print_vec(b);
        return;
    }
    // debug(p,b,inds);
    // return;
    rep(i,m-1) {
        if (inds[i]+1 == inds[i+1]) continue;
        assert(p[inds[i+1]] >= 0 && p[inds[i]] >= 0);
        if (inds[i+1]-inds[i] < abs(p[inds[i+1]]-p[inds[i]])) return void(cout << "-1\n");
        int d = abs(inds[i+1]-inds[i] - abs(p[inds[i+1]]-p[inds[i]]));
        if (d%2) return void(cout << "-1\n");
        if (d) {
            if (p[inds[i]] < p[inds[i+1]]) {
                int j = inds[i+1]-1;
                while(true) {
                    assert(b[j] == -1);
                    assert(b[j+1] != -1);
                    assert(p[j+1] != -1);
                    assert(p[j] == -1);
                    assert(j > inds[i]);
                    b[j] = b[j+1]/2;
                    p[j] = p[j+1]-1;
                    if (abs(j-inds[i]-abs(p[j]-p[inds[i]])) == 0) break;
                    if (p[j] == 0) {
                        assert(b[j] == 1);
                        p[j-1] = 1;
                        b[j-1] = 2;
                        j-=2;
                        if (j == inds[i]) {
                            assert(b[j] == 1);
                            break;
                        }
                        continue;
                    }
                    j--;
                }
                if (j == inds[i]) continue;
                assert(j > inds[i]);
                assert(abs(j-inds[i]-abs(p[j]-p[inds[i]])) == 0);
                assert(p[j] < p[inds[i]]);
                inds[i]++;
                while(inds[i] < j) {
                    assert(b[inds[i]] == -1);
                    assert(b[inds[i]-1] != -1);
                    b[inds[i]] = b[inds[i-1]]/2;
                    inds[i]++;
                }
                assert(b[j] != -1 && b[j-1] != -1);
                if (b[j] != b[j-1]/2) return void(cout << "-1\n");
                continue;
            }
            if (p[inds[i]] > p[inds[i+1]]) {
                int j = inds[i]+1;
                while(true) {

                    assert(b[j] == -1);
                    assert(b[j-1] != -1);
                    assert(p[j-1] != -1);
                    assert(p[j] == -1);
                    assert(j < inds[i+1]);
                    b[j] = b[j-1]/2;
                    p[j] = p[j-1]-1;
                    if (abs(inds[i+1]-j-abs(p[j]-p[inds[i+1]])) == 0) break;
                    if (p[j] == 0) {
                        assert(b[j] == 1);
                        p[j+1] = 1;
                        b[j+1] = 2;
                        j+=2;
                        if (j == inds[i+1]) {
                            assert(b[j] == 1);
                            break;
                        }
                        continue;
                    }
                    j++;
                }
                if (j == inds[i+1]) continue;
                assert(j < inds[i+1]);
                assert(abs(inds[i+1]-j-abs(p[j]-p[inds[i+1]])) == 0);
                assert(p[j] < p[inds[i+1]]);
                int k = inds[i+1];
                k--;
                while(k > j) {
                    assert(b[k] == -1);
                    assert(b[k+1] != -1);
                    b[k] = b[k+1]/2;
                    assert(b[k] >= 1);
                    k--;
                }
                assert(b[j] != -1 && b[j+1] != -1);
                if (b[j] != b[j+1]/2) return void(cout << "-1\n");
                continue;
            }
            assert(p[inds[i]] == p[inds[i+1]]);
            // if (p[inds[i]] == p[inds[i+1]]) {
            int l = inds[i], r = inds[i+1];
            l++;
            r--;
            while(l <= r) {
                assert(b[l-1] != -1 && b[r+1] != -1);
                assert(b[l] == -1 && b[r] == -1);
                if (l == r) {
                    if (b[l-1]/2 != b[r+1]/2) return void(cout << "-1\n");
                    if (b[l-1] == 1) b[l] = 2;
                    else b[l] = b[l-1]/2;
                    break;
                }
                if (b[l-1] == 1) b[l] = 2;
                else b[l] = b[l-1]/2;
                if (b[r+1] == 1) b[r] = 2;
                else b[r] = b[r+1]/2;
                l++;
                r--;
            }
            continue;
            // }
            // int j = inds[i]+1;
            // while(d > 0) {
            //     assert(j < inds[i+1]);
            //     assert(b[j] == -1);
            //     assert(b[j-1] != -1);
            //     if (b[j-1] == 1) {
            //         b[j] = 2;
            //         b[j+1] = b[j-1];
            //         j = j+2;
            //         d-=2;
            //         continue;
            //     }
            //     b[j] = b[j-1]/2;
            //     b[j+1] = b[j-1];
            //     j+=2;
            //     d-=2;
            // }
            // if (j == inds[i+1]) continue;
            // p[j-1] = p[inds[i]];
            // inds[i] = j-1;
        }
        assert(abs(inds[i+1]-inds[i]-abs(p[inds[i+1]]-p[inds[i]])) == 0);
        // if (d == 0) {
        if (p[inds[i]] > p[inds[i+1]]) {
            rep(j,inds[i]+1,inds[i+1]-1,1) {
                assert(b[j] == -1);
                assert(b[j-1] != -1);
                b[j] = b[j-1]/2;
            }
            if (b[inds[i+1]] != b[inds[i+1]-1]/2) return void(cout << "-1\n");
            continue;
        }
        assert(p[inds[i]] < p[inds[i+1]]);
        rep(j,inds[i+1]-1,inds[i]+1,-1) {
            assert(b[j] == -1);
            assert(b[j+1] != -1);
            b[j] = b[j+1]/2;
        }
        if (b[inds[i]] != b[inds[i]+1]/2) return void(cout << "-1\n");
        // continue;
        // }
    }
    rep(i,n-1) {
        if (b[i] >= b[i+1]) {
            if (b[i+1] != b[i]/2) return void(cout << "-1\n");
            continue;
        }
        if (b[i] != b[i+1]/2) return void(cout << "-1\n");
    }
    rep(i,n){
        if (a[i] == -1) assert(b[i] != -1);
        else assert(b[i] == a[i]);
    }
    print_vec(b);
}