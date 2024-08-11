/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sun Aug 11 20:28:49 IST 2024
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

// void solve1() {
//     int n, q; cin >> n >> q;
//     rep(i,n-1) {
//         int a; cin >> a;
//     }
//     vector<int> p(n+1);
//     vector<int> ind(n+1,-1);
//     vector<bool> ok(n+1,true);
//     int sum = n;
//     rep(i,1,n,1) {
//         cin >> p[i];
//         ind[p[i]] = i;
//         int v = p[i]/2;
//         while(v > 0) {
//             if (ind[v] == -1) {
//                 sum--;
//                 ok[p[i]] = false;
//                 break;
//             }
//             v/=2;
//         }
//     }
//     debug(ind,ok);
//     assert(accumulate(ok.begin()+1,ok.end(),0) == sum);
//     while(q--) {
//         int x, y; cin >> x >> y;
//         if (ok[p[x]] == false) {
//             sum++;
//             ok[p[x]] = true;
//         }
//         if (ok[p[x]] == false) {
//             sum++;
//             ok[p[y]] = true;
//         }
//         swap(p[x],p[y]);
//         ind[p[x]] = x;
//         ind[p[y]] = y;
//         int v = p[x]/2;
//         while(v > 0) {
//             if (ind[v] > ind[p[x]]) {
//                 ok[p[x]] = false;
//                 sum--;
//                 break;
//             }
//             v/=2;
//         }
//         v = p[y]/2;
//         while (v > 0) {
//             if (ind[v] > ind[p[y]]) {
//                 ok[p[y]] = false;
//                 sum--;
//                 break;
//             }
//             v/=2;
//         }
//         if (sum == n) cout << "YES\n";
//         else cout << "NO\n";
//     }
// }

class segtree {
public:
    int n;
    vector<int> mntree, mxtree, cval, p, pind, eind;
    segtree(int gn, vector<int> &geind, vector<int> &crng, vector<int> &gp, vector<int> &gpind) {
        n = gn;
        gn<<=1;
        if (__builtin_popcount(gn) != 1) 
            gn = (1<<(32-__builtin_clz(gn)));
        mntree.assign(gn,INT_MAX);
        mxtree.assign(gn,0);
        cval = crng;
        p = gp;
        pind = gpind;
        eind = geind;
        for (int u = 1; u <= n; ++u) {
            mntree[eind[u]+n] = pind[u];
            mxtree[eind[u]+n] = pind[u];
        }
        for (int i = n-1; i > 0; --i) {
            mntree[i] = min(mntree[i<<1],mntree[i<<1|1]);
            mxtree[i] = max(mxtree[i<<1],mxtree[i<<1|1]);
        }
        debug(mntree,mxtree);
    }

    void update(int x, int y) {
        swap(p[x],p[y]);
        pind[p[x]] = x;
        pind[p[y]] = y;
        int ind = eind[p[x]]+n;
        mntree[ind] = x;
        mxtree[ind] = x;
        for(;ind>1;ind>>=1) {
            mntree[ind>>1] = min(mntree[ind],mntree[ind^1]);
            mxtree[ind>>1] = max(mxtree[ind],mxtree[ind^1]);
        }
        ind = eind[p[y]]+n;
        mntree[ind] = y;
        mxtree[ind] = y;
        for(;ind>1;ind>>=1) {
            mntree[ind>>1] = min(mntree[ind],mntree[ind^1]);
            mxtree[ind>>1] = max(mxtree[ind],mxtree[ind^1]);
        }

    }

    int mnq(int l, int r) {
        int res = INT_MAX;
        for(l+=n,r+=n;l<r;l>>=1,r>>=1) {
            if (l&1) res = min(res,mntree[l++]);
            if (r&1) res = min(res,mntree[--r]);
        }
        return res;
    }

    int mnqn(int u) {
        int l = eind[u]+1, r = cval[u];
        if (r == -1) return -1;
        assert(l < r+1);
        return mnq(l,r+1);
    }

    int mxq(int l, int r) {
        int res = -1;
        for(l+=n,r+=n;l<r;l>>=1,r>>=1) {
            if (l&1) res = max(res,mxtree[l++]);
            if (r&1) res = max(res,mxtree[--r]);
        }
        return res;
    }

    int mxqn(int u) {
        int l = eind[u]+1, r = cval[u];
        if (r == -1) return -1;
        assert(l < r+1);
        return mxq(l,r+1);
    }
};

void solve() {
    int n, q; cin >> n >> q;
    rep(i,n-1) {
        int a; cin >> a;
    }
    vector<int> eind(n+1,-1);
    vector<int> crng(n+1), et;
    vector<int> nsz(n+1,0);

    int ecur = 0;
    auto dfs = [&](auto &&self, int u) -> int {
        eind[u] = ecur++;
        int mx = -1;
        et.push_back(u);
        nsz[u] = 1;
        if (2*u <= n) {
            mx = max(mx,self(self,2*u));
            nsz[u] += nsz[2*u];
        }
        if (2*u+1 <= n) {
            mx = max(mx,self(self,2*u+1));
            nsz[u] += nsz[2*u+1];
        }
        crng[u] = mx;
        return max(mx,eind[u]);
    };
    dfs(dfs,1);
    vector<int> p(n+1);
    vector<int> ind(n+1,-1);
    vector<bool> ok(n+1,false);
    int sum = 0;
    rep(i,1,n,1) {
        cin >> p[i];
        ind[p[i]] = i;
    }
    segtree seg(n,eind,crng,p,ind);
    auto check = [&](auto &&self, int v) -> void {
        if (v <= 0) return;
        int vind = ind[v];
        int mxind = seg.mxqn(v), mnind = seg.mnqn(v);
        // debug(endl,v,vind,mxind,mnind);
        if (mxind == -1) {
            assert(mnind == -1);
            if (!ok[v]) sum++;
            ok[v] = true;
        }
        else if (mnind == vind+1 && mxind == vind+nsz[v]-1) {
            if (!ok[v]) sum++;
            ok[v] = true;
        }
        else {
            if (ok[v]) sum--;
            ok[v] = false;
        }
        self(self,v/2);
    };
    rep(i,1,n,1) {
        check(check,i);
    }
    // check(check,2);
    // check(check,3);
    debug(ok,ind,et,eind,crng,sum,nsz);
    while(q--) {
        int x, y; cin >> x >> y;
        // continue;
        swap(p[x],p[y]);
        ind[p[x]] = x;
        ind[p[y]] = y;
        // todo seg update
        seg.update(x,y);
        check(check,p[x]);
        check(check, p[y]);
        debug(endl,ok);
        if (sum == n) cout << "YES\n";
        else cout << "NO\n";
    }
}