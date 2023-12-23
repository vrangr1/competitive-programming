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
#include <numeric>
#include <cmath>
#include <assert.h>

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
#define space " "

#define debug_mode false

typedef long long int ll;
typedef unsigned long long int ull;
template <typename type> void print(const vector<vector<type> > &arr);
template <typename type> void print(const vector<type> &arr);
template <typename type> void off_print(const vector<type> &arr);
template <typename t1, typename t2> void print(const vector<pair<t1,t2> > &arr);
template <typename t1, typename t2> void print(const vector<vector<pair<t1,t2> > > &arr);
template <typename t1, typename t2> void print(const pair<t1, t2> &p);

ll get_counter(ll num){
    ll ans = 0;
    ll count = 0, index = 0;
    bool begun = false;
    while(num > 0){
        if (!begun && num % 2 == 1)
            begun = true;
        else if (begun && num % 2 == 0)
            return -1;
        else if (begun && num % 2 == 1){
            begun = false;
            ans |= (1ll << (index - 1));
        }
        index++;
        num >>= 1;
    }
    if (!begun) return ans;
    else return -1;
}

inline bool predicate(const pair<ll,ll> &pr, const ll &val){
    return pr.first < val;
}

void solve(){
	ll n, other, ans = 0;
    cin >> n;
    vector<ll> arr(n);
    forn(i, n) cin >> arr[i];
    sort(arr.begin(), arr.end());
    vector<pair<ll, ll>> newarr;
    ll nn = 0;
    forn(i, n){
        if (nn == 0 || newarr[nn-1].first != arr[i]){
            newarr.push_back({arr[i], 1});
            nn++;
            continue;
        }
        assert(newarr[nn-1].first == arr[i]);
        newarr[nn-1].second++;
    }
    vector<pair<ll,ll>>::iterator iter;
    #if debug_mode
        print(newarr);
    #endif
    // reverse(arr.begin(), arr.end());
    forr(i, n){
        other = get_counter(arr[i]);
        #if debug_mode
            print_var(arr[i])
            print_var(other);
            cout << endl;
        #endif
        if (other == -1) continue;
        iter = lower_bound(newarr.begin(), newarr.end(), other, predicate);
        if (iter == newarr.end() || iter->first != other){
            #if debug_mode
            cout << "continuing\n";
            if (iter != newarr.end()) print(*iter);
            else cout << "newarr.end()\n";
            cout << endl;
            #endif
            continue;
        }
        // if (iter > arr.begin()) assert(*(prev(iter)) != other);
        assert(iter->first == other);
        assert(other != arr[i]);
        #if debug_mode
        cout << "found!\n";
        print(*iter);
        cout << endl;
        #endif
        ans += iter->second;
        // while(iter != arr.end() && *iter == other){
        //     ans++;
        //     iter = next(iter);
        // }
    }
    cout << ans << endl;
    return;
}

// void solve(){
//     ll n, ans = 0;
//     cin >> n;
//     vector<ll> arr(n);
//     forn(i, n) cin >> arr[i];
//     forn(i, n)
//         forsn(j, i + 1, n-1)
//             if (2ll * (arr[i] ^ arr[j]) == arr[i] + arr[j]) ans++;
//     cout << ans << endl;
// }

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
