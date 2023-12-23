#if 0
    me=`basename $0 .cpp`
    rm -f $me $me.out
    only_compile=${1:-0}
    if [ $only_compile == compile ]; then
        g++ -std=c++20 $me.cpp -o $me -Wall -O2 -Wextra -Wno-sign-conversion -Wshadow
        exit
    fi
    g++ -std=c++20 -DLOCAL $me.cpp -o $me -Wall -O2 -Wextra -Wno-sign-conversion -Wshadow
    if test -f $me; then
	    ./$me > $me.out
        echo "\noutput begins now:"
        cat $me.out
    	rm $me $me.out
    fi
    exit
#endif
/***************************************************
* AUTHOR : Anav Prasad
* Nick   : vrangr
****************************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <ctype.h>
#include <unordered_set>
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
#include <unordered_map>
#include <bit>
#include <bitset>
#include <random>
#include <assert.h>
#define debug(...)
#ifdef LOCAL
    #undef debug
    #include <algo/debug.hpp>
    const bool DEBUG = true;
#endif

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0)
#define TEST int T;cin>>T;while(T--)solve();
#define TEST1 solve();
#define GET_MACRO(_1,_2,_3,_4,NAME,...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, forsn, qwe, forn)(__VA_ARGS__)
#define repll(...) GET_MACRO(__VA_ARGS__, forsnll, qwe, fornll)(__VA_ARGS__)
#define qwe(r,t,y)
#define forn(i, n) for (int i = 0; i < n; i++)
#define fornll(i, n) for (ll i = 0ll; i < n; i++)
#define forsn(i, st, end, d) for(int i = st; (d>0?i<=end:i>=end); i+=d)
#define forsnll(i, st, end, d) for(ll i = st; (d>0?i<=end:i>=end); i+=(ll)d)
#define all(x) (x).begin(), (x).end()
#define pass (void)0
#define space " "
#define yes "YES\n"
#define no "NO\n"
void solve();

int main(){
	fastIO;
	TEST;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

// vector<ll> ftree(2e5+2);
vector<ll> ftree(1);

int get_sum(int index){
    ll sum = 0ll;
    index++;
    while(index>0ll){
        sum += ftree[index]; 
        index -= (index&(-index));
    }
    return sum;
}

void update_ftree(int index, ll val, int n){
    index++;
    while (index <= n){
        ftree[index] += val;
        index += index & (-index);
    }
}

void construct_ftree(vector<ll> &arr, int n) 
{ 
    fill(ftree.begin(), ftree.begin()+n+1,0);
    rep(i,n)
        update_ftree(i,arr[i],n);
}

int binary_search(int left, int right, const ll target, int n){
    if (left > right) return -1;
    if (left == right) return (get_sum(left) == target?left:-1);
    int mid = (left+right+1)/2;
    ll sum = get_sum(mid);
    if (sum == target) return mid;
    if (sum < target) return binary_search(mid,right, target, n);
    return binary_search(left,mid-1,target,n);
}

int my_lower_bound(int left, int right, const ll target, int n){
    if (left == right) return left;
    int mid = (left+right);
    ll sum = get_sum(mid);
    if (sum >= target) return my_lower_bound(left,mid,target,n);
    return my_lower_bound(mid+1,right,target,n);
}

void solve1(){
    int n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> dp(n);
    dp[n-1] = 1;
    vector<ll> psums(n,0ll);
    construct_ftree(psums,n);
    rep(i,n-2,0,-1){
        if (a[i] == dp[i+1]+1){
            dp[i] = 0;
            update_ftree(i+1,-dp[i+1],n);
            update_ftree(i,dp[i+1]+1ll,n);
            continue;
        }
        int ind;
        if (a[i] > dp[i+1]){
            ind = binary_search(i+1,n-1,a[i]-dp[i+1],n);
            if (ind != -1){
                dp[i] = 0;
                update_ftree(i,a[i],n);
                continue;
            }
            else{
                
            }
        }
        assert(get_sum(i+1) <= a[i]);
        ll target = max(a[i]-dp[i+1],0ll);
        if (get_sum(n-1) < target){
            dp[i] = dp[i+1]+1ll;
            continue;
        }
        ind = my_lower_bound(i+1,n-1,target,n);
        ll cursum = get_sum(ind);
        assert(cursum >= target);
        if (cursum > a[i]){
            
        }
    }
}


void solve(){
    int n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<bool> pos(n);
    pos[n-1]=false;
    rep(i,n-2,0,-1){
        if (i+a[i] >= n) pos[i] = false;
        else if (i + a[i] == n-1) pos[i] = true;
        else pos[i] = pos[i+a[i]+1];
    }
    if (pos[0]) return void (cout << "0\n");
    vector<ll> mindist(n,INT_MAX);
    rep(i,n-2,0,-1){
        if (pos[i]) mindist[i] = 0ll;
        else mindist[i] = mindist[i+1]+1ll;
    }
    vector<ll> dp(n);
    dp[n-1] = 1;
    rep(i,n-2,0,-1){
        if (pos[i]) dp[i] = 0;
        else{
            dp[i] = dp[i+1]+1;
            dp[i] = min(mindist[i],dp[i]);
            if (a[i]+i >= n-1) continue;
            dp[i] = min(dp[i], dp[i+a[i]+1]);
            dp[i] = min(dp[i],mindist[i+a[i]+1]);
        }
    }
    cout << dp[0] << endl;
}