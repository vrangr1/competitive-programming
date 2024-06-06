/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Sat Jun  1 06:22:29 IST 2024
****************************************************/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
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
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// END OF SNIPPETS

int main() {
	fastIO;
	TEST1;
#ifdef LOCAL
    cout << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

class segtree {
public:
    int n;
    vector<int> tree;
    segtree(int gn) {
        n = gn;
        gn<<=1;
        if (__builtin_popcount(gn) != 1)
            gn = 1<<(32-__builtin_clz(gn));
        tree.assign(gn,0);
    };

    void clear() {
        fill(all(tree),0ll);
    }
    
    void update(int ind) {
        for(tree[ind+=n]++;ind > 1; ind>>=1)
            tree[ind>>1] = tree[ind]+tree[ind^1];
    }

    int query(int l, int r) {
        int res = 0;
        for (l+=n,r+=n;l<r;l>>=1,r>>=1) {
            if (l&1) res += tree[l++];
            if (r&1) res += tree[--r];
        }
        return res;
    }
};

void solve() {
    int n; cin >> n;
    vector<int> p(n), q(n);
    rep(i,n) cin >> p[i];
    rep(i,n) cin >> q[i];
    segtree st(n);
    auto get_fn = [n,&st](vector<int> &p) -> vector<int> {
        vector<int> sol(n,0);
        rep(i,n-1,0,-1) {
            sol[i] = st.query(0,p[i]);
            assert(sol[i] < n-i);
            st.update(p[i]);
        }
        st.clear();
        return sol;
    };
    vector<int> pfn = get_fn(p), qfn = get_fn(q);
    vector<int> diff(n);
    rep(i,n)
        diff[i] = n-i-1-pfn[i];
    auto greater = [n](vector<int> &a, vector<int> &b) -> bool {
        rep(i,(int)n) 
            if (a[i] > b[i]) return true;
            else if (a[i] < b[i]) return false;
        return false;
    };
    auto comp_diff = [&n,&greater](vector<int> &a, vector<int> &b) -> void {
        assert(greater(a,b));
        rep(i,n) {
            if (a[i] >= b[i]) {
                a[i] -= b[i];
                continue;
            }
            assert(i);
            bool fd = false;
            rep(j,i-1,0,-1) {
                if (a[j]) {
                    a[j]--;
                    fd = true;
                    rep(k,j+1,i-1,1)
                        a[j] = n-k-1;
                    break;
                }
            }
            assert(fd);
            a[i] = n-i+a[i]-b[i];
            assert(a[i] < n-i);
        }
    };
    debug(p,endl,q,endl,pfn,endl,qfn,endl,diff,endl);
    vector<int> sol(n);
    if (greater(qfn,diff)) {
        debug('g');
        comp_diff(qfn,diff);
        vector<int> temp(n,0);
        temp[n-2] = 1;
        sol = qfn;
        comp_diff(sol,temp);
    }
    else {
        int carry = 0;
        rep(i,n-1,0,-1) {
            sol[i] = pfn[i] + qfn[i] + carry;
            carry = 0;
            while(sol[i] >= n-i) {
                carry++;
                sol[i] -= n-i;
            }
        }
        assert(carry == 0);
    }
    ordered_set ost;
    rep(i,n) ost.insert(i);
    vector<int> psol(n);
    debug(sol);
    rep(i,n) {
        psol[i] = *ost.find_by_order(sol[i]);
        ost.erase(psol[i]);
    }
    print_vec(psol);
}