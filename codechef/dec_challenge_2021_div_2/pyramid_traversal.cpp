/***************************************************
* AUTHOR : Anav Prasad
* Nick : graworth
****************************************************/
#include <bits/stdc++.h>

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
#define upperbd 1000000
#define prime 1000000007
vector<ll> factorial(upperbd);
bool debug = false;

ll find_row(ll n){
	// double row = (((double)-1) + sqrt(1 + 8 * n))/((double)2);
	ll row = ceil((-1 + ceil(sqrt(1 + 8*n)))/2.);
	return row;
	// ll inrow = row;
	// if (((double)inrow) < row)
	// 	return inrow + 1;
	// return inrow;
}


ll calcpow(ll n, ll m){
	assert(n>0);
	assert(m >= 0);
	if (m == 0)
		return 1;
	n = n %prime;
	if (m == 1)
		return n;
	ll temp = calcpow(n, m/2);
	temp = (temp * temp) % prime;
	if (m % 2 == 1){
		temp = (temp * n)%prime;
	}
	return temp;
}


ll modinv(ll n){
	// assert(n>0);
	return calcpow(n, prime - 2);
}



ll nck(ll n, ll k){
	// assert(n > k);
	// assert(n < upperbd);
	// assert(n-k < upperbd);
	// assert(k < upperbd);
	if (debug){
		cout << "n: " << n << endl;
		cout << "k: " << k << endl;
		cout << "fact[n]: " << factorial[n] << endl;
		cout << "fact[n-k]: " << factorial[n-k] << endl;
		cout << "fact[k]: " << factorial[k] << endl;
	}
	ll ans = (((factorial[n] * (modinv(factorial[n-k]) % prime)) % prime) * (modinv(factorial[k]) % prime))% prime;
	return ans;
}


void init(){
	factorial[0] = 1;
	factorial[1] = 1;
	factorial[2] = 2;
	for(ll i = 3; i < upperbd; ++i){
		factorial[i] = (factorial[i-1]*i)%prime;
	}
}


int main(){
	fastIO;
	if (debug){
		cout << "Reach here?" << endl;
	}
	int t;
	init();
	cin >> t;
	if (debug){
		cout <<"test_cases: " << t << endl;
	}
	while (t--){
		ll s, e;
		cin >> s >> e;
		if (s >= e){
			cout << 0 << endl;
			continue;
		}
		ll sr = find_row(s), er = find_row(e);
		if (sr == er){
			cout << 0 << endl;
			continue;
		}
		ll sind = (sr * (sr + 1))/2ll, eind = (er * (er + 1))/2ll;
		sind -= s;
		eind -= e;
		if (eind - sind < 0){
			cout << 0 << endl;
			continue;
		}
		if (er-sr < eind - sind){
			cout << 0 << endl;
			continue;
		}
		if (er - sr <= 0){
			cout << 0 << endl;
			continue;
		}
		if (debug){
		    cout << "trying this\n";
		    cout << "sr: " << sr << endl;
		    cout << "er: " << er << endl;
		    cout << "sind: " << sind << endl;
		    cout << "eind: " << eind << endl;
		    cout << "er - sr: " << er - sr << endl;
		    cout << "eind - sind: " << eind - sind << endl;
		    cout << nck(er-sr, eind-sind) << endl;
		}
		else
		    cout << nck(er - sr, eind-sind) << endl;

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