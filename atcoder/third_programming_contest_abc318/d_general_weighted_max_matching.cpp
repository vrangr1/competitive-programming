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
#define debug true

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


class DSU{
private:
    vector<int> parent, rank;
public:
    DSU(int n) : parent(n,-1), rank(n,0){}
    int find(int i){
        assert(i >= 0 && i < parent.size());
        if (this->parent[i] == -1) return -1;
        int p = find(this->parent[i]);
        if (p == -1) return i;
        return this->parent[i] = p;
    }

    void unite(int x, int y)
    {
        #if debug
            if (x < 0 || x >= parent.size() || y < 0 || y >= parent.size() || x >= rank.size()){
                cout << "problem!";
                print_var(x);
                print_var(y);
                exit(0);
            }
        #endif
        int px = this->find(x), py = this->find(y);
        if (px == py && px != -1) return;
        #if debug
            print_var(x);
            print_var(y);
            print_var(px);
            print_var(py);
        #endif
        if (px == py){
            assert(x >= 0 && x < parent.size());
            assert(y >= 0 && y < parent.size());
            assert(x >= 0 && x < rank.size());
            parent[x] = x;
            parent[y] = x;
            rank[x]++;
            return;
        }
        assert(px != -1);
        assert(py != -1);
        assert(px >= 0 && px < rank.size());
        assert(py >= 0 && py < rank.size());
        if (rank[px] < rank[py])
            parent[px] = py;
        else if (rank[px] > rank[py])
            parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }
    }
};


ll kruskals_algo(vector<vector<ll>> &edges, int n){
    DSU dsu(n);
    ll mst_wt = 0;
    for (auto it=edges.begin(); it!=edges.end(); it++)
    {
        int u = it->at(0), v = it->at(1);
        #if debug
            if (u < 0 || u >= n || v < 0 || v >= n){
                cout << "problem2\n";
                print_var(u);
                print_var(v);
                exit(0);
            }
        #endif
        int set_u = dsu.find(u);
        int set_v = dsu.find(v);
        if (set_u != -1 || set_v != -1) continue;
        mst_wt += it->at(2);
        dsu.unite(v, u);
        #if debug
            cout << "counting\n";
            print_var(u);
            print_var(v);
            print_var(it->at(2));
            print_var(mst_wt);
            print_var(dsu.find(u));
            print_var(dsu.find(v));
            cout << endl;
        #endif
    }
  
    return mst_wt;
}

void solve(){
    int n; cin >> n;
    vector<vector<ll>> edges;
    ll val;
    forsn(i, 0, n-2){
        forsn(j, i+1, n-1){
            cin >> val;
            edges.push_back({i, j, -val});
        }
    }
    sort(edges.begin(), edges.end(), [](const vector<ll> &a, const vector<ll> &b){
        return a[2] < b[2];
    });
    // return;
    cout << -kruskals_algo(edges, n) << endl;
}