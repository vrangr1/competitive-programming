/***************************************************
* AUTHOR : Anav Prasad
* Nick : vrangr
****************************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <map>
#include <iterator>
#include <iomanip>
#include <algorithm>
#include <climits>
#include <assert.h>
// TODO: Check if all the header files are included

using namespace std;

#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0)
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
#define space " "
typedef long long int ll;
typedef unsigned long long int ull;
template <typename type> void print(const vector<vector<type> > &arr);
template <typename type> void print(const vector<type> &arr);
template <typename t1, typename t2> void print(const vector<pair<t1,t2> > &arr);
template <typename t1, typename t2> void print(const vector<vector<pair<t1,t2> > > &arr);
template <typename t1, typename t2> void print(const pair<t1, t2> &p);

bool compare_function(const pair<int, int> &first, const pair<int, int> &second){
    return first.first < second.first;
}

bool search_function(const pair<int, int> &item, const int val){
    return item.first < val;
}

void chkpt(bool reset = false){
    static int count = 0;
    if (reset) count = 0;
    cout << "checkpoint: " << count++ << endl;
}

int main(){
	fastIO;
	int T;
    cin >> T;
    while(T--){
        ll n, k;
        cin >> n >> k;
        vector<ll> weights(n);
        vector<pair<ll,ll> > remainders(n);
        vector<bool> accounted(n, false);
        forn(i,n){
            cin >> weights[i];
            remainders[i] = make_pair(weights[i] % k, i);
        }
        ll ans = 0;
        // chkpt(true);
        sort(remainders.begin(), remainders.end(), compare_function);
        // chkpt();
        ll start = 0, end = n-1;
        while(start < end){
            while(start < end && remainders[start].first + remainders[end].first < k){
                start++;
            }
            while(start < end && remainders[start].first + remainders[end].first < k){
                end--;
            }
            if (start < end && remainders[start].first + remainders[end].first >= k){
                // assert((weights[remainders[start].second] + weights[remainders[end].second]) % k == 0);
                ans += (weights[remainders[start].second] + weights[remainders[end].second])/k;
                accounted[remainders[start].second] = true;
                accounted[remainders[end].second] = true;
                start++;
                end--;
            }
            // else if (start < end){
            //     // assert(start < end && remainders[start].first + remainders[end].first > k);
            //     ans += (weights[remainders[start].second] + weights[remainders[end].second])/k;
            //     accounted[remainders[start].second] = true;
            //     accounted[remainders[end].second] = true;
            //     start++;
            //     end--;
            // }
        }
        // chkpt();
        // end = n-1;
        // vector<pair<int, int> >::iterator iter;
        // while(end >= 0){
        //     if (accounted[remainders[end].second]){
        //         end--;
        //         continue;
        //     }
        //     assert(end != 0);
        //     iter = lower_bound(remainders.begin(), remainders.begin() + end, k - remainders[end].first, search_function);
        //     if (iter >= remainders.begin() + end)
        //         break;
        //     int index = iter - remainders.begin();
        //     assert(remainders[index].first >= k - remainders[end].first);
        //     while(index < end && accounted[remainders[index].second]) index++;
        //     if (index == end)
        //         break;
        //     assert((remainders[start].first + remainders[end].first) > k);
        //     ans += (weights[remainders[index].second] + weights[remainders[end].second])/k;
        //     accounted[remainders[end].second] = true;
        //     accounted[remainders[index].second] = true;
        //     end--;
        // }
        // chkpt();
        forn(i, n){
            if (accounted[i]) continue;
            ans += (weights[i]/k);
        }
        // chkpt();
        // print_var(ans);
        cout << ans << endl;
    }
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
