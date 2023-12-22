/***************************************************
* AUTHOR : Anav Prasad
* Nick   : vrangr
****************************************************/
#include <iostream>
#include <vector>
#include <string.h>
#include <ctype.h>
#include <set>
#include <stdlib.h>
#include <map>
#include <iterator>
#include <iomanip>
#include <algorithm>
#include <climits>
#include <numeric>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <forward_list>
#include <bit>
#include <bitset>
#include <array>
#include <assert.h>
#define debug(...)
#ifdef LOCAL
    #undef debug
    #include <algo/debug.hpp>
    const bool DEBUG = true;
#else
    [[maybe_unused]] const bool DEBUG = false;
#endif

using namespace std;

#define int long long

const int mod = 1e9 + 7;
const int N = 2e5 + 10;

vector<int> adj[N];
int a[N];
int dp[N][2];
int dp1[N];
int vis[N];

const int MAXN = 2e5;
int SUMN = 0;

int pow_(int a, int p){
    if(p == 0) return 1;
    if(p&1){
        int k = a * pow_(a, p-1);
        k %= mod;
        return k;
    }
    int k = pow_(a, p/2);
    k *= k;
    k %= mod;
    return k;
}


int dfs(int v, int chance, int p){
    if(dp[v][chance] != -1) return dp[v][chance];
    if(chance&1){
        int ans = 1e18;
        for(auto &x: adj[v]){
            if(x == p) continue;
            ans = min(ans, a[x - 1] + dfs(x, chance^1, v));
        }
        if(ans == 1e18) ans = 0;
        return dp[v][chance] = ans;
    }
    int ans = 0;
    int next = -1;
    for(auto &x: adj[v]){
        if(x == p) continue;
        if(dfs(x, chance^1, v) + a[x - 1] > ans){
            next = x;
            ans = a[x - 1] + dfs(x, chance^1, v);
        }
        if(dfs(x, chance^1, v) + a[x - 1] == ans){
            if(x < next) {
                next = x;
            }
        }
    }
    dp1[v] = next;
    return dp[v][chance] = ans;
}

int solve(int v, int chance, int p){
    if(dp[v][chance] != -1) return dp[v][chance]; 
    if(chance&1){
        int ans = 0;
        int nodes = 0;
        for(auto &x: adj[v]){
            if(x == p) continue;
            ans += (a[x - 1] + solve(x, chance ^ 1, v)) % mod;
            ans %= mod;
            nodes++;
        }
        if(nodes == 0) return 0;
        int inv = pow_(nodes, mod - 2);
        ans *= inv;
        ans %= mod;
        return dp[v][chance] = ans;
    }
    if(dp1[v] == -1) return 0;
    return dp[v][chance] = ((a[dp1[v] - 1] +  solve(dp1[v], chance ^ 1, v)) % mod);
}

void clear(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 2; j++) dp[i][j] = -1;
        dp1[i] = -1;
        adj[i].clear();
    }
}

void chk(int v, int p) {
    assert(vis[v] == 0);
    vis[v] = 1;
    for(auto &x: adj[v]) {
        if(x == p) continue;
        chk(x, v);
    }
}

void solve() {
    int n; cin>>n;
    SUMN += n;
    clear(n + 5);
    for(int i = 0; i < n; i++) cin>>a[i], assert(a[i] <= 1e9 && a[i] >= 1);
    for(int i = 0; i < n - 1; i++){
        int a, b; cin>>a>>b;
        assert(a != b);
        assert(1 <= a && a <= n);
        assert(1 <= b && b <= n);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1; i <= n; i++) vis[i] = 0;
    chk(1, -1);
    for(int i = 1; i <= n; i++) assert(vis[i] == 1);
    dfs(1, 0, -1);
    for(int i = 0; i <= n; i++) for(int j = 0; j < 2; j++) dp[i][j] = -1;
    cout<<(a[0] + solve(1, 0, -1))%mod<<"\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); 
    int t; cin>>t;
    assert(t <= 1000);
    while(t--) solve();
    assert(SUMN <= MAXN);
}