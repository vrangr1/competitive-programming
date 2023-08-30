#if 0
    me=`basename $0 .cpp`
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
#include <unordered_map>
#include <bit>
#include <bitset>
#include <assert.h>
#define debug false

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
	TEST;
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

void initialize_factors(int x, map<int,int> &factors){
    if (x == 1) return;
    int num = 2;
    if (num % 2 == 0) factors[num] = 0;
    while(x % 2 == 0){
        x/=2;
        factors[num]++;
    }
    for (num = 3; x != 1 && num <= sqrt(x); num+=2){
        if (x%num == 0) factors[num] = 0;
        while(x % num == 0){
            x/=num;
            factors[num]++;
        }
    }
    if (factors.find(x) == factors.end()) factors[x] = 1;
    else factors[x]++;
}

int get_number(const vector<int> &factor, vector<int> &counts, int diff, int &sum){
    int ans = 1, n = counts.size();
    for (int i = 0; i < n; ++i){
        if (counts[i] > 0){
            ans *= ((int)pow(factor[i], diff));
            counts[i] -= diff;
            // assert(counts[i] >= 0);
            if (counts[i] < 0){
                cout << "early end\n";
                exit(0);
            }
            sum -= diff;
        }
    }
    return ans;
}

int get_min(const vector<int> &counts){
    int mn = INT_MAX;
    for(int ct : counts){
        if (ct == 0) continue;
        mn = min(mn, ct);
    }
    return mn;
}

int get_num(int x, map<int,int> &deductions){
    int num = 2;
    while(x % num != 0 || (deductions.find(x/num) != deductions.end() && deductions[x/num] >= 2)){
        if (num > x){
            return -1;
        }
        num++;
    }
    assert(x%num == 0 && (deductions.find(x/num) == deductions.end() || deductions[x/num] < 2));
    return x/num;
}

void solve(){
    int x, num; cin >> x;
    map<int,int> deductions;
    int k = 1;
    string output = "";
    output += to_string(x) + space;
    int itercount = 0;
    while(x != 1){
        itercount++;
        if (itercount > 50) assert(false);
        num = get_num(x, deductions);
        if (num == -1){
            cout << "problem!!\n";
            print_var(k);
            print_var(output);
            exit(0);
        }
        if (deductions.find(num) == deductions.end()) deductions[num] = 0;
        deductions[num]++;
        x -= num;
        k++;
        output += to_string(x) + space;
    }
    cout << k << endl << output << endl;
}
`
void solve10(){
    int x; cin >> x;
    vector<int> seen;
    int k = 1;
    map<int, int> factors, deductions;
    string output = "";
    output += to_string(x) + space;
    if (x % 2 != 0){
        x--;
        output += to_string(x) + space;
        k++;
        deductions[1] = 1;
    }
    if (x == 1){
        cout << k << endl;
        cout << output << endl;
        return;
    }
    #if debug
        print_var(x);
    #endif
    initialize_factors(x, factors);
    #if debug
        cout << "factors: ";
        for (auto iter = factors.begin(); iter != factors.end(); ++iter)
            cout << "{" << iter->first << ", " << iter->second << "} ";
        cout << endl;
    #endif
    assert(factors[2] > 0);
    factors[2]--;
    vector<int> factor(factors.size()), counts(factors.size());
    int index = 0;
    for (auto iter = factors.begin(); iter != factors.end(); ++iter){
        factor[index] = iter->first;
        counts[index++] = iter->second;
    }
    int n = factors.size();
    int sum = accumulate(counts.begin(), counts.end(), 0), mn, temp;
    #if debug
        // print_var(sum);
        // print_arr(counts);
    #endif
    while(sum > 0){
        mn = get_min(counts);
        #if debug
            print_var(sum);
            print_arr(counts);
            print_var(mn);
        #endif
        k++;
        temp = get_number(factor,counts, mn, sum);
        x -= temp;
        // assert(x > 1);
        output += to_string(x) + space;
        // if (sum > 0) output += space;
    }
    k++;
    output += "1";
    cout << k << endl;
    cout << output << endl;
}