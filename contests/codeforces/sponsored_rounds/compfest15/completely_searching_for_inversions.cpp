#if 0
    me=`basename $0 .cpp`
    rm -f $me
    rm -f $me.out
    g++ -std=c++20 $me.cpp -o $me
    if test -f $me; then
	    ./$me > $me.out
    	rm $me
        echo "\noutput begins now:"
        cat $me.out
        rm $me.out
    fi
    exit
#endif

/***************************************************
* AUTHOR : Anav Prasad
* Nick : vrangr
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
#include <unordered_map>
#include <bit>
#include <bitset>
#include <assert.h>
#define debug false
#define mod 998244353

using namespace std;

#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0)
#define TEST int T;cin>>T;while(T--)solve();
#define TEST1 solve();
#define forn(i, n) for (int i = 0; i < n; i++)
#define forsn(i, st_val, n) for (int i = st_val; i <= n; ++i)
#define forr(i, n) for (int i = n - 1; i >= 0; --i)
#define forsr(i, st_val, n) for (int i = st_val; i >= n; --i)
#define pb1(a) push_back(a)
#define pb2(a,b) push_back({a, b})
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define pb(...) GET_MACRO(__VA_ARGS__, pb1, pb2)(__VA_ARGS__)
#define pass (void)0
#define print_var(x) cout << #x << ": " << x << "\n";
#define print_iter(x) cout << "*" << #x << ": " << *x << endl;
#define print_arr(arr) cout << #arr << ": ";print(arr);
#define print_pair(pr) cout << #pr << ": ";print(pr);
#define space " "
#define yes "YES\n"
#define no "NO\n"

typedef long long int ll;
typedef unsigned long long int ull;
template <typename type> void print(const vector<vector<type> > &arr);
template <typename type> void print(const vector<type> &arr);
template <typename type> void off_print(const vector<type> &arr);
template <typename t1, typename t2> void print(const vector<pair<t1,t2> > &arr);
template <typename t1, typename t2> void print(const vector<vector<pair<t1,t2> > > &arr);
template <typename t1, typename t2> void print(const pair<t1, t2> &p);

void solve();

int main(){
	fastIO;
	TEST1;
	return 0;
}


template <typename type> void print(const vector<vector<type> > &arr){
	cout << "\n[";
	forn(i, arr.size()){
		cout << "[";
		forn(j, arr[i].size() - 1)
			cout << arr[i][j] << ", ";
		cout << arr[i][arr[i].size() - 1] << "]";
		if (i != arr.size() - 1)
			cout << "," << endl;
	}
	cout << "], 2D Vector\n";
}


template <typename type> void print(const vector<type> &arr){
	cout << "\n[";
	forn(i, arr.size()){
		cout << arr[i];
		if (i != arr.size() - 1)
			cout << ", ";
	}
	cout << "], 1D Vector\n";
}

template <typename type> void off_print(const vector<type> &arr){
	forn(i, arr.size())
		cout << arr[i] << " ";
	cout << endl;
}


template <typename t1, typename t2> void print(const vector<pair<t1,t2> > &arr){
	int n = arr.size();
	cout << "\n[";
	forn(i, n - 1){
		cout << "{" << arr[i].first << "," << arr[i].second << "}, ";
	}
	cout << "{" << arr[n - 1].first << "," << arr[n - 1].second << "}], 1D Vector of Pairs\n";
}


template <typename t1, typename t2> void print(const vector<vector<pair<t1,t2> > > &arr){
	cout << "\n[";
	forn(i, arr.size()){
		cout << "[";
		forn(j, arr[i].size()){
			cout << "{" << arr[i][j].first << "," << arr[i][j].second << "}";
			if (j != arr[i].size() - 1)
				cout << ", ";
		}
		cout << "]";
		if (i != arr.size() - 1)
			cout << "," << endl;
	}
	cout << "], 2D Vector of Pairs\n";
}


template <typename t1, typename t2> void print(const pair<t1, t2> &p){
	cout << "\n{" << p.first << "," << p.second << "}, Pair\n";
}
// vector<ll> temp(5e7);
ll merge(vector<int> &z, ll start, ll mid, ll end){
    ll left = start, right = mid+1, k = 0, inv = 0;
    vector<int> temp(end- start + 1);
    while(left <= mid && right <= end){
        if (z[left] <= z[right]){
            inv = (inv + right-mid-1)%mod;
            temp[k++] = z[left++];
        }
        else
            temp[k++] = z[right++];
    }
    #if debug
        if (start == 3 && end == 4){
            cout << "in merge\n";
            print_var(inv);
            print_var(z[3]);
            print_var(z[4]);
            print_var(k);
            // print_var(z[5]);
        }
    #endif
    
    while(left <= mid){
        inv = (inv + right-mid-1)%mod;
        #if debug
        if (start == 3 && end == 5){
            cout << "here\n";
            print_var(inv);
            print_var(right-mid-1);
            print_var(left);
        }
    #endif
        temp[k++] = z[left++];
    }
    
    #if debug
        if (start == 3 && end == 5){
            print_var(inv);
        }
    #endif
    
    while(right <= end)
        temp[k++] = z[right++];
    
    #if debug
        if (start == 3 && end == 4){
            print_var(k);
        }
    #endif
    forn(i, k){
        assert(i+start <= end);
        z[i+start] = temp[i];
    }
    return inv;
}

ll merge_sort(vector<int> &z, ll start, ll end){
    if (start >= end) return 0;
    ll mid = (start+end)/2ll;
    #if debug
        if (start == 3 && end == 4){
            print_var(z[3]);
            print_var(z[4]);
        }
    #endif
    ll inv = merge_sort(z, start, mid);
    #if debug
        if (start == 3 && end == 4){
            cout << "after 1merge\n";
            print_arr(z);
        }
    #endif
    inv = (inv + merge_sort(z, mid+1, end))%mod;
    #if debug
        if (start == 3 && end == 4){
            cout << "after 2merge\n";
            print_arr(z);
        }
    #endif
    inv = (inv + merge(z, start, mid, end))%mod;
    #if debug
        print_var(start)
        print_var(end);
        print_var(mid);
        print_var(inv);
        print_arr(z);
        cout << endl;
    #endif
    return inv;
}

inline ll count_inversions(vector<int> &z){
    return merge_sort(z, 0, z.size()-1);
}

void dfs(int i, vector<vector<pair<int,int>>> &edges, vector<int> &z) {
    for(int j = 0; j < edges[i].size(); j++) {
        z.push_back(edges[i][j].second);
        dfs(edges[i][j].first, edges, z);
    }
}

void solve(){
    int n; cin >> n;
    vector<vector<pair<int,int>>> edges(n+1);
    int s, node, w;
    forsn(i,1,n){
        cin >> s;
        forn(j,s){
            cin >> node >> w;
            edges[i].push_back(make_pair(node,w));
        }
    }
    vector<int> z;
    dfs(1, edges, z);
    #if debug
        print_arr(z);
    #endif
    cout << count_inversions(z) << endl;
    #if debug
        print_arr(z);
    #endif
}